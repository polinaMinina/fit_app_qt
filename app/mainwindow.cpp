#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "schedule.h"

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QTimer>
#include <QFile>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , darkStyleEnabled(false)
{
    ui->setupUi(this);
    initDatabase();
    ui->PasswordEdit->setEchoMode(QLineEdit::Password);
    this->setWindowTitle("FitApp - Главная");


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_authButton_clicked()
{
    QString username = ui->LoginEdit->text(); // Предполагается, что ui->LoginEdit - это QLineEdit для логина
    QString password = ui->PasswordEdit->text(); // Аналогично для пароля

    // Проверка на пустые поля
    if(username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Ошибка аутентификации", "Логин и пароль не могут быть пустыми.");
        return;
    }

    // Хеширование пароля
    QCryptographicHash hash(QCryptographicHash::Sha256);
    hash.addData(password.toUtf8());
    QString passwordHash = hash.result().toHex();

    QSqlQuery query;
    query.prepare("SELECT password_hash FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if(!query.exec()) {
        QMessageBox::critical(this, "Ошибка аутентификации",
                              "Произошла ошибка при попытке аутентификации пользователя. Пожалуйста, попробуйте снова.");
        qDebug() << "Ошибка при аутентификации пользователя:" << query.lastError().text();
    } else {
        if(query.next()) {
            QString dbPasswordHash = query.value(0).toString();
            if(passwordHash == dbPasswordHash) {
                QMessageBox::information(this, "Аутентификация", "Пользователь успешно аутентифицирован.");

                Schedule *scheduleWindow = new Schedule(username);
                scheduleWindow->show();

                // Закрытие текущего окна (необязательно)
                this->close();
            } else {
                QMessageBox::warning(this, "Ошибка аутентификации", "Неверный логин или пароль.");
            }
        } else {
            QMessageBox::warning(this, "Ошибка аутентификации", "Неверный логин или пароль.");
        }
    }
}


void MainWindow::on_registButton_clicked()
{
    QString username = ui->LoginEdit->text(); // предполагается, что ui->LoginEdit - это QLineEdit для логина
    QString password = ui->PasswordEdit->text(); // аналогично для пароля

    // Установка ограничений на минимальную длину логина и пароля
    const int minUsernameLength = 4; // Минимальная длина логина
    const int minPasswordLength = 6; // Минимальная длина пароля

    if(username.length() < minUsernameLength || password.length() < minPasswordLength) {
        QMessageBox::warning(this, "Ошибка регистрации",
                             QString("Логин должен быть не менее %1 символов и пароль не менее %2 символов.")
                             .arg(minUsernameLength)
                                 .arg(minPasswordLength));
        return;
    }

    // Проверяем, существует ли уже пользователь с таким именем
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT EXISTS(SELECT 1 FROM users WHERE username = :username)");
    checkQuery.bindValue(":username", username);
    if(!checkQuery.exec()) {
        qDebug() << "Ошибка при проверке существования пользователя:" << checkQuery.lastError().text();
    } else {
        if(checkQuery.next() && checkQuery.value(0).toBool()) {
            QMessageBox::warning(this, "Ошибка регистрации",
                                 "Пользователь с таким именем уже существует.");
            return;
        }
    }

    // Хеширование пароля
    QCryptographicHash hash(QCryptographicHash::Sha256);
    hash.addData(password.toUtf8());
    QString passwordHash = hash.result().toHex();

    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password_hash) VALUES (:username, :password_hash)");
    query.bindValue(":username", username);
    query.bindValue(":password_hash", passwordHash);

    if(!query.exec()) {
        qDebug() << "Ошибка при регистрации пользователя:" << query.lastError().text();
    } else {
        QMessageBox::information(this, "Регистрация",
                                 "Пользователь успешно зарегистрирован.");
    }
}



void MainWindow::initDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("db_path.db"); // Укажите путь к файлу вашей базы данных

    if (!db.open()) {
        qDebug() << "Не удалось подключиться к базе данных:" << db.lastError().text();
        return;
    }

    QSqlQuery query;
    // Создание таблицы с именем 'users', если она еще не существует
    bool success = query.exec("CREATE TABLE IF NOT EXISTS users ("
                              "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                              "username VARCHAR(50) UNIQUE NOT NULL, "
                              "password_hash VARCHAR(255) NOT NULL)");

    if (!success) {
        qDebug() << "Ошибка при создании таблицы пользователей:" << query.lastError().text();
    }
    success = query.exec("CREATE TABLE IF NOT EXISTS exercises ("
                         "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                         "name VARCHAR(100) NOT NULL, "
                         "muscle_group VARCHAR(50) NOT NULL, "
                         "difficulty VARCHAR(50) NOT NULL)");
    if (!success) {
        qDebug() << "Ошибка при создании таблицы упражнений:" << query.lastError().text();
    }
    success = query.exec("CREATE TABLE IF NOT EXISTS exercise_sets ("
                         "set_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                         "set_name VARCHAR(100) NOT NULL)");
    if (!success) {
        qDebug() << "Ошибка при создании таблицы сетов упражнений:" << query.lastError().text();
    }
    // Проверяем, была ли создана таблица exercise_set_links
    success = query.exec("CREATE TABLE IF NOT EXISTS exercise_set_links ("
                         "set_id INTEGER NOT NULL, "
                         "exercise_id INTEGER NOT NULL, "
                         "reps_count INTEGER NOT NULL, "
                         "FOREIGN KEY(set_id) REFERENCES exercise_sets(set_id), "
                         "FOREIGN KEY(exercise_id) REFERENCES exercises(id))");
    if (!success) {
        qDebug() << "Ошибка при создании таблицы связей сетов и упражнений:" << query.lastError().text();
    }

    // Добавляем столбец username в таблицу exercise_set_links
    //success = query.exec("ALTER TABLE exercise_set_links ADD COLUMN username VARCHAR(50)");

    if (!success) {
        qDebug() << "Ошибка при добавлении столбца username в таблицу exercise_set_links:" << query.lastError().text();
    }

    success = query.exec("CREATE TABLE IF NOT EXISTS exercise_logs ("
                         "log_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                         "set_id INTEGER NOT NULL, "
                         "execution_date DATE NOT NULL, "
                         "FOREIGN KEY(set_id) REFERENCES exercise_sets(set_id))");
    if (!success) {
        qDebug() << "Ошибка при создании таблицы exercise_logs:" << query.lastError().text();
    }
    success = query.exec("ALTER TABLE exercise_logs ADD COLUMN username VARCHAR(50)");

    if (!success) {
        qDebug() << "Ошибка при добавлении столбца username в таблицу exercise_logs:" << query.lastError().text();
    }



}

void MainWindow::on_changeStyleButton_clicked()
{
    QFile file(darkStyleEnabled ? ":/design/Aqua.qss" : ":/design/DarkStyle.qss"); // Путь к файлу стиля
    if(file.open(QFile::ReadOnly)) {
        QString stylesheet = file.readAll();
        qApp->setStyleSheet(stylesheet); // Устанавливаем стиль для всего приложения
        file.close();
        darkStyleEnabled = !darkStyleEnabled; // Переключаем состояние стиля
    }
}


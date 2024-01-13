    #include "sets.h"
    #include "schedule.h"
    #include "ui_sets.h"
    #include <QSqlQuery>
    #include <QTableWidgetItem>
    #include <QSqlError>
    #include <QMessageBox>
    #include <QCheckBox>

    Sets::Sets(QString username, QWidget *parent) :
        QDialog(parent),
        ui(new Ui::sets),
        m_username(username)
    {
        ui->setupUi(this);
        loadExercises();
        setupConnections();


        // Запреты на редактирование таблиц
    }

    void Sets::loadExercises() {
        QSqlQuery query;
        if (!query.exec("SELECT name FROM exercises")) {
            qDebug() << "Ошибка запроса: " << query.lastError().text();
            return;
        }

        ui->exerciseSelect_tableWidget->clear(); // Очистить таблицу перед добавлением новых элементов
        ui->exerciseSelect_tableWidget->setRowCount(0); // Сброс количества строк
        ui->exerciseSelect_tableWidget->setColumnCount(3); // Три столбца
        ui->exerciseSelect_tableWidget->setHorizontalHeaderLabels(QStringList() << "Выбрать" << "Название упражнения" << "Количество подходов");

        int row = 0;
        while (query.next()) {
            ui->exerciseSelect_tableWidget->insertRow(row);
            QString exerciseName = query.value(0).toString();

            // Столбец с флажком
            QCheckBox *checkBox = new QCheckBox(); // Создаем флажок
            checkBox->setCheckState(Qt::Unchecked); // Устанавливаем состояние по умолчанию

            // Создаем виджет, который будет содержать флажок
            QWidget *widget = new QWidget();
            QHBoxLayout *layout = new QHBoxLayout(widget); // Устанавливаем горизонтальное выравнивание
            layout->addWidget(checkBox); // Добавляем флажок в layout
            layout->setAlignment(Qt::AlignCenter); // Выравниваем флажок по центру
            layout->setContentsMargins(0,0,0,0); // Убираем отступы
            widget->setLayout(layout); // Устанавливаем layout в виджет

            ui->exerciseSelect_tableWidget->setCellWidget(row, 0, widget); // Добавляем виджет с флажком в таблицу

            // Столбец с названием упражнения
            QTableWidgetItem *nameItem = new QTableWidgetItem(exerciseName);
            nameItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            ui->exerciseSelect_tableWidget->setItem(row, 1, nameItem);

            // Столбец для ввода количества подходов
            QTableWidgetItem *repsItem = new QTableWidgetItem("1");
            repsItem->setFlags(Qt::ItemIsEditable | Qt::ItemIsEnabled);
            ui->exerciseSelect_tableWidget->setItem(row, 2, repsItem);

            row++;
        }

        // Настройка ширины столбцов
        ui->exerciseSelect_tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
        ui->exerciseSelect_tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
        ui->exerciseSelect_tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);

        loadSets();

        this->setWindowTitle("FitApp - сеты");
    }

    void Sets::loadSets() {
        QSqlQuery query;
        if (!query.exec("SELECT set_id, set_name FROM exercise_sets")) {
            qDebug() << "Ошибка запроса при загрузке сетов: " << query.lastError().text();
            return;
        }

        ui->exercise_tableWidget->clear();
        ui->exercise_tableWidget->setRowCount(0);
        ui->exercise_tableWidget->setColumnCount(3); // Три столбца
        ui->exercise_tableWidget->setHorizontalHeaderLabels(QStringList() << "ID сета" << "Название сета" << "Упражнения");

        int row = 0;
        while (query.next()) {
            ui->exercise_tableWidget->insertRow(row);
            int setId = query.value(0).toInt();
            QString setName = query.value(1).toString();

            QTableWidgetItem *idItem = new QTableWidgetItem(QString::number(setId));
            QTableWidgetItem *nameItem = new QTableWidgetItem(setName);
            QTableWidgetItem *exercisesItem = new QTableWidgetItem();

            // Делаем все ячейки нередактируемыми
            idItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            nameItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            exercisesItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);


            // Получение упражнений, связанных с сетом
            QSqlQuery exerciseQuery;
            exerciseQuery.prepare("SELECT e.name, l.reps_count FROM exercise_set_links l JOIN exercises e ON l.exercise_id = e.id WHERE l.set_id = :set_id");
            exerciseQuery.bindValue(":set_id", setId);

            qDebug() << "Запрос для получения упражнений сета:" << exerciseQuery.executedQuery(); // Вывод сформированного запроса


            if (exerciseQuery.exec()) {
                QStringList exercisesInfo;
                while (exerciseQuery.next()) {
                    QString exerciseName = exerciseQuery.value(0).toString();
                    int repsCount = exerciseQuery.value(1).toInt();
                    exercisesInfo.append(exerciseName + ": " + QString::number(repsCount));
                }
                exercisesItem->setText(exercisesInfo.join(", "));
            } else {
                qDebug() << "Ошибка при получении упражнений для сета: " << exerciseQuery.lastError().text();
            }

            ui->exercise_tableWidget->setItem(row, 0, idItem);
            ui->exercise_tableWidget->setItem(row, 1, nameItem);
            ui->exercise_tableWidget->setItem(row, 2, exercisesItem);

            row++;
        }
    }




    void Sets::setupConnections() {
        connect(ui->addSet_pushButton, &QPushButton::clicked, this, &Sets::addSet);
        connect(ui->deleteSet_pushButton, &QPushButton::clicked, this, &Sets::deleteSet);
    }

    void Sets::addSet() {
        QString setName = ui->setname_lineEdit->text().trimmed();
        if (setName.isEmpty()) {
            QMessageBox::warning(this, "Предупреждение", "Название сета не может быть пустым.");
            return;
        }

        QSqlQuery query;
        query.prepare("INSERT INTO exercise_sets (set_name) VALUES (:set_name)");
        query.bindValue(":set_name", setName);
        if (!query.exec()) {
            qDebug() << "Ошибка при добавлении сета: " << query.lastError().text();
                return;
        }
        int setId = query.lastInsertId().toInt();

        bool exercisesAdded = false;

        qDebug() << "Я еще тут жив";
        // Теперь добавляем связи между сетом и упражнениями
        for (int i = 0; i < ui->exerciseSelect_tableWidget->rowCount(); ++i) {
                QWidget *widget = ui->exerciseSelect_tableWidget->cellWidget(i, 0);
                QCheckBox *checkBox = widget ? widget->findChild<QCheckBox *>() : nullptr;
                if (checkBox && checkBox->isChecked()) {
                exercisesAdded = true;

                QTableWidgetItem *nameItem = ui->exerciseSelect_tableWidget->item(i, 1);
                QTableWidgetItem *repsItem = ui->exerciseSelect_tableWidget->item(i, 2);

                if (!nameItem || !repsItem) {
                    qDebug() << "Ошибка: один из элементов nameItem или repsItem - nullptr";
                    continue;
                }
                // Получаем ID упражнения по его названию
                query.prepare("SELECT id FROM exercises WHERE name = :name");
                query.bindValue(":name", nameItem->text());
                if (!query.exec()) {
                    qDebug() << "Ошибка при получении ID упражнения: " << query.lastError().text();
                        continue;
                }
                if (!query.next()) {
                    qDebug() << "Упражнение не найдено: " << nameItem->text();
                        continue;
                }
                int exerciseId = query.value(0).toInt();

                // Добавляем связь упражнения с сетом
                query.prepare("INSERT INTO exercise_set_links (set_id, exercise_id, reps_count) VALUES (:set_id, :exercise_id, :reps_count)");
                query.bindValue(":set_id", setId);
                query.bindValue(":exercise_id", exerciseId);
                query.bindValue(":reps_count", repsItem->text().toInt());
                if (!query.exec()) {
                    qDebug() << "Ошибка при добавлении упражнения в сет: " << query.lastError().text();
                }
            }
        }
        if (exercisesAdded) {
            loadSets(); // Обновляем список сетов
        }
    }




    // Реализация deleteSet
    void Sets::deleteSet() {
        auto selectedRows = ui->exercise_tableWidget->selectionModel()->selectedRows();
        QSqlQuery query;
        QVector<int> setIdsToDelete;

        // Сначала собираем ID сетов для удаления
        for (const QModelIndex &row : selectedRows) {
            int setId = ui->exercise_tableWidget->item(row.row(), 0)->text().toInt();
            setIdsToDelete.push_back(setId);
        }

        // Удаление связей и самих сетов
        for (int setId : setIdsToDelete) {
            // Удаление связей сета с упражнениями
            query.prepare("DELETE FROM exercise_set_links WHERE set_id = :set_id");
            query.bindValue(":set_id", setId);
            if (!query.exec()) {
                qDebug() << "Ошибка при удалении связей упражнений сета: " << query.lastError().text();
            }

            // Удаление самого сета
            query.prepare("DELETE FROM exercise_sets WHERE set_id = :set_id");
            query.bindValue(":set_id", setId);
            if (!query.exec()) {
                qDebug() << "Ошибка при удалении сета: " << query.lastError().text();
            }
        }

        // Удаление строк из таблицы виджета
        for (const QModelIndex &row : selectedRows) {
            ui->exercise_tableWidget->removeRow(row.row());
        }

        // Обновляем список сетов после удаления
        loadSets();
    }


    Sets::~Sets() {
        delete ui;
    }

    void Sets::on_addSet_pushButton_clicked() {
        // Обновляем список сетов после добавления нового сета
        loadSets();
    }

    void Sets::on_pushButton_clicked()
    {
        Schedule *scheduleWindow = new Schedule(m_username);

        // Установка флага для автоматического удаления окна после закрытия
        scheduleWindow->setAttribute(Qt::WA_DeleteOnClose);

        // Запуск окна в немодальном режиме
        scheduleWindow->show();

        // Закрытие текущего окна
        this->close();
    }


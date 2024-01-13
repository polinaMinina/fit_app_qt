/*!
 * \file mainwindow.h
 * \brief Описание класса MainWindow, управляющего основным окном приложения.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
 * \class MainWindow mainwindow.h "mainwindow.h"
 * \brief Класс MainWindow представляет главное окно приложения.
 *
 * Класс MainWindow управляет взаимодействиями пользователя с главным окном приложения,
 * обрабатывая события авторизации и регистрации, а также инициализирует базу данных.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор класса MainWindow.
     * \param parent Указатель на родительский виджет.
     */
    MainWindow(QWidget *parent = nullptr);

    /*!
     * \brief Деструктор класса MainWindow.
     */
    ~MainWindow();

private slots:
    /*!
     * \brief Обработка нажатия кнопки авторизации.
     *
     * Авторизует пользователя в системе, проверяя введенные учетные данные.
     */
    void on_authButton_clicked();

    /*!
     * \brief Обработка нажатия кнопки регистрации.
     *
     * Регистрирует нового пользователя в системе.
     */
    void on_registButton_clicked();

    void on_changeStyleButton_clicked();

private:
    Ui::MainWindow *ui; //!< Указатель на пользовательский интерфейс.
    bool darkStyleEnabled; //!< Флаг стиля.
    /*!
     * \brief Инициализация базы данных.
     *
     * Выполняет подключение к базе данных и создает необходимые таблицы.
     */
    void initDatabase();
};
#endif // MAINWINDOW_H

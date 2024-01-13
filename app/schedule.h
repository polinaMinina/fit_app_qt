/*!
 * \file schedule.h
 * \brief Описание класса schedule, управляющего расписанием упражнений.
 */

#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class schedule;
}

/*!
 * \class Schedule Schedule.h "Schedule.h"
 * \brief Класс Schedule предоставляет интерфейс для управления расписанием упражнений.
 *
 * Этот класс позволяет добавлять, удалять и отображать упражнения,
 * а также обрабатывает действия пользователя в пользовательском интерфейсе.
 */
class Schedule : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор класса Schedule.
     * \param parent Указатель на родительский виджет.
     */
    explicit Schedule(QWidget *parent = nullptr);

    /*!
     * \brief Перегруженный конструктор класса Schedule с указанием имени пользователя.
     * \param username Логин пользователя.
     * \param parent Указатель на родительский виджет.
     */
    explicit Schedule(QString username, QWidget *parent = nullptr);

    /*!
     * \brief Деструктор класса Schedule.
     */
    ~Schedule();

private slots:
    /*!
     * \brief Обработка нажатия кнопки сохранения изменений.
     */
    void on_saveButton_clicked();

    /*!
     * \brief Обработка нажатия кнопки отмены изменений.
     */
    void on_cancelButton_clicked();

    /*!
     * \brief Обработка нажатия кнопки добавления нового упражнения.
     */
    void on_addButton_clicked();

    /*!
     * \brief Обработка нажатия кнопки удаления упражнения.
     */
    void on_DeleteButton_clicked();

    /*!
     * \brief Обработка нажатия кнопки авторизации.
     */
    void on_authButton_clicked();

    /*!
     * \brief Обработка нажатия кнопки перехода к настройкам сетов упражнений.
     */
    void on_setButton_clicked();

    /*!
     * \brief Обработка нажатия кнопки перехода к календарю упражнений.
     */
    void on_timetableButton_clicked();

private:
    Ui::schedule *ui; //!< Указатель на пользовательский интерфейс.
    QSqlTableModel *model; //!< Модель для работы с данными.
    QString m_username; //!< Логин пользователя, использующего приложение.
};

#endif // SCHEDULE_H

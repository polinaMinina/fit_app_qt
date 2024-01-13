/*!
 * \file calendaractivity.h
 * \brief Описание класса CalendarActivity, управляющего активностью календаря.
 */

#ifndef CALENDARACTIVITY_H
#define CALENDARACTIVITY_H

#include <QDialog>
#include <QDate>

namespace Ui {
class CalendarActivity;
}

/**
 * @class CalendarActivity
 * @brief Класс для управления активностью календаря в приложении.
 *
 * CalendarActivity представляет собой диалоговое окно, отображающее календарь
 * и список упражнений пользователя, а также позволяет управлять этими данными.
 */
class CalendarActivity : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор класса CalendarActivity.
     * \param parent Указатель на родительский виджет.
     */
    explicit CalendarActivity(QString username, QWidget *parent = nullptr);

    /*!
     * \brief Деструктор класса CalendarActivity.
     */
    ~CalendarActivity();

private slots:
    /*!
     * \brief Слот, вызываемый при изменении выбранной даты в календаре.
     *
     * Обновляет представление сетов упражнений в соответствии с выбранной датой.
     */
    void onCalendarSelectionChanged();

    /*!
     * \brief Слот для обработки radiobuttons в таблице.
     *
     * Представляет дополнительный функционал для обработки.
     */
    void setupSetsView();

    /*!
     * \brief Слот для обработки нажатия на кнопку добавления сета.
     *
     * Добавляет выбранный сет упражнений в базу данных для выбранной даты.
     */
    void on_addSet_clicked();

    /*!
     * \brief Слот для обработки нажатия на кнопку удаления сета.
     *
     * Удаляет выбранный сет упражнений из базы данных.
     */
    void on_removeSet_clicked();

    void on_calendarSets_selectionChanged();

    void on_go_backButton_clicked();

private:
    Ui::CalendarActivity *ui; //!< Указатель на пользовательский интерфейс.
    QString m_username; //!< Имя пользователя, использующего форму.

    /*!
     * \brief Обновляет представление сетов упражнений.
     * \param date Выбранная дата для отображения сетов.
     *
     * Загружает и отображает сеты упражнений, соответствующие выбранной дате.
     */
    void updateSetsView(const QDate &date);
};

#endif // CALENDARACTIVITY_H

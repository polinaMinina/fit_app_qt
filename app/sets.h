/*!
 * \file sets.h
 * \brief Описание класса sets, управляющего наборами упражнений.
 */

#ifndef SETS_H
#define SETS_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class sets;
}

/*!
 * \class Sets Sets.h "Sets.h"
 * \brief Класс Sets предоставляет функциональность для управления наборами упражнений (сетами).
 *
 * Этот класс позволяет загружать, добавлять, удалять и отображать наборы упражнений,
 * а также устанавливать соединения между элементами пользовательского интерфейса.
 */
class Sets : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Конструктор класса Sets.
     * \param parent Указатель на родительский виджет.
     */
    explicit Sets(QString username, QWidget *parent = nullptr);


    /*!
     * \brief Деструктор класса Sets.
     */
    ~Sets();

private slots:
    /*!
     * \brief Загрузка списка упражнений из базы данных.
     */
    void loadExercises();

    /*!
     * \brief Добавление нового сета.
     */
    void addSet();

    /*!
     * \brief Удаление существующего сета.
     */
    void deleteSet();

    /*!
     * \brief Настройка соединений между элементами интерфейса и слотами.
     */
    void setupConnections();

    /*!
     * \brief Загрузка списка сетов из базы данных.
     */
    void loadSets();

    /*!
     * \brief Обработка нажатия кнопки для добавления сета.
     */
    void on_addSet_pushButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::sets *ui; //!< Указатель на пользовательский интерфейс.
    QSqlTableModel *model; //!< Модель для работы с данными базы данных.
    QString m_username; //!< Имя пользователя, использующего форму.

};

#endif // SETS_H

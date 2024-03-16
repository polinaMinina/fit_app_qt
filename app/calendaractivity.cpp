#include "calendaractivity.h"
#include "ui_calendaractivity.h"
#include "schedule.h"
#include "qsqlquerymodel.h"
#include "qsqlquery.h"
#include "qsqlerror.h"
#include "qdebug.h"
#include "qsqldatabase.h"
#include "qmessagebox.h"
#include "qcheckbox.h"
#include "qstandarditemmodel.h"
#include "qstyleditemdelegate.h"
#include "calendaractivity.h"
#include "ui_calendaractivity.h"
#include "checkboxdelegate.h"


void CalendarActivity::setupSetsView() {
    ui->SetstableView->clear();
    ui->SetstableView->setRowCount(0);
    ui->SetstableView->setColumnCount(2); // Две колонки: чекбокс и название

    ui->SetstableView->setHorizontalHeaderLabels(QStringList() << "Выбрать" << "Название сета");

    QSqlQuery query("SELECT set_id, set_name FROM exercise_sets");
    int row = 0;
    while (query.next()) {
        ui->SetstableView->insertRow(row);

        int setId = query.value(0).toInt(); // Получаем set_id

        // Добавление чекбокса
        QCheckBox *checkBox = new QCheckBox();
        QWidget *checkboxWidget = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(checkboxWidget);
        layout->addWidget(checkBox);
        layout->setAlignment(Qt::AlignCenter);
        layout->setContentsMargins(0, 0, 0, 0);
        checkboxWidget->setLayout(layout);

        ui->SetstableView->setCellWidget(row, 0, checkboxWidget);

        // Добавление названия сета и сохранение set_id
        QTableWidgetItem *nameItem = new QTableWidgetItem(query.value(1).toString());
        nameItem->setData(Qt::UserRole, setId); // Сохраняем set_id в UserRole
        nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable); // Сделать ячейку нередактируемой
        ui->SetstableView->setItem(row, 1, nameItem);

        row++;
    }

    ui->SetstableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}





CalendarActivity::CalendarActivity(QString username, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalendarActivity),
    m_username(username)
{
    ui->setupUi(this);
    setupSetsView();

    connect(ui->calendarSets, &QCalendarWidget::selectionChanged,
            this, &CalendarActivity::onCalendarSelectionChanged);

    QSqlQueryModel *setsModel = new QSqlQueryModel(this);
    setsModel->setQuery("SELECT set_id, set_name FROM exercise_sets");
     //ui->SetstableView->setModel(setsModel);

    // Растягиваем заголовки таблицы на всю ширину для SetstableView
    ui->SetstableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    this->setWindowTitle("FitApp - Календарь");
}


CalendarActivity::~CalendarActivity()
{
    delete ui;
}

void CalendarActivity::onCalendarSelectionChanged() {
    QDate selectedDate = ui->calendarSets->selectedDate();
    updateSetsView(selectedDate);
}

void CalendarActivity::updateSetsView(const QDate &date) {
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString dateString = date.toString("yyyy-MM-dd");

    // Измененный запрос для получения названий сетов, упражнений и количества подходов
    QString queryString = QString(
                              "SELECT es.set_name, "
                              "GROUP_CONCAT(e.name || ' (' || l.reps_count || ' подходов)') AS exercises_info "
                              "FROM exercise_logs el "
                              "JOIN exercise_sets es ON el.set_id = es.set_id "
                              "JOIN exercise_set_links l ON es.set_id = l.set_id "
                              "JOIN exercises e ON l.exercise_id = e.id "
                              "WHERE el.execution_date = '%1' AND el.username = '%2' "
                              "GROUP BY el.log_id, es.set_name")
                              .arg(dateString)
                              .arg(m_username);

    model->setQuery(queryString);
    if (model->lastError().isValid()) {
        qDebug() << "Ошибка при запросе к базе данных:" << model->lastError().text();
    } else {
        // Настройка заголовков столбцов
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Название сета"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Упражнения и подходы"));
    }

    ui->exerciseLogsView->setModel(model); // Присваиваем модель для таблицы exerciseLogsView
}





void CalendarActivity::on_addSet_clicked() {
    QDate selectedDate = ui->calendarSets->selectedDate();
    if (!selectedDate.isValid()) {
        QMessageBox::warning(this, "Ошибка", "Выберите дату.");
        return;
    }

    bool anySetAdded = false; // Флаг для отслеживания добавления хотя бы одного сета

    for (int i = 0; i < ui->SetstableView->rowCount(); ++i) {
        QWidget *widget = ui->SetstableView->cellWidget(i, 0);
        QCheckBox *checkBox = widget ? widget->findChild<QCheckBox*>() : nullptr;
        if (checkBox && checkBox->isChecked()) {
            int setId = ui->SetstableView->item(i, 1)->data(Qt::UserRole).toInt();

            QSqlQuery query;
            query.prepare("INSERT INTO exercise_logs (set_id, execution_date, username) VALUES (:set_id, :execution_date, :username)");
            query.bindValue(":set_id", setId);
            query.bindValue(":execution_date", selectedDate.toString("yyyy-MM-dd"));
            query.bindValue(":username", m_username);
            if (query.exec()) {
                anySetAdded = true; // Отмечаем, что был добавлен хотя бы один сет
            } else {
                qDebug() << "Ошибка при добавлении сета: " << query.lastError().text();
            }
        }
    }

    if (anySetAdded) {
        QMessageBox::information(this, "Успешно", "Выбранные сеты добавлены в журнал.");
        updateSetsView(selectedDate); // Обновление списка сетов
    } else {
        QMessageBox::warning(this, "Информация", "Не выбрано ни одного сета для добавления.");
    }
}





void CalendarActivity::on_removeSet_clicked() {
    QModelIndexList selected = ui->exerciseLogsView->selectionModel()->selectedRows();

    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Выберите сет для удаления.");
        return;
    }

    int logId = selected.first().siblingAtColumn(0).data().toInt(); // Предполагаем, что log_id находится в первой колонке

    QSqlQuery query;
    QString queryString = QString("DELETE FROM exercise_logs WHERE log_id = %1").arg(logId);
    if (!query.exec(queryString)) {
        qDebug() << "Ошибка при удалении сета: " << query.lastError().text();
                QMessageBox::warning(this, "Ошибка", "Не удалось удалить сет.");
    } else {
        QMessageBox::information(this, "Успешно", "Сет удален из журнала.");
        QDate selectedDate = ui->calendarSets->selectedDate();
        updateSetsView(selectedDate); // Обновление списка сетов
    }
}


void CalendarActivity::on_calendarSets_selectionChanged()
{
    QDate selectedDate = ui->calendarSets->selectedDate();
    updateSetsView(selectedDate);

    // Растягиваем заголовки таблицы на всю ширину для exerciseLogsView
    ui->exerciseLogsView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


void CalendarActivity::on_go_backButton_clicked() {
    Schedule *scheduleWindow = new Schedule(m_username);

    // Установка флага для автоматического удаления окна после закрытия
    scheduleWindow->setAttribute(Qt::WA_DeleteOnClose);

    // Запуск окна в немодальном режиме
    scheduleWindow->show();

    // Закрытие текущего окна
    this->close();
}


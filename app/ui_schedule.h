/********************************************************************************
** Form generated from reading UI file 'schedule.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEDULE_H
#define UI_SCHEDULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_schedule
{
public:
    QVBoxLayout *verticalLayout_5;
    QTableView *tableView;
    QLabel *label;
    QGridLayout *gridLayout;
    QPushButton *cancelButton;
    QPushButton *saveButton;
    QPushButton *DeleteButton;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QComboBox *difficultyComboBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLineEdit *exerciseNameLineEdit;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QComboBox *muscleGroupComboBox;
    QPushButton *addButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *authButton;
    QPushButton *timetableButton;
    QPushButton *setButton;

    void setupUi(QDialog *schedule)
    {
        if (schedule->objectName().isEmpty())
            schedule->setObjectName("schedule");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(schedule->sizePolicy().hasHeightForWidth());
        schedule->setSizePolicy(sizePolicy);
        schedule->setAcceptDrops(false);
        verticalLayout_5 = new QVBoxLayout(schedule);
        verticalLayout_5->setObjectName("verticalLayout_5");
        tableView = new QTableView(schedule);
        tableView->setObjectName("tableView");

        verticalLayout_5->addWidget(tableView);

        label = new QLabel(schedule);
        label->setObjectName("label");

        verticalLayout_5->addWidget(label);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        cancelButton = new QPushButton(schedule);
        cancelButton->setObjectName("cancelButton");

        gridLayout->addWidget(cancelButton, 1, 0, 1, 1);

        saveButton = new QPushButton(schedule);
        saveButton->setObjectName("saveButton");

        gridLayout->addWidget(saveButton, 0, 0, 1, 1);

        DeleteButton = new QPushButton(schedule);
        DeleteButton->setObjectName("DeleteButton");

        gridLayout->addWidget(DeleteButton, 2, 0, 1, 1);


        verticalLayout_5->addLayout(gridLayout);

        label_2 = new QLabel(schedule);
        label_2->setObjectName("label_2");

        verticalLayout_5->addWidget(label_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_5 = new QLabel(schedule);
        label_5->setObjectName("label_5");

        verticalLayout->addWidget(label_5);

        difficultyComboBox = new QComboBox(schedule);
        difficultyComboBox->setObjectName("difficultyComboBox");

        verticalLayout->addWidget(difficultyComboBox);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_3 = new QLabel(schedule);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        exerciseNameLineEdit = new QLineEdit(schedule);
        exerciseNameLineEdit->setObjectName("exerciseNameLineEdit");

        verticalLayout_2->addWidget(exerciseNameLineEdit);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_4 = new QLabel(schedule);
        label_4->setObjectName("label_4");

        verticalLayout_3->addWidget(label_4);

        muscleGroupComboBox = new QComboBox(schedule);
        muscleGroupComboBox->setObjectName("muscleGroupComboBox");

        verticalLayout_3->addWidget(muscleGroupComboBox);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_2);

        addButton = new QPushButton(schedule);
        addButton->setObjectName("addButton");

        verticalLayout_4->addWidget(addButton);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        authButton = new QPushButton(schedule);
        authButton->setObjectName("authButton");

        horizontalLayout->addWidget(authButton);

        timetableButton = new QPushButton(schedule);
        timetableButton->setObjectName("timetableButton");

        horizontalLayout->addWidget(timetableButton);

        setButton = new QPushButton(schedule);
        setButton->setObjectName("setButton");

        horizontalLayout->addWidget(setButton);


        verticalLayout_5->addLayout(horizontalLayout);


        retranslateUi(schedule);

        QMetaObject::connectSlotsByName(schedule);
    } // setupUi

    void retranslateUi(QDialog *schedule)
    {
        schedule->setWindowTitle(QCoreApplication::translate("schedule", "FitApp - \320\243\320\277\321\200\320\260\320\266\320\275\320\265\320\275\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("schedule", "\320\255\320\273\320\265\320\274\320\265\320\275\321\202\321\213 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));
        cancelButton->setText(QCoreApplication::translate("schedule", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        saveButton->setText(QCoreApplication::translate("schedule", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        DeleteButton->setText(QCoreApplication::translate("schedule", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\275\321\213\320\265 \320\267\320\260\320\277\320\270\321\201\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("schedule", "\320\255\320\273\320\265\320\274\320\265\320\275\321\202\321\213 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));
        label_5->setText(QCoreApplication::translate("schedule", "\320\241\320\273\320\276\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("schedule", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\203\320\277\321\200\320\260\320\266\320\275\320\265\320\275\320\270\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("schedule", "\320\223\321\200\321\203\320\277\320\277\320\260 \320\274\321\213\321\211\321\206", nullptr));
        addButton->setText(QCoreApplication::translate("schedule", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\203\320\277\321\200\320\260\320\266\320\275\320\265\320\275\320\270\320\265", nullptr));
        authButton->setText(QCoreApplication::translate("schedule", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\272 \320\260\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\320\270", nullptr));
        timetableButton->setText(QCoreApplication::translate("schedule", "\320\240\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
        setButton->setText(QCoreApplication::translate("schedule", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\201\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class schedule: public Ui_schedule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEDULE_H

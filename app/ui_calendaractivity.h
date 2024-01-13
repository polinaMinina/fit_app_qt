/********************************************************************************
** Form generated from reading UI file 'calendaractivity.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDARACTIVITY_H
#define UI_CALENDARACTIVITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CalendarActivity
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarSets;
    QHBoxLayout *horizontalLayout;
    QPushButton *addSet;
    QPushButton *removeSet;
    QPushButton *go_backButton;
    QTableWidget *SetstableView;
    QTableView *exerciseLogsView;

    void setupUi(QDialog *CalendarActivity)
    {
        if (CalendarActivity->objectName().isEmpty())
            CalendarActivity->setObjectName("CalendarActivity");
        CalendarActivity->resize(558, 371);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CalendarActivity->sizePolicy().hasHeightForWidth());
        CalendarActivity->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(CalendarActivity);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        calendarSets = new QCalendarWidget(CalendarActivity);
        calendarSets->setObjectName("calendarSets");

        verticalLayout->addWidget(calendarSets);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        addSet = new QPushButton(CalendarActivity);
        addSet->setObjectName("addSet");

        horizontalLayout->addWidget(addSet);

        removeSet = new QPushButton(CalendarActivity);
        removeSet->setObjectName("removeSet");

        horizontalLayout->addWidget(removeSet);

        go_backButton = new QPushButton(CalendarActivity);
        go_backButton->setObjectName("go_backButton");

        horizontalLayout->addWidget(go_backButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        SetstableView = new QTableWidget(CalendarActivity);
        SetstableView->setObjectName("SetstableView");

        horizontalLayout_2->addWidget(SetstableView);


        verticalLayout_2->addLayout(horizontalLayout_2);

        exerciseLogsView = new QTableView(CalendarActivity);
        exerciseLogsView->setObjectName("exerciseLogsView");

        verticalLayout_2->addWidget(exerciseLogsView);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(CalendarActivity);

        QMetaObject::connectSlotsByName(CalendarActivity);
    } // setupUi

    void retranslateUi(QDialog *CalendarActivity)
    {
        CalendarActivity->setWindowTitle(QCoreApplication::translate("CalendarActivity", "FitApp - \320\232\320\260\320\273\320\265\320\275\320\264\320\260\321\200\321\214 \320\260\320\272\321\202\320\270\320\262\320\275\320\276\321\201\321\202\320\270", nullptr));
        addSet->setText(QCoreApplication::translate("CalendarActivity", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\320\265\321\202", nullptr));
        removeSet->setText(QCoreApplication::translate("CalendarActivity", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\320\265\321\202", nullptr));
        go_backButton->setText(QCoreApplication::translate("CalendarActivity", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalendarActivity: public Ui_CalendarActivity {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDARACTIVITY_H

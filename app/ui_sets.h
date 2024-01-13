/********************************************************************************
** Form generated from reading UI file 'sets.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETS_H
#define UI_SETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_sets
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTableWidget *exercise_tableWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *exerciseSelect_tableWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *setname_lineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *addSet_pushButton;
    QPushButton *pushButton;
    QPushButton *deleteSet_pushButton;

    void setupUi(QDialog *sets)
    {
        if (sets->objectName().isEmpty())
            sets->setObjectName("sets");
        sets->resize(400, 350);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sets->sizePolicy().hasHeightForWidth());
        sets->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(sets);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(sets);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        exercise_tableWidget = new QTableWidget(sets);
        exercise_tableWidget->setObjectName("exercise_tableWidget");

        verticalLayout_2->addWidget(exercise_tableWidget);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(sets);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        exerciseSelect_tableWidget = new QTableWidget(sets);
        exerciseSelect_tableWidget->setObjectName("exerciseSelect_tableWidget");

        verticalLayout->addWidget(exerciseSelect_tableWidget);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(sets);
        label_3->setObjectName("label_3");
        label_3->setLayoutDirection(Qt::RightToLeft);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_3->addWidget(label_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        setname_lineEdit = new QLineEdit(sets);
        setname_lineEdit->setObjectName("setname_lineEdit");

        horizontalLayout_2->addWidget(setname_lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        addSet_pushButton = new QPushButton(sets);
        addSet_pushButton->setObjectName("addSet_pushButton");

        horizontalLayout->addWidget(addSet_pushButton);

        pushButton = new QPushButton(sets);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        deleteSet_pushButton = new QPushButton(sets);
        deleteSet_pushButton->setObjectName("deleteSet_pushButton");

        horizontalLayout->addWidget(deleteSet_pushButton);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);


        retranslateUi(sets);

        QMetaObject::connectSlotsByName(sets);
    } // setupUi

    void retranslateUi(QDialog *sets)
    {
        sets->setWindowTitle(QCoreApplication::translate("sets", "FitApp - \321\201\320\265\321\202\321\213", nullptr));
        label_2->setText(QCoreApplication::translate("sets", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260 \321\201\320\265\321\202\320\276\320\262", nullptr));
        label->setText(QCoreApplication::translate("sets", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\203\320\277\321\200\320\260\320\266\320\275\320\265\320\275\320\270\320\271", nullptr));
        label_3->setText(QCoreApplication::translate("sets", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\201\320\265\321\202\320\260", nullptr));
        addSet_pushButton->setText(QCoreApplication::translate("sets", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\320\265\321\202", nullptr));
        pushButton->setText(QCoreApplication::translate("sets", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        deleteSet_pushButton->setText(QCoreApplication::translate("sets", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sets: public Ui_sets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETS_H

/********************************************************************************
** Form generated from reading UI file 'blacklist_vehicle_page.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLACKLIST_VEHICLE_PAGE_H
#define UI_BLACKLIST_VEHICLE_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Blacklist_vehicle_page
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tableWidget_blacklist;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_vehicle_ocr_number;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_remarks;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_cancel_blacklist;
    QPushButton *pushButton_submit_blacklist;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *Blacklist_vehicle_page)
    {
        if (Blacklist_vehicle_page->objectName().isEmpty())
            Blacklist_vehicle_page->setObjectName(QString::fromUtf8("Blacklist_vehicle_page"));
        Blacklist_vehicle_page->resize(604, 300);
        gridLayout = new QGridLayout(Blacklist_vehicle_page);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableWidget_blacklist = new QTableWidget(Blacklist_vehicle_page);
        tableWidget_blacklist->setObjectName(QString::fromUtf8("tableWidget_blacklist"));
        tableWidget_blacklist->horizontalHeader()->setStretchLastSection(true);
        tableWidget_blacklist->verticalHeader()->setVisible(false);

        gridLayout->addWidget(tableWidget_blacklist, 0, 3, 2, 1);

        verticalSpacer = new QSpacerItem(20, 178, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Blacklist_vehicle_page);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_vehicle_ocr_number = new QLineEdit(Blacklist_vehicle_page);
        lineEdit_vehicle_ocr_number->setObjectName(QString::fromUtf8("lineEdit_vehicle_ocr_number"));

        horizontalLayout->addWidget(lineEdit_vehicle_ocr_number);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Blacklist_vehicle_page);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_remarks = new QLineEdit(Blacklist_vehicle_page);
        lineEdit_remarks->setObjectName(QString::fromUtf8("lineEdit_remarks"));

        horizontalLayout_2->addWidget(lineEdit_remarks);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_cancel_blacklist = new QPushButton(Blacklist_vehicle_page);
        pushButton_cancel_blacklist->setObjectName(QString::fromUtf8("pushButton_cancel_blacklist"));

        horizontalLayout_3->addWidget(pushButton_cancel_blacklist);

        pushButton_submit_blacklist = new QPushButton(Blacklist_vehicle_page);
        pushButton_submit_blacklist->setObjectName(QString::fromUtf8("pushButton_submit_blacklist"));

        horizontalLayout_3->addWidget(pushButton_submit_blacklist);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(21, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        retranslateUi(Blacklist_vehicle_page);

        QMetaObject::connectSlotsByName(Blacklist_vehicle_page);
    } // setupUi

    void retranslateUi(QWidget *Blacklist_vehicle_page)
    {
        Blacklist_vehicle_page->setWindowTitle(QApplication::translate("Blacklist_vehicle_page", "Form", nullptr));
        label->setText(QApplication::translate("Blacklist_vehicle_page", "Vehicle OCR Number   ", nullptr));
        label_2->setText(QApplication::translate("Blacklist_vehicle_page", "Remarks                           ", nullptr));
        pushButton_cancel_blacklist->setText(QApplication::translate("Blacklist_vehicle_page", "Cancel", nullptr));
        pushButton_submit_blacklist->setText(QApplication::translate("Blacklist_vehicle_page", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Blacklist_vehicle_page: public Ui_Blacklist_vehicle_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLACKLIST_VEHICLE_PAGE_H

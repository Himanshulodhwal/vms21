/********************************************************************************
** Form generated from reading UI file 'report_class.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORT_CLASS_H
#define UI_REPORT_CLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Report_class
{
public:
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDateEdit *dateEdit_start_date;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDateEdit *dateEdit_end_date;
    QComboBox *comboBox_server;
    QComboBox *comboBox_add_devices;
    QPushButton *pushButton_search;
    QSpacerItem *horizontalSpacer;
    QRadioButton *radioButton_csv;
    QRadioButton *radioButton_pdf;
    QPushButton *pushButton_export;
    QTableWidget *tableWidget_report;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_Prev;
    QPushButton *pushButton_Next;

    void setupUi(QWidget *Report_class)
    {
        if (Report_class->objectName().isEmpty())
            Report_class->setObjectName(QString::fromUtf8("Report_class"));
        Report_class->resize(946, 478);
        horizontalLayout_5 = new QHBoxLayout(Report_class);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Report_class);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        dateEdit_start_date = new QDateEdit(Report_class);
        dateEdit_start_date->setObjectName(QString::fromUtf8("dateEdit_start_date"));
        dateEdit_start_date->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit_start_date);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Report_class);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        dateEdit_end_date = new QDateEdit(Report_class);
        dateEdit_end_date->setObjectName(QString::fromUtf8("dateEdit_end_date"));
        dateEdit_end_date->setCalendarPopup(true);

        horizontalLayout_2->addWidget(dateEdit_end_date);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        comboBox_server = new QComboBox(Report_class);
        comboBox_server->setObjectName(QString::fromUtf8("comboBox_server"));

        horizontalLayout_3->addWidget(comboBox_server);

        comboBox_add_devices = new QComboBox(Report_class);
        comboBox_add_devices->setObjectName(QString::fromUtf8("comboBox_add_devices"));

        horizontalLayout_3->addWidget(comboBox_add_devices);

        pushButton_search = new QPushButton(Report_class);
        pushButton_search->setObjectName(QString::fromUtf8("pushButton_search"));

        horizontalLayout_3->addWidget(pushButton_search);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        radioButton_csv = new QRadioButton(Report_class);
        radioButton_csv->setObjectName(QString::fromUtf8("radioButton_csv"));

        horizontalLayout_3->addWidget(radioButton_csv);

        radioButton_pdf = new QRadioButton(Report_class);
        radioButton_pdf->setObjectName(QString::fromUtf8("radioButton_pdf"));

        horizontalLayout_3->addWidget(radioButton_pdf);

        pushButton_export = new QPushButton(Report_class);
        pushButton_export->setObjectName(QString::fromUtf8("pushButton_export"));

        horizontalLayout_3->addWidget(pushButton_export);


        verticalLayout->addLayout(horizontalLayout_3);

        tableWidget_report = new QTableWidget(Report_class);
        tableWidget_report->setObjectName(QString::fromUtf8("tableWidget_report"));
        tableWidget_report->horizontalHeader()->setStretchLastSection(true);
        tableWidget_report->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableWidget_report);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        pushButton_Prev = new QPushButton(Report_class);
        pushButton_Prev->setObjectName(QString::fromUtf8("pushButton_Prev"));

        horizontalLayout_4->addWidget(pushButton_Prev);

        pushButton_Next = new QPushButton(Report_class);
        pushButton_Next->setObjectName(QString::fromUtf8("pushButton_Next"));

        horizontalLayout_4->addWidget(pushButton_Next);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout);


        retranslateUi(Report_class);

        QMetaObject::connectSlotsByName(Report_class);
    } // setupUi

    void retranslateUi(QWidget *Report_class)
    {
        Report_class->setWindowTitle(QApplication::translate("Report_class", "Form", nullptr));
        label->setText(QApplication::translate("Report_class", "StartDate", nullptr));
        label_2->setText(QApplication::translate("Report_class", "EndDate", nullptr));
        pushButton_search->setText(QApplication::translate("Report_class", "Search", nullptr));
        radioButton_csv->setText(QApplication::translate("Report_class", "Eport to csv", nullptr));
        radioButton_pdf->setText(QApplication::translate("Report_class", "Export to pdf", nullptr));
        pushButton_export->setText(QApplication::translate("Report_class", "Export", nullptr));
        pushButton_Prev->setText(QApplication::translate("Report_class", "Prev", nullptr));
        pushButton_Next->setText(QApplication::translate("Report_class", "Next", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Report_class: public Ui_Report_class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORT_CLASS_H

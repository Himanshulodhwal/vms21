/********************************************************************************
** Form generated from reading UI file 'control_center.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROL_CENTER_H
#define UI_CONTROL_CENTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Control_center
{
public:
    QVBoxLayout *verticalLayout_6;
    QTabWidget *tabWidget;
    QWidget *tab_dashboard;
    QGridLayout *gridLayout_2;
    QPushButton *dashboard_refresh_btn;
    QGroupBox *groupBox_LPU;
    QGroupBox *groupBox_Camera_status;
    QGroupBox *groupBox_todays_stats;
    QGroupBox *groupBox_Total_vehicle;
    QGroupBox *groupBox_Statistics;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_LPU;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_16;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_LPU_count;
    QLabel *label_Camera_count;
    QLabel *label_Vehicle_type_count;
    QLabel *label_Vehicle_count_total;
    QLabel *label_Vehicle_count_todays;
    QGroupBox *groupBox_updates;
    QLabel *label_10;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLineEdit *sever_lineEdit_name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *server_lineEdit__description;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *server_pushButton_submit;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *server_pushButton_cancel;
    QSpacerItem *horizontalSpacer_5;
    QTableWidget *server_tableWidget;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_24;
    QHBoxLayout *horizontalLayout_23;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_6;
    QComboBox *add_device_comboBox;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *add_device_lineEdit_name;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *add_device_lineEdit_ip;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_10;
    QLineEdit *add_device_lineEdit_port;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *add_device_lineEdit_username;
    QSpacerItem *horizontalSpacer_15;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_11;
    QLineEdit *add_device_lineEdit_password;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_12;
    QLineEdit *lineEdit_RTSP_main_url;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer_27;
    QLineEdit *lineEdit_RTSP_sub_url;
    QHBoxLayout *horizontalLayout_22;
    QSpacerItem *horizontalSpacer_29;
    QPushButton *add_device_pushButton_submit;
    QSpacerItem *horizontalSpacer_28;
    QPushButton *add_device_pushButton_cancel;
    QSpacerItem *horizontalSpacer_30;
    QTableWidget *add_device_tableWidget;

    void setupUi(QWidget *Control_center)
    {
        if (Control_center->objectName().isEmpty())
            Control_center->setObjectName(QString::fromUtf8("Control_center"));
        Control_center->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Control_center->sizePolicy().hasHeightForWidth());
        Control_center->setSizePolicy(sizePolicy);
        Control_center->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_6 = new QVBoxLayout(Control_center);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(Control_center);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab_dashboard = new QWidget();
        tab_dashboard->setObjectName(QString::fromUtf8("tab_dashboard"));
        gridLayout_2 = new QGridLayout(tab_dashboard);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        dashboard_refresh_btn = new QPushButton(tab_dashboard);
        dashboard_refresh_btn->setObjectName(QString::fromUtf8("dashboard_refresh_btn"));
        dashboard_refresh_btn->setStyleSheet(QString::fromUtf8("QPushButton:hover {\n"
"        border: none;\n"
"        background-color: rgb(128,128,128);\n"
"        }"));

        gridLayout_2->addWidget(dashboard_refresh_btn, 0, 2, 1, 1);

        groupBox_LPU = new QGroupBox(tab_dashboard);
        groupBox_LPU->setObjectName(QString::fromUtf8("groupBox_LPU"));
        groupBox_LPU->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid #22a4bc;\n"
"    border-radius: 0px;\n"
"    padding-top: 10px;\n"
"    margin-top: 5px;\n"
"}\n"
"\n"
"QGroupBox:title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    margin-left: 3px;\n"
"    margin-right: 3px;\n"
"}"));

        gridLayout_2->addWidget(groupBox_LPU, 1, 1, 1, 1);

        groupBox_Camera_status = new QGroupBox(tab_dashboard);
        groupBox_Camera_status->setObjectName(QString::fromUtf8("groupBox_Camera_status"));
        groupBox_Camera_status->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid #22a4bc;\n"
"    border-radius: 0px;\n"
"    padding-top: 10px;\n"
"    margin-top: 5px;\n"
"}\n"
"\n"
"QGroupBox:title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    margin-left: 3px;\n"
"    margin-right: 3px;\n"
"}"));

        gridLayout_2->addWidget(groupBox_Camera_status, 2, 0, 2, 1);

        groupBox_todays_stats = new QGroupBox(tab_dashboard);
        groupBox_todays_stats->setObjectName(QString::fromUtf8("groupBox_todays_stats"));
        groupBox_todays_stats->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid #22a4bc;\n"
"    border-radius: 0px;\n"
"    padding-top: 10px;\n"
"    margin-top: 5px;\n"
"}\n"
"\n"
"QGroupBox:title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    margin-left: 3px;\n"
"    margin-right: 3px;\n"
"}"));

        gridLayout_2->addWidget(groupBox_todays_stats, 1, 0, 1, 1);

        groupBox_Total_vehicle = new QGroupBox(tab_dashboard);
        groupBox_Total_vehicle->setObjectName(QString::fromUtf8("groupBox_Total_vehicle"));
        groupBox_Total_vehicle->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid #22a4bc;\n"
"    border-radius: 0px;\n"
"    padding-top: 10px;\n"
"    margin-top: 5px;\n"
"}\n"
"\n"
"QGroupBox:title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    margin-left: 3px;\n"
"    margin-right: 3px;\n"
"}"));

        gridLayout_2->addWidget(groupBox_Total_vehicle, 2, 1, 1, 1);

        groupBox_Statistics = new QGroupBox(tab_dashboard);
        groupBox_Statistics->setObjectName(QString::fromUtf8("groupBox_Statistics"));
        groupBox_Statistics->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid #22a4bc;\n"
"    border-radius: 0px;\n"
"    padding-top: 10px;\n"
"    margin-top: 5px;\n"
"}\n"
"\n"
"QGroupBox:title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    margin-left: 3px;\n"
"    margin-right: 3px;\n"
"}"));
        layoutWidget = new QWidget(groupBox_Statistics);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 212, 113));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_LPU = new QLabel(layoutWidget);
        label_LPU->setObjectName(QString::fromUtf8("label_LPU"));

        verticalLayout_7->addWidget(label_LPU);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_7->addWidget(label_11);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_7->addWidget(label_12);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_7->addWidget(label_13);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_7->addWidget(label_14);


        horizontalLayout_13->addLayout(verticalLayout_7);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_16);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_LPU_count = new QLabel(layoutWidget);
        label_LPU_count->setObjectName(QString::fromUtf8("label_LPU_count"));

        verticalLayout_8->addWidget(label_LPU_count);

        label_Camera_count = new QLabel(layoutWidget);
        label_Camera_count->setObjectName(QString::fromUtf8("label_Camera_count"));

        verticalLayout_8->addWidget(label_Camera_count);

        label_Vehicle_type_count = new QLabel(layoutWidget);
        label_Vehicle_type_count->setObjectName(QString::fromUtf8("label_Vehicle_type_count"));

        verticalLayout_8->addWidget(label_Vehicle_type_count);

        label_Vehicle_count_total = new QLabel(layoutWidget);
        label_Vehicle_count_total->setObjectName(QString::fromUtf8("label_Vehicle_count_total"));

        verticalLayout_8->addWidget(label_Vehicle_count_total);

        label_Vehicle_count_todays = new QLabel(layoutWidget);
        label_Vehicle_count_todays->setObjectName(QString::fromUtf8("label_Vehicle_count_todays"));

        verticalLayout_8->addWidget(label_Vehicle_count_todays);


        horizontalLayout_13->addLayout(verticalLayout_8);


        gridLayout_2->addWidget(groupBox_Statistics, 3, 1, 1, 1);

        groupBox_updates = new QGroupBox(tab_dashboard);
        groupBox_updates->setObjectName(QString::fromUtf8("groupBox_updates"));
        groupBox_updates->setMinimumSize(QSize(255, 0));
        groupBox_updates->setMaximumSize(QSize(500, 16777215));
        groupBox_updates->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid #22a4bc;\n"
"    border-radius: 0px;\n"
"    padding-top: 10px;\n"
"    margin-top: 5px;\n"
"}\n"
"\n"
"QGroupBox:title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    margin-left: 3px;\n"
"    margin-right: 3px;\n"
"}"));
        label_10 = new QLabel(groupBox_updates);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(50, 210, 161, 41));

        gridLayout_2->addWidget(groupBox_updates, 1, 2, 3, 1);

        tabWidget->addTab(tab_dashboard, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout = new QVBoxLayout(tab_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 250));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_5 = new QHBoxLayout(groupBox);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        sever_lineEdit_name = new QLineEdit(groupBox);
        sever_lineEdit_name->setObjectName(QString::fromUtf8("sever_lineEdit_name"));

        horizontalLayout->addWidget(sever_lineEdit_name);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        server_lineEdit__description = new QLineEdit(groupBox);
        server_lineEdit__description->setObjectName(QString::fromUtf8("server_lineEdit__description"));

        horizontalLayout_2->addWidget(server_lineEdit__description);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        server_pushButton_submit = new QPushButton(groupBox);
        server_pushButton_submit->setObjectName(QString::fromUtf8("server_pushButton_submit"));
        server_pushButton_submit->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(server_pushButton_submit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        server_pushButton_cancel = new QPushButton(groupBox);
        server_pushButton_cancel->setObjectName(QString::fromUtf8("server_pushButton_cancel"));

        horizontalLayout_3->addWidget(server_pushButton_cancel);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        server_tableWidget = new QTableWidget(groupBox);
        if (server_tableWidget->columnCount() < 3)
            server_tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        server_tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        server_tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        server_tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        server_tableWidget->setObjectName(QString::fromUtf8("server_tableWidget"));
        server_tableWidget->setStyleSheet(QString::fromUtf8(""));
        server_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        server_tableWidget->setTabKeyNavigation(false);
        server_tableWidget->setProperty("showDropIndicator", QVariant(false));
        server_tableWidget->setDragDropOverwriteMode(false);
        server_tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        server_tableWidget->setShowGrid(false);
        server_tableWidget->horizontalHeader()->setDefaultSectionSize(100);
        server_tableWidget->verticalHeader()->setVisible(false);

        horizontalLayout_4->addWidget(server_tableWidget);


        horizontalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_24 = new QHBoxLayout(groupBox_2);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_6->addWidget(label_3);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        add_device_comboBox = new QComboBox(groupBox_2);
        add_device_comboBox->setObjectName(QString::fromUtf8("add_device_comboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(add_device_comboBox->sizePolicy().hasHeightForWidth());
        add_device_comboBox->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(add_device_comboBox);


        gridLayout->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_13, 0, 1, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_9->addWidget(label_6);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);

        add_device_lineEdit_name = new QLineEdit(groupBox_2);
        add_device_lineEdit_name->setObjectName(QString::fromUtf8("add_device_lineEdit_name"));

        horizontalLayout_9->addWidget(add_device_lineEdit_name);


        gridLayout->addLayout(horizontalLayout_9, 0, 2, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_7->addWidget(label_4);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        add_device_lineEdit_ip = new QLineEdit(groupBox_2);
        add_device_lineEdit_ip->setObjectName(QString::fromUtf8("add_device_lineEdit_ip"));

        horizontalLayout_7->addWidget(add_device_lineEdit_ip);


        gridLayout->addLayout(horizontalLayout_7, 1, 0, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_14, 1, 1, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_10->addWidget(label_7);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_10);

        add_device_lineEdit_port = new QLineEdit(groupBox_2);
        add_device_lineEdit_port->setObjectName(QString::fromUtf8("add_device_lineEdit_port"));

        horizontalLayout_10->addWidget(add_device_lineEdit_port);


        gridLayout->addLayout(horizontalLayout_10, 1, 2, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_8->addWidget(label_5);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        add_device_lineEdit_username = new QLineEdit(groupBox_2);
        add_device_lineEdit_username->setObjectName(QString::fromUtf8("add_device_lineEdit_username"));

        horizontalLayout_8->addWidget(add_device_lineEdit_username);


        gridLayout->addLayout(horizontalLayout_8, 2, 0, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_15, 2, 1, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_11->addWidget(label_8);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_11);

        add_device_lineEdit_password = new QLineEdit(groupBox_2);
        add_device_lineEdit_password->setObjectName(QString::fromUtf8("add_device_lineEdit_password"));

        horizontalLayout_11->addWidget(add_device_lineEdit_password);


        gridLayout->addLayout(horizontalLayout_11, 2, 2, 1, 1);


        verticalLayout_5->addLayout(gridLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_12->addWidget(label_9);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_12);

        lineEdit_RTSP_main_url = new QLineEdit(groupBox_2);
        lineEdit_RTSP_main_url->setObjectName(QString::fromUtf8("lineEdit_RTSP_main_url"));

        horizontalLayout_12->addWidget(lineEdit_RTSP_main_url);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_21->addWidget(label_18);

        horizontalSpacer_27 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_27);

        lineEdit_RTSP_sub_url = new QLineEdit(groupBox_2);
        lineEdit_RTSP_sub_url->setObjectName(QString::fromUtf8("lineEdit_RTSP_sub_url"));

        horizontalLayout_21->addWidget(lineEdit_RTSP_sub_url);


        verticalLayout_3->addLayout(horizontalLayout_21);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        horizontalSpacer_29 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_29);

        add_device_pushButton_submit = new QPushButton(groupBox_2);
        add_device_pushButton_submit->setObjectName(QString::fromUtf8("add_device_pushButton_submit"));

        horizontalLayout_22->addWidget(add_device_pushButton_submit);

        horizontalSpacer_28 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_28);

        add_device_pushButton_cancel = new QPushButton(groupBox_2);
        add_device_pushButton_cancel->setObjectName(QString::fromUtf8("add_device_pushButton_cancel"));

        horizontalLayout_22->addWidget(add_device_pushButton_cancel);


        verticalLayout_4->addLayout(horizontalLayout_22);


        verticalLayout_5->addLayout(verticalLayout_4);


        horizontalLayout_23->addLayout(verticalLayout_5);

        horizontalSpacer_30 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_30);

        add_device_tableWidget = new QTableWidget(groupBox_2);
        if (add_device_tableWidget->columnCount() < 4)
            add_device_tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        add_device_tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        add_device_tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        add_device_tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        add_device_tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem6);
        add_device_tableWidget->setObjectName(QString::fromUtf8("add_device_tableWidget"));
        add_device_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        add_device_tableWidget->setTabKeyNavigation(false);
        add_device_tableWidget->setProperty("showDropIndicator", QVariant(false));
        add_device_tableWidget->setDragDropOverwriteMode(false);
        add_device_tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        add_device_tableWidget->setShowGrid(false);
        add_device_tableWidget->verticalHeader()->setVisible(false);

        horizontalLayout_23->addWidget(add_device_tableWidget);


        horizontalLayout_24->addLayout(horizontalLayout_23);


        verticalLayout->addWidget(groupBox_2);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_6->addWidget(tabWidget);


        retranslateUi(Control_center);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Control_center);
    } // setupUi

    void retranslateUi(QWidget *Control_center)
    {
        Control_center->setWindowTitle(QApplication::translate("Control_center", "Form", nullptr));
        dashboard_refresh_btn->setText(QApplication::translate("Control_center", "Refresh", nullptr));
        groupBox_LPU->setTitle(QApplication::translate("Control_center", "LPU", nullptr));
        groupBox_Camera_status->setTitle(QApplication::translate("Control_center", "Camera Status", nullptr));
        groupBox_todays_stats->setTitle(QApplication::translate("Control_center", "Todays stats", nullptr));
        groupBox_Total_vehicle->setTitle(QApplication::translate("Control_center", "Total Vehicles", nullptr));
        groupBox_Statistics->setTitle(QApplication::translate("Control_center", "Statistics", nullptr));
        label_LPU->setText(QApplication::translate("Control_center", "LPU", nullptr));
        label_11->setText(QApplication::translate("Control_center", "Camera", nullptr));
        label_12->setText(QApplication::translate("Control_center", "Vehicle Types", nullptr));
        label_13->setText(QApplication::translate("Control_center", "Vehicle Count Total", nullptr));
        label_14->setText(QApplication::translate("Control_center", "Vehicle Count Todays", nullptr));
        label_LPU_count->setText(QApplication::translate("Control_center", "0", nullptr));
        label_Camera_count->setText(QApplication::translate("Control_center", "0", nullptr));
        label_Vehicle_type_count->setText(QApplication::translate("Control_center", "0", nullptr));
        label_Vehicle_count_total->setText(QApplication::translate("Control_center", "0", nullptr));
        label_Vehicle_count_todays->setText(QApplication::translate("Control_center", "0", nullptr));
        groupBox_updates->setTitle(QApplication::translate("Control_center", "Updates", nullptr));
        label_10->setText(QApplication::translate("Control_center", "Blacklisted Vehicles", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_dashboard), QApplication::translate("Control_center", "Dashboard", nullptr));
        groupBox->setTitle(QApplication::translate("Control_center", "ADD SERVER", nullptr));
        label->setText(QApplication::translate("Control_center", "Name :          ", nullptr));
        sever_lineEdit_name->setText(QString());
        label_2->setText(QApplication::translate("Control_center", "Description :", nullptr));
        server_pushButton_submit->setText(QApplication::translate("Control_center", "Submit", nullptr));
        server_pushButton_cancel->setText(QApplication::translate("Control_center", "Cancel", nullptr));
        QTableWidgetItem *___qtablewidgetitem = server_tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Control_center", "LPU Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = server_tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Control_center", "Action", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = server_tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Control_center", "id", nullptr));
        groupBox_2->setTitle(QApplication::translate("Control_center", "ADD DEVICE", nullptr));
        label_3->setText(QApplication::translate("Control_center", "Server :                 ", nullptr));
        label_6->setText(QApplication::translate("Control_center", "Name :          ", nullptr));
        label_4->setText(QApplication::translate("Control_center", "IP/Cloud ID :        ", nullptr));
        label_7->setText(QApplication::translate("Control_center", "Port :          ", nullptr));
        label_5->setText(QApplication::translate("Control_center", "User Name :        ", nullptr));
        label_8->setText(QApplication::translate("Control_center", "Password :          ", nullptr));
        label_9->setText(QApplication::translate("Control_center", "RTSP Main url :           ", nullptr));
        label_18->setText(QApplication::translate("Control_center", "RTSP Sub Url :            ", nullptr));
        add_device_pushButton_submit->setText(QApplication::translate("Control_center", "Submit", nullptr));
        add_device_pushButton_cancel->setText(QApplication::translate("Control_center", "Cancel", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = add_device_tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("Control_center", "Server", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = add_device_tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("Control_center", "Device", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = add_device_tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("Control_center", "Action", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = add_device_tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("Control_center", "id", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Control_center", "AddDevices", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Control_center: public Ui_Control_center {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROL_CENTER_H

/********************************************************************************
** Form generated from reading UI file 'carddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDDIALOG_H
#define UI_CARDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CardDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_plate_image_path;
    QLabel *label_vehicle_image_path;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *label_camename;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *label_datetime;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *label_vehicle_class;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLabel *label_ocr_number;

    void setupUi(QDialog *CardDialog)
    {
        if (CardDialog->objectName().isEmpty())
            CardDialog->setObjectName(QString::fromUtf8("CardDialog"));
        CardDialog->resize(581, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CardDialog->sizePolicy().hasHeightForWidth());
        CardDialog->setSizePolicy(sizePolicy);
        CardDialog->setMinimumSize(QSize(581, 300));
        CardDialog->setMaximumSize(QSize(581, 300));
        layoutWidget = new QWidget(CardDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 211, 281));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_plate_image_path = new QLabel(layoutWidget);
        label_plate_image_path->setObjectName(QString::fromUtf8("label_plate_image_path"));
        label_plate_image_path->setScaledContents(true);

        verticalLayout_2->addWidget(label_plate_image_path);

        label_vehicle_image_path = new QLabel(layoutWidget);
        label_vehicle_image_path->setObjectName(QString::fromUtf8("label_vehicle_image_path"));
        label_vehicle_image_path->setScaledContents(true);

        verticalLayout_2->addWidget(label_vehicle_image_path);

        layoutWidget1 = new QWidget(CardDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(220, 10, 351, 141));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 80));

        horizontalLayout->addWidget(label_2);

        label_camename = new QLabel(layoutWidget1);
        label_camename->setObjectName(QString::fromUtf8("label_camename"));

        horizontalLayout->addWidget(label_camename);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        label_datetime = new QLabel(layoutWidget1);
        label_datetime->setObjectName(QString::fromUtf8("label_datetime"));

        horizontalLayout_2->addWidget(label_datetime);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        label_vehicle_class = new QLabel(layoutWidget1);
        label_vehicle_class->setObjectName(QString::fromUtf8("label_vehicle_class"));

        horizontalLayout_3->addWidget(label_vehicle_class);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        label_ocr_number = new QLabel(layoutWidget1);
        label_ocr_number->setObjectName(QString::fromUtf8("label_ocr_number"));

        horizontalLayout_4->addWidget(label_ocr_number);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(CardDialog);

        QMetaObject::connectSlotsByName(CardDialog);
    } // setupUi

    void retranslateUi(QDialog *CardDialog)
    {
        CardDialog->setWindowTitle(QApplication::translate("CardDialog", "Dialog", nullptr));
        label_plate_image_path->setText(QApplication::translate("CardDialog", "TextLabel", nullptr));
        label_vehicle_image_path->setText(QApplication::translate("CardDialog", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("CardDialog", "  CamName :", nullptr));
        label_camename->setText(QApplication::translate("CardDialog", "value", nullptr));
        label_3->setText(QApplication::translate("CardDialog", "  Date :", nullptr));
        label_datetime->setText(QApplication::translate("CardDialog", "value", nullptr));
        label_4->setText(QApplication::translate("CardDialog", "  VehicleClass:", nullptr));
        label_vehicle_class->setText(QApplication::translate("CardDialog", "value", nullptr));
        label_5->setText(QApplication::translate("CardDialog", "  OCR :", nullptr));
        label_ocr_number->setText(QApplication::translate("CardDialog", "value", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CardDialog: public Ui_CardDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDDIALOG_H

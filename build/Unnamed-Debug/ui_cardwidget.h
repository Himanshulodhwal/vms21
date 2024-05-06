/********************************************************************************
** Form generated from reading UI file 'cardwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDWIDGET_H
#define UI_CARDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cardwidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_plate_image_path;
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

    void setupUi(QWidget *Cardwidget)
    {
        if (Cardwidget->objectName().isEmpty())
            Cardwidget->setObjectName(QString::fromUtf8("Cardwidget"));
        Cardwidget->resize(285, 150);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Cardwidget->sizePolicy().hasHeightForWidth());
        Cardwidget->setSizePolicy(sizePolicy);
        Cardwidget->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_2 = new QVBoxLayout(Cardwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_plate_image_path = new QLabel(Cardwidget);
        label_plate_image_path->setObjectName(QString::fromUtf8("label_plate_image_path"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_plate_image_path->sizePolicy().hasHeightForWidth());
        label_plate_image_path->setSizePolicy(sizePolicy1);
        label_plate_image_path->setScaledContents(true);

        horizontalLayout_5->addWidget(label_plate_image_path);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(Cardwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(9);
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        label_camename = new QLabel(Cardwidget);
        label_camename->setObjectName(QString::fromUtf8("label_camename"));
        label_camename->setFont(font);

        horizontalLayout->addWidget(label_camename);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(Cardwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_2->addWidget(label_3);

        label_datetime = new QLabel(Cardwidget);
        label_datetime->setObjectName(QString::fromUtf8("label_datetime"));
        label_datetime->setFont(font);

        horizontalLayout_2->addWidget(label_datetime);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(Cardwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_3->addWidget(label_4);

        label_vehicle_class = new QLabel(Cardwidget);
        label_vehicle_class->setObjectName(QString::fromUtf8("label_vehicle_class"));
        label_vehicle_class->setFont(font);

        horizontalLayout_3->addWidget(label_vehicle_class);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(Cardwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_4->addWidget(label_5);

        label_ocr_number = new QLabel(Cardwidget);
        label_ocr_number->setObjectName(QString::fromUtf8("label_ocr_number"));
        label_ocr_number->setFont(font);

        horizontalLayout_4->addWidget(label_ocr_number);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_5);


        retranslateUi(Cardwidget);

        QMetaObject::connectSlotsByName(Cardwidget);
    } // setupUi

    void retranslateUi(QWidget *Cardwidget)
    {
        Cardwidget->setWindowTitle(QApplication::translate("Cardwidget", "Form", nullptr));
        label_plate_image_path->setText(QString());
        label_2->setText(QApplication::translate("Cardwidget", "   CamName :", nullptr));
        label_camename->setText(QApplication::translate("Cardwidget", "value", nullptr));
        label_3->setText(QApplication::translate("Cardwidget", "   Date :", nullptr));
        label_datetime->setText(QApplication::translate("Cardwidget", "value", nullptr));
        label_4->setText(QApplication::translate("Cardwidget", "   VehicleClass:", nullptr));
        label_vehicle_class->setText(QApplication::translate("Cardwidget", "value", nullptr));
        label_5->setText(QApplication::translate("Cardwidget", "   OCR :", nullptr));
        label_ocr_number->setText(QApplication::translate("Cardwidget", "value", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Cardwidget: public Ui_Cardwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDWIDGET_H

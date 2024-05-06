/********************************************************************************
** Form generated from reading UI file 'overlay_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OVERLAY_WIDGET_H
#define UI_OVERLAY_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Overlay_Widget
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QLabel *label;

    void setupUi(QWidget *Overlay_Widget)
    {
        if (Overlay_Widget->objectName().isEmpty())
            Overlay_Widget->setObjectName(QString::fromUtf8("Overlay_Widget"));
        Overlay_Widget->resize(639, 82);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Overlay_Widget->sizePolicy().hasHeightForWidth());
        Overlay_Widget->setSizePolicy(sizePolicy);
        Overlay_Widget->setWindowOpacity(0.500000000000000);
        gridLayout = new QGridLayout(Overlay_Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(Overlay_Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("background-color:transparent"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 10, 301, 41));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(Overlay_Widget);

        QMetaObject::connectSlotsByName(Overlay_Widget);
    } // setupUi

    void retranslateUi(QWidget *Overlay_Widget)
    {
        Overlay_Widget->setWindowTitle(QApplication::translate("Overlay_Widget", "Form", nullptr));
        label->setText(QApplication::translate("Overlay_Widget", "OVERLAY WIDGET", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Overlay_Widget: public Ui_Overlay_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OVERLAY_WIDGET_H

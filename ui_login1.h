/********************************************************************************
** Form generated from reading UI file 'login1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN1_H
#define UI_LOGIN1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_login1
{
public:
    QPushButton *pushButton;
    QLabel *backgroundLabel;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEditName;
    QLineEdit *lineEditPassword;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;

    void setupUi(QDialog *login1)
    {
        if (login1->objectName().isEmpty())
            login1->setObjectName(QString::fromUtf8("login1"));
        login1->resize(824, 615);
        pushButton = new QPushButton(login1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(360, 364, 121, 51));
        QFont font;
        font.setPointSize(15);
        pushButton->setFont(font);
        backgroundLabel = new QLabel(login1);
        backgroundLabel->setObjectName(QString::fromUtf8("backgroundLabel"));
        backgroundLabel->setGeometry(QRect(480, 10, 411, 621));
        backgroundLabel->setAutoFillBackground(true);
        label = new QLabel(login1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(310, 160, 121, 31));
        QFont font1;
        font1.setPointSize(19);
        label->setFont(font1);
        label->setAutoFillBackground(false);
        label_2 = new QLabel(login1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(310, 250, 191, 31));
        label_2->setFont(font1);
        label_2->setAutoFillBackground(false);
        lineEditName = new QLineEdit(login1);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        lineEditName->setGeometry(QRect(300, 200, 131, 25));
        lineEditPassword = new QLineEdit(login1);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        lineEditPassword->setGeometry(QRect(300, 280, 141, 25));
        checkBox = new QCheckBox(login1);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(510, 280, 21, 27));
        checkBox_2 = new QCheckBox(login1);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(420, 320, 139, 23));
        QFont font2;
        font2.setPointSize(8);
        checkBox_2->setFont(font2);

        retranslateUi(login1);

        QMetaObject::connectSlotsByName(login1);
    } // setupUi

    void retranslateUi(QDialog *login1)
    {
        login1->setWindowTitle(QApplication::translate("login1", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("login1", "Submit", nullptr));
        backgroundLabel->setText(QString());
        label->setText(QApplication::translate("login1", "NAME :", nullptr));
        label_2->setText(QApplication::translate("login1", "PASSWORD:", nullptr));
        checkBox->setText(QApplication::translate("login1", "CheckBox", nullptr));
        checkBox_2->setText(QApplication::translate("login1", "REMBEMBER ME", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login1: public Ui_login1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN1_H

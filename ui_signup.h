/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Signup
{
public:
    QLabel *backgroundLabel;
    QLineEdit *lineEditName;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *backgroundLabel_3;
    QLineEdit *lineEditEmail;
    QLineEdit *lineEditPassword;
    QLabel *label_5;
    QPushButton *pushButton;
    QCheckBox *checkBox;

    void setupUi(QDialog *Signup)
    {
        if (Signup->objectName().isEmpty())
            Signup->setObjectName(QString::fromUtf8("Signup"));
        Signup->resize(856, 495);
        backgroundLabel = new QLabel(Signup);
        backgroundLabel->setObjectName(QString::fromUtf8("backgroundLabel"));
        backgroundLabel->setGeometry(QRect(780, 340, 281, 151));
        lineEditName = new QLineEdit(Signup);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        lineEditName->setGeometry(QRect(330, 160, 181, 41));
        label_3 = new QLabel(Signup);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(330, 290, 191, 31));
        QFont font;
        font.setPointSize(19);
        label_3->setFont(font);
        label_3->setAutoFillBackground(false);
        label_4 = new QLabel(Signup);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(340, 120, 121, 31));
        label_4->setFont(font);
        label_4->setAutoFillBackground(false);
        backgroundLabel_3 = new QLabel(Signup);
        backgroundLabel_3->setObjectName(QString::fromUtf8("backgroundLabel_3"));
        backgroundLabel_3->setGeometry(QRect(850, -30, 31, 621));
        backgroundLabel_3->setAutoFillBackground(true);
        lineEditEmail = new QLineEdit(Signup);
        lineEditEmail->setObjectName(QString::fromUtf8("lineEditEmail"));
        lineEditEmail->setGeometry(QRect(330, 240, 181, 41));
        lineEditPassword = new QLineEdit(Signup);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        lineEditPassword->setGeometry(QRect(330, 330, 181, 41));
        label_5 = new QLabel(Signup);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(340, 200, 191, 31));
        label_5->setFont(font);
        label_5->setAutoFillBackground(false);
        pushButton = new QPushButton(Signup);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(440, 420, 121, 51));
        QFont font1;
        font1.setPointSize(15);
        pushButton->setFont(font1);
        checkBox = new QCheckBox(Signup);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(490, 300, 21, 23));

        retranslateUi(Signup);

        QMetaObject::connectSlotsByName(Signup);
    } // setupUi

    void retranslateUi(QDialog *Signup)
    {
        Signup->setWindowTitle(QApplication::translate("Signup", "Dialog", nullptr));
        backgroundLabel->setText(QString());
        label_3->setText(QApplication::translate("Signup", "PASSWORD:", nullptr));
        label_4->setText(QApplication::translate("Signup", "NAME :", nullptr));
        backgroundLabel_3->setText(QString());
        label_5->setText(QApplication::translate("Signup", "E-MAIL:", nullptr));
        pushButton->setText(QApplication::translate("Signup", "Submit", nullptr));
        checkBox->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Signup: public Ui_Signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H

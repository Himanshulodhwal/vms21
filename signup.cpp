#include "signup.h"
#include "ui_signup.h"
#include "mainwindow.h"
#include"database.h"
#include"login1.h"
Signup::Signup(QWidget *parent) : QDialog(parent), ui(new Ui::Signup) {
    ui->setupUi(this);
    setWindowTitle("Sparsh");
    setWindowIcon(QIcon(":/new/prefix1/Sparsh-Logo1.png"));
    database = new Database();
    QPixmap backgroundImage(":/Signup.png");
    ui->backgroundLabel->setPixmap(backgroundImage);
    ui->backgroundLabel->setScaledContents(true);
    ui->backgroundLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->backgroundLabel->setGeometry(0, 0, this->width(), this->height());
    ui->backgroundLabel->lower();
    ui->lineEditPassword->setEchoMode(QLineEdit::Password);
    ui->lineEditName->setPlaceholderText("Enter Name");
    ui->lineEditEmail->setPlaceholderText("Enter Email");
    ui->lineEditPassword->setPlaceholderText("Enter Password");
    ui->lineEditName->clear();
    ui->lineEditPassword->clear();
    ui->lineEditEmail->clear();
}
Signup::~Signup() {
    delete ui;
    delete database;
}

void Signup::on_checkBox_stateChanged(int state) {
    if (state == Qt::Checked) {
        ui->lineEditPassword->setEchoMode(QLineEdit::Normal);
    } else {
        ui->lineEditPassword->setEchoMode(QLineEdit::Password);
    }
}

void Signup::clearFields() {
    ui->lineEditName->clear();
    ui->lineEditPassword->clear();
    ui->lineEditEmail->clear();
}

void Signup::clearSignupFields() {
    clearFields();
}

void Signup::on_pushButton_clicked()
{/*
    // Modify the call to addUser to provide the required number of arguments
    std::string name = ui->lineEditName->text().toStdString();
    std::string password = ui->lineEditPassword->text().toStdString();
    std::string email = ui->lineEditEmail->text().toStdString();

    if (!name.empty() && !password.empty() && !email.empty()) {
        if (database->addUser(name, password, email)) { // Pass all required arguments
            qDebug() << "User added successfully!";
            // Handle successful signup
        } else {
            qDebug() << "Failed to add user!";
            // Handle signup failure
        }
    } else {
        // Handle case where fields are empty
    }*/
}

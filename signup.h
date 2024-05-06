// signup.h
#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include "database.h"
namespace Ui {
class Signup;
}

class Signup : public QDialog {
    Q_OBJECT

public:
    explicit Signup(QWidget *parent = nullptr);
    ~Signup();
void clearFields();
    void clearSignupFields();

private slots:
    void on_checkBox_stateChanged(int state);
    void on_pushButton_clicked();

private:
    Ui::Signup *ui;
    Database *database; // Declare Database object

};

#endif // SIGNUP_H

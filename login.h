#ifndef LOGIN_H
#define LOGIN_H
#include <QDialog>
// Include the generated UI header file
#include "ui_login1.h"  // Ensure this file name matches your actual generated file name

namespace Ui {
class Login; // Forward declaration
}

class Login : public QDialog {
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private:
    Ui::Login *ui; // Pointer to the UI class
};

#endif // LOGIN_H

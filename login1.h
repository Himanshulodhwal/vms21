#ifndef LOGIN1_H
#define LOGIN1_H

#include <QDialog>
#include <QTimer>
#include <QMessageBox>
// #include "mainwindow.h"
#include "control_center.h"

namespace Ui {
class login1;
}

class login1 : public QDialog
{
    Q_OBJECT

public:
    explicit login1(QWidget *parent = nullptr);
    ~login1();

private slots:
    void on_pushButton_clicked();
    void on_checkBox_stateChanged(int arg1);
    void on_checkBox_2_stateChanged(int arg1);
    void hideMessageBox();

private:
    Ui::login1 *ui;
    QTimer *messageBoxTimer;
    void saveCredentials();
    void clearCredentials();
    QMessageBox *messageBox;
    // MainWindow* mainWindow ;
    Control_center *control_center_obj;


};

#endif // LOGIN1_H

#ifndef CARDDIALOG_H
#define CARDDIALOG_H

#include <QDialog>

namespace Ui {
class CardDialog;
}

class CardDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CardDialog(QString camname,QString plateimgpath, QString vehicleimgpath,QString ocrnumber,QString datetime,QString vehicle_class,QWidget *parent = nullptr);
    ~CardDialog();

private:
    Ui::CardDialog *ui;
};

#endif // CARDDIALOG_H

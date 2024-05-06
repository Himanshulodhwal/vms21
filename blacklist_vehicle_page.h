#ifndef BLACKLIST_VEHICLE_PAGE_H
#define BLACKLIST_VEHICLE_PAGE_H

#include <QWidget>
#include "sql_helper.h"
namespace Ui {
class Blacklist_vehicle_page;
}

class Blacklist_vehicle_page : public QWidget
{
    Q_OBJECT

public:
    explicit Blacklist_vehicle_page(QWidget *parent = nullptr);
    ~Blacklist_vehicle_page();

private slots:
    void on_pushButton_submit_blacklist_clicked();

    void on_pushButton_cancel_blacklist_clicked();

private:
    Ui::Blacklist_vehicle_page *ui;
    sql_helper& sql_help = sql_helper::getInstance();
    sql_helper::tblVehicle_blacklist Vehicle_blacklist_obj;

    void set_tblvehicle_blacklist_data_to_tablewidget_blacklist(bool str);
    void vehicle_blacklist_trash_btn_clicked();
    void vehicle_blacklist_delete_btn_clicked(int index);
};

#endif // BLACKLIST_VEHICLE_PAGE_H

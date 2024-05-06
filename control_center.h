#ifndef CONTROL_CENTER_H
#define CONTROL_CENTER_H

#include <QWidget>
#include "sql_helper.h"
#include "QMessageBox"
#include "QTableWidgetItem"

#include <VLCQtCore/Common.h>
#include <VLCQtWidgets/WidgetVideo.h>
#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>
#include "QGridLayout"
#include <QMouseEvent>
#include "DraggableButton.h"
#include<mainwindow.h>
#include<QMainWindow>
#include <report_class.h>
#include <blacklist_vehicle_page.h>
#include <handel_thread.h>

class DraggableButton;

namespace Ui {
class Control_center;
}

class Control_center : public QWidget
{
    Q_OBJECT

public:
    explicit Control_center(QWidget *parent = nullptr);
    ~Control_center();

    void set_db_value_to_server_tablewidget();
    void set_db_value_to_add_devices_tablewidget();

private slots:
    void on_server_pushButton_submit_clicked();
    void on_server_pushButton_cancel_clicked();
    void server_trash_btn_clicked();
    void server_delete_btn_clicked(int server_name);
    void update_server_lineedit_name();
    void set_server_list_value_to_tablewidget(int id);
    void on_add_device_pushButton_submit_clicked();
    void on_add_device_pushButton_cancel_clicked();
    void add_devices_trash_btn_clicked();
    void add_devices_delete_btn_clicked(int server_name);
    void update_add_devices_lineedit_name();
    void insertItem(QString cmd);
    void updateItem(QString cmd);
    void handleItemSelectionChanged();
    void insertDataToTable();
    void add_device_handleItemSelectionChanged();
    void add_device_insertDataToTable();
    void set_add_device_list_value_to_tablewidget(int id);
    void on_dashboard_refresh_btn_clicked();
    // void create_groupbox_listwidget();

protected:
private:
    Ui::Control_center *ui;
    sql_helper& sql_help = sql_helper::getInstance();

    // sql_helper sql_help;
     sql_helper::server obj;
     sql_helper::add_devices device_obj;
     sql_helper::tblVehicle_blacklist balcklist_vehicle_obj;

     MainWindow *main_window_obj;
     void create_dashboard();
     QListWidget *listwidget;
     QVBoxLayout *VLayout_to_listwidget;
    void create_groupbox_listwidget();
     Cardwidget *cardWidget;
    QThread *groupbox_update_thread;
     QThread *update_groupbox_from_db;
    Handel_Thread *handel_thread_groupbox_update;
    Handel_Thread *update_groupbox_db_thread;
    QTimer *timer ;
};

#endif // CONTROL_CENTER_H

#include "control_center.h"
#include "ui_control_center.h"
#include "QDebug"
#include <QDesktopWidget>
#include <QMessageBox>
#include <QGridLayout>
#include <QDockWidget>
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include <VLCQtCore/Common.h>
#include <VLCQtCore/Media.h>
#include <VLCQtWidgets/WidgetVideo.h>
#include <VLCQtCore/MediaPlayer.h>
#include <VLCQtCore/Error.h>
#include <QLabel>
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>
// #include "DraggableButton.h"
#include <QMessageBox>
#include <QEventLoop>
#include <QRegularExpression>
#include <QThread>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QScreen>
#include <QWindow>
#include <QFileDialog>
#include <QDir>
#include <QLabel>
#include <QDialog>
#include <QVBoxLayout>
#include <QDialog>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QScreen>
#include <QGuiApplication>
#include <QWindow>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QStatusBar>
#include <QMenu>
#include <QVideoWidget>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QPieSlice>
#include <QSequentialAnimationGroup>
#include <QtConcurrent>
#include <QFuture>
Control_center::Control_center(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::Control_center)
{
    ui->setupUi(this);
    // sql_helper& helper = sql_helper::getInstance();

    //code for add device
    // Connect item selection signal to slot
    connect(ui->server_tableWidget, &QTableWidget::itemSelectionChanged, this, &Control_center::handleItemSelectionChanged);
    // Connect button click signal to slot
    connect(ui->server_pushButton_submit, &QPushButton::clicked, this, &Control_center::insertDataToTable);
    // Connect item selection signal to slot
    connect(ui->add_device_tableWidget, &QTableWidget::itemSelectionChanged, this, &Control_center::add_device_handleItemSelectionChanged);
    // Connect button click signal to slot
    connect(ui->add_device_pushButton_submit, &QPushButton::clicked, this, &Control_center::add_device_insertDataToTable);
    set_db_value_to_server_tablewidget();
    set_db_value_to_add_devices_tablewidget();
    //code for add device

    // //Dashboard codes
    // ui->groupBox_Total_vehicle->setMinimumHeight(ui->groupBox_Statistics->height());
    // ui->groupBox_Statistics->setMinimumHeight(ui->groupBox_Total_vehicle->height());
    // ui->groupBox_Camera_status->setMinimumHeight(ui->groupBox_todays_stats->height()+10);
    // ui->groupBox_todays_stats->setMinimumHeight(ui->groupBox_Camera_status->height());
    // ui->groupBox_todays_stats->setMinimumWidth(ui->groupBox_LPU->width());
    // ui->groupBox_LPU->setMinimumWidth(ui->groupBox_todays_stats->width());
    // create_dashboard();
    // //Dashboard codes

    //LiveView tab
    main_window_obj =new MainWindow();
    ui->tabWidget->addTab(main_window_obj,QString("Liveview"));
    // ui->tabWidget->addTab(new MainWindow,QString("Liveview"));
    //LiveView tab
    //reporting tab
    ui->tabWidget->addTab(new Report_class,QString("Reporting"));
    //reporting tab
    //Blacklist tab
    ui->tabWidget->addTab(new Blacklist_vehicle_page,QString("Blacklist Vehicle"));
    //Blacklist tab

    //Dashboard codes
    ui->groupBox_Total_vehicle->setMinimumHeight(ui->groupBox_Statistics->height());
    ui->groupBox_Statistics->setMinimumHeight(ui->groupBox_Total_vehicle->height());
    ui->groupBox_Camera_status->setMinimumHeight(ui->groupBox_todays_stats->height()+10);
    ui->groupBox_todays_stats->setMinimumHeight(ui->groupBox_Camera_status->height());
    ui->groupBox_todays_stats->setMinimumWidth(ui->groupBox_LPU->width());
    ui->groupBox_LPU->setMinimumWidth(ui->groupBox_todays_stats->width());
    groupbox_update_thread = new QThread();
    handel_thread_groupbox_update = new Handel_Thread(2000);

    // update_groupbox_db_thread = new Handel_Thread(3000);
    // update_groupbox_from_db = new QThread();
    // update_groupbox_db_thread->moveToThread(update_groupbox_from_db);
    // // Connect the timeout signal of update_groupbox_db_thread to the select_blacklist_vehicle slot of sql_help
    // connect(update_groupbox_db_thread, &Handel_Thread::timeout, &sql_help, &sql_helper::select_blacklist_vehicle);

    // // connect(update_groupbox_db_thread,SIGNAL(timeout()),&sql_help,SLOT(select_blacklist_vehicle()));
    // // // Start the thread
    // update_groupbox_from_db->start();
    // // // connect(update_groupbox_db_thread, &Handel_Thread::timeout, sql_help, &sql_helper::select_blacklist_vehicle);
    // // // Start the timer within the Handel_Thread
    // QMetaObject::invokeMethod(update_groupbox_db_thread, &Handel_Thread::start);


    // timer = new QTimer(this);

    // QObject::connect(timer, &QTimer::timeout, [this]() {
    //     // Call create_groupbox_listwidget asynchronously using QtConcurrent::run with a lambda function
    //     QFuture<void> future = QtConcurrent::run([this](){
    //         sql_help.select_blacklist_vehicle();
    //     });
    //     // You can optionally wait for the future to finish
    //     // future.waitForFinished();
    // });

    // // Start the QTimer
    // timer->start(2000);

    connect(&sql_help,&sql_helper::signal_to_blacklist_vehicle_db_update,&sql_help,&sql_helper::select_blacklist_vehicle);
    connect(&sql_help,&sql_helper::signal_to_update_groupbox_update,this,&Control_center::create_groupbox_listwidget);
    create_dashboard();

    //Dashboard codes

}

Control_center::~Control_center()
{
    groupbox_update_thread->quit();
    groupbox_update_thread->wait();

    update_groupbox_from_db->quit();
    update_groupbox_from_db->wait();
    delete ui;
}
//code for add device
void Control_center::on_server_pushButton_submit_clicked()
{
    QString servername = ui->sever_lineEdit_name->text();
    QString description = ui->server_lineEdit__description->text();

    QString insertcmd ;
    // = "INSERT INTO tblservers (ServerName, IpAddress, ServerType, Username, Password"
    //                              "VALUES ('"+servername+"', '"+obj.ip_address+"', '"+obj.server_type+"', '"+obj.user_name+"', "
    //                     "'"+obj.password+"')";
    if(!servername.isEmpty()){
        insertcmd = "INSERT INTO tblservers (ServerName, IpAddress, ServerType, Username, Password)"
                    " VALUES ('"+servername+"', '"+obj.ip_address+"', '"+obj.server_type+"', '"+obj.user_name+"', '"+obj.password+"')";


        QTableWidgetItem *currentItem = ui->server_tableWidget->currentItem();

        if (!currentItem) {

            // No item selected, perform insert
            insertItem(insertcmd);
        } else {
            int row = currentItem->row();
            int id =ui->server_tableWidget->item(row, 2)->text().toInt();

            QString updatecmd = "UPDATE tblservers SET ServerName = '"+servername+"'"
                                                                                      "WHERE id = "+ QString::number(id)+"";

            // Item selected, perform update
            updateItem(updatecmd);
        }
    }
    else{
        QMessageBox::information(this,tr("Warning"),"Name field can not empty",Qt::NoButton);
    }
    // sql_help.add_server_to_db(insertcmd,cmd_type) ;
    set_db_value_to_server_tablewidget();

}

void Control_center::set_db_value_to_server_tablewidget()
{
    sql_help.serverlist.clear();
    sql_help.list_server_name.clear();
    ui->add_device_comboBox->clear();

    sql_help.load_server_data_to_strut_server();

    foreach (const QString &item, sql_help.list_server_name) {
        ui->add_device_comboBox->addItem(item);
    }


    int numRows = sql_help.serverlist.size();
    int numCols = 3;
    ui->server_tableWidget->setRowCount(numRows);
    ui->server_tableWidget->setColumnCount(numCols);

    // Iterate over the list and insert data into the table widget
    for (int row = 0; row < numRows; ++row) {
        obj = sql_help.serverlist.at(row);

        QWidget *widget = new QWidget();

        QHBoxLayout *layout = new QHBoxLayout(widget);

        // QPushButton *button1 = new QPushButton();
        // button1->setStyleSheet("border: none;");

        QPushButton *button2 = new QPushButton();
        button2->setStyleSheet("border: none;");

        QIcon icon_to_btn2("/home/sunny/Downloads/trash_icon.png");
        button2->setIcon(icon_to_btn2);

        // layout->addWidget(button1);
        layout->addWidget(button2);
        layout->setAlignment(Qt::AlignCenter);
        layout->setContentsMargins(0, 0, 0, 0);
        widget->setLayout(layout);
        button2->setProperty("row", row);
        QObject::connect(button2, &QPushButton::clicked, this,&Control_center::server_trash_btn_clicked);

        QTableWidgetItem *nameItem = new QTableWidgetItem(obj.server_name);
        ui->server_tableWidget->setItem(row, 0, nameItem);
        ui->server_tableWidget->setCellWidget(row, 1, widget);

        QTableWidgetItem *_id = new QTableWidgetItem(QString::number(obj.id));
        ui->server_tableWidget->setItem(row, 2, _id);

        // Set the width of column 2 to zero to hide it visually
        // ui->server_tableWidget->setColumnWidth(2, 0);
        ui->server_tableWidget->setColumnHidden(2, true);
    }
    QHeaderView *header2 = ui->server_tableWidget->horizontalHeader();

    // Set the resize mode for each section to stretch
    for (int i = 0; i < header2->count(); ++i) {
        header2->setSectionResizeMode(i, QHeaderView::Stretch);
    }


    //Connect item selection changed signal to slot
    connect(ui->server_tableWidget, &QTableWidget::itemSelectionChanged, this, &Control_center::update_server_lineedit_name);
}

void Control_center::on_add_device_pushButton_submit_clicked()
{
    // Get the currently selected text
    QString server_name = ui->add_device_comboBox->currentText();
    qDebug() << "server_name text:" << server_name;
    // int id = sql_help.getIdByServerName(sql_help.serverlist,server_name);

    QString ip= ui->add_device_lineEdit_ip->text();
    QString name=ui->add_device_lineEdit_name->text();
    QString username=ui->add_device_lineEdit_username->text();
    QString password=ui->add_device_lineEdit_password->text();
    QString port=ui->add_device_lineEdit_port->text();
    QString RTSP_main_url=ui->lineEdit_RTSP_main_url->text();
    QString RTSP_sub_url=ui->lineEdit_RTSP_sub_url->text();

    QTableWidgetItem *currentitem = ui->add_device_tableWidget->currentItem();
    qDebug()<<"------------11111111111-------";

    int serverid= sql_help.getIdByServerName(sql_help.serverlist,server_name);

    // QString insertcmd = "INSERT INTO tbldevices (Model, Method, Host, Port, "
    //                     "CloudId, Username, Password, MacAddress, DeviceType, "
    //                     "CreatedAt, CreatedBy, CreatedPc, ModifiedAt, ModifiedBy, ModifiedPc, "
    //                     "ServerId, PrimaryUrl, SecondaryUrl, Status)"
    //                     "VALUES ('"+device_obj.model+"', '"+device_obj.method+"', '"+device_obj.host+"', '"+device_obj.port+"', "
    //                     "'"+device_obj.cloud_id+"', '"+device_obj.user_name+"', '"+device_obj.password+"', '"+device_obj.mac_address+"', '"+device_obj.device_type+"', "
    //                     "'"+device_obj.created_at+"', '"+device_obj.created_by+"', '"+device_obj.created_pc+"', '"+device_obj.modified_at+"', '"+device_obj.modified_by+"', "
    //                     "'"+device_obj.modified_pc+"', "+ QString::number(id)+", '"+device_obj.primary_url+"', '"+device_obj.secondary_url+"', '"+device_obj.status+"')";
    // QString insertcmd;
    // if(ip !="" && name !="" && username !="" && password !="" && port !="" && RTSP_main_url !="" && RTSP_sub_url !="" )
    // {
    // insertcmd = "INSERT INTO tbldevices (DeviceName, Port, "
    //             "CloudId, Username, Password, "
    //             "ServerId, PrimaryUrl, SecondaryUrl)"
    //             "VALUES ('"+name+"', '"+port+"', "
    //                                      "'"+ip+"', '"+username+"', '"+password+"',"
    //                                                            ""+ QString::number(id)+", '"+RTSP_main_url+"', '"+RTSP_sub_url+"')";
    // }
    qDebug()<<"------------22222222-------";
    if(!(ip.isEmpty() && name.isEmpty() && username.isEmpty() && password.isEmpty() && port.isEmpty() && RTSP_main_url.isEmpty() && RTSP_sub_url.isEmpty() && server_name.isEmpty()))
    {
        if (!currentitem) {
            qDebug()<<"------------55555-------";

            QString insertcmd = "INSERT INTO tbldevices (DeviceName, Port, "
                                "CloudId, Username, Password, "
                                "ServerId, PrimaryUrl, SecondaryUrl)"
                                "VALUES ('"+name+"', '"+port+"', "
                                                         "'"+ip+"', '"+username+"', '"+password+"',"
                                                                               ""+ QString::number(serverid)+", '"+RTSP_main_url+"', '"+RTSP_sub_url+"')";


            // No item selected, perform insert
            insertItem(insertcmd);
        } else {
            int row = currentitem->row();
            int id =ui->add_device_tableWidget->item(row, 3)->text().toInt();
            QString updatecmd = "UPDATE tbldevices SET CloudId = '" + ip + "', Username = '" + username + "', Password = '" + password + "', Port = '" + port + "', PrimaryUrl = '" + RTSP_main_url + "', SecondaryUrl = '" + RTSP_sub_url + "', ServerId = " + QString::number(serverid) + ", DeviceName ='"+name+"' WHERE id = " + QString::number(id);

            // Item selected, perform update
            updateItem(updatecmd);
        }
    }
    else{
        QMessageBox::information(this,tr("Warning"),"All fields are compolsory",Qt::NoButton);
    }

    // sql_help.add_device_detail_to_db(insertcmd);
    set_db_value_to_add_devices_tablewidget();
}
void Control_center::set_db_value_to_add_devices_tablewidget()
{
    sql_help.add_devices_list.clear();
    sql_help.load_server_data_to_strut_add_device();

    int numRows = sql_help.add_devices_list.size();
    int numCols = 4;
    ui->add_device_tableWidget->setRowCount(numRows);
    ui->add_device_tableWidget->setColumnCount(numCols);

    // Iterate over the list and insert data into the table widget
    for (int row = 0; row < numRows; ++row) {
        device_obj = sql_help.add_devices_list.at(row);

        QWidget *widget = new QWidget();

        QHBoxLayout *layout = new QHBoxLayout(widget);

        QPushButton *button2 = new QPushButton();
        button2->setStyleSheet("border: none;");
        QIcon icon_to_btn2("/home/sunny/Downloads/trash_icon.png");
        button2->setIcon(icon_to_btn2);

        // layout->addWidget(button1);
        layout->addWidget(button2);
        layout->setAlignment(Qt::AlignCenter);
        layout->setContentsMargins(0, 0, 0, 0);
        widget->setLayout(layout);
        button2->setProperty("row", row);

        QObject::connect(button2, &QPushButton::clicked, this,&Control_center::add_devices_trash_btn_clicked);

        int server_id = device_obj.server_id;
        QString server_name=sql_help.getServerNameFromId(sql_help.serverlist,server_id);
        if(server_name !=""){
            QTableWidgetItem *nameItem = new QTableWidgetItem(server_name);
            ui->add_device_tableWidget->setItem(row, 0, nameItem);
        }
        QTableWidgetItem *device = new QTableWidgetItem(device_obj.device_name);
        ui->add_device_tableWidget->setItem(row, 1, device);

        ui->add_device_tableWidget->setCellWidget(row, 2, widget);
        QTableWidgetItem *device_id = new QTableWidgetItem(QString::number(device_obj.id));
        ui->add_device_tableWidget->setItem(row, 3, device_id);

        // Set the width of column 2 to zero to hide it visually
        ui->add_device_tableWidget->setColumnWidth(3, 0);
    }
    //Connect item selection changed signal to slot
    connect(ui->add_device_tableWidget, &QTableWidget::itemSelectionChanged, this, &Control_center::update_add_devices_lineedit_name);
}

void Control_center::on_server_pushButton_cancel_clicked()
{
    ui->sever_lineEdit_name->clear();
    ui->server_lineEdit__description->clear();
}

void Control_center::on_add_device_pushButton_cancel_clicked()
{
    ui->add_device_lineEdit_ip->clear();
    ui->add_device_lineEdit_username->clear();
    ui->add_device_lineEdit_name->clear();
    ui->add_device_lineEdit_port->clear();
    ui->add_device_lineEdit_password->clear();
    ui->lineEdit_RTSP_main_url->clear();
    ui->lineEdit_RTSP_sub_url->clear();

}

void Control_center::server_trash_btn_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("The document you are trying to delete is permanently deleted.");
    msgBox.setWindowTitle("Delete Message");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStandardButtons(QMessageBox::Ok);

    QPushButton* button = qobject_cast<QPushButton*>(sender()); // Get the sender QPushButton

    int row;
    int value;
    if (button)
    {
        row = button->property("row").toInt();
        qDebug() << "Button clicked at Row:" << row;

        QTableWidgetItem *item = ui->server_tableWidget->item(row, 2);
        // Check if the item is not null and then retrieve its text
        if (item) {
            value = item->text().toInt();
            qDebug() << "Value at row" << row << ":" << value;
        } else {
            qDebug() << "No item at row" << row;
        }
    }


    connect(&msgBox, &QMessageBox::buttonClicked, this, [this,value](){
        server_delete_btn_clicked(value);
    });

    msgBox.exec();
}
void Control_center::server_delete_btn_clicked(int id)
{
    QString cmd_type ="delete";
    sql_help.removeRecord(sql_help.serverlist,id);

    set_server_list_value_to_tablewidget(id);
    set_add_device_list_value_to_tablewidget(id);

}

void Control_center::add_devices_trash_btn_clicked()
{
    QMessageBox add_device_msgBox;
    add_device_msgBox.setText("The document you are trying to delete is permanently deleted.");
    add_device_msgBox.setWindowTitle("Delete Message");
    add_device_msgBox.setIcon(QMessageBox::Information);
    add_device_msgBox.setStandardButtons(QMessageBox::Ok);

    QPushButton* button = qobject_cast<QPushButton*>(sender()); // Get the sender QPushButton

    int row;
    int value;
    if (button)
    {
        row = button->property("row").toInt();
        qDebug() << "Button clicked at Row:" << row;

        QTableWidgetItem *item = ui->add_device_tableWidget->item(row, 3);
        // Check if the item is not null and then retrieve its text
        if (item) {
            value = item->text().toInt();
            qDebug() << "Value at row" << row << ":" << value;
        } else {
            qDebug() << "No item at row" << row;
        }
    }

    connect(&add_device_msgBox, &QMessageBox::buttonClicked, this, [this,value](){
        add_devices_delete_btn_clicked(value);
    });

    add_device_msgBox.exec();
}
void Control_center::add_devices_delete_btn_clicked(int server_id)
{
    QString cmd_type ="delete";
    QString deletecmd = "DELETE FROM tbldevices WHERE id="+ QString::number(server_id)+"";
    sql_help.add_server_to_db(deletecmd,cmd_type) ;
    set_db_value_to_add_devices_tablewidget();

}
void Control_center::update_server_lineedit_name()
{
    QList<QTableWidgetItem *> selectedItems = ui->server_tableWidget->selectedItems();
    if (!selectedItems.isEmpty()) {
        // Assuming you only want the first selected item
        ui->sever_lineEdit_name->setText(selectedItems.first()->text());
    } else {
        ui->sever_lineEdit_name->clear();
    }
}
void Control_center::update_add_devices_lineedit_name()
{
    // Get the selected row(s)
    QItemSelectionModel *selection = ui->add_device_tableWidget->selectionModel();
    QModelIndexList selectedRows = selection->selectedRows();
    int id;
    // Iterate through each selected row
    for (const QModelIndex &index : selectedRows) {
        // Get the row number
        int row = index.row();

        // Retrieve data from each cell in the row
        id = ui->add_device_tableWidget->item(row, 3)->text().toInt();
    }
    QStringList list=sql_help.get_add_devices_list(sql_help.add_devices_list,id);
    if(!list.isEmpty())
    {
        for (int i = 0; i < list.size(); ++i) {
            ui->add_device_lineEdit_name->setText(list[0]);
            ui->add_device_lineEdit_username->setText(list[1]);
            ui->add_device_lineEdit_password->setText(list[2]);
            ui->add_device_lineEdit_ip->setText(list[3]);
            ui->add_device_lineEdit_port->setText(list[4]);
            int id =list[5].toInt();
            QString server=sql_help.getServerNameFromId(sql_help.serverlist,id);
            int index = ui->add_device_comboBox->findText(server);

            if (index != -1) {
                // Value found in the combo box's items
                ui->add_device_comboBox->setCurrentIndex(index); // Set the current index to the found index
            }
            ui->lineEdit_RTSP_main_url->setText(list[6]);
            ui->lineEdit_RTSP_sub_url->setText(list[7]);
        }
    }

}

void Control_center:: insertItem(QString cmd) {
    sql_help.add_server_to_db(cmd,"insert") ;

}
void Control_center:: updateItem(QString cmd)
{
    sql_help.add_server_to_db(cmd,"update") ;

}
// Slot to handle item selection change
void Control_center::handleItemSelectionChanged() {
    QList<QTableWidgetItem *> selectedItems = ui->server_tableWidget->selectedItems();
    if (!selectedItems.isEmpty()) {
        // Enable the button when an item is selected
        ui->server_pushButton_submit->setEnabled(true);
    } else {
        // Disable the button when no item is selected
        ui->server_pushButton_submit->setEnabled(false);
    }
}
// Slot to handle button click to insert data into the table
void Control_center::insertDataToTable() {
    QList<QTableWidgetItem *> selectedItems = ui->server_tableWidget->selectedItems();
    if (!selectedItems.isEmpty()) {
        int row = selectedItems.first()->row();
        QString data = ui->sever_lineEdit_name->text(); // Assuming lineEdit is your QLineEdit
        QTableWidgetItem *newItem = new QTableWidgetItem(data);
        ui->server_tableWidget->setItem(row, 0, newItem); // columnToInsertData is the column index where you want to insert data
    }
}
void Control_center::add_device_handleItemSelectionChanged() {
    QList<QTableWidgetItem *> selectedItems = ui->add_device_tableWidget->selectedItems();
    if (!selectedItems.isEmpty()) {
        // Enable the button when an item is selected
        ui->add_device_pushButton_submit->setEnabled(true);
    } else {
        // Disable the button when no item is selected
        ui->add_device_pushButton_submit->setEnabled(false);
    }
}
// Slot to handle button click to insert data into the table
void Control_center::add_device_insertDataToTable() {

    QItemSelectionModel *selection = ui->add_device_tableWidget->selectionModel();
    QModelIndexList selectedRows = selection->selectedRows();
    int id;
    // Iterate through each selected row
    for (const QModelIndex &index : selectedRows) {
        // Get the row number
        int row = index.row();

        // Retrieve data from each cell in the row
        id = ui->add_device_tableWidget->item(row, 3)->text().toInt();
    }

    QStringList list=sql_help.get_add_devices_list(sql_help.add_devices_list,id);
    if(!list.isEmpty())
    {
        for (int i = 0; i < list.size(); ++i) {
            ui->add_device_lineEdit_name->setText(list[0]);
            ui->add_device_lineEdit_username->setText(list[1]);
            ui->add_device_lineEdit_password->setText(list[2]);
            ui->add_device_lineEdit_ip->setText(list[3]);
            ui->add_device_lineEdit_port->setText(list[4]);
            int id =list[5].toInt();
            QString server=sql_help.getServerNameFromId(sql_help.serverlist,id);
            int index = ui->add_device_comboBox->findText(server);

            if (index != -1) {
                // Value found in the combo box's items
                ui->add_device_comboBox->setCurrentIndex(index); // Set the current index to the found index
            }
            ui->lineEdit_RTSP_main_url->setText(list[6]);
            ui->lineEdit_RTSP_sub_url->setText(list[7]);
        }
    }

}

void Control_center::set_server_list_value_to_tablewidget(int id)
{
    // sql_help.list_server_name.clear();
    ui->add_device_comboBox->clear();
    QString servername = sql_help.getServerNameFromId(sql_help.serverlist,id);

    for (const sql_helper::server &item : sql_help.serverlist) {
        ui->add_device_comboBox->addItem(item.server_name); // Assuming you want to set the item's text as the name and item's data as the id
    }

    int numRows = sql_help.serverlist.size();
    int numCols = 3;
    ui->server_tableWidget->setRowCount(numRows);
    ui->server_tableWidget->setColumnCount(numCols);

    // Iterate over the list and insert data into the table widget
    for (int row = 0; row < numRows; ++row) {
        obj = sql_help.serverlist.at(row);

        QWidget *widget = new QWidget();

        QHBoxLayout *layout = new QHBoxLayout(widget);

        QPushButton *button2 = new QPushButton();
        button2->setStyleSheet("border: none;");

        QIcon icon_to_btn2("/home/sunny/Downloads/trash_icon.png");
        button2->setIcon(icon_to_btn2);

        // layout->addWidget(button1);
        layout->addWidget(button2);
        layout->setAlignment(Qt::AlignCenter);
        layout->setContentsMargins(0, 0, 0, 0);
        widget->setLayout(layout);
        button2->setProperty("row", row);
        QObject::connect(button2, &QPushButton::clicked, this,&Control_center::server_trash_btn_clicked);

        QTableWidgetItem *nameItem = new QTableWidgetItem(obj.server_name);
        ui->server_tableWidget->setItem(row, 0, nameItem);
        ui->server_tableWidget->setCellWidget(row, 1, widget);

        QTableWidgetItem *_id = new QTableWidgetItem(QString::number(obj.id));
        ui->server_tableWidget->setItem(row, 2, _id);

        // Set the width of column 2 to zero to hide it visually
        //ui->server_tableWidget->setColumnWidth(2, 0);
        ui->server_tableWidget->setColumnHidden(2, true);
    }
    QHeaderView *header2 = ui->server_tableWidget->horizontalHeader();

    // Set the resize mode for each section to stretch
    for (int i = 0; i < header2->count(); ++i) {
        header2->setSectionResizeMode(i, QHeaderView::Stretch);
    }


    //Connect item selection changed signal to slot
    connect(ui->server_tableWidget, &QTableWidget::itemSelectionChanged, this, &Control_center::update_server_lineedit_name);

}
void Control_center::set_add_device_list_value_to_tablewidget(int id)
{
    int device_id = sql_help.get_id_from_add_device_list(sql_help.add_devices_list,id);
    sql_help.add_device_removeRecord(sql_help.add_devices_list,device_id);

    int numRows = sql_help.add_devices_list.size();
    int numCols = 4;
    ui->add_device_tableWidget->setRowCount(numRows);
    ui->add_device_tableWidget->setColumnCount(numCols);
    // Iterate over the list and insert data into the table widget
    for (int row = 0; row < numRows; ++row) {
        device_obj = sql_help.add_devices_list.at(row);

        QWidget *widget = new QWidget();

        QHBoxLayout *layout = new QHBoxLayout(widget);

        QPushButton *button2 = new QPushButton();
        button2->setStyleSheet("border: none;");
        QIcon icon_to_btn2("/home/sunny/Downloads/trash_icon.png");
        button2->setIcon(icon_to_btn2);

        layout->addWidget(button2);
        layout->setAlignment(Qt::AlignCenter);
        layout->setContentsMargins(0, 0, 0, 0);
        widget->setLayout(layout);
        // Store the row index as a property of the button
        button2->setProperty("row", row);

        QObject::connect(button2, &QPushButton::clicked, this,&Control_center::add_devices_trash_btn_clicked);

        int server_id = device_obj.server_id;
        QString server_name=sql_help.getServerNameFromId(sql_help.serverlist,server_id);
        if(server_name !=""){
            QTableWidgetItem *nameItem = new QTableWidgetItem(server_name);
            ui->add_device_tableWidget->setItem(row, 0, nameItem);
        }
        QTableWidgetItem *device = new QTableWidgetItem(device_obj.device_name);
        ui->add_device_tableWidget->setItem(row, 1, device);

        ui->add_device_tableWidget->setCellWidget(row, 2, widget);
        QTableWidgetItem *device_id = new QTableWidgetItem(QString::number(device_obj.id));
        // Set the width of column 2 to zero to hide it visually
        ui->add_device_tableWidget->setColumnWidth(3, 0);
        ui->add_device_tableWidget->setItem(row, 3, device_id);


    }
    //Connect item selection changed signal to slot
    connect(ui->add_device_tableWidget, &QTableWidget::itemSelectionChanged, this, &Control_center::update_add_devices_lineedit_name);    
}
void Control_center::create_dashboard()
{
    qDebug()<<"============create_dashboard===========";
    QMap<QString, int> vehicle_count_total =sql_help.get_vehicle_type_count();
    QMap<QString, int> vehicle_count_todays =sql_help.get_vehicle_type_count_todays();

    // if(!vehicle_count_todays.isEmpty()){

    QtCharts::QChart *Todays_stats_chart = new QtCharts::QChart();
    QtCharts::QBarSeries *Todays_stats_series = new QtCharts::QBarSeries();
    Todays_stats_series->clear();
    if(!vehicle_count_todays.isEmpty()){

        // Iterate over the QMap and add data to the series
        for (auto it = vehicle_count_todays.constBegin(); it != vehicle_count_todays.constEnd(); ++it) {
            // Check if the key is empty
            QString vehicleType = it.key().isEmpty() ? "Other Vehicle" : it.key();
            // Create a QBarSet for each category and add the count to it
            QtCharts::QBarSet *set = new QtCharts::QBarSet(vehicleType);
            *set << it.value();
            // Set the label for the bar to display the count along with the category label
            set->setLabel(vehicleType + ": " + QString::number(it.value()));        // Append the QBarSet to the series
            Todays_stats_series->append(set);
        }


        // Add the series to the chart
        Todays_stats_chart->addSeries(Todays_stats_series);

        // Create axes
        QtCharts::QBarCategoryAxis *axisX = new QtCharts::QBarCategoryAxis();
        axisX->append("Vehicle Type"); // Use the vehicle types as categories on the X-axis
        Todays_stats_chart->addAxis(axisX, Qt::AlignBottom);
        Todays_stats_series->attachAxis(axisX);

        QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis();
        // Get the maximum count as an integer
        int maxCount = static_cast<int>(*std::max_element(vehicle_count_todays.constBegin(), vehicle_count_todays.constEnd()));

        // Set the range of the Y-axis to integers
        axisY->setRange(0, maxCount);
        // axisY->setRange(0, *std::max_element(vehicle_car.constBegin(), vehicle_car.constEnd())); // Set range based on maximum count
        Todays_stats_chart->addAxis(axisY, Qt::AlignLeft);
        Todays_stats_series->attachAxis(axisY);
        Todays_stats_chart->update();
    }
    QtCharts::QChartView *Todays_stats_chartView = new QtCharts::QChartView(Todays_stats_chart);
    Todays_stats_chartView->setRenderHint(QPainter::Antialiasing);
    Todays_stats_chartView->update();
    QVBoxLayout *Vlayout = new QVBoxLayout(this);
    Vlayout->addWidget(Todays_stats_chartView);
    ui->groupBox_todays_stats->setLayout(Vlayout);
    Todays_stats_chartView->repaint();
    //Todays stats charts

    //LPUchart
    QtCharts::QChart *LPUchart = new QtCharts::QChart();
    QtCharts::QPieSeries *LPUseries = new QtCharts::QPieSeries();
    int server_active= sql_help.getLPU_count(sql_help.serverlist);
    int server_inactive=0;
    LPUseries->append("Active", server_active);
    LPUseries->append("Inactive", server_inactive);
    QString LPUlabelFormat = "%1: %2";
    for (QtCharts::QPieSlice *slice : LPUseries->slices()) {
        slice->setLabel(LPUlabelFormat.arg(slice->label()).arg(slice->value()));
    }

    LPUchart->addSeries(LPUseries);
    LPUchart->legend()->setVisible(true);

    QtCharts::QChartView *LPUchartView = new QtCharts::QChartView(LPUchart);
    LPUchartView->setRenderHint(QPainter::Antialiasing);
    QVBoxLayout *LPUVlayout = new QVBoxLayout(this);
    LPUVlayout->addWidget(LPUchartView);

    ui->groupBox_LPU->setLayout(LPUVlayout);
    // ui->groupBox_LPU->setMinimumWidth(ui->groupBox_todays_stats->width());
    //LPU charts

    //camera status
    QtCharts::QChart *Camerachart = new QtCharts::QChart();
    QtCharts::QPieSeries *Cameraseries = new QtCharts::QPieSeries();
    main_window_obj = new MainWindow();
    Cameraseries->append("Connected", sql_help.getCamera_count(sql_help.add_devices_list));
    Cameraseries->append("Disconnected", 0);
    // Set label format to show both the label and the count
    QString labelFormat = "%1: %2";
    for (QtCharts::QPieSlice *slice : Cameraseries->slices()) {
        slice->setLabel(labelFormat.arg(slice->label()).arg(slice->value()));
    }
    Camerachart->addSeries(Cameraseries);
    Camerachart->legend()->setVisible(true);
    // Set label format to show percentage and count

    QtCharts::QChartView *CamerachartView = new QtCharts::QChartView(Camerachart);
    CamerachartView->setRenderHint(QPainter::Antialiasing);
    QVBoxLayout *CameraVlayout = new QVBoxLayout(this);
    CameraVlayout->addWidget(CamerachartView);
    int height =ui->tab_dashboard->height();
    qDebug()<<"====tab_dashboard height====="<<height;
    ui->groupBox_Camera_status->setLayout(CameraVlayout);
    // ui->groupBox_Camera_status->setMinimumHeight(ui->groupBox_todays_stats->height()+10);

    ui->label_LPU_count->setText(QString::number(sql_help.getLPU_count(sql_help.serverlist)));
    ui->label_Camera_count->setText(QString::number(sql_help.getCamera_count(sql_help.add_devices_list)));
    ui->label_Vehicle_type_count->setText(QString::number(sql_help.getLPU_count(sql_help.serverlist)));
    ui->label_Vehicle_count_total->setText(QString::number(sql_help.get_vehicle_total_count()));
    ui->label_Vehicle_count_todays->setText(QString::number(sql_help.get_vehicle_todays_count()));


    //Total vehicle
    QtCharts::QChart *Vehicle_total_chart = new QtCharts::QChart();
    QtCharts::QPieSeries *Vehicle_total_series = new QtCharts::QPieSeries();
    Vehicle_total_series->clear();
    qDebug()<<"=====vehicle_count_total==11111=="<<vehicle_count_total;
    // Iterate over the QMap and add data to the series
    for (auto it = vehicle_count_total.constBegin(); it != vehicle_count_total.constEnd(); ++it) {
        // Check if the key is empty
        QString vehicleType = it.key().isEmpty() ? "Other Vehicle" : it.key();

        Vehicle_total_series->append(it.key(), it.value());
    }
    // Set label format to show both the label and the count
    QString Vehicle_labelFormat = "%1: %2";
    for (QtCharts::QPieSlice *slice : Vehicle_total_series->slices()) {
        slice->setLabel(Vehicle_labelFormat.arg(slice->label()).arg(slice->value()));
    }

    Vehicle_total_chart->addSeries(Vehicle_total_series);
    Vehicle_total_chart->legend()->setVisible(true);
    // Set label format to show percentage and count
    Vehicle_total_chart->update();
    QtCharts::QChartView *Vehicle_total_chartView = new QtCharts::QChartView(Vehicle_total_chart);
    Vehicle_total_chartView->setRenderHint(QPainter::Antialiasing);
    QVBoxLayout *Vehicle_total_Vlayout = new QVBoxLayout(this);
    Vehicle_total_Vlayout->addWidget(Vehicle_total_chartView);
    ui->groupBox_Total_vehicle->setLayout(Vehicle_total_Vlayout);
    //Total vehicle

    //Upadte groupbox
    listwidget = new QListWidget(this);
    VLayout_to_listwidget = new QVBoxLayout(this);
    VLayout_to_listwidget->addWidget(listwidget);
    ui->groupBox_updates->setLayout(VLayout_to_listwidget);

    //  groupbox_update_thread = new QThread();
    // handel_thread_groupbox_update->moveToThread(groupbox_update_thread);

    // connect(handel_thread_groupbox_update, &Handel_Thread::timeout, this, &Control_center::create_groupbox_listwidget);
    // // Start the thread
    // groupbox_update_thread->start();
    // // Start the timer within the Handel_Thread
    // QMetaObject::invokeMethod(handel_thread_groupbox_update, &Handel_Thread::start);


    // QThread *thread1 = new QThread();
    // QObject::connect(thread1, &QThread::started, [this, thread1]() {
    //     create_groupbox_listwidget();
    //     thread1->quit();
    // });
    // thread1->start();
    // QObject::connect(groupbox_update_thread, &QThread::started, [this]() {
    //     QTimer *timer = new QTimer();
    //     connect(timer, &QTimer::timeout, this, &Control_center::create_groupbox_listwidget);
    //     timer->start(2000); // Adjust the interval as needed
    // });
    // groupbox_update_thread->start();

    // create_groupbox_listwidget();
    //Upadte groupbox


    // Create a QTimer
    // QTimer *timer = new QTimer(this);

    // Connect the QTimer's timeout signal to a lambda function
    // QObject::connect(timer, &QTimer::timeout, [this]() {
    //     // Call create_groupbox_listwidget asynchronously using QtConcurrent::run with a lambda function
    //     QFuture<void> future = QtConcurrent::run([this](){
    // create_groupbox_listwidget();
    //     });
    //     // You can optionally wait for the future to finish
    //     // future.waitForFinished();
    // });

    // // Start the QTimer
    // timer->start(1000);
    sql_help.select_blacklist_vehicle();

}
void Control_center::on_dashboard_refresh_btn_clicked()
{
    if (ui->groupBox_Total_vehicle->layout()) {
        // Clear the existing layout
        QLayout *existingLayout = ui->groupBox_Total_vehicle->layout();
        while (QLayoutItem* item = existingLayout->takeAt(0)) {
            if (QWidget* widget = item->widget()) {
                delete widget;
            }
            delete item;
        }
        delete existingLayout;
    }

    if (ui->groupBox_todays_stats->layout()) {
        // Clear the existing layout
        QLayout *existingLayout = ui->groupBox_todays_stats->layout();
        while (QLayoutItem* item = existingLayout->takeAt(0)) {
            if (QWidget* widget = item->widget()) {
                delete widget;
            }
            delete item;
        }
        delete existingLayout;
    }
    if (ui->groupBox_Camera_status->layout()) {
        // Clear the existing layout
        QLayout *existingLayout = ui->groupBox_Camera_status->layout();
        while (QLayoutItem* item = existingLayout->takeAt(0)) {
            if (QWidget* widget = item->widget()) {
                delete widget;
            }
            delete item;
        }
        delete existingLayout;
    }
    if (ui->groupBox_Statistics->layout()) {
        // Clear the existing layout
        QLayout *existingLayout = ui->groupBox_Statistics->layout();
        while (QLayoutItem* item = existingLayout->takeAt(0)) {
            if (QWidget* widget = item->widget()) {
                delete widget;
            }
            delete item;
        }
        delete existingLayout;
    }
    if (ui->groupBox_LPU->layout()) {
        // Clear the existing layout
        QLayout *existingLayout = ui->groupBox_LPU->layout();
        while (QLayoutItem* item = existingLayout->takeAt(0)) {
            if (QWidget* widget = item->widget()) {
                delete widget;
            }
            delete item;
        }
        delete existingLayout;
    }
    if (ui->groupBox_updates->layout()) {
        // Clear the existing layout
        QLayout *existingLayout = ui->groupBox_updates->layout();
        while (QLayoutItem* item = existingLayout->takeAt(0)) {
            if (QWidget* widget = item->widget()) {
                delete widget;
            }
            delete item;
        }
        delete existingLayout;
    }
    ui->groupBox_todays_stats->setMinimumWidth(ui->groupBox_LPU->width());
    ui->groupBox_LPU->setMinimumWidth(ui->groupBox_todays_stats->width());
    ui->groupBox_updates->setMinimumWidth(ui->groupBox_todays_stats->width());

    qDebug()<<"======on_dashboard_refresh_btn_clicked====";
    create_dashboard();
}

void Control_center::create_groupbox_listwidget()
{
    // In your code, wherever you want to check the thread:
    // int maxItems = 5;
    qDebug() << "======create_groupbox_listwidget======";
    // Check if the function is running in the main thread or a separate thread
    if (QThread::currentThread() == QCoreApplication::instance()->thread()) {
        qDebug() << "Function is running in the main thread.";
        // QMetaObject::invokeMethod(this, "create_groupbox_listwidget", Qt::QueuedConnection);
        // return;
    } else {
        qDebug() << "Function is running in a separate thread.";
    }
    // sql_help.select_blacklist_vehicle();
    // // Remove the last item if the count exceeds the maximum limit
    // while (listwidget->count() >= maxItems) {
    //     delete listwidget->takeItem(listwidget->count() - 1);
    // }
    if(sql_help.blacklisted_v_for_groupbox_update_list.isEmpty())
    {
        listwidget->clear();
    }
    else{
        // Add new items to the beginning of the list
        for (int ii = sql_help.blacklisted_v_for_groupbox_update_list.size() - 1; ii >= 0; ii--) {
            const sql_helper::blacklisted_v_for_groupbox_update &data_obj = sql_help.blacklisted_v_for_groupbox_update_list[ii];
            Cardwidget *cardWidget = nullptr; // Define cardWidget here
            if (!data_obj.plateimgpath.isEmpty()) {
                cardWidget = new Cardwidget(data_obj.camname, data_obj.plateimgpath, data_obj.vehicleImagePath, data_obj.ocrnumber, data_obj.datetime, data_obj.vehicleclass);
                // connect(cardWidget, &Cardwidget::cardClicked, this, &MainWindow::ShowCard);
            } else {
                cardWidget = new Cardwidget(data_obj.camname, "/home/sunny/Downloads/edit_icon.png", data_obj.vehicleImagePath, data_obj.ocrnumber, data_obj.datetime, data_obj.vehicleclass);
                // connect(cardWidget, &Cardwidget::cardClicked, this, &MainWindow::ShowCard);
            }
            QListWidgetItem *newItem = new QListWidgetItem;
            newItem->setSizeHint(cardWidget->sizeHint());
            // Insert the QListWidgetItem at the beginning of the QListWidget
            listwidget->insertItem(0, newItem);

            // Set the cardWidget as the item widget
            listwidget->setItemWidget(newItem, cardWidget);
        }
    }
    qDebug()<<"===before==blacklisted_v_for_groupbox_update_list====="<<sql_help.blacklisted_v_for_groupbox_update_list.size();

    // // Clear the data list after adding new items
    sql_help.blacklisted_v_for_groupbox_update_list.clear();
    qDebug()<<"===after==blacklisted_v_for_groupbox_update_list====="<<sql_help.blacklisted_v_for_groupbox_update_list.size();

    // // In your code, wherever you want to check the thread:
    // int maxItems = 5;
    // qDebug() << "======create_groupbox_listwidget======";
    // // sql_help.select_blacklist_vehicle();
    // // // Process the first 5 records if available
    // int count = 0;
    // for (const auto &data_obj : sql_help.blacklisted_v_for_groupbox_update_list) {
    //     if (count >= maxItems) break; // Exit the loop if maxItems is reached
    //     Cardwidget *cardWidget = nullptr; // Define cardWidget here
    //     if (!data_obj.plateimgpath.isEmpty()) {
    //         cardWidget = new Cardwidget(data_obj.camname, data_obj.plateimgpath, data_obj.vehicleImagePath, data_obj.ocrnumber, data_obj.datetime, data_obj.vehicleclass);
    //         // connect(cardWidget, &Cardwidget::cardClicked, this, &MainWindow::ShowCard);
    //     } else {
    //         cardWidget = new Cardwidget(data_obj.camname, "/home/sunny/Downloads/edit_icon.png", data_obj.vehicleImagePath, data_obj.ocrnumber, data_obj.datetime, data_obj.vehicleclass);
    //         // connect(cardWidget, &Cardwidget::cardClicked, this, &MainWindow::ShowCard);
    //     }
    //     QListWidgetItem *newItem = new QListWidgetItem;
    //     newItem->setSizeHint(cardWidget->sizeHint());
    //     // Insert the QListWidgetItem at the beginning of the QListWidget
    //     listwidget->insertItem(count, newItem);

    //     // Set the cardWidget as the item widget
    //     listwidget->setItemWidget(newItem, cardWidget);

    //     count++; // Increment count after adding an item
    // }

    // // Clear the data list after adding new items
    // sql_help.blacklisted_v_for_groupbox_update_list.erase(sql_help.blacklisted_v_for_groupbox_update_list.begin(), sql_help.blacklisted_v_for_groupbox_update_list.begin() + count);

    ///////



}

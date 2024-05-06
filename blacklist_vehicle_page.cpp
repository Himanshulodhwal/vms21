#include "blacklist_vehicle_page.h"
#include "ui_blacklist_vehicle_page.h"

#include <QMessageBox>
Blacklist_vehicle_page::Blacklist_vehicle_page(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Blacklist_vehicle_page)
{
    ui->setupUi(this);
    int numCols=3;
    ui->tableWidget_blacklist->setColumnCount(numCols);
    QStringList labels;
    labels<<"id"<<"Vehicle Number"<<"Action";
    ui->tableWidget_blacklist->setHorizontalHeaderLabels(labels);
    ui->tableWidget_blacklist->setColumnHidden(0, true);
    ui->tableWidget_blacklist->setColumnWidth(1,210);

    set_tblvehicle_blacklist_data_to_tablewidget_blacklist(true);

}

Blacklist_vehicle_page::~Blacklist_vehicle_page()
{
    delete ui;
}

void Blacklist_vehicle_page::on_pushButton_submit_blacklist_clicked()
{
    QString ocr_number =ui->lineEdit_vehicle_ocr_number->text();
    QString remarks =ui->lineEdit_remarks->text();

    QString vehicle_number=sql_help.set_vehicle_to_blacklist(ocr_number);
    QString cmd;
    if(!(ocr_number.isEmpty() && remarks.isEmpty()))
    {
     cmd="INSERT INTO tblBlacklist_vehicle(ocr_number,remark)"
                  "VALUES('"+ocr_number+"','"+remarks+"')";
    sql_help.add_server_to_db(cmd,"insert into tblBlacklist_vehicle");
    set_tblvehicle_blacklist_data_to_tablewidget_blacklist(true);
    }
    else{
        QMessageBox::information(this,tr("Warning"),"All fields are compulsory to fill",Qt::NoButton);

    }
}


void Blacklist_vehicle_page::on_pushButton_cancel_blacklist_clicked()
{
    ui->lineEdit_vehicle_ocr_number->clear();
    ui->lineEdit_remarks->clear();
}

void Blacklist_vehicle_page::set_tblvehicle_blacklist_data_to_tablewidget_blacklist(bool value)
{
    qDebug()<<"===========99999999================"<<Q_FUNC_INFO;
    if(value){
    sql_help.blacklist_Vehicle.clear();
    sql_help.Select_from_tblBlacklist_vehicle();
    }
    int numRows = sql_help.blacklist_Vehicle.size();
    ui->tableWidget_blacklist->setRowCount(numRows);
    qDebug()<<"======Q_FUNC_INFO===="<<Q_FUNC_INFO;

    qDebug()<<"======numRows===="<<numRows;
    for (int row = 0; row < numRows; ++row) {
        Vehicle_blacklist_obj = sql_help.blacklist_Vehicle.at(row);

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
        button2->setProperty("row", row);
        QObject::connect(button2, &QPushButton::clicked, this,&Blacklist_vehicle_page::vehicle_blacklist_trash_btn_clicked);

        QTableWidgetItem *_id = new QTableWidgetItem(Vehicle_blacklist_obj.id);
        ui->tableWidget_blacklist->setItem(row, 0, _id);
        QTableWidgetItem *nameItem = new QTableWidgetItem(Vehicle_blacklist_obj.ocr_number);
        ui->tableWidget_blacklist->setItem(row, 1, nameItem);
        ui->tableWidget_blacklist->setCellWidget(row, 2, widget);

    }

}

void Blacklist_vehicle_page::vehicle_blacklist_trash_btn_clicked()
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

        QTableWidgetItem *item = ui->tableWidget_blacklist->item(row, 0);
        // Check if the item is not null and then retrieve its text
        if (item) {
            value = item->text().toInt();
            qDebug() << "Value at row" << row << ":" << value;
        } else {
            qDebug() << "No item at row" << row;
        }
    }

    connect(&msgBox, &QMessageBox::buttonClicked, this, [this,value](){
        vehicle_blacklist_delete_btn_clicked(value);
    });

    msgBox.exec();
}

void Blacklist_vehicle_page::vehicle_blacklist_delete_btn_clicked(int id)
{
    QString cmd_type ="delete";
    sql_help.vehicle_blacklist_removeRecord(sql_help.blacklist_Vehicle,id);
    set_tblvehicle_blacklist_data_to_tablewidget_blacklist(false);
    QString deletecmd = "DELETE FROM tblBlacklist_vehicle WHERE id="+ QString::number(id)+"";
    sql_help.add_server_to_db(deletecmd,cmd_type) ;

}

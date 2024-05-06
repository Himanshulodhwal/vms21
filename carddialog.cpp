#include "carddialog.h"
#include "ui_carddialog.h"

CardDialog::CardDialog(QString camname,QString plateimgpath, QString vehicleimgpath,QString ocrnumber,QString datetime,QString vehicle_class,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CardDialog)
{
    ui->setupUi(this);
    ui->label_camename->setText(camname);
    ui->label_datetime->setText(datetime);
    ui->label_ocr_number->setText(ocrnumber);
    ui->label_vehicle_class->setText(vehicle_class);
    QPixmap plate_img(plateimgpath);
    ui->label_plate_image_path->setPixmap(plate_img);

    QPixmap vehicle_image(vehicleimgpath);
    ui->label_vehicle_image_path->setPixmap(vehicle_image);
    this->show();
}

CardDialog::~CardDialog()
{
    delete ui;
}

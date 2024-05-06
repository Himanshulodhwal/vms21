#include "cardwidget.h"
#include "ui_cardwidget.h"
#include <QDialog>
#include <QDebug>
#include <QFont>
Cardwidget::Cardwidget(QString camname,QString plateimgpath, QString vehicleimgpath,QString ocrnumber,QString datetime,QString vehicle_class,QWidget *parent)
    :QWidget(parent),m_camname(camname), m_plateimgpath(plateimgpath), m_vehicleImagePath(vehicleimgpath), m_ocrnumber(ocrnumber), m_datetime(datetime), m_vehicleclass(vehicle_class),
    ui(new Ui::Cardwidget)
{
    ui->setupUi(this);
    QPixmap pixmap(plateimgpath);

    // Calculate aspect ratio to maintain proportions
    int width = pixmap.width();
    int height = pixmap.height();
    double aspectRatio = static_cast<double>(width) / height;

    // Set the maximum width to 95 pixels
    int maxWidth = 95;
    int newWidth = qMin(width, maxWidth);
    int newHeight = static_cast<int>(newWidth / aspectRatio);
    // sql_help.check_ocr_number(m_ocrnumber);
    if(sql_help.check_ocr_number_for_anpr4(m_ocrnumber))
    {
        ui->label_camename->setText(camname);
        ui->label_ocr_number->setText(ocrnumber);
        ui->label_plate_image_path->setContentsMargins(5,5,5,5);

        // Create a QLabel and set the image
        ui->label_plate_image_path->setPixmap(pixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio));
        // ui->label_plate_image_path->setPixmap(pixmap);
        ui->label_vehicle_class->setText(vehicle_class);
        ui->label_datetime->setText(datetime);
        this->setStyleSheet("background: #ABEBC6;");
    }

    else{
        // QPixmap pixmap(plateimgpath);
        ui->label_camename->setText(camname);
        ui->label_ocr_number->setText(ocrnumber);
        ui->label_plate_image_path->setContentsMargins(5,5,5,5);

        // Create a QLabel and set the image
        ui->label_plate_image_path->setPixmap(pixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio));
        // ui->label_plate_image_path->setPixmap(pixmap);
        ui->label_vehicle_class->setText(vehicle_class);
        ui->label_datetime->setText(datetime);

    }
    // sql_help.check_ocr_number_for_anpr4(m_ocrnumber);
}

Cardwidget::~Cardwidget()
{
    delete ui;
}
// Emit the signal in Cardwidget.cpp when the card is clicked
void Cardwidget::mousePressEvent(QMouseEvent *event) {
    qDebug()<<"------mousePressEvent----";
    emit cardClicked(m_camname, m_plateimgpath, m_vehicleImagePath, m_ocrnumber, m_datetime, m_vehicleclass);

}


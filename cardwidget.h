#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <sql_helper.h>
namespace Ui {
class Cardwidget;
}

class Cardwidget : public QWidget
{
    Q_OBJECT

public:
    explicit Cardwidget(QString camname,QString plateimgpath, QString vehicleimagepath,QString ocrnumber,QString datetime,QString vehicle_class,QWidget *parent = nullptr);
    ~Cardwidget();

private:
    Ui::Cardwidget *ui;
    void  mousePressEvent(QMouseEvent *event);

signals:
    void cardClicked(const QString &camname, const QString &plateimgpath, const QString &vehicleImagePath, const QString &ocrnumber, const QString &datetime, const QString &vehicleclass);
private:
    QString m_camname;
    QString m_plateimgpath;
    QString m_vehicleImagePath;
    QString m_ocrnumber;
    QString m_datetime;
    QString m_vehicleclass;

    sql_helper& sql_help = sql_helper::getInstance();
    sql_helper::blacklisted_v_for_groupbox_update balcklist_vehicle_obj;

};

#endif // CARDWIDGET_H

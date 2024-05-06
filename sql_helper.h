#ifndef SQL_HELPER_H
#define SQL_HELPER_H

#include <QObject>
#include "QtSql/QSqlDatabase"
#include <QTimer>
#include "QDebug"
#include "QtSql/QSqlError"
#include <QThread>
class sql_helper : public QObject
{
    Q_OBJECT

private:
    explicit sql_helper(QObject *parent = nullptr);
    sql_helper(const sql_helper&) = delete; // Disable copy constructor
    sql_helper& operator=(const sql_helper&) = delete; // Disable assignment operator
    // Static instance of the singleton
    static sql_helper* instance;
    ~sql_helper();
public:
    static sql_helper& getInstance();
    QList<QString> list_server_name;
    struct server{
        int id;
        QString server_name;
        QString ip_address;
        QString port;
        QString server_type;
        QString user_name;
        QString password;
        QString publisher_port;
        QString receiver_port;
        QString created_at;
        QString created_by;
        QString created_pc;
        QString modified_at;
        QString modified_by;
        QString modified_pc;

    };
    QList<struct server> serverlist;

    struct add_devices{
        int id;
        QString device_name;
        QString model;
        QString method;
        QString host;
        QString port;
        QString cloud_id;
        QString user_name;
        QString password;
        QString mac_address;
        QString created_at;
        QString created_by;
        QString created_pc;
        QString modified_at;
        QString modified_by;
        QString modified_pc;
        int server_id;
        QString primary_url;
        QString secondary_url;
        QString device_type;
        QString status;

    };
    QList<struct add_devices> add_devices_list;

    struct tbldata{
        int SrNo;
        QString camname;
        QString plateimgpath;
        QString vehicleImagePath;
        QString ocrnumber;
        QString vehicleclass;
        QString datetime;
        QString isSent;
    };
    QList<struct tbldata> datalist;

    struct tblVehicle_blacklist{
        QString id;
        QString ocr_number;
        QString remarks;
    };
    QList<struct tblVehicle_blacklist> blacklist_Vehicle;

    struct blacklisted_v_for_groupbox_update{
        int SrNo;
        QString camname;
        QString plateimgpath;
        QString vehicleImagePath;
        QString ocrnumber;
        QString vehicleclass;
        QString datetime;
        QString isSent;
    };
    QList<struct blacklisted_v_for_groupbox_update> blacklisted_v_for_groupbox_update_list;


public:
    QStringList get_rtsp_url(const QList<add_devices> &add_devicesList);
    void load_server_data_to_strut_server();
    void add_server_to_db(QString cmd,QString cmdType);
    void load_server_data_to_strut_add_device();
    void add_device_detail_to_db(QString cmd);
    void update_server_db(QString cmd);

    QString getServerNameFromId(const QList<server> &serverList,int id);
    QStringList get_add_devices_list(const QList<add_devices> &add_devicesList,int id);

    int getIdByServerName(const QList<server> &serverList, const QString &targetServerName);
    int getIdfromAddDevices(const QList<add_devices> &add_devicelist, const QString &targetServerName);
    int get_id_from_add_device_list(QList<add_devices> &list, int id);

    bool getserver_name_from_server_name(const QList<server> &serverList,const QString &newServerName);

    void removeRecord(QList<server> &list, int id);
    void add_device_removeRecord(QList<add_devices> &list, int id);
    QString convertTimestamp(const QString &timestamp);
    bool ckeck_db_status();
    void db_close();
    QStringList get_device_name_from_server_id(const QList<add_devices> &add_devicelist, const int &id);
    int getLPU_count(const QList<server> &serverList);
    int get_vehicle_total_count();
    int getCamera_count(const QList<add_devices> &add_device_list);
    int get_vehicle_todays_count();
    QMap<QString, int> get_vehicle_type_count();
    QMap<QString,int> get_vehicle_type_count_todays();
    QString set_vehicle_to_blacklist(QString vehicle_number);
    void Select_from_tblBlacklist_vehicle();
    void vehicle_blacklist_removeRecord(QList<tblVehicle_blacklist> &list, int id);
    // void select_blacklist_vehicle();
    bool check_ocr_number_for_anpr4(QString ocr_number);
public slots:
    void check_ocr_number();
    void selectdata_from_tbldata();
    void select_blacklist_vehicle();

signals:
    void signal_to_check_ocr_number();
    void signal_to_update_groupbox_update();
    void signal_to_blacklist_vehicle_db_update();
    void signal_to_anpr4_db_updated();
private:
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
     int previousCount=0;
    QStringList global_ocrnumber;

};


#endif // SQL_HELPER_H

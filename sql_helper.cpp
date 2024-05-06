#include "sql_helper.h"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlError"
#include "QDebug"
#include <QDateTime>
#include<QDir>
#include<QDirIterator>
// Initialize the static instance as nullptr
sql_helper* sql_helper::instance = nullptr;

sql_helper& sql_helper::getInstance() {
        qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    // Create the instance if it's not already created
    if (!instance) {
        instance = new sql_helper();
    }
        qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

    return *instance;
}
sql_helper::sql_helper(QObject *parent)
    : QObject{parent}
{
       qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    // QString connectionOptions;
    // // Get the current directory path
    // QString currentDir = QDir::currentPath();
    // qDebug() << "currentDir=========:" << currentDir;

    // // Recursively search for the driver file
    // QStringList filters;
    // filters << "libmyodbc8a.so";
    // QDirIterator it(currentDir, filters, QDir::Files | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);

    // // Store the path if found
    // QString driverPath;
    // while (it.hasNext()) {
    //     QString filePath = it.next();
    //     qDebug() << "Found driver at:" << filePath;
    //     driverPath = filePath;
    //     qDebug() << "driverPath:--------" << driverPath;

    //     break;  // Stop after finding the first occurrence
    // }

    // if (!driverPath.isEmpty()) {
    //     // Use driverPath to set the database connection
    //      // connectionOptions = QString("DRIVER=%1;SERVER=localhost;DATABASE=anpr;UID=root;PWD=Sparsh@2023").arg(driverPath);
    //     connectionOptions = QString("DRIVER=%1;SERVER=localhost;DATABASE=sparsh_ccc;UID=root;PWD=sparsh#24").arg(driverPath);

    //     qDebug() << "Connection options:" << connectionOptions;
    //      db.setDatabaseName(connectionOptions);
    // } else {
    //     qDebug() << "Driver not found in the current directory or its subdirectories!";
    // }
    // db.setDatabaseName(connectionOptions);
    db.setDatabaseName("DRIVER=/home/sunny/Downloads/mysqlconnect/lib/libmyodbc8a.so;SERVER=localhost;DATABASE=sparsh_ccc;UID=root;PWD=sparsh#24");
    // db.setDatabaseName("DRIVER=/home/sunny/Downloads/mysqlconnect/lib/libmyodbc8a.so;SERVER=192.168.29.171;DATABASE=anpr;UID=root;PWD=Sparsh@2023");
    //192.168.29.171
    check_ocr_number();
    connect(this,&sql_helper::signal_to_check_ocr_number,this,&sql_helper::check_ocr_number);
        qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

}

sql_helper::~sql_helper()
{
    // Destructor implementation
}
void sql_helper::load_server_data_to_strut_server()
{
        qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    if (db.open()) {
        qDebug() << "Connected to MySQL database!";
    } else {
        qWarning() << "Failed to connect to MySQL database:" << db.lastError().text();
    }
    QSqlQuery query;
    query.prepare("SELECT * FROM tblservers");

    if (!query.exec()) {
        qDebug() << "Failed to execute query:" << query.lastError().text();
        qDebug()<<"========"<<Q_FUNC_INFO;
        db.commit();
        db.close();

        return;
    }
    struct server server_obj;
    while(query.next()) {

        server_obj.id = query.value("id").toInt();
        server_obj.server_name = query.value("ServerName").toString();
        server_obj.ip_address = query.value("IpAddress").toString();
        server_obj.port = query.value("Port").toString();
        server_obj.server_type = query.value("ServerType").toString();

        server_obj.user_name = query.value("Username").toString();
        server_obj.password = query.value("Password").toString();
        server_obj.publisher_port = query.value("PublisherPort").toString();
        server_obj.receiver_port = query.value("ReceiverPort").toString();
        server_obj.created_at = query.value("CreatedAt").toString();

        server_obj.created_by = query.value("CreatedBy").toString();
        server_obj.created_pc = query.value("CreatedPc").toString();
        server_obj.modified_at = query.value("ModifiedAt").toString();
        server_obj.modified_by = query.value("ModifiedBy").toString();
        server_obj.modified_pc = query.value("ModifiedPc").toString();

        serverlist.append(server_obj);
        list_server_name.append(server_obj.server_name);
    }
    db.commit();
    db.close();
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";


}
void sql_helper::add_server_to_db(QString cmd,QString cmdType)
{
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    if (db.open()) {
        qDebug() << "Connected to MySQL database!";
    } else {
        qWarning() << "Failed to connect to MySQL database:" << db.lastError().text();
        qDebug()<<"========="<<Q_FUNC_INFO;
    }
    QSqlQuery query;
    query.prepare(cmd);

    if (!query.exec()) {
        qDebug() << "Failed to execute '"+cmdType+"' query:" << query.lastError().text();
        qDebug()<<"=========="<<Q_FUNC_INFO;
        db.commit();
        db.close();

        return;
    }

    db.commit();
    db.close();
    emit signal_to_blacklist_vehicle_db_update();
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

}
void sql_helper::load_server_data_to_strut_add_device()
{
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    if (db.open()) {
        qDebug() << "Connected to MySQL database!";
    } else {
        qWarning() << "Failed to connect to MySQL database:" << db.lastError().text();
    }
    QSqlQuery query;
    query.prepare("SELECT * FROM tbldevices");

    if (!query.exec()) {
        qDebug() << "Failed to execute select query:" << query.lastError().text();
        qDebug()<<"========="<<Q_FUNC_INFO;
        db.commit();
        db.close();

        return;
    }
    struct add_devices add_devices_obj;
    while(query.next()) {

        add_devices_obj.id = query.value("id").toInt();
        add_devices_obj.device_name = query.value("DeviceName").toString();
        add_devices_obj.model = query.value("Model").toString();
        add_devices_obj.method = query.value("Method").toString();
        add_devices_obj.host = query.value("Host").toString();

        add_devices_obj.port = query.value("Port").toString();
        add_devices_obj.cloud_id = query.value("CloudId").toString();
        add_devices_obj.user_name = query.value("Username").toString();
        add_devices_obj.password = query.value("Password").toString();
        add_devices_obj.mac_address = query.value("MacAddress").toString();

        add_devices_obj.device_type = query.value("DeviceType").toString();
        add_devices_obj.created_at = query.value("CreatedAt").toString();
        add_devices_obj.created_by = query.value("CreatedBy").toString();
        add_devices_obj.created_pc = query.value("CreatedPc").toString();
        add_devices_obj.modified_at = query.value("ModifiedAt").toString();

        add_devices_obj.modified_by = query.value("ModifiedBy").toString();
        add_devices_obj.modified_pc = query.value("ModifiedPc").toString();
        add_devices_obj.server_id = query.value("ServerId").toInt();
        add_devices_obj.primary_url = query.value("PrimaryUrl").toString();
        add_devices_obj.secondary_url = query.value("SecondaryUrl").toString();

        add_devices_obj.status = query.value("Status").toString();

        add_devices_list.append(add_devices_obj);
    }
    db.commit();
    db.close();
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

}

void sql_helper::add_device_detail_to_db(QString cmd)
{
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    if (db.open()) {
        qDebug() << "Connected to MySQL database!";
    } else {
        qWarning() << "Failed to connect to MySQL database:" << db.lastError().text();
    }
    QSqlQuery query;
    query.prepare(cmd);

    if (!query.exec()) {
        qDebug() << "Failed to execute insert query:" << query.lastError().text();
        qDebug()<<"========="<<Q_FUNC_INFO;
        db.commit();
        db.close();
        return;
    }

    db.commit();
    db.close();
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

}
void sql_helper::update_server_db(QString cmd)
{
}
int sql_helper::getIdByServerName(const QList<server> &serverList, const QString &targetServerName)
{
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    for (const server &server : serverList) {
        if (server.server_name == targetServerName) {
            return server.id;
        }

    }
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

    return -1; // Return -1 if the server_name is not found

}
int sql_helper::getIdfromAddDevices(const QList<add_devices> &add_devicelist, const QString &targetdeviceName)
{
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    for (const add_devices &add_devices : add_devices_list) {
        if (add_devices.device_name == targetdeviceName) {
            return add_devices.id;
        }

    }
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

    return -1; // Return -1 if the server_name is not found

}
QString sql_helper::getServerNameFromId(const QList<server> &serverList,int id)
{
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    for (const server &server_obj : serverlist) {
        if (server_obj.id == id) {
            return server_obj.server_name;
        }

    }
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

    return ""; // Return blank if the server_name is not found

}
QStringList sql_helper::get_add_devices_list(const QList<add_devices> &add_devicesList,int id)
{
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    QStringList deviceslist;
    for (const add_devices &device_obj : add_devices_list) {
        if (device_obj.id == id) {
            QString server_id = QString::number(device_obj.server_id);
            deviceslist<<device_obj.device_name << device_obj.user_name<< device_obj.password <<device_obj.cloud_id <<device_obj.port<<QString::number(device_obj.server_id)<<device_obj.primary_url<<device_obj.secondary_url;
            return deviceslist;
        }
    }
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

    return deviceslist; // Return blank if the server_name is not found

}

bool sql_helper::getserver_name_from_server_name(const QList<server> &serverList, const QString &newServerName)
{
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    for (const server &server_obj : serverlist) {
        if (server_obj.server_name == newServerName) {
            return true;
        }

    }
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

    return false; // Return blank if the server_name is not found

}

// Function to remove a record from the list based on some criteria
void sql_helper::removeRecord(QList<server> &list, int id) {
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    for (int i = 0; i < list.size(); ++i) {
        if (list.at(i).id == id) {
            list.removeAt(i);
            // If you want to remove only the first occurrence, you can break here
            //break;
        }
    }
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

}
void sql_helper::add_device_removeRecord(QList<add_devices> &list, int id) {
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    for (int i = 0; i < list.size(); ++i) {
        if (list.at(i).id == id) {
            list.removeAt(i);
        }
    }
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

}
int sql_helper::get_id_from_add_device_list(QList<add_devices> &list, int id)
{
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    int add_device_id =-1;
    for (const add_devices &add_device_obj : add_devices_list) {
        if (add_device_obj.server_id == id) {
            return add_device_obj.id;
        }

    }
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

    return add_device_id;

}
void sql_helper::selectdata_from_tbldata()
{
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    if (db.open()) {
        qDebug() << "Connected to MySQL database!";
    } else {
        qWarning() << "Failed to connect to MySQL database:" << db.lastError().text();
        qDebug()<<Q_FUNC_INFO;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM anpr4 ORDER BY datetime DESC LIMIT 100");

    if (!query.exec()) {
        qDebug() << "Failed to execute select query from anpr4 table:" << query.lastError().text();
        db.commit();
        db.close();
        qDebug()<<Q_FUNC_INFO;
        return;
    }
    struct tbldata data_obj;
    while(query.next()) {
        data_obj.SrNo = query.value("SrNo").toInt();
        data_obj.camname = query.value("camname").toString();
        data_obj.plateimgpath = query.value("plateimgpath").toString();
        data_obj.vehicleImagePath = query.value("vehicleImagePath").toString();
        data_obj.ocrnumber = query.value("ocrnumber").toString();

        data_obj.vehicleclass = query.value("vehicleclass").toString();
        QString date = query.value("datetime").toString();
        data_obj.datetime = convertTimestamp(date);

        datalist.append(data_obj);
    }

    db.commit();
    db.close();
    emit signal_to_anpr4_db_updated();
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

}
QString sql_helper:: convertTimestamp(const QString &timestamp) {
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    // Parse the timestamp string
    QDateTime dateTime = QDateTime::fromString(timestamp, Qt::ISODate);

    // Convert QDateTime to the desired format
    QString formattedDateTime = dateTime.toString("dd.MM.yyyy hh:mm:ss");
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

    return formattedDateTime;
}

bool sql_helper::ckeck_db_status()
{
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    if (db.open()) {
        qDebug() << "Connected to MySQL database!";
        return true;
    } else {
        qWarning() << "Failed to connect to MySQL database:" << db.lastError().text();
        return false;
    }
    if (db.isOpen()) {
        qDebug() << "MySQL server is active";
    } else {
        qDebug() << "MySQL server is inactive";
    }
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

}

void sql_helper::db_close()
{
    db.commit();
    db.close();
}
QStringList sql_helper::get_rtsp_url(const QList<add_devices> &add_devicesList)
{
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    QStringList deviceslist;
    for (const add_devices &device_obj : add_devices_list) {
        deviceslist<<device_obj.secondary_url;
        // return deviceslist;
    }
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

    return deviceslist; // Return blank if the server_name is not found

}

QStringList sql_helper::get_device_name_from_server_id(const QList<add_devices> &add_devicelist, const int &id)
{
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    QStringList device_name_list;
    for (const add_devices &add_devices : add_devices_list) {
        if (add_devices.server_id == id) {
            device_name_list<< add_devices.device_name;
            // return device_name_list;
        }

    }
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

    return device_name_list;
}

int sql_helper::getLPU_count(const QList<server> &serverList)
{
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    int count=0;
    for (const server &server : serverList) {
        if(!server.server_name.isEmpty()){
            count++;
        }
    }
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

    return count;

}

int sql_helper::getCamera_count(const QList<add_devices> &add_device_list)
{
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    int count=0;
    for (const add_devices &device : add_device_list) {
        if(!device.device_name.isEmpty()){
            count++;
        }
    }
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

    return count;
}
int sql_helper::get_vehicle_total_count()
{
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    if (db.open()) {
        qDebug() << "Connected to MySQL database!";
    } else {
        qWarning() << "Failed to connect to MySQL database:" << db.lastError().text();
    }
    QSqlQuery query;
    query.prepare("SELECT SrNo FROM anpr4");

    if (!query.exec()) {
        qDebug() << "Failed to execute select query from anpr4 table:" << query.lastError().text();
        qDebug()<<"==========="<<Q_FUNC_INFO;
        db.commit();
        db.close();
        // return;
    }
    int count=0;
    while(query.next()) {
        count++;
    }
    db.commit();
    db.close();
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

    return count;
}
int sql_helper::get_vehicle_todays_count()
{
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";
    if (db.open()) {
        qDebug() << "Connected to MySQL database!";
    } else {
        qWarning() << "Failed to connect to MySQL database:" << db.lastError().text();
    }
    // Get today's date
    QString today = QDate::currentDate().toString("yyyy-MM-d");
    qDebug()<<"====today====="<<today;
    QSqlQuery query;
    query.prepare("SELECT * FROM anpr4 WHERE DATE(datetime) = :date");
    query.bindValue(":date", today);
    if (!query.exec()) {
        qDebug() << "Failed to execute select query from anpr4 table:" << query.lastError().text();
        qDebug()<<"==============="<<Q_FUNC_INFO;
        db.commit();
        db.close();

        // return;
    }
    int count=0;
    while(query.next()) {
        count++;
    }
    db.commit();
    db.close();
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

    return count;
}

QMap<QString, int> sql_helper::get_vehicle_type_count()
{
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";
    if (db.open()) {
        qDebug() << "Connected to MySQL database!";
    } else {
        qWarning() << "Failed to connect to MySQL database:" << db.lastError().text();
        qDebug() << Q_FUNC_INFO;

    }
    // Execute SQL query to retrieve counts for each category
    QString queryselect="SELECT vehicleclass, COUNT(*) AS count FROM anpr4 GROUP BY vehicleclass";
    QSqlQuery query;
    query.prepare(queryselect);
    if (!query.exec()) {
        qDebug() << "Failed to execute select query" << query.lastError().text();
        qDebug() << Q_FUNC_INFO;
        qDebug()<<"Query is:===="<<queryselect;
        db.commit();
        db.close();

    }
    QMap<QString, int> vehicleCounts;
    // Process the query results
    while (query.next()) {
        QString vehicle = query.value("vehicleclass").toString();
        int count = query.value("count").toInt();
        vehicleCounts.insert(vehicle, count);
        qDebug() << "Vehicle:" << vehicle << "Count:" << count;
    }

    db.commit();
    db.close();
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

    return vehicleCounts;
}

QMap<QString, int> sql_helper::get_vehicle_type_count_todays()
{
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    Q_FUNC_INFO;
    if (db.open()) {
        qDebug() << "Connected to MySQL database!";
    } else {
        qWarning() << "Failed to connect to MySQL database:" << db.lastError().text();
        qDebug() << Q_FUNC_INFO;

    }
    // Get today's date
    QString today = QDate::currentDate().toString("yyyy-MM-d");
    qDebug()<<"====today====="<<today;


    QSqlQuery query;
    // Execute SQL query to retrieve counts for each category
    query.prepare("SELECT vehicleclass, COUNT(*) AS count FROM anpr4 WHERE DATE(datetime) = :date GROUP BY vehicleclass");
    query.bindValue(":date", today);

    if (!query.exec()) {
        qDebug() << "Failed to execute select query" << query.lastError().text();
        qDebug() << Q_FUNC_INFO;
        db.commit();
        db.close();

        // qDebug()<<"Query is:===="<<queryselect;
    }
    QMap<QString, int> vehicleCounts;
    // Process the query results
    while (query.next()) {
        QString vehicle = query.value("vehicleclass").toString();
        int count = query.value("count").toInt();
        vehicleCounts.insert(vehicle, count);
        qDebug() << "Vehicle:" << vehicle << "Count:" << count;
    }

    db.commit();
    db.close();
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

    return vehicleCounts;
}
QString sql_helper::set_vehicle_to_blacklist(QString vehicle_number)
{
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    if (db.open()) {
        qDebug() << "Connected to MySQL database!";
    } else {
        qWarning() << "Failed to connect to MySQL database:" << db.lastError().text();
        qDebug()<<Q_FUNC_INFO;
    }
    QSqlQuery query;
    query.prepare("SELECT ocrnumber FROM anpr4 WHERE ocrnumber="+vehicle_number+"");
    if (!query.exec()) {
        qDebug() << "Failed to execute select query from anpr4 table:" << query.lastError().text();
        qDebug()<<"==============="<<Q_FUNC_INFO;
        db.commit();
        db.close();

        // return;
    }
    QString ocr_number;
    while(query.next()) {
        ocr_number = query.value("ocrnumber").toString();
    }
    db.commit();
    db.close();
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

    return ocr_number;
}

void sql_helper:: Select_from_tblBlacklist_vehicle()
{
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    if (db.open()) {
        qDebug() << "Connected to MySQL database!";
    } else {
        qWarning() << "Failed to connect to MySQL database:" << db.lastError().text();
        qDebug()<<Q_FUNC_INFO;
    }
    QSqlQuery query;
    query.prepare("SELECT id,ocr_number FROM tblBlacklist_vehicle");
    if (!query.exec()) {
        qDebug() << "Failed to execute select query from tblBlacklist_vehicle table:" << query.lastError().text();
        qDebug()<<"==============="<<Q_FUNC_INFO;
        db.commit();
        db.close();

    }
    QString ocr_number;
    struct tblVehicle_blacklist vehicle_blacklist_obj;
    while(query.next()) {
        vehicle_blacklist_obj.id = query.value("id").toString();
        vehicle_blacklist_obj.ocr_number = query.value("ocr_number").toString();

        blacklist_Vehicle.append(vehicle_blacklist_obj);
    }
    db.commit();
    db.close();
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

}
void sql_helper::vehicle_blacklist_removeRecord(QList<tblVehicle_blacklist> &list, int id) {
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    for (int i = 0; i < list.size(); ++i) {
        if (list.at(i).id == QString::number(id)) {
            list.removeAt(i);
            // If you want to remove only the first occurrence, you can break here
            //break;
        }
    }
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

}
void sql_helper::select_blacklist_vehicle()
{
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    if (db.open()) {
        qDebug() << "Connected to MySQL database!";
    } else {
        qWarning() << "Failed to connect to MySQL database:" << db.lastError().text();
    }
    QSqlQuery query;
    query.prepare("SELECT anpr4.SrNo, anpr4.camname, anpr4.plateimgpath, anpr4.vehicleImagePath, anpr4.ocrnumber, anpr4.vehicleclass, anpr4.datetime "
                  "FROM anpr4 "
                  "INNER JOIN tblBlacklist_vehicle ON anpr4.ocrnumber = tblBlacklist_vehicle.ocr_number");

    if (!query.exec()) {
        qDebug() << "Failed to execute select query from anpr4 table:" << query.lastError().text();
        qDebug()<<Q_FUNC_INFO;
        db.commit();
        db.close();
        return;
    }
    struct blacklisted_v_for_groupbox_update data_obj;
    while(query.next()) {
        data_obj.SrNo = query.value("SrNo").toInt();
        data_obj.camname = query.value("camname").toString();
        data_obj.plateimgpath = query.value("plateimgpath").toString();
        data_obj.vehicleImagePath = query.value("vehicleImagePath").toString();
        data_obj.ocrnumber = query.value("ocrnumber").toString();

        data_obj.vehicleclass = query.value("vehicleclass").toString();
        QString date = query.value("datetime").toString();
        data_obj.datetime = convertTimestamp(date);

        blacklisted_v_for_groupbox_update_list.append(data_obj);
    }

    db.commit();
    db.close();
    emit signal_to_check_ocr_number();
    emit signal_to_update_groupbox_update();
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

}
void sql_helper::check_ocr_number()
{
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";

    global_ocrnumber.clear(); // Clear the list before accumulating new entries

    for (const auto &blacklist_vehicle : blacklisted_v_for_groupbox_update_list) {
        global_ocrnumber << blacklist_vehicle.ocrnumber; // Add matching ocrnumber to the list
    }
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

}

bool sql_helper::check_ocr_number_for_anpr4(QString ocr_number)
{
    qDebug()<<"========"<<Q_FUNC_INFO<<"========STRAT";
    for (const QString &ocrnumber : global_ocrnumber) {
        if (ocrnumber == ocr_number) {
            return true;
        }
    }
    qDebug()<<"========"<<Q_FUNC_INFO<<"========END";

    return false;
}


// database.h
#ifndef DATABASE_H
#define DATABASE_H
#include <QWidget>
#include <QDebug>
// #include <bsoncxx/builder/stream/document.hpp>
// #include <bsoncxx/json.hpp>
// #include <mongocxx/client.hpp>
// #include <mongocxx/instance.hpp>
#include <filesystem> // Include filesystem header for file operations



#include <string>
// #include <mongocxx/database.hpp>

class Database {
public:
    Database();
    bool isConnected() const;
    bool verifyUser(const std::string &name, const std::string &password);

private:
    // mongocxx::database db;
};

#endif // DATABASE_H

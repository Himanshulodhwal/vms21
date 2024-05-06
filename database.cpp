#include "database.h"
#include <iostream>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include "mongodb_instance.h"

Database::Database() {
    try {
        // Initialize MongoDB client
        mongocxx::uri uri("mongodb://localhost:27017/");
        mongocxx::client client(uri);
        db = client["Sparsh"]; // Replace with your MongoDB database name
        std::cout << "MongoDB connection established successfully!" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error connecting to MongoDB: " << e.what() << std::endl;
    }
}

bool Database::isConnected() const {
    return static_cast<bool>(db);
}

bool Database::verifyUser(const std::string &name, const std::string &password) {
    try {
        auto collection = db["users"];

        bsoncxx::builder::stream::document document{};
        document << "name" << bsoncxx::types::b_utf8{name}
                 << "password" << bsoncxx::types::b_utf8{password};

        auto cursor = collection.find(document.view());

        // Iterate directly over the cursor
        for (auto&& doc : cursor) {
            try {
                bsoncxx::document::view view = doc;

                auto nameElement = view["name"];
                auto passwordElement = view["password"];

                if (!nameElement || !passwordElement) {
                    // Skip this document if 'name' or 'password' fields are missing
                    continue;
                }

                std::string storedName, storedPassword;

                if (nameElement.type() == bsoncxx::type::k_utf8 &&
                    passwordElement.type() == bsoncxx::type::k_utf8) {
                    storedName = nameElement.get_utf8().value.to_string();
                    storedPassword = passwordElement.get_utf8().value.to_string();
                } else {
                    // Handle type mismatch or missing values here
                    continue;
                }

                if (name == storedName && password == storedPassword) {
                    std::cout << "User verified!" << std::endl;
                    return true;
                }
            } catch (const std::exception& e) {
                std::cerr << "Error processing document: " << e.what() << std::endl;
                // Handle the error gracefully or log it for debugging
            }
        }

        // No matching user found or invalid credentials
        std::cout << "No matching user found or invalid credentials!" << std::endl;
        return false;


    } catch (const std::exception &e) {
        std::cerr << "Error verifying user: " << e.what() << std::endl;
        std::cerr << "Name: " << name << ", Password: " << password << std::endl;
        return false;
    }
}


#include "login1.h"
#include "ui_login1.h"
// #include "mainwindow.h"
// #include "signup.h"
// #include "ui_signup.h"
// #include "database.h"
// #include <QRegExpValidator>
#include <QMessageBox>
#include <QDebug>
#include <QSettings>

#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "QtSql/QSqlError"
// #include <QRegExp>
// #include <mongocxx/client.hpp>
// #include <mongocxx/uri.hpp>
// #include <bsoncxx/builder/stream/document.hpp>
login1::login1(QWidget *parent) : QDialog(parent), ui(new Ui::login1) {
    ui->setupUi(this);
    setWindowTitle("Sparsh");
    setWindowIcon(QIcon(":/new/prefix1/Sparsh-Logo1.png"));

    // Load and set the background image
    QPixmap backgroundImage(":/login.png");
    ui->backgroundLabel->setPixmap(backgroundImage);
    // Set the label's geometry to cover the entire login page
    ui->backgroundLabel->setScaledContents(true);
    ui->backgroundLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->backgroundLabel->setGeometry(0, 0, this->width(), this->height());
    ui->backgroundLabel->lower();
    ui->pushButton->setStyleSheet("background-color:#a3a3a3"); // Replace #a3a3a3 with your desired color code

    ui->lineEditPassword->setEchoMode(QLineEdit::Password);
    ui->lineEditName->clear();
    ui->lineEditPassword->clear();
    ui->lineEditName->setPlaceholderText("Enter Name");
    ui->lineEditPassword->setPlaceholderText("Enter Password");
    // Set geometry for line edits
    ui->lineEditName->setGeometry(310, 193, 220, 35);
    ui->lineEditPassword->setGeometry(310, 282, 220, 35);
    ui->lineEditName->clear();
    ui->lineEditPassword->clear();
    // QRegExp regex("^[a-zA-Z]*$");
    // QValidator *validator = new QRegExpValidator(regex, this);
    // ui->lineEditName->setValidator(validator);
    // messageBox = new QMessageBox(this);
    // Customize the message box if needed
    //->setText("Your message here");

}

login1::~login1() {
    delete ui;
    hideMessageBox();  // Ensure any displayed QMessageBox is hidden or closed
}

void login1::on_checkBox_stateChanged(int state) {
    if (state == Qt::Checked) {
        ui->lineEditPassword->setEchoMode(QLineEdit::Normal);
    } else {
        ui->lineEditPassword->setEchoMode(QLineEdit::Password);
    }
}
void login1::on_pushButton_clicked() {
    // // Establish a connection to MongoDB
    // mongocxx::uri uri("mongodb://localhost:27017");
    // mongocxx::client client(uri);
    // if (!client) {
    //     qDebug() << "Failed to connect to MongoDB";
    //     return;
    // } else {
    //     qDebug() << "Connected to MongoDB";
    // }

    // // Access the "Sparsh" database and "user" collection
    // mongocxx::database db = client["Sparsh"];
    // mongocxx::collection collection = db["users"];

    // // Get username and password from UI
    // QString username = ui->lineEditName->text().trimmed();
    // QString password = ui->lineEditPassword->text().trimmed();

    // // Query MongoDB to find the user
    // bsoncxx::builder::stream::document filter_builder;
    // filter_builder << "name" << username.toStdString();
    // auto filter = filter_builder.view();

    // // Search for the user in the collection
    // auto result = collection.find_one(filter);

    // if (result) {
    //     // User found, check the password
    //     bsoncxx::document::view user_doc = result->view();
    //     std::string stored_password = user_doc["password"].get_utf8().value.to_string();

    //     // Trim whitespace and convert to consistent case for comparison
    //     QString stored_password_trimmed = QString::fromStdString(stored_password).trimmed();
    //     QString entered_password_trimmed = password.trimmed();

    //     if (entered_password_trimmed == stored_password_trimmed) {
    //         // Passwords match, proceed to main window
    //         qDebug() << "Authentication successful";
    //         if (ui->checkBox_2->isChecked()) {
    //             QSettings settings("MyCompany", "MyApp");
    //             settings.setValue("RememberMeChecked", true);
    //             settings.setValue("SavedUsername", ui->lineEditName->text());
    //             settings.setValue("SavedPassword", ui->lineEditPassword->text());
    //         }

    //int row=0;

    // QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    // db.setDatabaseName("DRIVER=/home/sunny/Downloads/mysqlconnect/lib/libmyodbc8a.so;SERVER=localhost;DATABASE=sparsh_ccc;UID=root;PWD=sparsh#24");
    // if (db.open()) {
    //     qDebug() << "Connected to MySQL database!";
    //     // Proceed with database operations
    // } else {
    //     qWarning() << "Failed to connect to MySQL database:" << db.lastError().text();
    // }
    // QSqlQuery query;
    // query.prepare("SELECT * FROM tbldevices");

    // if (!query.exec()) {
    //     qDebug() << "Failed to execute query:" << query.lastError().text();
    //     return;
    // }
    // Open the main window
    this->hide();
    // MainWindow* mainWindow = new MainWindow();
    // mainWindow->show();
    // mainWindow->activateWindow();
    QWidget centralWidget;
    control_center_obj = new Control_center(&centralWidget);
    control_center_obj->show();
    //     } else {
    //         qDebug() << "Incorrect password";
    //         QMessageBox::critical(this, "Login Failed", "Incorrect username or password.");
    //     }
    // } else {
    //     qDebug() << "User not found";
    //     QMessageBox::critical(this, "Login Failed", "Incorrect username or password.");
    // }

    // // Check and set "Remember Me" feature if enabled
    // QSettings settings("Sparsh", "VMS");
    // if (settings.value("RememberMeChecked").toBool()) {
    //     ui->checkBox_2->setChecked(true);
    //     ui->lineEditName->setText(settings.value("SavedUsername").toString());
    //     ui->lineEditPassword->setText(settings.value("SavedPassword").toString());
    // }
}

void login1::on_checkBox_2_stateChanged(int state) {
    if (state == Qt::Checked) {
        // When the "Remember Me" checkbox is checked, prompt the user for confirmation
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmation", "Do you want to save your credentials?",
                                      QMessageBox::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes) {
            // If the user confirms, save the credentials
            QSettings settings("Sparsh", "VMS");

            settings.setValue("RememberMeChecked", true);
            settings.setValue("SavedUsername", ui->lineEditName->text());
            settings.setValue("SavedPassword", ui->lineEditPassword->text());
        } else {
            // If the user cancels, uncheck the "Remember Me" checkbox
            ui->checkBox_2->setChecked(false);
        }
    } else {
        // If the "Remember Me" checkbox is unchecked, clear any saved credentials
        QSettings settings("Sparsh", "VMS");

        settings.remove("RememberMeChecked");
        settings.remove("SavedUsername");
        settings.remove("SavedPassword");
    }
}


void login1::hideMessageBox() {
    // Close or hide a QMessageBox if it's displayed
    // For example, assuming you have a QMessageBox object named messageBox

    // Check if the message box is currently visible
    if (messageBox && messageBox->isVisible()) {
        // Hide or close the message box
        messageBox->hide(); // or messageBox->close();
        delete messageBox;  // Delete the QMessageBox instance
        messageBox = nullptr;  // Reset the pointer to nullptr
    }
}

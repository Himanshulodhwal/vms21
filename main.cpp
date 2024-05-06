 // #include "mainwindow.h"
#include "login1.h"
#include <QApplication>
#include <QDateTime>
#include <QDebug>
#include <QSplashScreen>
// #include "control_center.h"
// #include "sql_helper.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Set up a splash screen
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/images/splash.png")); // Replace with your splash image
    splash->show();

    // Simulate some initialization work
    // Perform any necessary pre-loading tasks here
    QApplication::setStartDragDistance(20);
    // Close the splash screen after a certain time

    QTimer::singleShot(2500, splash, &QWidget::close);

    // // Create an instance of the login window
    // login1 loginDialog;
    // loginDialog.show();
    Control_center w;
    w.show();
    return a.exec();
        // int result = a.exec();

    // // Cleanup: Delete the splash screen instance
    delete splash;

    // return result;
}


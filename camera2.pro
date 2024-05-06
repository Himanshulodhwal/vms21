# Configuration for the Qt project

# Qt modules
QT += core gui widgets sql multimediawidgets
QT += widgets concurrent printsupport charts quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# C++ standard
CONFIG += c++17

# Include paths
INCLUDEPATH += library/include

# Library paths and dependencies
LIBS += -L$$PWD/library/lib -lVLCQtCore -lVLCQtWidgets

# Source files
SOURCES += \
    DraggableButton.cpp \
    blacklist_vehicle_page.cpp \
    carddialog.cpp \
    cardwidget.cpp \
    clickable_report_label.cpp \
    control_center.cpp \
    eventfilter.cpp \
    handel_thread.cpp \
    login1.cpp \
    main.cpp \
    mainwindow.cpp \
    overlay_widget.cpp \
    report_class.cpp \
    sql_helper.cpp

# Header files
HEADERS += \
    DraggableButton.h \
    blacklist_vehicle_page.h \
    carddialog.h \
    cardwidget.h \
    clickable_report_label.h \
    control_center.h \
    eventfilter.h \
    handel_thread.h \
    login1.h \
    mainwindow.h \
    overlay_widget.h \
    report_class.h \
    sql_helper.h

# UI forms
FORMS += \
    blacklist_vehicle_page.ui \
    carddialog.ui \
    cardwidget.ui \
    control_center.ui \
    login1.ui \
    mainwindow.ui \
    overlay_widget.ui \
    report_class.ui

# Deployment rules
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Resources
RESOURCES += \
    rs.qrc



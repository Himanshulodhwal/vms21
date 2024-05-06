// import QtQuick 2.15

// Item {

// }

import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "QML Inside QQuickWidget"
    background: "transparent"
    Rectangle {
        width: 100
        height: 50
        color: "lightblue"
        anchors.centerIn: parent

        Text {
            text: "Hello from QML!"
            anchors.centerIn: parent
            font.pixelSize: 16
        }
    }
}

import QtQuick
import FluentUIZ 1.0
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello Qt6 TreeView")

    FluTreeView {
        anchors.fill: parent
        anchors.margins: 10
    }
}

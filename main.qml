import QtQuick 2.15
import QtQuick.Window 2.15

Item {
    width: 640
    height: 480
    visible: true
    Rectangle{
        width: 50
        height: 50
        color: "red"
        MouseArea{
            anchors.fill: parent
            onClicked: {
                view.setvalue(100)
            }
        }
    }

    Text {
        id: name
        anchors.centerIn: parent
        text: view.value
    }
}

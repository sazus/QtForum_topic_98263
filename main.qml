import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.12

Window {
  visible: true
  width: 150
  height: 100
  title: qsTr("test")

  Rectangle {
    objectName: "colorBox"  /// 1st colorBox object name

    width: parent.width
    height: parent.height
    anchors.fill: parent

    color: "blue"
  }

  ToolBar {
    RowLayout {
        anchors.fill: parent

        ToolButton {
            text: "xx"

            Rectangle {
              objectName: "colorBox"  /// 2nd colorBox object name

              width: parent.width
              height: parent.height
              anchors.fill: parent

              color: "lightblue"
            }
        }
    }
  }
}

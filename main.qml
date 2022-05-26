import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs
import ChemView

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: "Chemical Structure Viewer"

    menuBar: MenuBar {
        Menu {
            title: "&File"
            Action {
                text: "&Open"
                onTriggered: fileDialog.open()
            }
        }

        Menu {
            title: "&View"
            Menu {
                title: "Camera"
                Action {
                    text: "Perpective"
                    onTriggered: chemView.currentCamera = "perspective"
                }
            }
        }
    }

    ChemView {
        id: chemView
        anchors.fill: parent
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        onAccepted: chemView.filename = fileDialog.selectedFile
    }
}

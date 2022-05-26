import QtQuick
import QtQuick.Controls
import QtQuick3D
import ChemView

Item {
    property string filename: ""
    property string currentCamera: "perspective"

    Qt3DViewer {
        id: chemView
        anchors.fill: parent

        StructureNode {
            id: structureNode
            structure: structure
        }
    }

    Structure {
        id: structure
    }

    Reader {
        id: reader
        structure: structureNode.structure
    }

    onCurrentCameraChanged: {
        if (currentCamera == "perspective")
            chemView.camera = chemView.perspectiveCamera
        else if (currentCamera == "orthographic")
            chemView.camera = chemView.orthographicCamera
    }

    onFilenameChanged: {
        reader.readUrl(filename)
        if (!reader.ok) {
            console.log("error when reading file")
            return;
        }
        structureNode.update()
    }
}

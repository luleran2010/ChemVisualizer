import QtQuick
import QtQuick3D
import QtQuick.Shapes

Node {
    id: root

    property vector3d startPos: Qt.vector3d(0, 0, 0)
    property vector3d endPos: Qt.vector3d(1, 0, 0)

    position: startPos

    function length() {
        return endPos.minus(startPos).length()
    }

    Node {
        Shape {
            height: 4
            width: length()
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            ShapePath {
                strokeWidth: 4
                strokeColor: "black"
                startX: 0; startY: 0
                PathLine { x: length(); y: 0 }
            }
        }
    }
    Node {
        rotation: Quaternion.fromAxisAndAngle(1, 0, 0, 90)
        Shape {
            height: 4
            width: length()
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            ShapePath {
                strokeWidth: 4
                strokeColor: "black"
                startX: 0; startY: 0
                PathLine { x: length(); y: 0 }
            }
        }
    }

    Component.onCompleted: {
        var initDir = Qt.vector3d(1, 0, 0)
        var destDir = endPos.minus(startPos).normalized()
        var normal = initDir.crossProduct(destDir)
        var degree = Math.acos(initDir.dotProduct(destDir))*180/Math.PI
        rotate(degree, normal, Qt.SceneSpace)
    }
}

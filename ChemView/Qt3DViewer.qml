import QtQuick
import QtQuick.Controls
import QtQuick3D
import QtQuick3D.Helpers


View3D {
    id: view3D
    camera: perspectiveCamera

    property alias perspectiveCamera: perspectiveCamera

    property real lastPosX: 0
    property real lastPosY: 0

    SceneEnvironment {
        id: sceneEnvironment
        antialiasingQuality: SceneEnvironment.High
        antialiasingMode: SceneEnvironment.MSAA
    }

    AxisHelper {}

    Node {
        id: cameraRoot
        position: Qt.vector3d(0, 0, 0)
        DirectionalLight {
            id: directionalLight
        }

        Node {
            id: cameraDir
            position: Qt.vector3d(0, 0, 350)
            PerspectiveCamera {
                id: perspectiveCamera
            }
        }
    }
    environment: sceneEnvironment

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        acceptedButtons: Qt.AllButtons

        onPressed:
            (mouse) => {
                if (mouse.buttons & Qt.LeftButton) {
                    var pickResult = view3D.pick(mouse.x, mouse.y)
                    console.log(pickResult)
                    if (pickResult.objectHit !== null) {
                        var objectHit = pickResult.objectHit
                        console.log(objectHit.objectName)
                        objectHit.isPicked = !objectHit.isPicked
                        if (objectHit.isPicked) objectHit.materials = materialList.selectedAtomMaterial
                        else objectHit.materials = materialList.atomMaterial
                    }
                } else {
                    lastPosX = mouse.x
                    lastPosY = mouse.y
                }
            }
        onPositionChanged:
            (mouse) => {
                var dx = mouse.x - lastPosX
                var dy = mouse.y - lastPosY

                if (mouse.buttons & Qt.RightButton) {
//                    console.log(cameraRoot.up)
//                    var upsideDown = cameraRoot.up.y < 0 ? -1 : 1;
                    cameraRoot.rotate(-dx*0.2, cameraDir.up, Qt.SceneSpace)
                    cameraRoot.rotate(-dy*0.2, cameraDir.right, Qt.SceneSpace)
                } else if (mouse.buttons & Qt.MiddleButton) {
                    cameraRoot.position = cameraRoot.position.plus(cameraDir.right.times(-dx)).plus(cameraDir.up.times(dy))
                }
                lastPosX = mouse.x
                lastPosY = mouse.y
            }
        onWheel:
            (wheel) => {
                var numDeg = wheel.angleDelta
                if (numDeg === null) return
                var factor = 150
                if (numDeg.y < 0) factor = -factor
                cameraDir.z -= factor
            }
    }
}

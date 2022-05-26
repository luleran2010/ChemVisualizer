import QtQuick
import QtQuick3D

Item {
    property alias atom: atom
    DefaultMaterial {
        id: atom
        diffuseColor: "blue"
    }

    DefaultMaterial {
        id: selected
        diffuseColor: "red"
    }
}

import QtQuick
import QtQuick3D
import QtQuick.Shapes
import ChemView

Node {
    id: root
    property alias atomMaterials: atomMaterials
    property Structure structure
    AtomMaterials {
        id: atomMaterials
    }

    Component {
        id: atomComponent
        Model {
            source: "#Sphere"
            materials: atomMaterials.atom
        }
    }

    Component {
        id: latticeComponent
        LatticeNode {
        }
    }

    Node {
        id: atomsNode
    }

    function update() {
        for (var i = 0; i < atomsNode.children.length; ++i)
            atomsNode.children[i].destroy()
        for (i = 0; i < structure.atoms.length; ++i) {
            var atom = atomComponent.createObject(atomsNode, {"position": structure.atoms[i].position.times(100)})
        }
        var latticeNode = latticeComponent.createObject(root, {"structure": structure})
    }
}

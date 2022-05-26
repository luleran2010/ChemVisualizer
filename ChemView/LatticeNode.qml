import QtQuick
import QtQuick3D
import ChemView

Node {
    id: root

    property Structure structure
    property vector3d a: structure.a.times(100)
    property vector3d b: structure.b.times(100)
    property vector3d c: structure.c.times(100)

    Qt3DLine { id: vectorA00; startPos: "0,0,0"  ; endPos: a                 }
    Qt3DLine { id: vectorA01; startPos: b        ; endPos: a.plus(b)         }
    Qt3DLine { id: vectorA10; startPos: c        ; endPos: a.plus(c)         }
    Qt3DLine { id: vectorA11; startPos: b.plus(c); endPos: a.plus(b).plus(c) }


    Qt3DLine { id: vectorB00; startPos: "0,0,0"  ; endPos: b                 }
    Qt3DLine { id: vectorB01; startPos: c        ; endPos: b.plus(c)         }
    Qt3DLine { id: vectorB10; startPos: a        ; endPos: b.plus(a)         }
    Qt3DLine { id: vectorB11; startPos: c.plus(a); endPos: b.plus(c).plus(a) }


    Qt3DLine { id: vectorC00; startPos: "0,0,0"  ; endPos: c                 }
    Qt3DLine { id: vectorC01; startPos: a        ; endPos: c.plus(a)         }
    Qt3DLine { id: vectorC10; startPos: b        ; endPos: c.plus(b)         }
    Qt3DLine { id: vectorC11; startPos: a.plus(b); endPos: c.plus(a).plus(b) }
}

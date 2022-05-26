find_package(Qt6 6.2 COMPONENTS Qml Quick Quick3D REQUIRED)
add_subdirectory(pybind11)

qt_add_qml_module(ChemView
    URI "ChemView"
    VERSION 1.0
    PLUGIN_TARGET ChemView
    SOURCES
        atom.h atom.cpp
        structure.h structure.cpp
        reader.h reader.cpp
    QML_FILES
        AtomMaterials.qml
        LatticeNode.qml
        StructureNode.qml
        Qt3DViewer.qml
        Qt3DLine.qml
        ChemView.qml
)

target_link_libraries(ChemView
    PRIVATE Qt6::Qml Qt6::Quick Qt6::Quick3D pybind11::embed)

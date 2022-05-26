#include <pybind11/embed.h>
#include <pybind11/stl.h>
#include <QFile>
#include <string>
#include "reader.h"

namespace py = pybind11;
using namespace py::literals;

Reader::Reader(QObject *parent)
    : QObject{parent}, m_filename(), m_structure(nullptr), m_ok(true)
{

}

const QString &Reader::filename() const
{
    return m_filename;
}

void Reader::setFilename(const QString &newFilename)
{
    if (m_filename == newFilename)
        return;
    m_filename = newFilename;
    emit filenameChanged();
}

Structure *Reader::structure() const
{
    return m_structure;
}

void Reader::setStructure(Structure *newStructure)
{
    if (m_structure == newStructure)
        return;
    m_structure = newStructure;
    emit structureChanged();
}

void Reader::read(const QString &filename)
{
    setFilename(filename);

    m_ok = false;
    if (filename.isEmpty()) {
        m_ok = true;
        return;
    }
    if (!QFile::exists(filename))
        return;

    py::scoped_interpreter guard{};
    py::module_ ase_io = py::module_::import("ase.io");
    py::object atoms = ase_io.attr("read")(filename.toStdString());

    py::list cell = atoms.attr("get_cell")();
    for (qsizetype i = 0; i < 3; ++i) {
        auto vect = cell[i].cast<std::vector<float>>();
        for (qsizetype j = 0; j < 3; ++j) {
            m_structure->m_cell(i,j) = vect[j];
        }
    }

    py::list symbols = atoms.attr("get_chemical_symbols")();
    py::list positions = atoms.attr("get_positions")();

    m_structure->m_atoms.clear();
    for (qsizetype i = 0; i < py::len(atoms); ++i) {
        auto symbol = symbols[i].cast<std::string>();
        auto position = positions[i].cast<std::vector<float>>();
        Atom *atom = new Atom{QString::fromStdString(symbol), position[0], position[1], position[2]};
        m_structure->m_atoms.append(atom);
    }
    m_ok = true;
}

void Reader::readUrl(const QUrl &url)
{
    read(url.toLocalFile());
}


bool Reader::ok() const
{
    return m_ok;
}

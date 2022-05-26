#include "structure.h"

Structure::Structure(QObject *parent)
    : QObject{parent}, m_cell(), m_atoms()
{

}

const QMatrix3x3 &Structure::cell() const
{
    return m_cell;
}

void Structure::setCell(const QMatrix3x3 &newCell)
{
    if (m_cell == newCell)
        return;
    m_cell = newCell;
    emit cellChanged();
}

QVector3D Structure::vector(int index) const
{
    return QVector3D(m_cell(index,0), m_cell(index,1), m_cell(index,2));
}

void Structure::setVector(int index, const QVector3D &newVector)
{
    if (QVector3D(m_cell(index,0), m_cell(index,1), m_cell(index,2)) == newVector)
        return;
    m_cell(index,0) = newVector.x();
    m_cell(index,1) = newVector.y();
    m_cell(index,2) = newVector.z();

    emit cellChanged();
}

QQmlListProperty<Atom> Structure::atoms()
{
    return QQmlListProperty<Atom>{this, &m_atoms};
}

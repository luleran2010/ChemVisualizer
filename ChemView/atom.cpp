#include "atom.h"

Atom::Atom(QObject *parent)
    : QObject{parent}
{

}

Atom::Atom(const QString &symbol, const QVector3D &position, QObject *parent)
    : QObject{parent}, m_symbol{symbol}, m_position{position}
{

}

Atom::Atom(const QString &symbol, float x, float y, float z, QObject *parent)
    : QObject{parent}, m_symbol{symbol}, m_position{x, y, z}
{

}

const QString &Atom::symbol() const
{
    return m_symbol;
}

void Atom::setSymbol(const QString &newSymbol)
{
    if (m_symbol == newSymbol)
        return;
    m_symbol = newSymbol;
    emit symbolChanged();
}

const QVector3D &Atom::position() const
{
    return m_position;
}

void Atom::setPosition(const QVector3D &newPosition)
{
    if (m_position == newPosition)
        return;
    m_position = newPosition;
    emit positionChanged();
}

float Atom::x() const
{
    return m_position.x();
}

void Atom::setX(float newX)
{
    if (m_position.x() == newX)
        return;
    m_position.setX(newX);
    emit positionChanged();
}

float Atom::y() const
{
    return m_position.y();
}

void Atom::setY(float newY)
{
    if (m_position.y() == newY)
        return;
    m_position.setY(newY);
    emit positionChanged();
}

float Atom::z() const
{
    return m_position.z();
}

void Atom::setZ(float newZ)
{
    if (m_position.z() == newZ)
        return;
    m_position.setZ(newZ);
    emit positionChanged();
}

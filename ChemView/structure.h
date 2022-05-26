#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <QObject>
#include <QtQml/qqml.h>
#include <QVector3D>
#include <QGenericMatrix>
#include <QVector3D>
#include "atom.h"

class Reader;

class Structure : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QMatrix3x3 cell READ cell WRITE setCell NOTIFY cellChanged)
    Q_PROPERTY(QVector3D a READ a WRITE setA NOTIFY cellChanged)
    Q_PROPERTY(QVector3D b READ b WRITE setB NOTIFY cellChanged)
    Q_PROPERTY(QVector3D c READ c WRITE setC NOTIFY cellChanged)

    Q_PROPERTY(QQmlListProperty<Atom> atoms READ atoms)

    friend Reader;
public:
    explicit Structure(QObject *parent = nullptr);
    Structure(QList<Atom *> const &atoms, QObject *parent=nullptr);

    const QMatrix3x3 &cell() const;
    void setCell(const QMatrix3x3 &newCell);
    Q_INVOKABLE QVector3D vector(int index) const;
    Q_INVOKABLE void setVector(int index, const QVector3D &newVector);
    QVector3D a() const { return vector(0); }
    void setA(const QVector3D &newA) { setVector(0, newA); }
    QVector3D b() const {return vector(1); }
    void setB(const QVector3D &newB) { setVector(1, newB); }
    QVector3D c() const { return vector(2); }
    void setC(const QVector3D &newC) { setVector(2, newC); }

    QQmlListProperty<Atom> atoms();
signals:
    void cellChanged();

private:
    QMatrix3x3 m_cell;
    QList<Atom *> m_atoms;
};

#endif // STRUCTURE_H

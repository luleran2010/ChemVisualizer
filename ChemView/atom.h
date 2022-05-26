#ifndef ATOM_H
#define ATOM_H

#include <QtQml/qqml.h>
#include <QObject>
#include <QVector3D>

class Atom : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString symbol READ symbol WRITE setSymbol NOTIFY symbolChanged)
    Q_PROPERTY(QVector3D position READ position WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(float x READ x WRITE setX NOTIFY positionChanged)
    Q_PROPERTY(float y READ y WRITE setY NOTIFY positionChanged)
    Q_PROPERTY(float z READ z WRITE setZ NOTIFY positionChanged)
public:
    explicit Atom(QObject *parent = nullptr);
    Atom(QString const &symbol, QVector3D const &position, QObject *parent = nullptr);
    Atom(QString const &symbol, float x, float y, float z, QObject *parent = nullptr);

    const QString &symbol() const;
    void setSymbol(const QString &newSymbol);

    const QVector3D &position() const;
    void setPosition(const QVector3D &newPosition);

    float x() const;
    void setX(float newX);
    float y() const;
    void setY(float newY);
    float z() const;
    void setZ(float newZ);

signals:

    void symbolChanged();
    void positionChanged();

private:
    QString m_symbol;
    QVector3D m_position;
};

#endif // ATOM_H

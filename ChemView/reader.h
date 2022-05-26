#ifndef READER_H
#define READER_H

#include <QObject>
#include <QtQml/qqml.h>
#include "structure.h"

class Reader : public QObject
{
    Q_OBJECT
    QML_ELEMENT

    Q_PROPERTY(QString filename READ filename WRITE setFilename NOTIFY filenameChanged)
    Q_PROPERTY(Structure * structure READ structure WRITE setStructure NOTIFY structureChanged)
    Q_PROPERTY(bool ok READ ok NOTIFY okChanged)
public:
    explicit Reader(QObject *parent = nullptr);

    const QString &filename() const;
    void setFilename(const QString &newFilename);

    Structure *structure() const;

    Q_INVOKABLE void read(QString const &filename = QString());
    Q_INVOKABLE void readUrl(QUrl const &url);
    bool ok() const;

    void setStructure(Structure *newStructure);

signals:

    void filenameChanged();
    void structureChanged();
    void okChanged();

private:
    QString m_filename;
    Structure *m_structure;
    bool m_ok;
};

#endif // READER_H

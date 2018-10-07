#ifndef JSONDATA_H
#define JSONDATA_H

#include <QObject>
#include <QFile>

class jsonData : public QObject
{
    Q_OBJECT
public:
    explicit jsonData(QObject *parent = nullptr);

signals:

public slots:
    void data();

private:

    QFile *file;





};

#endif // JSONDATA_H

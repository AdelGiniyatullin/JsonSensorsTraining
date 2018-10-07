#include "jsondata.h"
#include <QDir>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QDebug>


jsonData::jsonData(QObject *parent) : QObject(parent)
{
    file = new QFile(this);
    QDir::setCurrent("/users/adelginiatullin/");
    file->setFileName("coefficients.json");
    file->open(QIODevice::ReadOnly | QIODevice::Text);
   // QString val = file->readAll();
    file->close();
}

void jsonData::data()
{
    QString val = file->readAll();
    QJsonDocument d = QJsonDocument::fromJson(file->readAll());
    QJsonObject obj = d.object();
    QJsonValue value = obj.value("sensors");
    if (value.isArray())
    {
        QJsonArray vall = value.toArray();
        for (int i=0; i<vall.count(); i++)
        {
          QJsonObject object  = vall.at(i).toObject();
          QDebug()<<object.value["sensorNumber"].toString();
        }
    }



}



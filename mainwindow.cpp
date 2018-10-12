#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QDebug>
#include <QTextStream>
#include <QList>
#include <QFileDialog>
#include <QColor>
#include <QPalette>
#include <QSettings>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    file = new QFile(this);
    QSettings setting ("MyApp","TheWay");
    setting.beginGroup("TheWayToFile");
    file->setFileName(setting.value("Dir").toString());
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "FILE NOT OPEN";
    }

    if (file->isOpen())
    {
        QPalette palette = ui->pushbutton_choose->palette();
        palette.setColor(ui->pushbutton_choose->backgroundRole(), Qt::green);
        palette.setColor(ui->pushbutton_choose->foregroundRole(), Qt::green);
        ui->pushbutton_choose->setAutoFillBackground(true);
        ui->pushbutton_choose->setPalette(palette);

    }
    else
    {
        QPalette palette = ui->pushbutton_choose->palette();
        palette.setColor(ui->pushbutton_choose->backgroundRole(), Qt::red);
        palette.setColor(ui->pushbutton_choose->foregroundRole(), Qt::red);
        ui->pushbutton_choose->setAutoFillBackground(true);
        ui->pushbutton_choose->setPalette(palette);
    }

    document = QJsonDocument::fromJson(file->readAll());
    QJsonObject obj = document.object();
    QJsonValue value = obj.value("sensors");
    QJsonArray vall = value.toArray();
    for (int i=0; i<vall.count(); i++)
    {
        QJsonObject object  = vall.at(i).toObject();
        Sensor tmpSensor;
        tmpSensor.sensorNumber = object.value("sensorNumber").toDouble();
        tmpSensor.name = object.value("name").toString();
        tmpSensor.pressureChannel = object.value("pressureChannel").toDouble();
        tmpSensor.temperatureChannel = object.value("temperatureChannel").toDouble();
        tmpSensor.A = object.value("A").toArray();
        tmpSensor.Ft0 = object.value("Ft0").toInt();
        tmpSensor.Fp0 = object.value("Fp0").toInt();
        sensorsData.append(tmpSensor);
        ui->listWidget->addItem((QString::number(object.value("sensorNumber").toDouble())));
    }
    file->close();
    setting.endGroup();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    for (int i=0; i<sensorsData.count(); i++)
                {
                  if ((QString::number(sensorsData[i].sensorNumber)) == ui->listWidget->currentItem()->text()){
                      ui->SensorNumber->setText(QString::number(sensorsData[i].sensorNumber));
                      ui->Name->setText(sensorsData[i].name);
                      ui->pressureChanel->setText(QString::number(sensorsData[i].pressureChannel));
                      ui->temperatureChannel->setText(QString::number(sensorsData[i].temperatureChannel));
                      ui->A0->setText(QString::number(sensorsData[i].A.at(0).toDouble()));
                      ui->A1->setText(QString::number(sensorsData[i].A.at(1).toDouble()));
                      ui->A2->setText(QString::number(sensorsData[i].A.at(2).toDouble()));
                      ui->A3->setText(QString::number(sensorsData[i].A.at(3).toDouble()));
                      ui->A4->setText(QString::number(sensorsData[i].A.at(4).toDouble()));
                      ui->A5->setText(QString::number(sensorsData[i].A.at(5).toDouble()));
                      ui->Ft0->setText(QString::number(sensorsData[i].Ft0));
                      ui->Fp0->setText(QString::number(sensorsData[i].Fp0));
                 }
                  else if ("0" == ui->listWidget->currentItem()->text())
                  {
                                         ui->SensorNumber->setText("0");
                                         ui->Name->setText("");
                                         ui->pressureChanel->setText("");
                                         ui->temperatureChannel->setText("");
                                         ui->A0->setText("");
                                         ui->A1->setText("");
                                         ui->A2->setText("");
                                         ui->A3->setText("");
                                         ui->A4->setText("");
                                         ui->A5->setText("");
                                         ui->Ft0->setText("");
                                         ui->Fp0->setText("");
                  }


               }


}

void MainWindow::on_Pushbutton_add_clicked()
{
    ui->listWidget->addItem("0");
    Sensor tmpsensor;
    tmpsensor.sensorNumber = 0;
    tmpsensor.name = "default";
    tmpsensor.pressureChannel = 0;
    tmpsensor.temperatureChannel = 0;
    tmpsensor.A.at(0) = 0;
    tmpsensor.A.at(1) = 0;
    tmpsensor.A.at(2) = 0;
    tmpsensor.A.at(3) = 0;
    tmpsensor.A.at(4) = 0;
    tmpsensor.A.at(5) = 0;
    tmpsensor.Fp0 = 0;
    tmpsensor.Ft0 = 0;
    sensorsData.append(tmpsensor);
//    qDebug() << ui->listWidget->count() << sensorsData.count();
}

void MainWindow::on_pushbutton_delete_clicked()
{
      qDebug()<<sensorsData.size()<<" :Before delete";
      sensorsData.removeAt(ui->listWidget->currentRow());
      delete ui->listWidget->takeItem(ui->listWidget->currentRow());
      qDebug()<<sensorsData.size()<<" :After delete";
}

void MainWindow::on_pushbutton_save_clicked()
{
    if(!file->open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug() << "FILE NOT OPEN";
    QString sensor_Number("sensorNumber");
    QString namee("name");
    QString pressure_Channel("pressureChannel");
    QString temperature_Channel("temperatureChannel");
    QString FtO("Ft0");
    QString FpO("Fp0");
    QString AA("A");
    QJsonArray array;

    for (int i=0; i<sensorsData.count(); i++)
    {
        if((QString::number(sensorsData[i].sensorNumber)) == ui->listWidget->currentItem()->text())
        {
            sensorsData[i].sensorNumber = ui->SensorNumber->text().toDouble();
            sensorsData[i].name = ui->Name->text();
            sensorsData[i].pressureChannel = ui->pressureChanel->text().toDouble();
            sensorsData[i].temperatureChannel = ui->temperatureChannel->text().toDouble();
            sensorsData[i].A.at(0) = ui->A0->text().toDouble();
            sensorsData[i].A.at(1) = ui->A1->text().toDouble();
            sensorsData[i].A.at(2) = ui->A2->text().toDouble();
            sensorsData[i].A.at(3) = ui->A3->text().toDouble();
            sensorsData[i].A.at(4) = ui->A4->text().toDouble();
            sensorsData[i].A.at(5) = ui->A5->text().toDouble();
            sensorsData[i].Fp0 = ui->Fp0->text().toInt();
            sensorsData[i].Ft0 = ui->Ft0->text().toInt();
            ui->listWidget->currentItem()->setText(ui->SensorNumber->text());

        }
    }

    qDebug() << "count" << sensorsData.count();
    if(sensorsData.count() > 0)
        qDebug() << sensorsData[0].name << sensorsData[0].sensorNumber;

    QJsonObject new_dataa;

    for(int i = 0; i<ui->listWidget->count(); i++)
    {
        new_dataa.insert(sensor_Number,sensorsData[i].sensorNumber);
        new_dataa.insert(namee, sensorsData[i].name);
        new_dataa.insert(pressure_Channel, sensorsData[i].pressureChannel);
        new_dataa.insert(temperature_Channel, sensorsData[i].temperatureChannel);
        new_dataa.insert(AA, sensorsData[i].A);
        new_dataa.insert(FtO, sensorsData[i].Ft0);
        new_dataa.insert(FpO, sensorsData[i].Fp0);
        array.push_back(QJsonValue(new_dataa));
    }

       QJsonObject changed_data;
       changed_data.insert(QString("sensors"),QJsonValue(array));
       QJsonDocument new_doc (changed_data);
       QString strJson(new_doc.toJson(QJsonDocument::Compact));
       QTextStream stream(file);
       stream.operator << (new_doc.toJson());
       file->close();


}

void MainWindow::on_pushbutton_choose_clicked()
{
    ui->listWidget->clear();
    QString file_name = QFileDialog::getOpenFileName(this,"Open the file","/users/adelginiatullin");
    file->setFileName(file_name);
    QSettings setting ("MyApp","TheWay");
    setting.beginGroup("TheWayToFile");
    setting.setValue("Dir", file_name);

    if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "FILE NOT OPEN";
    }

    if (file->isOpen())
    {
        QPalette palette = ui->pushbutton_choose->palette();
        palette.setColor(ui->pushbutton_choose->backgroundRole(), Qt::green);
        palette.setColor(ui->pushbutton_choose->foregroundRole(), Qt::green);
        ui->pushbutton_choose->setAutoFillBackground(true);
        ui->pushbutton_choose->setPalette(palette);

    }
    else
    {
        QPalette palette = ui->pushbutton_choose->palette();
        palette.setColor(ui->pushbutton_choose->backgroundRole(), Qt::red);
        palette.setColor(ui->pushbutton_choose->foregroundRole(), Qt::red);
        ui->pushbutton_choose->setAutoFillBackground(true);
        ui->pushbutton_choose->setPalette(palette);
    }

    document = QJsonDocument::fromJson(file->readAll());
    QJsonObject obj = document.object();
    QJsonValue value = obj.value("sensors");
    QJsonArray vall = value.toArray();
    for (int i=0; i<vall.count(); i++)
    {
        QJsonObject object  = vall.at(i).toObject();
        Sensor tmpSensor;
        tmpSensor.sensorNumber = object.value("sensorNumber").toDouble();
        tmpSensor.name = object.value("name").toString();
        tmpSensor.pressureChannel = object.value("pressureChannel").toDouble();
        tmpSensor.temperatureChannel = object.value("temperatureChannel").toDouble();
        tmpSensor.A = object.value("A").toArray();
        tmpSensor.Ft0 = object.value("Ft0").toInt();
        tmpSensor.Fp0 = object.value("Fp0").toInt();
        sensorsData.append(tmpSensor);
        ui->listWidget->addItem((QString::number(object.value("sensorNumber").toDouble())));
    }
    file->close();
    setting.endGroup();
}



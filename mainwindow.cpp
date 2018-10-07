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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    file = new QFile("/users/adelginiatullin/coefficients.json", this);

    if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "FILE NOT OPEN";
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
          //QJsonObject arrayA = sensorsData[i].A.at(0).toObject();
          //qDebug() << QString::number(sensorsData[i].A.at(1).toDouble());
          //qDebug()<<sensorsData[i].A.count();


          ui->listWidget->addItem((QString::number(object.value("sensorNumber").toDouble())));
                  //((QString::number(object.value("sensorNumber").toDouble())));


        }
        file->close();
      //  sensorsData.reserve(vall.count()+1);
        //qDebug()<<sensorsData.size();



//        Sensor tmpsensor;
//        tmpsensor.sensorNumber = 0;
//        tmpsensor.name = "";
//        tmpsensor.pressureChannel = 0;
//        tmpsensor.temperatureChannel = 0;
//        tmpsensor.A.append("");
//        tmpsensor.A.append("");
//        tmpsensor.A.append("");
//        tmpsensor.A.append("");
//        tmpsensor.A.append("");
//        tmpsensor.A.append("");
//        tmpsensor.A.append("");
//        tmpsensor.Fp0 = 0;
//        tmpsensor.Ft0 = 0;
//        sensorsData.append(tmpsensor);

}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
  //  qDebug()<<ui->listWidget->currentItem()->text();
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
    for (int i=0; i<sensorsData.count(); i++)
                {
                  if ("Default" == ui->listWidget->currentItem()->text()){
//                      ui->SensorNumber->setText("Default");
//                      ui->Name->setText("Default");
//                      ui->pressureChanel->setText("Default");
//                      ui->temperatureChannel->setText("Default");
//                      ui->A0->setText("Default");
//                      ui->A1->setText("");
//                      ui->A2->setText("");
//                      ui->A3->setText("");
//                      ui->A4->setText("");
//                      ui->A5->setText("");
//                      ui->Ft0->setText("");
//                      ui->Fp0->setText("");
                      if ((ui->listWidget->count() - sensorsData.count()) > 0 )
                      {
                          sensorsData.reserve(ui->listWidget->count() - sensorsData.count());
                          sensorsData[sensorsData.size()+1].sensorNumber = ui->listWidget->currentItem()->text().toDouble();
                      }

                 }



               }


}

void MainWindow::on_pushbutton_delete_clicked()
{
    qDebug()<<sensorsData.count();
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


    for (int i=0; i<sensorsData.count()-1; i++)
        {
            if((QString::number(sensorsData[i].sensorNumber)) == ui->listWidget->currentItem()->text())

            {
                Sensor tmpSensor2;
                tmpSensor2.sensorNumber =  ui->SensorNumber->text().toDouble();
                tmpSensor2.name = ui->Name->text();
                tmpSensor2.pressureChannel = ui->pressureChanel->text().toDouble();
                tmpSensor2.temperatureChannel = ui->temperatureChannel->text().toDouble();
                tmpSensor2.A.append(ui->A0->text().toDouble());
                tmpSensor2.A.append(ui->A1->text().toDouble());
                tmpSensor2.A.append(ui->A2->text().toDouble());
                tmpSensor2.A.append(ui->A3->text().toDouble());
                tmpSensor2.A.append(ui->A4->text().toDouble());
                tmpSensor2.A.append(ui->A5->text().toDouble());
                tmpSensor2.Fp0 = ui->Fp0->text().toInt();
                tmpSensor2.Ft0 = ui->Ft0->text().toInt();
                sensorsData.append(tmpSensor2);
            }

            else if ((QString::number(sensorsData[sensorsData.size()+1].sensorNumber)) == ui->listWidget->currentItem()->text())
            {
                if ((ui->listWidget->count() - sensorsData.count()) > 0 )
                {
                sensorsData.reserve(ui->listWidget->count() - sensorsData.count());
                Sensor tmpSensor3;
                tmpSensor3.sensorNumber =  ui->SensorNumber->text().toDouble();
                tmpSensor3.name = ui->Name->text();
                tmpSensor3.pressureChannel = ui->pressureChanel->text().toDouble();
                tmpSensor3.temperatureChannel = ui->temperatureChannel->text().toDouble();
                tmpSensor3.A.append(ui->A0->text().toDouble());
                tmpSensor3.A.append(ui->A1->text().toDouble());
                tmpSensor3.A.append(ui->A2->text().toDouble());
                tmpSensor3.A.append(ui->A3->text().toDouble());
                tmpSensor3.A.append(ui->A4->text().toDouble());
                tmpSensor3.A.append(ui->A5->text().toDouble());
                tmpSensor3.Fp0 = ui->Fp0->text().toInt();
                tmpSensor3.Ft0 = ui->Ft0->text().toInt();
                sensorsData.append(tmpSensor3);
                }
            }
    }


      QJsonObject new_dataa;
     // int dif;
      //ui->listWidget->count() - sensorsData.count() = dif;
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

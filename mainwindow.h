#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QFile>
#include <QJsonDocument>
#include <QTextStream>
#include <QJsonArray>
#include <QListWidget>
#include <QListWidgetItem>
namespace Ui {
class MainWindow;
}


struct Sensor{
 double sensorNumber;
 QString name;
 double pressureChannel;
 double temperatureChannel;
 QJsonArray A;
 int Ft0;
 int Fp0;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
  //  void data();

private slots:




    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_Pushbutton_add_clicked();

    void on_pushbutton_delete_clicked();

    void on_pushbutton_save_clicked();

private:
    Ui::MainWindow *ui;
    QFile *file;
    QJsonDocument document;
    QJsonDocument doc1;
    QList<Sensor> sensorsData;
};

#endif // MAINWINDOW_H

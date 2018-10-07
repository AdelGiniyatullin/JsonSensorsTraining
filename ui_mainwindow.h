/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Pushbutton_add;
    QPushButton *pushbutton_delete;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *SensorNumber;
    QLineEdit *Name;
    QLineEdit *pressureChanel;
    QLineEdit *temperatureChannel;
    QLineEdit *Ft0;
    QLineEdit *Fp0;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *A0;
    QLineEdit *A1;
    QLineEdit *A2;
    QLineEdit *A3;
    QLineEdit *A4;
    QLineEdit *A5;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushbutton_save;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(795, 503);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);


        verticalLayout_2->addLayout(verticalLayout);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout_2->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Pushbutton_add = new QPushButton(centralWidget);
        Pushbutton_add->setObjectName(QStringLiteral("Pushbutton_add"));

        horizontalLayout->addWidget(Pushbutton_add);

        pushbutton_delete = new QPushButton(centralWidget);
        pushbutton_delete->setObjectName(QStringLiteral("pushbutton_delete"));

        horizontalLayout->addWidget(pushbutton_delete);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_5->addWidget(label_2);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_5->addWidget(label_3);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_5->addWidget(label_4);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_5->addWidget(label_5);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_5->addWidget(label_6);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_5->addWidget(label_7);


        horizontalLayout_3->addLayout(verticalLayout_5);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        SensorNumber = new QLineEdit(centralWidget);
        SensorNumber->setObjectName(QStringLiteral("SensorNumber"));

        verticalLayout_4->addWidget(SensorNumber);

        Name = new QLineEdit(centralWidget);
        Name->setObjectName(QStringLiteral("Name"));

        verticalLayout_4->addWidget(Name);

        pressureChanel = new QLineEdit(centralWidget);
        pressureChanel->setObjectName(QStringLiteral("pressureChanel"));

        verticalLayout_4->addWidget(pressureChanel);

        temperatureChannel = new QLineEdit(centralWidget);
        temperatureChannel->setObjectName(QStringLiteral("temperatureChannel"));

        verticalLayout_4->addWidget(temperatureChannel);

        Ft0 = new QLineEdit(centralWidget);
        Ft0->setObjectName(QStringLiteral("Ft0"));

        verticalLayout_4->addWidget(Ft0);

        Fp0 = new QLineEdit(centralWidget);
        Fp0->setObjectName(QStringLiteral("Fp0"));

        verticalLayout_4->addWidget(Fp0);


        horizontalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_6->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_2->addWidget(label_8);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        A0 = new QLineEdit(centralWidget);
        A0->setObjectName(QStringLiteral("A0"));

        verticalLayout_3->addWidget(A0);

        A1 = new QLineEdit(centralWidget);
        A1->setObjectName(QStringLiteral("A1"));

        verticalLayout_3->addWidget(A1);

        A2 = new QLineEdit(centralWidget);
        A2->setObjectName(QStringLiteral("A2"));

        verticalLayout_3->addWidget(A2);

        A3 = new QLineEdit(centralWidget);
        A3->setObjectName(QStringLiteral("A3"));

        verticalLayout_3->addWidget(A3);

        A4 = new QLineEdit(centralWidget);
        A4->setObjectName(QStringLiteral("A4"));

        verticalLayout_3->addWidget(A4);

        A5 = new QLineEdit(centralWidget);
        A5->setObjectName(QStringLiteral("A5"));

        verticalLayout_3->addWidget(A5);


        horizontalLayout_2->addLayout(verticalLayout_3);


        verticalLayout_6->addLayout(horizontalLayout_2);


        verticalLayout_7->addLayout(verticalLayout_6);

        verticalSpacer_2 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);

        pushbutton_save = new QPushButton(centralWidget);
        pushbutton_save->setObjectName(QStringLiteral("pushbutton_save"));

        verticalLayout_7->addWidget(pushbutton_save);


        horizontalLayout_4->addLayout(verticalLayout_7);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 795, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "Sensor's number", nullptr));
        Pushbutton_add->setText(QApplication::translate("MainWindow", "Add", nullptr));
        pushbutton_delete->setText(QApplication::translate("MainWindow", "delete", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Sensor number", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "name", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "pressureChannel", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "temperatureChannel", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Ft0", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Fp0", nullptr));
        pressureChanel->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "A", nullptr));
        pushbutton_save->setText(QApplication::translate("MainWindow", "Save", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", ".!.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

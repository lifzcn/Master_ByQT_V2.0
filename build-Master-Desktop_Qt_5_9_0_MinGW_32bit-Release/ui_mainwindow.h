/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox_1;
    QWidget *layoutWidget_1;
    QGridLayout *Layout_1;
    QComboBox *comboBox_BaudRate;
    QComboBox *comboBox_StopBit;
    QComboBox *comboBox_DataBit;
    QLabel *label_2;
    QLabel *label_1;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox_ParityBit;
    QLabel *label_5;
    QComboBox *comboBox_PortNo;
    QWidget *layoutWidget_2;
    QVBoxLayout *Layout_2;
    QPushButton *pushButton_CheckPort;
    QPushButton *pushButton_Connect;
    QGroupBox *groupBox_5;
    QPlainTextEdit *plainTextEdit_Receive;
    QPushButton *pushButton_ClearScreen;
    QCheckBox *checkBox_TimeStamp;
    QGroupBox *groupBox_6;
    QCustomPlot *widget_WaveDisplay;
    QGroupBox *groupBox_7;
    QPlainTextEdit *plainTextEdit_Send;
    QPushButton *pushButton_SendData;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget_3;
    QHBoxLayout *Layout_3;
    QRadioButton *radioButton_ReceiveChar;
    QRadioButton *radioButton_ReceiveHex;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget_4;
    QHBoxLayout *Layout_4;
    QRadioButton *radioButton_SendChar;
    QRadioButton *radioButton_SendHex;
    QGroupBox *groupBox_4;
    QCheckBox *checkBox_AutoSend;
    QWidget *layoutWidget_5;
    QHBoxLayout *Layout_5;
    QLabel *label_6;
    QLineEdit *lineEdit_Period;
    QSplitter *splitter;
    QWidget *layoutWidget_6;
    QHBoxLayout *Layout_6;
    QLabel *label_7;
    QLabel *label_8;
    QWidget *layoutWidget_7;
    QHBoxLayout *Layout_7;
    QLabel *label_9;
    QTimeEdit *timeEdit_CurrentTime;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(661, 559);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox_1 = new QGroupBox(centralWidget);
        groupBox_1->setObjectName(QStringLiteral("groupBox_1"));
        groupBox_1->setGeometry(QRect(20, 10, 191, 251));
        layoutWidget_1 = new QWidget(groupBox_1);
        layoutWidget_1->setObjectName(QStringLiteral("layoutWidget_1"));
        layoutWidget_1->setGeometry(QRect(20, 20, 151, 160));
        Layout_1 = new QGridLayout(layoutWidget_1);
        Layout_1->setSpacing(6);
        Layout_1->setContentsMargins(11, 11, 11, 11);
        Layout_1->setObjectName(QStringLiteral("Layout_1"));
        Layout_1->setContentsMargins(0, 0, 0, 0);
        comboBox_BaudRate = new QComboBox(layoutWidget_1);
        comboBox_BaudRate->setObjectName(QStringLiteral("comboBox_BaudRate"));

        Layout_1->addWidget(comboBox_BaudRate, 1, 1, 1, 1);

        comboBox_StopBit = new QComboBox(layoutWidget_1);
        comboBox_StopBit->setObjectName(QStringLiteral("comboBox_StopBit"));

        Layout_1->addWidget(comboBox_StopBit, 4, 1, 1, 1);

        comboBox_DataBit = new QComboBox(layoutWidget_1);
        comboBox_DataBit->setObjectName(QStringLiteral("comboBox_DataBit"));

        Layout_1->addWidget(comboBox_DataBit, 2, 1, 1, 1);

        label_2 = new QLabel(layoutWidget_1);
        label_2->setObjectName(QStringLiteral("label_2"));

        Layout_1->addWidget(label_2, 1, 0, 1, 1);

        label_1 = new QLabel(layoutWidget_1);
        label_1->setObjectName(QStringLiteral("label_1"));

        Layout_1->addWidget(label_1, 0, 0, 1, 1);

        label_3 = new QLabel(layoutWidget_1);
        label_3->setObjectName(QStringLiteral("label_3"));

        Layout_1->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(layoutWidget_1);
        label_4->setObjectName(QStringLiteral("label_4"));

        Layout_1->addWidget(label_4, 3, 0, 1, 1);

        comboBox_ParityBit = new QComboBox(layoutWidget_1);
        comboBox_ParityBit->setObjectName(QStringLiteral("comboBox_ParityBit"));

        Layout_1->addWidget(comboBox_ParityBit, 3, 1, 1, 1);

        label_5 = new QLabel(layoutWidget_1);
        label_5->setObjectName(QStringLiteral("label_5"));

        Layout_1->addWidget(label_5, 4, 0, 1, 1);

        comboBox_PortNo = new QComboBox(layoutWidget_1);
        comboBox_PortNo->setObjectName(QStringLiteral("comboBox_PortNo"));

        Layout_1->addWidget(comboBox_PortNo, 0, 1, 1, 1);

        layoutWidget_2 = new QWidget(groupBox_1);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(40, 190, 111, 54));
        Layout_2 = new QVBoxLayout(layoutWidget_2);
        Layout_2->setSpacing(6);
        Layout_2->setContentsMargins(11, 11, 11, 11);
        Layout_2->setObjectName(QStringLiteral("Layout_2"));
        Layout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_CheckPort = new QPushButton(layoutWidget_2);
        pushButton_CheckPort->setObjectName(QStringLiteral("pushButton_CheckPort"));

        Layout_2->addWidget(pushButton_CheckPort);

        pushButton_Connect = new QPushButton(layoutWidget_2);
        pushButton_Connect->setObjectName(QStringLiteral("pushButton_Connect"));

        Layout_2->addWidget(pushButton_Connect);

        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(230, 9, 411, 151));
        plainTextEdit_Receive = new QPlainTextEdit(groupBox_5);
        plainTextEdit_Receive->setObjectName(QStringLiteral("plainTextEdit_Receive"));
        plainTextEdit_Receive->setGeometry(QRect(10, 20, 291, 121));
        pushButton_ClearScreen = new QPushButton(groupBox_5);
        pushButton_ClearScreen->setObjectName(QStringLiteral("pushButton_ClearScreen"));
        pushButton_ClearScreen->setGeometry(QRect(320, 50, 71, 41));
        checkBox_TimeStamp = new QCheckBox(groupBox_5);
        checkBox_TimeStamp->setObjectName(QStringLiteral("checkBox_TimeStamp"));
        checkBox_TimeStamp->setGeometry(QRect(320, 100, 71, 16));
        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(229, 170, 411, 221));
        widget_WaveDisplay = new QCustomPlot(groupBox_6);
        widget_WaveDisplay->setObjectName(QStringLiteral("widget_WaveDisplay"));
        widget_WaveDisplay->setGeometry(QRect(10, 20, 391, 191));
        groupBox_7 = new QGroupBox(centralWidget);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(230, 400, 411, 71));
        plainTextEdit_Send = new QPlainTextEdit(groupBox_7);
        plainTextEdit_Send->setObjectName(QStringLiteral("plainTextEdit_Send"));
        plainTextEdit_Send->setGeometry(QRect(10, 20, 291, 41));
        pushButton_SendData = new QPushButton(groupBox_7);
        pushButton_SendData->setObjectName(QStringLiteral("pushButton_SendData"));
        pushButton_SendData->setGeometry(QRect(320, 20, 71, 41));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(19, 269, 191, 51));
        layoutWidget_3 = new QWidget(groupBox_2);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 20, 186, 18));
        Layout_3 = new QHBoxLayout(layoutWidget_3);
        Layout_3->setSpacing(6);
        Layout_3->setContentsMargins(11, 11, 11, 11);
        Layout_3->setObjectName(QStringLiteral("Layout_3"));
        Layout_3->setContentsMargins(0, 0, 0, 0);
        radioButton_ReceiveChar = new QRadioButton(layoutWidget_3);
        radioButton_ReceiveChar->setObjectName(QStringLiteral("radioButton_ReceiveChar"));

        Layout_3->addWidget(radioButton_ReceiveChar);

        radioButton_ReceiveHex = new QRadioButton(layoutWidget_3);
        radioButton_ReceiveHex->setObjectName(QStringLiteral("radioButton_ReceiveHex"));

        Layout_3->addWidget(radioButton_ReceiveHex);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(19, 329, 191, 51));
        layoutWidget_4 = new QWidget(groupBox_3);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 20, 186, 18));
        Layout_4 = new QHBoxLayout(layoutWidget_4);
        Layout_4->setSpacing(6);
        Layout_4->setContentsMargins(11, 11, 11, 11);
        Layout_4->setObjectName(QStringLiteral("Layout_4"));
        Layout_4->setContentsMargins(0, 0, 0, 0);
        radioButton_SendChar = new QRadioButton(layoutWidget_4);
        radioButton_SendChar->setObjectName(QStringLiteral("radioButton_SendChar"));

        Layout_4->addWidget(radioButton_SendChar);

        radioButton_SendHex = new QRadioButton(layoutWidget_4);
        radioButton_SendHex->setObjectName(QStringLiteral("radioButton_SendHex"));

        Layout_4->addWidget(radioButton_SendHex);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 390, 191, 81));
        checkBox_AutoSend = new QCheckBox(groupBox_4);
        checkBox_AutoSend->setObjectName(QStringLiteral("checkBox_AutoSend"));
        checkBox_AutoSend->setGeometry(QRect(10, 20, 71, 16));
        layoutWidget_5 = new QWidget(groupBox_4);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 50, 171, 22));
        Layout_5 = new QHBoxLayout(layoutWidget_5);
        Layout_5->setSpacing(6);
        Layout_5->setContentsMargins(11, 11, 11, 11);
        Layout_5->setObjectName(QStringLiteral("Layout_5"));
        Layout_5->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget_5);
        label_6->setObjectName(QStringLiteral("label_6"));

        Layout_5->addWidget(label_6);

        lineEdit_Period = new QLineEdit(layoutWidget_5);
        lineEdit_Period->setObjectName(QStringLiteral("lineEdit_Period"));

        Layout_5->addWidget(lineEdit_Period);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(0, 0, 0, 0));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget_6 = new QWidget(centralWidget);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(22, 477, 191, 21));
        Layout_6 = new QHBoxLayout(layoutWidget_6);
        Layout_6->setSpacing(6);
        Layout_6->setContentsMargins(11, 11, 11, 11);
        Layout_6->setObjectName(QStringLiteral("Layout_6"));
        Layout_6->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_6);
        label_7->setObjectName(QStringLiteral("label_7"));

        Layout_6->addWidget(label_7);

        label_8 = new QLabel(layoutWidget_6);
        label_8->setObjectName(QStringLiteral("label_8"));

        Layout_6->addWidget(label_8);

        layoutWidget_7 = new QWidget(centralWidget);
        layoutWidget_7->setObjectName(QStringLiteral("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(470, 474, 171, 22));
        Layout_7 = new QHBoxLayout(layoutWidget_7);
        Layout_7->setSpacing(6);
        Layout_7->setContentsMargins(11, 11, 11, 11);
        Layout_7->setObjectName(QStringLiteral("Layout_7"));
        Layout_7->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget_7);
        label_9->setObjectName(QStringLiteral("label_9"));

        Layout_7->addWidget(label_9);

        timeEdit_CurrentTime = new QTimeEdit(layoutWidget_7);
        timeEdit_CurrentTime->setObjectName(QStringLiteral("timeEdit_CurrentTime"));

        Layout_7->addWidget(timeEdit_CurrentTime);

        MainWindow->setCentralWidget(centralWidget);
        layoutWidget_6->raise();
        layoutWidget_7->raise();
        groupBox_5->raise();
        groupBox_6->raise();
        groupBox_7->raise();
        groupBox_2->raise();
        groupBox_3->raise();
        groupBox_4->raise();
        splitter->raise();
        groupBox_1->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 661, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox_1->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_1->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        pushButton_CheckPort->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        pushButton_Connect->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        pushButton_ClearScreen->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        checkBox_TimeStamp->setText(QApplication::translate("MainWindow", "CheckBox", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        pushButton_SendData->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        radioButton_ReceiveChar->setText(QApplication::translate("MainWindow", "RadioButton", Q_NULLPTR));
        radioButton_ReceiveHex->setText(QApplication::translate("MainWindow", "RadioButton", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        radioButton_SendChar->setText(QApplication::translate("MainWindow", "RadioButton", Q_NULLPTR));
        radioButton_SendHex->setText(QApplication::translate("MainWindow", "RadioButton", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        checkBox_AutoSend->setText(QApplication::translate("MainWindow", "CheckBox", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

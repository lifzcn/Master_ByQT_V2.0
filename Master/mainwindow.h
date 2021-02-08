#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSerialPort>//提供访问串行端口的功能
#include <QSerialPortInfo>//提供有关现有串行端口的信息
#include <QTimer>//提供重复的和单次的计时器
#include <QDebug>//控制台输出

#include "qcustomplot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_CheckPort_clicked();//串口检测

    void on_pushButton_Connect_clicked();//建立串口通信联结

    void on_pushButton_SendData_clicked();//数据发送

    void on_pushButton_ClearScreen_clicked();//清空屏幕

    void readData();//读取缓存中的数据

    void handleError(QSerialPort::SerialPortError error);//错误处理

    void changeAutoCheckState();//更改自动发送状态

    void sendOutMessage();//发送编辑框中信息

    void displayWave();//绘制实时波形图

private:
    void fillPortParameters();//填充串口相关参数即串口初始化

    void fillPortInfo();//填充串口信息即检测可用串口

    void showStatusMessage(const QString &category, const QString &content);//页面信息展示

    void closeSerialPort();//关闭虚拟串口

    void activeAuto();//使能自动发送功能

    void deactiveAuto();//失能自动发送功能

    Ui::MainWindow *ui;

    QSerialPort *m_serial = nullptr;//利用m_serial指代QSerialPort对象类

    QTimer *timer = nullptr;//利用timer指代QTimer对象类

    QTimer dataTimer;//日期时间类

    double value;//电机转速值

    int i=1;//接收数据记序符
};

#endif // MAINWINDOW_H

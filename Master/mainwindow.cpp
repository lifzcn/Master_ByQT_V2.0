#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

#include "qcustomplot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), m_serial(new QSerialPort(this))
{
    ui->setupUi(this);

    //软件界面总体设计
    setWindowTitle(tr("永磁同步电机转速监控系统 V2.0 By Leonard"));
    setWindowIcon(QIcon("./logo.ico"));
    setFixedSize(size());//保持界面设计大小不变

    //groupBox命名初始化
    ui->groupBox_1->setTitle(tr("串口设置"));
    ui->groupBox_2->setTitle(tr("接收设置"));
    ui->groupBox_3->setTitle(tr("发送设置"));
    ui->groupBox_4->setTitle(tr("定时发送设置"));
    ui->groupBox_5->setTitle(tr("接收数据显示"));
    ui->groupBox_6->setTitle(tr("转速波形显示"));
    ui->groupBox_7->setTitle(tr("转速设置显示"));

    //串口设置标签项初始化
    ui->label_1->setText(tr("串口号："));
    ui->label_2->setText(tr("波特率："));
    ui->label_3->setText(tr("数据位："));
    ui->label_4->setText(tr("校验位："));
    ui->label_5->setText(tr("停止位："));
    ui->label_6->setText(tr("发送周期(ms)："));
    ui->label_9->setText(tr("当前时间："));

    //按钮名称初始化
    ui->pushButton_CheckPort->setText(tr("串口检测"));
    ui->pushButton_Connect->setText(tr("建立联结"));
    ui->pushButton_ClearScreen->setText(tr("清空屏幕"));
    ui->pushButton_SendData->setText(tr("转速设置"));

    //选择框名称初始化
    ui->radioButton_ReceiveChar->setText(tr("字符串"));
    ui->radioButton_ReceiveHex->setText(tr("十六进制"));
    ui->radioButton_SendChar->setText(tr("字符串"));
    ui->radioButton_SendHex->setText(tr("十六进制"));


    ui->checkBox_AutoSend->setText(tr("定时发送"));
    ui->checkBox_TimeStamp->setText(tr("时间戳"));

    ui->plainTextEdit_Receive->setReadOnly(true);

    ui->label_7->setText(tr(""));
    ui->label_7->setLineWidth(ui->groupBox_3->width());
    ui->label_8->setText(tr(""));

    ui->radioButton_ReceiveChar->setChecked(true);
    ui->radioButton_SendChar->setChecked(true);

    //自动发送周期范围设置
    ui->lineEdit_Period->setValidator((new QIntValidator(1, 99999, this)));
    changeAutoCheckState();
    timer=new QTimer(this);

    //信号槽处理函数
    connect(timer, SIGNAL(timeout()), this, SLOT(sendOutMessage()));
    connect(ui->lineEdit_Period, &QLineEdit::textChanged, this, &MainWindow::changeAutoCheckState);
    connect(m_serial, &QSerialPort::errorOccurred, this, &MainWindow::handleError);
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readData);

    //当前时间相关设置
    ui->timeEdit_CurrentTime->setReadOnly(true);
    ui->timeEdit_CurrentTime->setDisplayFormat("HH:mm:ss");

    fillPortParameters();//填充串口相关参数即串口初始化

    QCustomPlot *customPlot=ui->widget_WaveDisplay;

    customPlot->addGraph();
    customPlot->graph(0)->setPen(QPen(QColor(255,0,0)));
    QSharedPointer<QCPAxisTickerTime>timeTicker(new QCPAxisTickerTime);//坐标轴使用时间刻度
    timeTicker->setTimeFormat("%mm:%ss");
    customPlot->xAxis->setTicker(timeTicker);
    customPlot->xAxis->setLabel(tr("历经时间"));
    customPlot->yAxis->setLabel(tr("电机转速值"));
    customPlot->yAxis->setRange(-250,250);//设置y轴范围
    customPlot->axisRect()->setupFullAxesBox();//添加完全坐标轴
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));//使上下轴范围同步
    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));//使左右轴范围同步
    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(displayWave()));//定时器连接槽函数displayWave

    dataTimer.start(0);//间隔时间0ms表示尽可能快的触发
}

MainWindow::~MainWindow()
{
    delete ui;
}

//填充串口相关参数即串口初始化
void MainWindow::fillPortParameters()
{
    //波特率初始化
    ui->comboBox_BaudRate->addItem(QStringLiteral("1200"), QSerialPort::Baud9600);
    ui->comboBox_BaudRate->addItem(QStringLiteral("2400"), QSerialPort::Baud9600);
    ui->comboBox_BaudRate->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    ui->comboBox_BaudRate->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    ui->comboBox_BaudRate->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    ui->comboBox_BaudRate->setCurrentIndex(2);

    //数据位初始化
    ui->comboBox_DataBit->addItem(QStringLiteral("6"), QSerialPort::Data6);
    ui->comboBox_DataBit->addItem(QStringLiteral("7"), QSerialPort::Data7);
    ui->comboBox_DataBit->addItem(QStringLiteral("8"), QSerialPort::Data8);
    ui->comboBox_DataBit->setCurrentIndex(2);

    //校验位初始化
    ui->comboBox_ParityBit->addItem(tr("无校验"), QSerialPort::NoParity);
    ui->comboBox_ParityBit->addItem(tr("奇校验"), QSerialPort::OddParity);
    ui->comboBox_ParityBit->addItem(tr("偶校验"), QSerialPort::EvenParity);
    ui->comboBox_ParityBit->setCurrentIndex(0);

    //停止位初始化
    ui->comboBox_StopBit->addItem(QStringLiteral("1"), QSerialPort::OneStop);
    ui->comboBox_StopBit->addItem(QStringLiteral("2"), QSerialPort::TwoStop);
    ui->comboBox_StopBit->setCurrentIndex(0);

    fillPortInfo();//填充串口信息即检测可用串口
}

//填充串口信息即检测可用串口
void MainWindow::fillPortInfo()
{
    ui->comboBox_PortNo->clear();//串口号清空
    const auto infos = QSerialPortInfo::availablePorts();//可用串口信息变量
    if(infos.size() == 0)
    {
        ui->comboBox_PortNo->addItem(tr("无"));
        ui->pushButton_Connect->setEnabled(false);//串口联结按钮失能
    }
    else
    {
        ui->pushButton_Connect->setEnabled(true);//串口联结按钮使能
        for(const QSerialPortInfo & info:infos)
        {
            ui->comboBox_PortNo->addItem(info.portName());//可用串口号压入comboBox_PortNo显示
        }
    }
}

//更改自动发送状态
void MainWindow::changeAutoCheckState()
{
    if(ui->lineEdit_Period->hasAcceptableInput())
    {
        ui->checkBox_AutoSend->setCheckable(true);//若自动发送周期在设置范围内，则自动发送复选框使能
    }
    else
    {
        ui->checkBox_AutoSend->setCheckable(false);//若自动发送周期不在设置范围内，则自动发送复选框失能
    }
}

//串口检测
void MainWindow::on_pushButton_CheckPort_clicked()
{
    fillPortInfo();//填充串口信息即检测可用串口
}

//建立串口通信联结
void MainWindow::on_pushButton_Connect_clicked()
{
    if(m_serial->isOpen())//若串口已打开
    {
        closeSerialPort();
        ui->pushButton_Connect->setText(tr("建立联结"));//此时进行关闭，再次进入串口联结功能，即进行串口更新，以防串口复用
    }
    else
    {
        m_serial->setPortName(ui->comboBox_PortNo->currentText());
        m_serial->setFlowControl(QSerialPort::NoFlowControl);//此属性保存所需的流控制模式如果设置成功或在打开端口之前设置，则返回true
                                                             //否则返回false并设置一个错误代码，该错误代码可以通过访问QSerialPort:：error属性的值获得。
        m_serial->setBaudRate(static_cast<QSerialPort::BaudRate>
                              (ui->comboBox_BaudRate->itemData(ui->comboBox_BaudRate->currentIndex()).toInt()));
        m_serial->setDataBits(static_cast<QSerialPort::DataBits>
                              (ui->comboBox_DataBit->itemData(ui->comboBox_DataBit->currentIndex()).toInt()));
        m_serial->setParity(static_cast<QSerialPort::Parity>
                            (ui->comboBox_ParityBit->itemData(ui->comboBox_ParityBit->currentIndex()).toInt()));

        if (m_serial->open(QIODevice::ReadWrite))//若串口读写设备已打开
        {
            showStatusMessage(tr("串口联结状态："), tr("已成功联结！"));
            ui->pushButton_Connect->setText(tr("断开联结"));
        }
        else
        {
            showStatusMessage(tr("串口联结状态："), m_serial->errorString());
        }
    }
}

//发送编辑框中信息
void MainWindow::sendOutMessage()
{

    const QString sendString(ui->plainTextEdit_Send->toPlainText());
    if(ui->radioButton_SendHex->isChecked())
    {
        bool ok;
        QByteArray temp;
        QStringList list(sendString.simplified().split(" "));
        for(QString &e:list)
        {
            temp.append(e.toInt(&ok, 16) & 0xFF);
        }
        if(ok)
        {
            m_serial->write(temp);
        }
        else
        {
           showStatusMessage(tr("错误"), tr("不可知十六进制数"));
           deactiveAuto();
           QMessageBox::critical(this, tr("错误"), tr("不可知十六进制数"));
        }
    }
    else
    {
        m_serial->write(QByteArray(sendString.toUtf8()));
    }
}

//读取缓存中的数据
void MainWindow::readData()
{
    ui->timeEdit_CurrentTime->setTime(QTime::currentTime());
    QString strCurrentTime = QTime::currentTime().toString("HH:mm:ss");

    QString j = QString::number(i);

    QByteArray buffer;
    buffer = m_serial->readAll();
    if (!buffer.isEmpty())
    {
        QString temp=buffer;
        QString data=temp.replace("\r\n","");

        value = data.toDouble();
        qDebug()<<"序列为："<<i;
        qDebug()<<"当前时间为："<<strCurrentTime;
        qDebug()<<"电机转速值为："<<value<<"转/秒";
        displayWave();
        if(ui->checkBox_TimeStamp->isChecked())
        {
            if (ui->radioButton_ReceiveChar->isChecked())
            {
                ui->plainTextEdit_Receive->appendPlainText(tr("#"));
                ui->plainTextEdit_Receive->insertPlainText(j);
                ui->plainTextEdit_Receive->insertPlainText(tr("  "));
                ui->plainTextEdit_Receive->insertPlainText(strCurrentTime);
                ui->plainTextEdit_Receive->insertPlainText(tr("  "));
                ui->plainTextEdit_Receive->insertPlainText(tr("电机转速值为："));
                ui->plainTextEdit_Receive->insertPlainText(data);
                ui->plainTextEdit_Receive->insertPlainText(tr("转/秒"));
                i++;
            }
            else if(ui->radioButton_ReceiveHex->isChecked())
            {
                std::string temp(buffer.toHex().toUpper().toStdString());
                QString toBeShow;
                for(auto it=temp.begin();it!=temp.end();++it)
                {
                    toBeShow.append(*it++).append(*it).append(" ");
                }
                ui->plainTextEdit_Receive->appendPlainText(toBeShow);
            }
        }
        else
        {
            if (ui->radioButton_ReceiveChar->isChecked())
            {
                ui->plainTextEdit_Receive->appendPlainText(tr("#"));
                ui->plainTextEdit_Receive->insertPlainText(j);
                ui->plainTextEdit_Receive->insertPlainText(tr("  "));
                ui->plainTextEdit_Receive->insertPlainText(tr("电机转速值为："));
                ui->plainTextEdit_Receive->insertPlainText(data);
                ui->plainTextEdit_Receive->insertPlainText(tr("转/秒"));
                i++;
            }
            else if(ui->radioButton_ReceiveHex->isChecked())
            {
                std::string temp(buffer.toHex().toUpper().toStdString());
                QString toBeShow;
                for(auto it=temp.begin();it!=temp.end();++it)
                {
                    toBeShow.append(*it++).append(*it).append(" ");
                }
                ui->plainTextEdit_Receive->appendPlainText(toBeShow);
            }
        }
    }
    buffer.clear();
}

//关闭虚拟串口
void MainWindow::closeSerialPort()
{
    m_serial->close();
    showStatusMessage(tr("串口联结状态："), tr("已断开联结！"));
}

//错误控制函数
void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if(error == QSerialPort::NoError)
        return;
    if (error == QSerialPort::ResourceError)
    {
        closeSerialPort();
    }
    QMessageBox::critical(this, tr("错误"), m_serial->errorString());
    deactiveAuto();
}

//串口联结状态输出显示函数
void MainWindow::showStatusMessage(const QString &category, const QString &content)
{
    ui->label_7->setText(category);
    ui->label_8->setText(content);
}

//使能自动发送功能
void MainWindow::activeAuto()
{
    if(ui->plainTextEdit_Send->toPlainText().size()==0)
        return;
    timer->start(ui->lineEdit_Period->text().toInt());
    ui->pushButton_SendData->setText(tr("停止"));
    timer->start();
}

//失能自动发送功能
void MainWindow::deactiveAuto()
{
    ui->pushButton_SendData->setText(tr("转速设置"));
    timer->stop();
}

//清空屏幕
void MainWindow::on_pushButton_ClearScreen_clicked()
{
    ui->plainTextEdit_Receive->clear();
}

//数据发送
void MainWindow::on_pushButton_SendData_clicked()
{
    if(ui->checkBox_AutoSend->isChecked())
    {
        if(timer->isActive())
            deactiveAuto();
        else
            activeAuto();
    }
    else
        sendOutMessage();
}

//绘制实时波形图
void MainWindow::displayWave()
{
    QCustomPlot *customPlot = ui->widget_WaveDisplay;
    static QTime time(QTime::currentTime());

    double key = time.elapsed()/1000.0;//演示开始后经过的时间，以秒为单位
    static double lastPointKey = 0;

    if (key - lastPointKey > 0.1)//添加数据周期为100ms
    {
        customPlot->graph(0)->addData(key,value);
        customPlot->graph(0)->addData(key,value);
        customPlot->graph(0)->rescaleValueAxis(true);//重新缩放数值轴以适应当前数据
        lastPointKey=key;
    }
    customPlot->xAxis->setRange(key, 8 , Qt::AlignRight);//使时间轴范围与数据一起滚动
    customPlot->replot();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "udpcom.h"
#include "serialport.h"

SerialPort *mySerial = NULL;
UDPCOM *udp;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))
             ui->tbMyIp->setText(address.toString());
    }

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())ui->cb_serial->addItem(info.portName());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readPendingDatagrams()
{
    QString lido = udp->UDPread();
    if(mySerial!=NULL){
        if(mySerial->isOpen()) {
            mySerial->write(lido);
        }
    }
    ui->plainTextEdit->appendPlainText("UDP: "+lido);
}
/*
void MainWindow::on_btSendSerial_clicked()
{
    //mySerial->write(ui->tbSend->text());
}*/

void MainWindow::readResponse()
{
    ui->plainTextEdit->appendPlainText("Serial: "+mySerial->readAll());
}

void MainWindow::on_btOpenSerial_clicked()
{
    //Serial Port,Baudrate
    mySerial = new SerialPort(this,ui->cb_serial->currentText(),57600);
}

void MainWindow::on_btRefresh_clicked()
{
    ui->cb_serial->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->cb_serial->addItem(info.portName());
    }
}

void MainWindow::on_btCloseSerial_clicked()
{
    if(mySerial!=NULL){
        if(mySerial->isOpen()) {
        if(mySerial->close()) qDebug() << "Serial Closed";
        else qDebug() << "Error Closing";
        }
        else qDebug() << "Serial Port not Open";
    }
    else qDebug() << "Serial Port not Open";
}

void MainWindow::on_btOpenUDP_clicked()
{

    //MyAddress,DestinationAddress,MyPort,DestinationPort
    //udp = new UDPCOM(this,"172.16.49.110","172.16.49.2",1234,1235);

    //MyAddress,DestinationAddress,MyPort,DestinationPort
    udp = new UDPCOM(this,ui->tbMyIp->text(),ui->tbDestIp->text(),ui->tbMyPort->text().toInt(),ui->tbDestPort->text().toInt());
}

void MainWindow::on_btSendUDP_clicked()
{
    udp->UDPwrite(ui->tbSend->text());
    qDebug() << "UDP Send: " << ui->tbSend->text();
}

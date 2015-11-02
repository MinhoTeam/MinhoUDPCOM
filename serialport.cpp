#include "serialport.h"

bool SerialPort::ConnectSerial()
{
    if (serial.open(QIODevice::ReadWrite))
    {
        myMain->connect(&serial, SIGNAL(readyRead()),myMain, SLOT(readResponse()));
        qDebug() << "Serial Port Opened";
    }
    else
    {
        qDebug() << "Error Open Serial Port: " << serial.errorString();
    }
    return true;
}

QString SerialPort::readAll()
{
    return serial.readAll();
}

void SerialPort::write(QString txt)
{
    frameToSend.append(txt);
    serial.write(frameToSend);
    frameToSend.clear();
}

bool SerialPort::close()
{
    serial.close();
    if(serial.isOpen()) return false;
    else return true;
}

bool SerialPort::isOpen()
{
    if(serial.isOpen()) return true;
    else return false;
}

SerialPort::SerialPort(MainWindow *mainw, QString name, int baudRate)
{
    myMain = mainw;
    serial.setPortName(name);
    serial.setBaudRate(baudRate);
    ConnectSerial();
}

SerialPort::~SerialPort()
{

}


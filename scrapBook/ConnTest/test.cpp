#include "test.h"
#include <QDebug>


Test::Test(QObject *parent) : QObject(parent)
{
    serial = new QSerialPort(this);
    connect(serial, SIGNAL(readyRead()), this, SLOT(recieveData()) );
}

Test::~Test(){

}

bool Test::openPortConn(){
    serial->setPortName("ttyUSB1");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setParity(QSerialPort::NoParity);
    serial->setDataBits(QSerialPort::Data8);
    bool open = serial->open(QIODevice::ReadWrite);

    qDebug() << "connection achieved";
    return open;
}

void Test::sendData(char * data){
    if(openPortConn()){
        serial->write(data);
        qDebug() << "written";
    }
}

QString Test::recieveData(){
    QByteArray readData = serial->readAll();
        QString ret(readData);

        qDebug() << ret ;
        return ret;
}

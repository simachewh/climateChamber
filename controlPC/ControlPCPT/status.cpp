#include "status.h"

Status::Status(QObject *parent) : QObject(parent)
{
    serial = new QSerialPort(this);
    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));
}

Status::~Status(){

}

void Status::openPort(){
    serial->setPortName("ttyUSB1");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setParity(QSerialPort::NoParity);
    *open = serial->open(QIODevice::ReadWrite);
}

QByteArray Status::readData(){
    QByteArray ret = serial->readAll();
    //*content = QString(ret);
    setContent(QString(ret));
    return ret;
}

QString *Status::getContent(){
    //emit contentChanged();
    return content;
}

void Status::setContent(QString data){
    *content = data;
    emit contentChanged(*content);
}


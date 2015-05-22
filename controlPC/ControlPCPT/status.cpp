#include "status.h"



Status::Status(QObject *parent) : QObject(parent)
{
    content = new QString();
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
    if(!serial->isOpen()){
        serial->open(QIODevice::ReadWrite);
    }

}

QByteArray Status::readData(){
    QByteArray ret = serial->readAll();
    //*content = QString(ret);
    //*content = "";
    (*content)= (QString(ret));
    emit contentChanged(*content);
    //setContent(QString(ret));
    //qDebug() << "from readData" << ret;
    return ret;
}

QString *Status::getContent(){
    //emit contentChanged();
    return content;
}

void Status::setContent(QString data){
    *content = "";
    *content = data;
    qDebug() <<" from setContent, content = " << *content;
    emit contentChanged(*content);
}


#include "intro.h"
#include <QDebug>

Intro::Intro(QObject *parent) : QObject(parent),
        currentVals("0A+022.50 +015.82 49.0\n"),
        commOff("0B<COMMUNICATION OFF>\n"),
        unknown("0I????????????\n"),
        quest("06"),
        dryTemp(25.13) ,
        wetTemp(20.75),
        humidity(40.07)
{
    portInfo = new QSerialPortInfo();
    serial = new QSerialPort(this);
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(boxTimer()));
    connect(serial, SIGNAL(readyRead()), this, SLOT(readPort()));


    timer->start(2000);
}

Intro::~Intro(){

}

void Intro::opPort(){
    serial->setPortName("ttyUSB1");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setParity(QSerialPort::NoParity);
    bool open = serial->open(QIODevice::ReadWrite);
    qDebug() << "Controll box Runing: " << open << endl;
}

void Intro::wrToPort(char *data){

    if(serial->isOpen()){
        serial->write(data);
    }
}

void Intro::boxTimer(){
    initValues();
    wrToPort(quest);

    wrToPort(unknown);
    wrToPort(currentVals);
    wrToPort(commOff);

}

QByteArray Intro::readPort(){
    QByteArray ret = serial->readAll();
    qDebug() << ret;
}

//
//"0A+022.50 +015.82 49.0\n"
void Intro::initValues(){

    if(dryTemp < 150 ){
        dryTemp += 3.95;
    }

    if(humidity < 150){
        humidity += 3.89;
    }
    wetTemp = dryTemp - humidity/20;

    QString ss = "0A+" + QString("%1").arg(dryTemp, 6, 'f', 2, '0') + " +"
            + QString("%1").arg(wetTemp, 6, 'f', 2, '0') + " +"
            + QString("%1").arg(humidity, 6, 'f', 2, '0') + "\n";

            //QString("%1%2").arg(humidity < 100 ? "0" : "").arg(humidity) + "\n";
    qDebug() << ss<< endl;
    QByteArray baStr = ss.toLatin1();
    currentVals = baStr.data();
}

#include "intro.h"
#include <QDebug>

Intro::Intro(QObject *parent) : QObject(parent),
    currentVals("0B<COMMUNICATION OFF>\n"),
    commOff("0A+022.50 +015.82 49.0\n"),
    unknown("0I????????????\n"),
    quest("x0006"),
    temperature(20.13) ,
    humidity(40.07)
{
    portInfo = new QSerialPortInfo();
    serial = new QSerialPort(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(boxTimer()));
    timer->start(1000);
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

//
void Intro::initValues(){

    if(temperature < 70.00 ){
        temperature += 3.95;
    }

    if(humidity < 70){
        humidity += 3.89;
    }
    //022.50 +015.82 49.0\n
    currentVals = "0A+";
}

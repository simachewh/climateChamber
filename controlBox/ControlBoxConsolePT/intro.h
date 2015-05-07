#ifndef INRO_H
#define INRO_H

#include <QObject>
#include <QtSerialPort/QtSerialPort>

class Intro : public QObject
{
    Q_OBJECT
public:
    QSerialPortInfo *portInfo;
    QSerialPort *serial;
    QTimer *timer;

    void opPort();
    void conPort();
    void wrToPort(char*);
    void disConPort();
    void clPort();
    void initValues();
    explicit Intro(QObject *parent = 0);
    ~Intro();

private:
    char *boxPortName;
    char *pcPortName;
    char *commOff;
    char *currentVals;
    char *unknown;
    char *quest;
    double wetTemp;
    double dryTemp;
    double humidity;

signals:

public slots:
    void boxTimer();
};

#endif // INRO_H

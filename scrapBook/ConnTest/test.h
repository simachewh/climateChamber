#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QtSerialPort/QtSerialPort>

class Test : public QObject
{
    Q_OBJECT

public:
    QSerialPort *serial;
    double dryTemp;
    double wetTemp;
    double humidity;
    explicit Test(QObject *parent = 0);
    bool openPortConn();
    void sendData(char *data);
    //QString recieveData();
    ~Test();

signals:

public slots:
    QString recieveData();
};

#endif // TEST_H

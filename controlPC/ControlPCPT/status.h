#ifndef STATUS_H
#define STATUS_H

#include <QObject>
#include <QtSerialPort/QtSerialPort>

class Status : public QObject
{
    Q_OBJECT
public:
    QString *content;
    QSerialPort *serial;
    void openPort();
    QString *getContent();
    void setContent(QString);

    bool *open;

    explicit Status(QObject *parent = 0);
    ~Status();

signals:
     void contentChanged(QString);

public slots:
    QByteArray readData();
};

#endif // STATUS_H

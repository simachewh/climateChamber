#include <QCoreApplication>
#include <test.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Test test;
    //test.openPortConn();
    test.sendData("check");
    return a.exec();
}

#include <QCoreApplication>
#include <intro.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Intro intro;
    intro.opPort();
    //intro.wrToPort();
    return a.exec();
}

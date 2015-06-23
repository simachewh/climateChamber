#include <QCoreApplication>
#include <test.h>
#include <iostream>
#include <bitset>

using namespace std;

class Dummy {
  public:
    bool isitme (int& param);
};

bool Dummy::isitme (int& param)
{
    cout << param << endl;
    cout << &param << endl;
  return false;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    Test test;
//    //test.openPortConn();
//    test.sendData("check");

//    char c = 'A';
//    bool d = true;

//    for (int i = 0; i < 8; ++i) {
//        bool is_set = c & (1 << i);
//        cout << "Bit " << i << ": " << is_set << '\n';
//    }
//    cout << "Bool: " << sizeof(bool) << " d: " << d <<endl;

//  //here is an example of separiting something to bit set
//    unsigned i = 242122534;
//        std::bitset<sizeof(i) * 8> bits;
//        bits = i;
//        std::cout << bits.to_string() << "\n";
//    QByteArray ba;
//    ba[0] = 0x02;
//    QString bas(ba);
//    qDebug() << bas ;
//    char stx = 0x02;
//    cout << stx << endl;
//    stx = 0x0D;
//    cout << stx << endl;
//    stx = 0x73;
//    cout << stx << endl;
    char n = 0x30;
      cout << "n: " << n << " Size: " << sizeof(n) << endl;

    return a.exec();
}




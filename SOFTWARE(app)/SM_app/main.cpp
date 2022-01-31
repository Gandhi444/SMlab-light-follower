#include "mainwidget.h"
//CONFIG += c++17 console
QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.resize(720, 480);
    w.show();
    return a.exec();
}

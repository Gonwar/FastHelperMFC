#include "fasthelper.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FastHelper w;
    w.show();

    return a.exec();
}

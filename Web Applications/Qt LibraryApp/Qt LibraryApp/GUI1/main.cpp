#include "userwin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    userwin w;
    w.show();
    return a.exec();
}

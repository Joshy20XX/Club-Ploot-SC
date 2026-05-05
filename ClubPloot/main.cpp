#include "login_screen.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login_screen w;
    w.show();
    return QCoreApplication::exec();
}

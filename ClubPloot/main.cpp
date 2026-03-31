#include "login_sceen.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login_sceen w;
    w.show();
    return QCoreApplication::exec();
}

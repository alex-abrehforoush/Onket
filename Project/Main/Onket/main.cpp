#include "mainwindow.h"
#include <QApplication>
#include "type.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Type t("موبایل","none");

    MainWindow w;
    w.show();

    return a.exec();
}

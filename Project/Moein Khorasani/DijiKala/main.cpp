#include "mainwindow.h"

#include <QApplication>
#include <QString>

#include "LinkedList.h"
#include "date.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LinkedList<int> l;
    l+=3;
    Date d;
    d.goToCurrentDate();

    QString s=d.toString();

    w.show();
    return a.exec();
}

#include "mainwindow.h"
#include <QApplication>
#include "goodpropertywidget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Type("t","none");
   const  Type& t=Type::getType("t");

   t.addProperty("p1");
   t.addProperty("p2");
   Good("g","t","",3);
   GoodPropertyWidget gp("1");
   gp.show();


//    MainWindow w;
//    w.show();

    return a.exec();
}

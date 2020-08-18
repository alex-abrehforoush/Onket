#ifndef STORAGE_H
#define STORAGE_H
#include <QVector>
#include <QMap>


#include "Commodity.h"
#include "good.h"
class Storage
{
private:
    QMap<QString,Commodity>remaining;
    QMap<QString,int>sales;
    unsigned long long int inventory;
public:
    Storage();
    void sold(QString type ,QString coloor, int num);
    int getPropertyValue();
    int getRemaining(QString type,QString coloor);
    void setRemaining(QString type,QString coloor,int num);
    void setSales(QString type, int num);
    int getSales(QString type);
};

#endif // STORAGE_H

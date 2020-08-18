#ifndef STORAGE_H
#define STORAGE_H
#include <QVector>
#include <QMap>
#include "Commodity.h"
#include "good.h"

class Storage
{
private:
    QMap<QString,Commodity> remaining;
    QMap<QString,int> sales;
    unsigned long long int inventory;
public:
    Storage();
    Commodity& getCommodityOf(QString type);
    void loadStorage();
    void addGood(QString type, QString color, int num = 1);

    void sold(QString type, QString color, int num);
    int getPropertyValue();
    int getRemaining(QString type, QString color);
    void setRemaining(QString type, QString color,int num);
    void setSales(QString type, int num);
    int getSales(QString type);
};

#endif // STORAGE_H

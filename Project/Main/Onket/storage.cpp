#include "storage.h"
#include <QFile>
#include <QDir>
#include <QTextStream>


Storage::Storage()
{

}

Commodity &Storage::getCommodityOf(QString type)
{
    return this->remaining[type];
}

void Storage::loadStorage()
{
    QFile data("Database/Commodity/commodity_list.csv");
    if(data.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&data);
        QString content = in.readAll();
        QStringList list_1 = content.split(",");
        for(int i = 0; i < list_1.size(); i++)
        {
            this->remaining.insert(list_1.at(i), Commodity::getCommodity(list_1.at(i)));
        }
        data.close();
    }
    return;
}

void Storage::addGood(QString type, QString color, int num)
{
    if(this->remaining.contains(type))
    {
        getCommodityOf(type).add(color, num);
        Commodity::addCommodity(getCommodityOf(type));
    }
    else
    {
        Commodity temp(type);
        temp.add(color, num);
        this->remaining.insert(type, temp);
        Commodity::addCommodity(temp);
    }
    return;
}

QMap<QString, Commodity> &Storage::getRemaining()
{
    return this->remaining;
}

void Storage::sold(QString type,QString color ,int num)
{
//    void Commodity::add(QString color, unsigned int number)
//    {
//        unsigned int temp = this->color.value(color);
//        this->color.insert(color, number + temp);
//    }
  auto it =this->remaining.find(type);
  if(   it.value().inventoryOf(color)==0)
  {
      return;
  }
  it.value().remove(color,num);
  int temp = this->sales.value(type);
  this->sales.insert(type,num+temp);
  QString good_id=it.value().getCommodityId();
  Good& g=Good::getGood(good_id);
  int income=num*(g.getFinalPrice());
  inventory = inventory + income;
}

int Storage::getPropertyValue()
{
    return this->inventory;
}
//need check
//int Storage::getRemaining(QString type, QString color)
//{
//     auto it =this->remaining.find(type);
//     return it.value().inventoryOf(color);
//}
//need check
void Storage::setRemaining(QString type, QString color, int num)
{
    auto it =this->remaining.find(type);
    int temp_num=it.value().inventoryOf(color);
    temp_num= num-temp_num;
    it->add(color,temp_num);
}

void Storage::setSales(QString type, int num)
{
    this->sales.insert(type,num);
}

int Storage::getSales(QString type)
{
    auto it =this->sales.find(type);
    return it.value();
}

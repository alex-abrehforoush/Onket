#include "storage.h"


Storage::Storage()
{

}

void Storage::sold(QString type,QString coloor ,int num)
{
//    void Commodity::add(QString color, unsigned int number)
//    {
//        unsigned int temp = this->color.value(color);
//        this->color.insert(color, number + temp);
//    }
  auto it =this->remaining.find(type);
  if(   it.value().inventoryOf(coloor)==0)
  {
      return;
  }
  it.value().remove(coloor,num);
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
int Storage::getRemaining(QString type, QString coloor)
{
     auto it =this->remaining.find(type);
     return it.value().inventoryOf(coloor);
}
//need check
void Storage::setRemaining(QString type, QString coloor, int num)
{
    auto it =this->remaining.find(type);
    int temp_num=it.value().inventoryOf(coloor);
    temp_num= num-temp_num;
    it->add(coloor,temp_num);
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

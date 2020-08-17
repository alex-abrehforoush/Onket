#include "item.h"

Item::Item(QString good_id, QString color, int number)
    :good_id(good_id)
    ,color(color)
    ,number(number)
{
}

QString Item::getItemId() const
{
    return this->good_id;
}

QString Item::getItemColor() const
{
    return this->color;
}

int Item::getNumber() const
{
    return this->number;
}

void Item::setItemId(QString id)
{
    this->good_id = id;
}

void Item::setItemColor(QString color)
{
    this->color = color;
}

void Item::setItemNumber(int number)
{
    this->number = number;
}

bool Item::operator==(const Item &itm)
{
    if(this->getItemId() == itm.getItemId() && this->getItemColor() == itm.getItemColor() && this->getNumber() == itm.getNumber()) return 1;
    else return 0;
}

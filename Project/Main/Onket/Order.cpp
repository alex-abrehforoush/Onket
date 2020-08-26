#include "Order.h"
#include <QDir>
#include <QFile>
#include <QTextStream>

Order::Order(QString order_id, QDateTime order_date, QString owner_name, QString owner_phone, QString deliver_address, QDateTime deliver_date, unsigned long long int deliver_price)
    :order_id(order_id)
    ,order_date(order_date)
	,owner_name(owner_name)
	,owner_phone(owner_phone)
	,deliver_address(deliver_address)
    ,deliver_date(deliver_date)
	,deliver_price(deliver_price)
{
}

void Order::setStuffPrice(unsigned long long stuff_price)
{
    this->stuff_price = stuff_price;
}

unsigned long long Order::getStuffPrice() const
{
    return this->stuff_price;
}

QDateTime Order::getOrderDate() const
{
	return this->order_date;
}

QString Order::getOrderId() const
{
	return this->order_id;
}

QString Order::getOwnerName() const
{
	return this->owner_name;
}

QString Order::getOwnerPhone() const
{
	return this->owner_phone;
}

QString Order::getDeliverAddress() const
{
    return this->deliver_address;
}

QVector<Item> Order::getBasket() const
{
    return this->basket;
}

void Order::setBasket(QVector<Item> basket)
{
    this->basket = basket;
    return;
}

Item Order::getItemAt(int i)
{
    return basket.at(i);
}

unsigned long long int Order::stuffPriceToday() const
{
    unsigned long long int temp = 0;
    for(int i = 0; i < basket.size(); i++)
    {
        ///temp += basket.at(i).getNumber() * price
    }
    return temp;
}

QDateTime Order::getDeliverDate() const
{
	return this->deliver_date;
}

unsigned long long int Order::getDeliverPrice() const
{
	return this->deliver_price;
}

unsigned long long int Order::totalPrice()
{
    return this->deliver_price + this->getStuffPrice();
}

int Order::orderExist(QString order_id)
{
    int flag = 0;
    QFile data("Database/Order/orders_list.csv");
    if(data.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString content = data.readAll();
        QStringList list_1 = content.split("\n");
        for(int i = 0; i<list_1.size(); i++)
        {
            QStringList list_2 = list_1.at(i).split(",");
            if(order_id == list_1.at(0))
            {
                flag = 1;
                break;
            }
            else continue;
        }
    }
    return flag;
}

Order Order::getOrder(QString order_id)
{
    if(orderExist(order_id))
    {
        int flag = 0;
        QFile data("Database/Order/orders_list.csv");
        if(data.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&data);
            in.setCodec("UTF-8");
            QString content = in.readAll();
            QStringList list_1 = content.split("\n");
            for(int i = 0; i<list_1.size(); i++)
            {
                QStringList List_2 = list_1.at(i).split(",");
                if(order_id == list_1.at(0))
                {
                    flag = i;
                    break;
                }
                else continue;
            }
            QStringList list_2 = list_1.at(flag).split(",");
            QString _order_id = list_2.at(0);
            QDateTime _order_date = QDateTime::fromString(list_2.at(1));
            QString _owner_name = list_2.at(2);
            QString _owner_phone = list_2.at(3);
            QString _deliver_address = list_2.at(4);
            unsigned long long int _stuff_price = list_2.at(5).toULongLong();
            QDateTime _deliver_date = QDateTime::fromString(list_2.at(6));
            unsigned long long int _deliver_price = list_2.at(7).toULongLong();
            Order return_order(_order_id, _order_date, _owner_name, _owner_phone, _deliver_address, _deliver_date, _deliver_price);
            return_order.setStuffPrice(_stuff_price);
            QStringList list_3 = list_2.at(8).split("|");
            QVector<Item> temp;
            for(int i = 0; i < list_3.size(); i++)
            {
                QStringList list_4 = list_3.at(i).split("─");
                Item kemp(list_4.at(0), list_4.at(1), list_4.at(2).toInt());
                temp.push_back(kemp);
            }
            return_order.setBasket(temp);
            data.close();
            return return_order;
        }
    }
}

void Order::addOrder(Order new_order)
{
    QDir dir;
    dir.mkpath("Database/Order");
    QFile data("Database/Order/orders_list.csv");
    if(data.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        QTextStream out(&data);
        out.setCodec("UTF-8");
        out << new_order.getOrderId() << "," << new_order.getOrderDate().toString() << "," << new_order.getOwnerName() << ","
            << new_order.getOwnerPhone() << "," << new_order.getDeliverAddress() << "," << new_order.getStuffPrice() << ","
            << new_order.getDeliverDate().toString() << "," << new_order.getDeliverPrice() << ",";
        for(int i = 0; i<new_order.getBasket().size(); i++)
        {
            out << new_order.getItemAt(i).getItemId() << "_" << new_order.getItemAt(i).getItemColor() << "_"
                << QString::number(new_order.getItemAt(i).getNumber());
            if(i != new_order.getBasket().size()-1) out << "|";
        }
        out << "\n";
        data.close();
    }
}

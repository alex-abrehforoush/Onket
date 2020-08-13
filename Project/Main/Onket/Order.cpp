#include "Order.h"
#include <QDir>
#include <QFile>
#include <QTextStream>

Order::Order(QString order_id, QDateTime order_date, QString owner_name, QString owner_phone, QString deliver_address, unsigned long long int total_price, QDateTime deliver_date, unsigned long long int deliver_price)
    :order_id(order_id)
    ,order_date(order_date)
	,owner_name(owner_name)
	,owner_phone(owner_phone)
	,deliver_address(deliver_address)
	,total_price(total_price)
	,deliver_date(deliver_date)
	,deliver_price(deliver_price)
{
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

unsigned long long int Order::totalPrice() const
{
	return this->total_price;
}

QDateTime Order::getDeliverDate() const
{
	return this->deliver_date;
}

unsigned long long int Order::getDeliverPrice() const
{
	return this->deliver_price;
}

unsigned long long int Order::payPrice()
{
    return this->deliver_price + this->total_price;
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
            unsigned long long int _total_price = list_2.at(5).toULongLong();
            QDateTime _deliver_date = QDateTime::fromString(list_2.at(6));
            unsigned long long int _deliver_price = list_2.at(7).toULongLong();
            Order return_order(_order_id, _order_date, _owner_name, _owner_phone, _deliver_address, _total_price, _deliver_date, _deliver_price);
            return return_order;
        }
    }
}

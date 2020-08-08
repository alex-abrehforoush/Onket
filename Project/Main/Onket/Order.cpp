#include "Order.h"

Order::Order(QDateTime order_date, QString order_id, QString owner_name, QString owner_phone, QString deliver_address, unsigned long long int total_price, QDateTime deliver_date, unsigned long long int deliver_price)
	:order_date(order_date)
	,order_id(order_id)
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

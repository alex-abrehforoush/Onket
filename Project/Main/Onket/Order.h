#ifndef ORDER_HBUHGGBKX
#define ORDER_HBUHGGBKX
#include <qstring.h>
#include <qdatetime.h>
class Order
{
protected:
private:
	//Basket bskt;
	QDateTime order_date;
	QString order_id;
	QString owner_name;
	QString owner_phone;
	QString deliver_address;
	unsigned long long int total_price;
	QDateTime deliver_date;
	unsigned long long int deliver_price;
	
public:
	Order(QDateTime order_date, QString order_id, QString owner_name, QString owner_phone, QString deliver_address, unsigned long long int total_price, QDateTime deliver_date, unsigned long long int deliver_price);
	QDateTime getOrderDate() const;
	QString getOrderId() const;
	QString getOwnerName() const;
	QString getOwnerPhone() const;
	QString getDeliverAddress() const;
	unsigned long long int totalPrice() const;
	QDateTime getDeliverDate() const;
	unsigned long long int getDeliverPrice() const;
	unsigned long long int payPrice();
};

#endif
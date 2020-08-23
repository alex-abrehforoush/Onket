#ifndef ORDER_HBUHGGBKX
#define ORDER_HBUHGGBKX
#include <qstring.h>
#include <qdatetime.h>
#include "item.h"
#include <QVector>

class Order
{
protected:
private:
    QVector<Item> basket;
    QString order_id;
	QDateTime order_date;
    QString owner_name;
	QString owner_phone;
	QString deliver_address;
    unsigned long long int stuff_price = 0;
	QDateTime deliver_date;
	unsigned long long int deliver_price;
	
public:
    Order(QString order_id, QDateTime order_date, QString owner_name, QString owner_phone, QString deliver_address, QDateTime deliver_date, unsigned long long int deliver_price);
    void setStuffPrice(unsigned long long int stuff_price);
    unsigned long long int getStuffPrice() const;
    QDateTime getOrderDate() const;
	QString getOrderId() const;
	QString getOwnerName() const;
	QString getOwnerPhone() const;
    QString getDeliverAddress() const;
    QVector<Item> getBasket() const;
    void setBasket(QVector<Item> basket);
    Item getItemAt(int i);
    unsigned long long int stuffPriceToday() const;
	QDateTime getDeliverDate() const;
	unsigned long long int getDeliverPrice() const;
    unsigned long long int totalPrice();
    static int orderExist(QString order_id);
    static Order getOrder(QString order_id);
    static void addOrder(Order new_order);
};

#endif

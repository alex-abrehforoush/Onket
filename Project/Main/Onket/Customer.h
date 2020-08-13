#ifndef CUSTOMER_BNUB
#define CUSTOMER_BNUB
#include "User.h"
#include "Order.h"
class Customer :
	public User
{
protected:
private:
	const int mode = 0;
	QDateTime birthday;
	QString phone_number;
	QVector<Order> orders_history;
	QVector<QString> addresses;
public:
    int getMode() const;
    Customer(QString username, QString password, QDateTime _birthday, QString _phone_number);
	void setBirthday(QDateTime birthday);
	QDateTime getBirthday() const;
	void setPhoneNumber(QString phone_number);
    QString getPhoneNumber() const;
    QVector<QString> getAddresses() const;
	void addAddress(QString address);
	void removeAddressAt(int at);
	void buy(QString good_id, QString color, int number);
	void sell(QString good_id, QString color, int number);

};

#endif

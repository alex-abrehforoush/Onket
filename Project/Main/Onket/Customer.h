#ifndef CUSTOMER_BNUB
#define CUSTOMER_BNUB
#include "User.h"
class Customer :
	public User
{
protected:
private:
	const int is_admin = 0;
	QDateTime birthday;
	QString phone_number;
	//QVector<Order> orders_history;
	QVector<QString> addresses;
public:
	QString getId(User& user) const;
	void setBirthday(QDateTime birthday);
	QDateTime getBirthday() const;
	void setPhoneNumber(QString phone_number);
	QString getPhoneNumber();
	void addAddress(QString address);
	void removeAddressAt(int at);
	void buy(QString good_id, QString color, int number);
	void sell(QString good_id, QString color, int number);


	friend class Admin;
};

#endif
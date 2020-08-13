#include "Customer.h"

int Customer::getMode() const
{
	return mode;
}

Customer::Customer(QString username, QString password, QDateTime _birthday, QString _phone_number)
    :User(username, password)
    ,birthday(_birthday)
    ,phone_number(_phone_number)
{

}

void Customer::setBirthday(QDateTime birthday)
{
	this->birthday = birthday;
	return;
}

QDateTime Customer::getBirthday() const
{
	return this->birthday;
}

void Customer::setPhoneNumber(QString phone_number)
{
	this->phone_number = phone_number;
    return;
}

QVector<QString> Customer::getAddresses() const
{
    return this->addresses;
}

QString Customer::getPhoneNumber() const
{
	return this->phone_number;
}

void Customer::addAddress(QString address)
{
	this->addresses.append(address);
	return;
}

void Customer::removeAddressAt(int at)
{
	this->addresses.removeAt(at);
	return;
}

void Customer::buy(QString good_id, QString color, int number)
{

}

void Customer::sell(QString good_id, QString color, int number)
{
}

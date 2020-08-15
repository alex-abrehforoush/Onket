#include "Customer.h"
#include <QDir>
#include <QFile>
#include <QTextStream>

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

QVector<QString> Customer::getOrderIds() const
{
    return this->order_ids;
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

int Customer::buy(QVector<Item> my_basket)
{
    Order new_order(this->getUsername() + QString::number(this->getOrderIds().size()+1), QDateTime::currentDateTime(), this->getFirstname() + " " + this->getLastname(), this->getPhoneNumber(), this->getAddresses().at(0), QDateTime::currentDateTime().addDays(5), 10000);
    for(int i = 0; i < my_basket.size(); i++)
    {
        new_order.addToBasket(my_basket.at(i).getItemId(),my_basket.at(i).getItemColor(), my_basket.at(i).getNumber());
    }
    Order::addOrder(new_order);
    QFile data_read("Database/User/" + this->getUsername() + ".csv");
    if(data_read.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&data_read);
        QString content = in.readAll();
        QStringList list_1 = content.split("\n");
        QString line_2_of_csv_file = list_1.at(1);
        line_2_of_csv_file.append(this->getUsername() + QString::number(this->getOrderIds().size()+1));
        data_read.close();
        QFile data_write("Database/User/" + this->getUsername() + ".csv");
        if(data_write.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&data_write);
            out << list_1.at(0) << "\n" << line_2_of_csv_file << "\n" << list_1.at(2);
            data_write.close();
        }
        else return 0;
        data_read.close();
        return 1;
    }
    else return 0;
}

void Customer::sell(QString good_id, QString color, QString number)
{
}

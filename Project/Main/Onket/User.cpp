#include "User.h"

void User::setUsername(QString username)
{
	this->username = username;
	return;
}

void User::setPassword(QString password)
{
	this->password = this->encryptPassword(password);
	return;
}

QString User::getUsername() const
{
	return this->username;
}

QString User::getPassword() const
{
	return this->password;
}

QString User::encryptPassword(QString password)
{
	QString temp1 = "";
	std::string temp2 = password.toStdString();
	char temp3;
	int length = password.length();
	for (int i = 1; i <= length; i++)
	{
		temp3 = temp2.at(i);
		temp3 += (i * i + 7) % 128;
		temp1.append(temp3);
	}
	return temp1;
}

QString User::decryptPassword(QString password)
{
	QString temp1 = "";
	std::string temp2 = password.toStdString();
	char temp3;
	int length = password.length();
	for (int i = 1; i <= length; i++)
	{
		temp3 = temp2.at(i);
		temp3 -= (i * i + 7) % 128;
		temp1.append(temp3);
	}
	return temp1;
}

void User::addActivity(QDateTime new_login)
{
	this->last_activities.push_back(new_login);
	return;
}

#include "Admin.h"

QDateTime Admin::getBirthday() const
{
    return QDateTime::currentDateTime();
}

QString Admin::getPhoneNumber() const
{
    return "";
}

QVector<QString> Admin::getAddresses() const
{
    QVector<QString> temp;
    return temp;
}

int Admin::getMode() const
{
	return mode;
}

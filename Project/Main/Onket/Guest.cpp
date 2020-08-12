#include "Guest.h"

int Guest::getMode() const
{
    return mode;
}

QDateTime Guest::getBirthday() const
{
    return QDateTime::currentDateTime();
}

QString Guest::getPhoneNumber() const
{
    return "";
}

QVector<QString> Guest::getAddresses() const
{
    QVector<QString> temp;
    return temp;
}

Guest::Guest(QString username, QString password)
    :User(username, password)
{
}

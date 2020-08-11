#include "Guest.h"

int Guest::getMode() const
{
    return mode;
}

Guest::Guest(QString username, QString password)
    :User(username, password)
{
}

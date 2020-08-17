#include "Admin.h"

Admin::Admin(QString username, QString password)
    :User(username, password)
{

}

void Admin::setFirstname(QString firstname)
{
    this->firstname = firstname;
}

void Admin::setLastname(QString lastname)
{
    this->lastname = lastname;
}

int Admin::getMode() const
{
	return mode;
}

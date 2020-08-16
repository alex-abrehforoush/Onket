#include "Admin.h"

Admin::Admin(QString username, QString password)
    :User(username, password)
{

}

int Admin::getMode() const
{
	return mode;
}

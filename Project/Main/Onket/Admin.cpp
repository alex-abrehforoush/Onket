#include "Admin.h"

int Admin::isAdmin()
{
	return is_admin;
}

void Admin::setUserId(User& user, QString id)
{
	user.id = id;
	return;
}

QString Admin::getUserId(User& user) const
{
	return user.id;
}

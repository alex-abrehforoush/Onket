#include "Admin.h"

void Admin::setUserId(User& user, QString id)
{
	user.id = id;
	return;
}

QString Admin::getUserId(User& user) const
{
	return user.id;
}

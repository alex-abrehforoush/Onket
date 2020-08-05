#include "Admin.h"

void Admin::setUserId(User& user, unsigned long long int id)
{
	user.id = id;
	return;
}

unsigned long long int Admin::getUserId(User& user) const
{
	return user.id;
}

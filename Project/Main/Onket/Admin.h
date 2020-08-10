#ifndef ADMIN_QSFEESX
#define ADMIN_QSFEESX
#include "User.h"
class Admin :
	private User
{
protected:
private:
	const int is_admin = 1;
public:
	int isAdmin();
	void setUserId(User& user, QString id);
	QString getUserId(User& user) const;
};

#endif
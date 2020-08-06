#ifndef ADMIN_QSFEESX
#define ADMIN_QSFEESX
#include "User.h"
class Admin :
	private User
{
protected:
private:
public:
	void setUserId(User& user, unsigned long long int id);
	unsigned long long int getUserId(User& user) const;
};

#endif
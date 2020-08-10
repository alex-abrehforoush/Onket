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
};

#endif
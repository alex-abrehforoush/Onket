#ifndef GUEST_BYVTCTX
#define GUEST_BYVTCTX
#include "User.h"
class Guest :
	public User
{
protected:
private:
	const int mode = -1;
public:
	int getMode() const;
    Guest(QString username = "Guest", QString password = "Guest");
};

#endif

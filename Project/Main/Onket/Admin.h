#ifndef ADMIN_QSFEESX
#define ADMIN_QSFEESX
#include "User.h"
class Admin :
    public User
{
protected:
private:
	const int mode = 1;
public:
    Admin(QString username, QString password);
    void setFirstname(QString firstname);
    void setLastname(QString lastname);
    int getMode() const;
};

#endif

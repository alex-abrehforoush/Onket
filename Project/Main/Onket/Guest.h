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
    QDateTime getBirthday() const;
    QString getPhoneNumber() const;
    QVector<QString> getAddresses() const;
    Guest(QString username = "Guest", QString password = "Guest");
};

#endif

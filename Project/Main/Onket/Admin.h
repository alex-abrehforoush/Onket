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
    Admin(QString username, QString password):User(username, encryptPassword(password)) {}
    QDateTime getBirthday() const;
    QString getPhoneNumber() const;
    QVector<QString> getAddresses() const;
    void setFirstname(QString firstname);
    int getMode() const;
};

#endif

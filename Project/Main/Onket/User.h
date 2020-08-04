#ifndef USER_BEHBWVYP
#define USER_BEHBWVYP
#include <qstring.h>
#include <string>
class User
{
protected:
	unsigned long long int id;
	QString username, password;
private:
public:
	void setUsername(QString username);
	void setPassword(QString password);
	QString getUsername() const;
	QString getPassword() const;
	QString encryptPassword(QString password);
	QString decryptPassword(QString password);
};

#endif
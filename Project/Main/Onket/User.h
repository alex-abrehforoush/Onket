#ifndef USER_BEHBWVYP
#define USER_BEHBWVYP
#include <qvector.h>
#include <qdatetime.h>
#include <qstring.h>
#include <string>
class User
{
protected:
	QString id;
	QString firstname, lastname, username, password;
	QVector<QDateTime> last_activities;
private:
public:
	virtual int isAdmin() = 0;
	void setFirstname(QString firstname);
	void setLastname(QString lastname);
	void setUsername(QString username);
	void setPassword(QString password);
	QString getFirstname() const;
	QString getLastname() const;
	QString getUsername() const;
	QString getPassword() const;
	QString encryptPassword(QString password);
	QString decryptPassword(QString password);
	void addActivity(QDateTime new_login);

};

#endif
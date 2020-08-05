#ifndef USER_BEHBWVYP
#define USER_BEHBWVYP
#include <qvector.h>
#include <qdatetime.h>
#include <qstring.h>
#include <string>
class User
{
protected:
	unsigned long long int id;
	QString username, password;
	QVector<QDateTime> last_activities;
private:
public:
	void setUsername(QString username);
	void setPassword(QString password);
	QString getUsername() const;
	QString getPassword() const;
	QString encryptPassword(QString password);
	QString decryptPassword(QString password);
	void addActivity(QDateTime new_login);

	friend class Admin;
};

#endif
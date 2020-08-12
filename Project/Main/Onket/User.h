#ifndef USER_BEHBWVYP
#define USER_BEHBWVYP
#include <qvector.h>
#include <qmap.h>
#include <qdatetime.h>
#include <qstring.h>
#include <string>
class User
{
protected:
	QString firstname, lastname, username, password;
	QVector<QDateTime> last_activities;
private:
	static QMap<QString, User*> user_list;
public:
	User(QString username, QString password);
	virtual int getMode() const = 0;
    virtual QDateTime getBirthday() const = 0;
    virtual QString getPhoneNumber() const = 0;
    virtual QVector<QString> getAddresses() const = 0;
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

	static void loadUsersInfo();
    static int addUser(User* new_user);
	static void removeUser(QString username);

};

#endif

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
public:
	User(QString username, QString password);
	virtual int getMode() const = 0;
    virtual QDate getBirthday() const;
    virtual QString getPhoneNumber() const;
    virtual void setBirthday(QDate/*Time*/ birthday);
    virtual void setPhoneNumber(QString phone_number);
    virtual QVector<QString>& getAddresses();
    virtual void addAddress(QString address);
    virtual void removeAddressAt(int at);
	void setFirstname(QString firstname);
	void setLastname(QString lastname);
	void setUsername(QString username);
	void setPassword(QString password);
	QString getFirstname() const;
	QString getLastname() const;
	QString getUsername() const;
	QString getPassword() const;
    static QString encryptPassword(QString password);
    static QString decryptPassword(QString password);
	void addActivity(QDateTime new_login);

    static int userExist(QString username);
    static User* getUser(QString username);
    static int addUser(User* new_user);
	static void removeUser(QString username);

};

#endif

#include "User.h"
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

QMap<QString, User*> User::user_list;

User::User(QString username, QString password)
	:username(username)
	,password(decryptPassword(password))
{

}

void User::setFirstname(QString firstname)
{
	this->firstname = firstname;
	return;
}

void User::setLastname(QString lastname)
{
	this->lastname = lastname;
	return;
}

void User::setUsername(QString username)
{
	this->username = username;
	return;
}

void User::setPassword(QString password)
{
	this->password = this->encryptPassword(password);
	return;
}

QString User::getFirstname() const
{
	return this->firstname;
}

QString User::getLastname() const
{
	return this->lastname;
}

QString User::getUsername() const
{
	return this->username;
}

QString User::getPassword() const
{
	return this->password;
}

QString User::encryptPassword(QString password)
{
	QString temp1 = "";
	std::string temp2 = password.toStdString();
	char temp3;
	int length = password.length();
    for (int i = 0; i < length; i++)
	{
		temp3 = temp2.at(i);
		temp3 += (i * i + 7) % 128;
		temp1.append(temp3);
	}
	return temp1;
}

QString User::decryptPassword(QString password)
{
	QString temp1 = "";
	std::string temp2 = password.toStdString();
	char temp3;
	int length = password.length();
    for (int i = 0; i < length; i++)
	{
		temp3 = temp2.at(i);
		temp3 -= (i * i + 7) % 128;
		temp1.append(temp3);
	}
	return temp1;
}

void User::addActivity(QDateTime new_login)
{
	this->last_activities.push_back(new_login);
	return;
}

void User::loadUsersInfo()
{

}

int User::addUser(User* new_user)
{
    if (!(user_list.contains(new_user->getUsername())))
	{
        user_list.insert(new_user->getUsername(), new_user);
        QDir data;
        data.mkpath("Database/User");
        QFile username_password_list("Database/User/uplist.csv");
        if(!username_password_list.open(QIODevice::WriteOnly | QIODevice::Append))
        {
            return 0;
        }
        else
        {
            QTextStream out(&username_password_list);
            out << new_user->getUsername() << "," << new_user->getPassword() << "\n";
            username_password_list.close();
        }
        QFile user_personal("Database/User/" + new_user->getUsername() + ".csv");
        if(!user_personal.open(QIODevice::WriteOnly))
        {
            return 0;
        }
        else
        {
            QTextStream out(&user_personal);
            out << new_user->getUsername() << "," << new_user->getPassword() << "," << new_user->getMode() << "," << new_user->getFirstname() << "," << new_user->getLastname() << "," ;
            if(new_user->getMode()==0)
            {
                out << new_user->getBirthday().toString() << "," << new_user->getPhoneNumber() << ",";
                for(int i = 0; i<new_user->getAddresses().size(); i++)
                {
                    if(i==new_user->getAddresses().size()-1)
                    {
                        out << new_user->getAddresses().at(i) << ",";
                    }
                    else
                    {
                        out << new_user->getAddresses().at(i) << "|";
                    }
                }
                out << "\n\n";
                QDateTime now=QDateTime::currentDateTime();
                out << "Account created in " << now.toString() << "\n";
            }
        }
		//open file
        //write info
        //close file
	}
	else
	{
		//cout this username exists
	}
}

void User::removeUser(QString username)
{
	if (user_list.contains(username))
	{
		user_list.remove(username);
		//open file
		//add user to deleted users
		//delete user
		//close file
	}
	else
	{
		//there is no user with this username
	}
}

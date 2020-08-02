#include "xmlfuncitions.h"

QString xml_QDate::toQString(const QDate& input)
{
    QString resault=QString::number(input.year());
    resault.append(",");
    resault.append(QString::number(input.month()));
    resault.append(",");
    resault.append(QString::number(input.day()));
    return  resault;
}

QDate xml_QDate::toQDate(const QString& input)
{
    QStringList date_list=input.split(",");
 //    int year=date_list[0].toInt();
 //      int month=date_list[1].toInt();
 //        int day=date_list[2].toInt();

    QDate resualt(date_list[0].toInt(),date_list[1].toInt(),date_list[2].toInt());
    return resualt;
}

QString xml_QMap::toQString(const QMap<QString,bool>& input)
{
    if(input.isEmpty()==true)
    {
        return QString("");
    }

    auto it=input.cbegin();
    QString resault=it.key();
    resault.append("_");
    resault.append(QString::number(*it));

    if(it != input.cend())
        it++;
    for(;it !=  input.cend();it++)
    { resault.append(",");
        resault.append(it.key());
        resault.append("_");
        resault.append(QString::number(*it));

    }
    return resault;
}


QMap<QString,bool> xml_QMap:: toQMap(const QString& input)
{
    QMap<QString,bool>resualt;
    QString sender;
    for(auto it=input.cbegin();it != input.cend(); it++)
    {
        if(*it == '_')
        {
            it++;
            bool mode;
            if(*it=='0')
            {
                mode=false;
            }
            else
            {
                mode=true;
            }
            it++;
            resualt.insert(sender,mode);
            sender.clear();
        }
        else
        {
         sender.append(*it);
        }
    }
    return resualt;
}

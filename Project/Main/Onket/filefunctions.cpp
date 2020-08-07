#include "filefunctions.h"


QString file_QDate::toQString(const QDate &input)
{
    QString resault=QString::number(input.year());
    resault.append("_");
    resault.append(QString::number(input.month()));
    resault.append("_");
    resault.append(QString::number(input.day()));
    return  resault;
}

QDate file_QDate::toQDate(const QString &input)
{
    QStringList date_list=input.split("_");
 //    int year=date_list[0].toInt();
 //      int month=date_list[1].toInt();
 //        int day=date_list[2].toInt();

    QDate resualt(date_list[0].toInt(),date_list[1].toInt(),date_list[2].toInt());
    return resualt;
}

bool csv_validator::isValidInCsv(const QString &input)
{
    for(auto it=input.cbegin();it != input.cend();it++)
    {
        if(*it==','||*it=='\n')
            return  false;
    }
    return true;
}




QString xml_QMap::toQString(const QMap<QString,double>& input)
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


QMap<QString,double> xml_QMap:: toDoubleQMap(const QString& input)
{
  QMap<QString,double>res;
  QStringList str_list=input.split(",");
  for(int cnt=0;cnt<str_list.size();cnt++)
  {
     QString key,value;
     QStringList field=str_list[cnt].split("_");
     key=field[0],value=field[1];
     res.insert(key,value.toDouble());
  }
  return res;
}


QString xml_QMap::toQString(const QMap<QString, bool> &input)
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

QMap<QString, bool> xml_QMap::toBoolQMap(const QString &input)
{
    QMap<QString,bool>res;
    QStringList str_list=input.split(",");
    for(int cnt=0;cnt<str_list.size();cnt++)
    {
       QString key,value;
       QStringList field=str_list[cnt].split("_");
       key=field[0],value=field[1];
       res.insert(key,value.toInt());
    }
    return res;
}

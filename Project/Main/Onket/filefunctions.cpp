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
        if(*it==';'||*it=='\n')
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
     if(field.size()!=2)
     {
         break;
     }
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
       if(field.size()!=2)
       {
           break;
       }

       key=field[0],value=field[1];
       res.insert(key,value.toInt());
    }
    return res;
}

QString xml_QMap::toQString(const QMap< unsigned int,QString> &input)
{
    if(input.isEmpty()==true)
    {
        return QString("");
    }

    auto it=input.cbegin();
    QString resault=QString::number(it.key());
    resault.append("_");
    resault.append(*it);

    if(it != input.cend())
        it++;
    for(;it !=  input.cend();it++)
    { resault.append(",");
        resault.append(QString::number(it.key()));
        resault.append("_");
        resault.append(*it);

    }
    return resault;
}



QMap<unsigned int,QString> xml_QMap::toIntQMap(const QString &input)
{
    QMap<unsigned int,QString>res;
    QStringList str_list=input.split(",");
    for(int cnt=0;cnt<str_list.size();cnt++)
    {
       QString key,value;
       QStringList field=str_list[cnt].split("_");
       if(field.size()!=2)
       {
           break;
       }
       key=field[0],value=field[1];
       res.insert(key.toInt(),value);
    }
    return res;
}



QString csv_QMap::toQStirng(const QMap<QString, QString> &input)
{

    if(input.isEmpty()==true)
    {
        return "";
    }

    QString res;

   for(auto  it=input.cbegin();;)
   {
     res.append(it.key());
     res.append("_");
     res.append(it.value());
     it++;
     if(it== input.cend())
     {
         break;
     }
     else
     {

         res.append("#");
     }

   }
   return res;

}

QString csv_QMap::toQString(const QMap<QString, double> &input)
{

    if(input.isEmpty()==true)
    {
        return "";
    }

    QString res;

   for(auto it=input.cbegin();;)
   {
     res.append(it.key());
     res.append("_");
     res.append(QString::number(it.value()));
     it++;
     if(it== input.cend())
     {
         break;
     }
     else
     {
         res.append("#");
     }

   }
   return res;
}

QMap<QString, QString> csv_QMap::toQStringQMap(const QString &input)
{
    QMap<QString,QString>res;
    QStringList str_list=input.split("#");

    for(int cnt=0;cnt<str_list.size() && str_list[cnt].isEmpty()==false;cnt++)
    {
        QStringList field=str_list[cnt].split("_");
        if(field.size() !=2)
        {
            break;
        }
        else
        {
          res.insert(field[0],field[1]);
        }

    }

    return res;
}

QMap<QString, double> csv_QMap::toDoubleQMap(const QString &input)
{
    QMap<QString,double>res;
    QStringList str_list=input.split("#");

    for(int cnt=0;cnt<str_list.size() && str_list[cnt].isEmpty()==false;cnt++)
    {
        QStringList field=str_list[cnt].split("_");
        if(field.size() !=2)
        {
            break;
        }
        else
        {
          res.insert(field[0],field[1].toDouble());
        }

    }

    return res;
}

QString csv_QVector::toQString(const QVector<QString> &input)
{
    if(input.isEmpty()==true)
    {
        return "";
    }
    else
    {
        QString res;

        for(auto it=input.cbegin();;)
        {
            res.append(*it);
            it++;
            if(it==input.cend())
            {
                break;
            }
            else
            {
                res.append("_");
            }
        }
        return res;
    }
}

QVector<QString> csv_QVector::toQVector(const QString &input)
{
   QVector<QString>res;

   if(input.isEmpty()==true)
   {
       return res;
   }
   QStringList str_list=input.split("_");

   for(auto it=str_list.begin();it!=str_list.end();it++)
   {
       res.push_back(*it);
   }
   return res;
}

QString price::number(unsigned int input)
{
    QString number=QString::number(input);
    QString res;
    for( int  cnt=0;cnt <number.size();cnt++)
    {
        if((number.size()-cnt)%3==0 && cnt!=0 )
        {
            res.append(",");
        }
        res.append(number[cnt]);
    }
    return res;
}

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

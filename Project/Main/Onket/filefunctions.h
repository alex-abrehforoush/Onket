#ifndef FILEFUNCTIONS_H
#define FILEFUNCTIONS_H

#include <QDate>
#include <QMap>
#include <QString>
namespace file_QDate
{
QString toQString(const QDate& input);
QDate toQDate(const QString& input);
};



#endif // FILEFUNCTIONS_H

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

namespace csv_validator
{
bool isValidInCsv(const QString& input);
}
namespace xml_QMap
{
    QString toQString(const QMap<QString,bool> & input);
     QMap<QString,bool> toQMap(const QString& input);
};


#endif // FILEFUNCTIONS_H

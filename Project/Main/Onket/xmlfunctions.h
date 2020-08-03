#ifndef XMLFUNCITIONS_H
#define XMLFUNCITIONS_H

#endif // XMLFUNCITIONS_H

#include <QString>
#include<QDate>
#include <QMap>

namespace xml_QMap
{
    QString toQString(const QMap<QString,bool> & input);
     QMap<QString,bool> toQMap(const QString& input);
};


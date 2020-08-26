#ifndef ACTIONTYPERETURN_H
#define ACTIONTYPERETURN_H

#include <QObject>
#include <QWidget>

#include "actiontype.h"

class ActionTypeReturn : public ActionType
{
    Q_OBJECT
public:
    explicit ActionTypeReturn(const QString& type_id,QWidget *parent = nullptr);

signals:

};

#endif // ACTIONTYPERETURN_H

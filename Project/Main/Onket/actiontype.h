#ifndef ACTIONTYPE_H
#define ACTIONTYPE_H

#include <QObject>
#include <QWidget>
#include <QAction>
#include "type.h"

class ActionType : public QAction
{
    Q_OBJECT
    QString type_id;
    bool info_valid=false;
signals:
    void actionTriggered(const QString& type_id);
private slots:
    void action_tirggered();
public:
    explicit ActionType(const QString& type_id,QWidget *parent = nullptr);

signals:

};

#endif // ACTIONTYPE_H

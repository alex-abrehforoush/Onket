#ifndef ACTIONADDGOOD_H
#define ACTIONADDGOOD_H
#include <QAction>
#include "good.h"



class ActionAddGood:public QAction
{
    QString type_id;
private slots:
    void action_triggered();
public:
    ActionAddGood(const QString& type_id,QWidget* parent=nullptr);
};

#endif // ACTIONADDGOOD_H

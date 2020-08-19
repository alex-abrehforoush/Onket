#ifndef ACTIONADDTYPE_H
#define ACTIONADDTYPE_H
#include <QAction>
#include "type.h"

class ActionAddType: public QAction
{
   QString parent_id;

private slots:
   void action_triggered();
public:
    ActionAddType(const QString& parent_id,QWidget* parnet=nullptr);
};

#endif // ACTIONADDTYPE_H

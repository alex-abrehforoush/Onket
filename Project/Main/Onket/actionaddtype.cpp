#include "actionaddtype.h"



void ActionAddType::action_triggered()
{
    //show some widget to add type
}

ActionAddType::ActionAddType(const QString &parent_id, QWidget *parnet):QAction(parnet)
{
    this->parent_id=parent_id;

    connect(this,SIGNAL(triggered()),this,SLOT(action_triggered()));
}

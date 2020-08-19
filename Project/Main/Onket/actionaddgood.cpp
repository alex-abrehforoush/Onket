#include "actionaddgood.h"


void ActionAddGood::action_triggered()
{
    //show some widget
}

ActionAddGood::ActionAddGood(const QString &type_id, QWidget *parent):QAction(parent)
{
    this->type_id=type_id;
    connect(this,SIGNAL(triggered()),this,SLOT(action_triggered()));

}

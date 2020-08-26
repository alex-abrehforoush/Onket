#include "actiontypereturn.h"

ActionTypeReturn::ActionTypeReturn(const QString& type_id,QWidget *parent) : ActionType(type_id,parent)
{
    this->setText("<<");
}

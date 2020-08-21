#include "actiointype.h"



void ActoinType::action_triggered()
{
    if(info_valid==false)
    {
        return;
    }
    Type::setCurrentTypeId(type_id);
    emit this->action_triggered();
}

ActoinType::ActoinType(const QString &type_id, QWidget *parent):QAction(parent)
{
    this->type_id=type_id;
    if(Type::existTypeId(type_id)==false)
    {
        return;
    }
    else
    {
        this->info_valid=true;
       this->setText(Type::getType(type_id).getName());
        connect(this,SIGNAL(triggered()),this,SLOT(action_triggered()));
    }
}

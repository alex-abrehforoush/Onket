#include "actiontype.h"

void ActionType::action_tirggered()
{
    if(this->info_valid==false)
    {
        return;
    }
    else
    {
        Type::setCurrentTypeId(type_id);
        emit this->actionTriggered(type_id);
    }
}

ActionType::ActionType(const QString& type_id,QWidget *parent) : QAction(parent)
{
    this->type_id=type_id;
    if(this->type_id=="none")
    {
        this->info_valid=true;
        connect(this,SIGNAL(triggered()),this,SLOT(action_tirggered()));
    }
    if(Type::existTypeId(type_id)==false)
    {
        return;
    }
    else
    {
        this->info_valid=true;
        const Type& t=Type::getType(type_id);
        this->setText(t.getName());
        connect(this,SIGNAL(triggered()),this,SLOT(action_tirggered()));

    }
}

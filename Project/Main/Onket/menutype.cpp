#include "menutype.h"



MenuType::MenuType(const QString &type_id, QWidget *parent):QMenu(parent)
{
    if(Type::existTypeId(type_id)==false)
    {
        return;
    }
    this->type_id=type_id;
    this->info_valid=true;

    const Type& t=Type::getType(type_id);
    this->setTitle(t.getName());
    for(t.setBranchSeekBegin();t.BranchSeekAtEnd()==false;)
    {
        QString branch_id=t.readBranchId();
        if(Type::getType(branch_id).branchIdIsEmpty()==true)
        {
            ActoinType * act=new ActoinType(branch_id,parent);
            this->addAction(act);
        }
        else
        {
            MenuType* menu=new MenuType(branch_id,parent);
            this->addMenu(menu);
        }
    }
}

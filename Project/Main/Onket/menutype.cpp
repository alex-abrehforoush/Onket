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

void MenuType::setUpMenu(QMenu *menu, QWidget *parent)
{

      menu->clear();
      Type::readFile();


        QVector<QString> base_id=Type::getBaseTypeId();
        for(auto it : base_id)
        {
            const Type& t=Type::getType(it);
            if(t.branchIdIsEmpty()==true)
            {
                menu->addAction(new ActoinType(it,menu));
            }
            else
            {
                menu->addMenu(new MenuType(it,menu));
            }
        }


}

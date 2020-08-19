#include "menutype.h"

User* MenuType::current_user=nullptr;
QMenu* MenuType::menu_base=nullptr;

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
//    if(current_user->getMode()==1)
//    {
//        ActionAddGood* act_good=new ActionAddGood(type_id,parent);
//        act_good->setText("افزودن کالا");
//        this->addAction(act_good);
//        ActionAddType* act_type=new ActionAddType(type_id,parent);
//        act_type->setText("افزودن نوع");
//        this->addAction(act_type);
//    }
}

QMenu *MenuType::getMenu(User *current_user, QWidget *parent)
{
    delete menu_base;

   MenuType::current_user=current_user;
    if(current_user==nullptr)
    {
        return new QMenu("");
    }
    else
    {
         menu_base=new QMenu("دسته بندی کالا ها",parent);
        QVector<QString> base_id=Type::getBaseTypeId();
        for(auto it : base_id)
        {
            const Type& t=Type::getType(it);
            if(t.branchIdIsEmpty()==true)
            {
                menu_base->addAction(new ActoinType(it,menu_base));
            }
            else
            {
                menu_base->addMenu(new MenuType(it,menu_base));
            }
        }
        return  menu_base;
    }

}

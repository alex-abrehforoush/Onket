#include "type.h"

QMap<QString,Type> Type::types;
bool Type::existTypeId(const QString &type_id)
{
    auto it=types.find(type_id);
    if(it == types.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

Type &Type::getType(const QString &type_id)
{
    auto it=types.find(type_id);
    return *it;
}

Type::Type(QString type_name, QString parent_id)
{

    this->parent_id=parent_id;
    this->name=type_name;
    if(this->parent_id=="null")
    {
        this->id=this->name;
    }
    else
    {
        this->id=parent_id;
         this->id.append("/");this->id.append(this->name);
    }

    if(Type::existTypeId(this->id)==false && csv_validator::isValidInCsv(this->id)==true)
    {
        types.insert(this->id,*this);
    }
}

QString Type::getId()const
{
    return  this->id;
}

QString Type::getName() const
{
    return this->name;
}

QString Type::getParentId() const
{
    return  this->parent_id;
}

int Type::getGoodsNumber() const
{
    return this->goods_id.size();
}

int Type::getBranchNumber() const
{
    return this->branches_id.size();
}

bool Type::existBranch(const QString branch_name) const
{
    QString branch_id=this->id;
    branch_id.append("/");branch_id.append(branch_name);

    for(int cnt=0;cnt<this->branches_id.size();cnt++)
    {
        if(branch_id== this->branches_id[cnt])
        {
            return true;
        }
    }
    return false;
}

Type& Type::addBranch(const QString branch_name)
{
    QString branch_id=this->id;
    branch_id.append("/");branch_id.append(branch_name);

    if(existTypeId(branch_id)==true || this->goods_id.isEmpty()==false || csv_validator::isValidInCsv(branch_id)==false)
    {
        return *this;
    }
    else
    {
      this->branches_id.push_back(branch_id);
     Type temp(branch_name,this->id);
     types.insert(temp.getId(),temp);
     return getType(temp.getId());
    }

}

bool Type::removeBranch(const QString &branch_name)
{
    QString branch_id=this->id;
    branch_id.append("/");branch_id.append(branch_name);
    if(existTypeId(branch_id)==false)
    {
        return false;
    }
    else if(getType(branch_id).getGoodsNumber()==0||getType(branch_id).getBranchNumber()==0)
    {
        return false;
    }
    else
    {
        types.remove(branch_id);
        int index=this->branches_id.indexOf(branch_id);
        this->branches_id.remove(index);
    }
}

bool Type::existGood(const QString good_id) const
{
    for(int cnt=0;cnt<this->goods_id.size();cnt++)
    {
        if(this->goods_id[cnt]==good_id)
        {
            return true;
        }

    }
    return false;
}

bool Type::addGood(const QString &good_id)
{
   if(this->existGood(good_id) || csv_validator::isValidInCsv(good_id)==false)
   {
       return false;
   }
   else
   {
       this->goods_id.push_back(good_id);
       return true;
   }
}

bool Type::removeGood(const QString &good_id)
{
    if(this->existGood(good_id)==false)
    {
        return false;
    }
    else
    {
        int index=this->goods_id.indexOf(good_id);
        this->goods_id.remove(index);
        return true;
    }
}

bool Type::existProperty(const QString property_name) const
{
    for(int cnt=0;cnt<this->property_name.size();cnt++)
    {
        if(this->property_name[cnt]==property_name)
        {
            return true;
        }
    }
    return false;
}

bool Type::addProperty(const QString property_name)
{

    if(this->existProperty(property_name)==true)
    {
        return false;
    }
    else if(csv_validator::isValidInCsv(property_name)==false)
    {
        return false;
    }
    else
    {
        this->property_name.push_back(property_name);
        return true;
    }
}

bool Type::removeProperty(const QString property_name)
{

    if(this->existProperty(property_name)==false)
    {
        return false;
    }
    else
    {
        int index=this->property_name.indexOf(property_name);
        this->property_name.remove(index);

        return true;

    }
}

bool Type::existCommentItem(const QString &item_name)
{
    for(int cnt=0;cnt<comment_item.size();cnt++)
    {
        if(this->comment_item[cnt]==item_name)
        {
            return true;
        }
    }

    return false;
}



bool Type::addCommentItem(const QString &item_name)
{
  if(this->existCommentItem(item_name)==true)
  {
      return false;
  }
  else
  {
      this->comment_item.push_back(item_name);

      return true;
  }
}

bool Type::removeCommentItem(const QString &item_name)
{
    if(this->existCommentItem(item_name)==false)
    {
        return false;
    }
    else
    {
        int index=this->comment_item.indexOf(item_name);
        this->comment_item.remove(index);
        return true;
    }
}

void Type::setBranchSeekBegin() const
{
    this->branches_it=this->branches_id.cbegin();
}

QString Type::readBranchId() const
{
    if(this->goods_it==this->goods_id.cend())
    {
        return "";
    }
    QString res=(*this->branches_it);
    if(this->branches_it !=this->branches_id.cend())
    {
        this->branches_it++;
    }
    return res;
}

bool Type::BranchSeekAtEnd() const
{
    if(this->branches_it==this->branches_id.cend())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Type::setGoodSeekBegin() const
{
    this->goods_it=this->goods_id.cbegin();
}

QString Type::readGoodId() const
{
    if(this->goods_it==this->goods_id.cend())
    {
        return "";
    }
    QString res=(*this->goods_it);
    if(this->goods_it !=this->goods_id.cend())
    {
        this->goods_it++;
    }
    return res;
}

bool Type::GoodSeekAtEnd() const
{
    if(this->goods_it==this->goods_id.cend())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Type::setPropertySeekBegin() const
{
    this->property_it=this->property_name.cbegin();
}

QString Type::readPropertyName() const
{
    if(this->property_it==this->property_name.cend())
    {
        return "";
    }
    QString res=(*this->property_it);
    if(this->property_it !=this->property_name.cend())
    {
        this->property_it++;
    }
    return res;
}

bool Type::PropertySeekAtEnd() const
{
    if(this->property_it==this->property_name.cend())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Type::setCommentSeekBegin() const
{
    this->comment_item_it=this->comment_item.cbegin();
}

QString Type::readCommentId() const
{
    if(this->comment_item_it==this->comment_item.cend())
    {
        return "";
    }
    QString res=(*this->comment_item_it);
    if(this->comment_item_it !=this->comment_item.cend())
    {
        this->comment_item_it++;
    }
    return res;
}

bool Type::CommentSeekAtEnd() const
{
    if(this->comment_item_it==this->comment_item.cend())
    {
        return true;
    }
    else
    {
        return false;
    }
}


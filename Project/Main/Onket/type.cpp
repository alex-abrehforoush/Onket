

#include "type.h"

QMap<QString,Type> Type::types;
QString Type::current_type_id="none";
bool Type::addBranch(const QString branch_name)
{
    if(this->existBranch(branch_name)==true)
    {
        return false;
    }
    else
    {
        QString branch_id=this->id;
        branch_id.append("/");branch_id.append(branch_name);
        this->branches_id.push_back(branch_id);
        return true;
    }

}

Type &Type::getTypePrivate(const QString &type_id)
{
    auto it=types.find(type_id);
    return *it;
}

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

const Type &Type::getType(const QString &type_id)
{
    auto it=types.find(type_id);
    return *it;
}

QVector<QString> Type::getBaseTypeId()
{
    QVector <QString>res;
    for(auto it=Type::types.cbegin();it!=Type::types.cend();it++)
    { if((*it).getParentId()=="none")

        res.push_back(it.key());
    }
    return res;
}

QString Type::getCurrentTypeId()
{
    return Type::current_type_id;
}

void Type::setCurrentTypeId(QString type_id)
{
    if(Type::existTypeId(type_id)==true)
    {
        Type::current_type_id=type_id;
    }
}

Type::Type(QString type_name, QString parent_id)
{

    this->parent_id=parent_id;
    this->name=type_name;
    if(this->parent_id=="none")
    {
        this->id=this->name;

    }
    else
    {
        this->id=parent_id;
         this->id.append("/");this->id.append(this->name);
    }

    if(Type::existTypeId(this->id)==false  && csv_validator::isValidInCsv(this->id)==true)
    {
        if(Type::existTypeId(parent_id)==false)
        {
            if(this->parent_id=="none")
           {
               Type::types.insert(this->id,*this);
               return;
           }
           else
           {
               return;
           }
        }
        Type& parent=Type::getTypePrivate(this->parent_id);
        parent.addBranch(this->name);

        for(parent.setCommentSeekBegin();parent.CommentSeekAtEnd()==false;)
        {
            this->addCommentItem(parent.readCommentItem());
        }
        for(parent.setPropertySeekBegin();parent.PropertySeekAtEnd()==false;)
        {
            this->addProperty(parent.readPropertyName());
        }

        Type::types.insert(this->id,*this);
    }
}

Type::Type(const QString &line)
{
    using namespace csv_QVector;
    QStringList str_list=line.split(";");

   if(str_list.size()!=7)
   {
       return;
   }
   else
   {
       this->id=str_list[0];this->name=str_list[1];this->parent_id=str_list[2];
       if(Type::existTypeId(this->id)==true)
       {
           return;
       }
       this->branches_id=toQVector(str_list[3]);
       this->goods_id=toQVector(str_list[4]);
       this->property_name=toQVector(str_list[5]);
       this->comment_item=toQVector(str_list[6]);

       Type::types.insert(this->id,*this);

   }
}

void Type::addToFile(QTextStream &txt_writer)
{
    using namespace csv_QVector;
    txt_writer<<this->id.toUtf8()<<";"<<this->name.toUtf8()<<";"<<this->parent_id.toUtf8()<<";"<<toQString(this->branches_id).toUtf8()<<";"<<toQString(this->goods_id).toUtf8()<<";"<<toQString(this->property_name).toUtf8()<<";"<<toQString(this->comment_item).toUtf8()<<endl;
}

bool Type::WriteToFile()
{

   QString path="Database/Types";
    QDir d;
    if(d.exists(path)==false)
    {
        d.mkpath(path);
    }
    path.append("/Types.csv");

    QFile file(path);
    if(file.open(QFile::WriteOnly | QFile::Text)==false)
    {
        return false;

    }

    else
    {
        QTextStream txt_writer;
        txt_writer.setDevice(& file);
        //txt_writer.setAutoDetectUnicode(true);
        txt_writer.setCodec("UTF-8");
        txt_writer<<"id;name;parent_id;children_id;goods_id;property;comment"<<endl;
        for(auto it: Type::types)
        {
            it.addToFile(txt_writer);
        }
        file.flush();
        file.close();
        return true;
    }
}

bool Type::readFile()
{
     Type::types.clear();
     QString path="Database/Types";
     QDir d;
     if(d.exists(path)==false)
     {
         d.mkpath(path);
     }
     path.append("/Types.csv");

     QFile file(path);
     if(file.open(QFile::ReadOnly | QFile::Text)==false)
     {
         return false;

     }
     else
     {
         QTextStream txt_reader;
         txt_reader.setDevice(& file);
         txt_reader.setCodec("UTF-8");
         txt_reader.readLine();
         while(txt_reader.atEnd()==false)
         {
             Type(txt_reader.readLine());
         }

         file.flush();
         file.close();
         return true;
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
        return true;
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

bool Type::addGood(const QString &good_id)const
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

bool Type::removeGood(const QString &good_id)const
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

bool Type::GoodListIsEmpty()const
{
    return  this->goods_id.empty();
}

bool Type::existProperty(const QString input) const
{
    for(int cnt=0;cnt<this->property_name.size();cnt++)
    {
        QString s=this->property_name[cnt];
        if(this->property_name[cnt]==input)
        {
            return true;
        }
    }
    return false;
}

bool Type::addProperty(const QString property_name)const
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

bool Type::removeProperty(const QString property_name)const
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

bool Type::existCommentItem(const QString &item_name)const
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



bool Type::addCommentItem(const QString &item_name)const
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

bool Type::removeCommentItem(const QString &item_name)const
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

bool Type::branchIdIsEmpty() const
{
    return this->branches_id.empty();
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

QString Type::readCommentItem() const
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


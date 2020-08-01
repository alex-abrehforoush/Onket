#include "comment.h"
const QVector<double> Comment::grades={0.0,0.25,0.5,0.75,1.0};
/////

QString Comment::itemToXml(const QString &item_name)
{
    QString resualt;
   for(auto it=item_name.cbegin(); it!= item_name.cend();it++)
   {
       if(*it==' ')
       {
           resualt.append("-");
       }
       else
       {
           resualt.append(*it);
       }
   }
   return  resualt;
}

bool Comment::isValidInxml(const QString &input)
{
    for(auto it=input.cbegin();it != input.cend();it++)
    {
        if(*it=='<'||*it== '>')
        {
            return false;
        }
    }


        return true;
}

QString Comment::xmlToItem(const QString &xml)
{
    QString resualt;
   for(auto it=xml.cbegin(); it!= xml.cend();it++)
   {
       if(*it=='-')
       {
           resualt.append(" ");
       }
       else
       {
           resualt.append(*it);
       }
   }
   return  resualt;
}

QString Comment::toQString(const QMap<QString, bool> &input)
{
    if(input.isEmpty()==true)
    {
        return QString("");
    }

    auto it=input.cbegin();
    QString resault=it.key();
    resault.append("_");
    resault.append(QString::number(*it));

    if(it != input.cend())
        it++;
    for(;it !=  input.cend();it++)
    { resault.append(",");
        resault.append(it.key());
        resault.append("_");
        resault.append(QString::number(*it));

    }
    return resault;
}

QMap<QString, bool> Comment::toQMap(const QString &input)
{
    QMap<QString,bool>resualt;
    QString sender;
    for(auto it=input.cbegin();it != input.cend(); it++)
    {
        if(*it == '_')
        {
            it++;
            bool mode;
            if(*it=='0')
            {
                mode=false;
            }
            else
            {
                mode=true;
            }
            it++;
            resualt.insert(sender,mode);
            sender.clear();
        }
        else
        {
         sender.append(*it);
        }
    }
    return resualt;
}

bool Comment::setAdvantages(const QString & advantages)
{
    if(this->isValidInxml(advantages)==false)
    {
        return false;
    }
    this->advantages=advantages;
    return true;
}

bool Comment::setDisAdvantages(const QString &disadvantages)
{
    if(this->isValidInxml(disadvantages)==false)
    {
        return false;
    }
    this->disadvantages=disadvantages;
    return true;
}

bool Comment::setDescription(const QString &description)
{   if(this->isValidInxml(description)==false)
    {
        return false;
    }
    this->description=description;
    return true;
}

QString Comment::getSenderId()
{
    return this->sender_id;
}

QString Comment::getAdvantages()
{
    return this->advantages;
}

QString Comment::getDisadvantages()
{
    return this->disadvantages;
}


QString Comment::getDescription()
{
    return this->description;
}

bool Comment::find(const QString &sender_id)
{
    auto it=users_like.find(sender_id);
    if (it != users_like.end())
    {
        return true;
    }
    else return false;
}

void Comment::addLike(const QString &sender_id)
{
    auto it=users_like.find(sender_id);
    if (it != users_like.end())
    {
        users_like[sender_id]=true;
    }
    else
    {
        users_like.insert(sender_id,true);
    }
}

void Comment::addDisLike(const QString &sender_id)
{
    auto it=users_like.find(sender_id);
    if (it != users_like.end())
    {
        users_like[sender_id]=false;
    }
    else
    {
        users_like.insert(sender_id,false);
    }
}

bool Comment::getLikeMode(const QString &sender_id)
{
    if(this->find(sender_id)==true)
    {
        return users_like[sender_id];
    }
    else return true;
}




bool Comment::insertItem(const QString &item_name)
{
    bool resualt;
    auto it=map_items.find(item_name);
    if(it == map_items.end())
    {
        foreach(QChar ch,item_name)
        {
            if(ch=='-' || ch=='\n' || ch=='*' ||ch=='~' || ch=='$' || ch=='<' || ch=='>')
                return false;


        }
        resualt=true;
        map_items.insert(item_name,0.5);
    }


    else
    {

        resualt=false;
    }



    return resualt;
}

bool Comment::removeItem(const QString &item_name)
{
    bool resualt;
    auto it=map_items.find(item_name);
    if(it != map_items.end())
    {
        resualt=true;
        map_items.remove(item_name);
    }
    else
        resualt=false;



    return resualt;
}

bool Comment::setItemValue(const QString &item_name, double item_value)
{
  auto it=map_items.find(item_name);
  if(it == map_items.end())
  {
      return  false;
  }
  else
  {
      bool resualt=false;
      for(auto i :grades)
      {
          if(i == item_value)
          {
              resualt=true;
              *it=item_value;
          }
      }
      return  resualt;
  }
}



Comment::Comment(const QString& sender_id,const QString& advantages,const QString& disadvatages, const QString &description)
{
    this->sender_id=sender_id;
    this->setAdvantages(advantages);
    this->setDisAdvantages(disadvatages);
    this->setDescription(description);

    map_items.insert("قیمت",0.5);
}

Comment::~Comment()
{


}

void Comment::addToFile(QXmlStreamWriter &xml_writer)
{
    xml_writer.writeStartElement("comment");

        for(auto it=map_items.begin();it != map_items.end();it++)
        {
            xml_writer.writeAttribute(itemToXml(it.key()),QString::number(it.value()));
        }

       xml_writer.writeTextElement("sender_id",this->sender_id);
        xml_writer.writeTextElement("advantages",this->advantages);
         xml_writer.writeTextElement("disadvantages",this->disadvantages);
       xml_writer.writeTextElement("description",this->description);
        xml_writer.writeTextElement("users_like",Comment::toQString(this->users_like));
    xml_writer.writeEndElement();
}




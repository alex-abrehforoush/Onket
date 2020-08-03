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

QDate Comment::getDateCreate()
{
    return this->date_create;
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

unsigned int Comment::getLikeNumber()
{
    return this->like;
}

unsigned int Comment::getDisLikeNumber()
{
    return this->dislike;
}

unsigned int Comment::getViewNumber()
{
    return this->like+this->dislike;
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
        if(users_like[sender_id]==false)
        {
            this->dislike--;
            this->like++;
        }
        users_like[sender_id]=true;
    }
    else
    {
        users_like.insert(sender_id,true);
        this->like++;
    }
}

void Comment::addDisLike(const QString &sender_id)
{
    auto it=users_like.find(sender_id);
    if (it != users_like.end())
    {
        if(users_like[sender_id]== true)
        {
            this->like--;
            this->dislike++;
        }
        users_like[sender_id]=false;
    }
    else
    {
        users_like.insert(sender_id,false);
        this->dislike++;
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
            if(ch=='-' || ch=='\n' || ch=='*' ||ch=='~' || ch=='$' || ch=='<' || ch=='>' || ch=='&')
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



Comment::Comment(const QDate& date_create,const QString& sender_id,const QString& advantages,const QString& disadvatages, const QString &description)
{
    this->date_create=date_create;
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
       xml_writer.writeTextElement("date",file_QDate::toQString(this->date_create));
        xml_writer.writeTextElement("advantages",this->advantages);
         xml_writer.writeTextElement("disadvantages",this->disadvantages);
       xml_writer.writeTextElement("description",this->description);
        xml_writer.writeTextElement("users_like",xml_QMap::toQString(this->users_like));
    xml_writer.writeEndElement();
}




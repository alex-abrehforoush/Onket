#include "comment.h"
const QVector<double> Comment::grades={0.0,0.25,0.5,0.75,1.0};
/////

void Comment::setDescription(const QString &description)
{
    this->description=description;
}

QString Comment::getSenderId()
{
    return this->sender_id;
}


QString Comment::getDescription()
{
    return this->description;
}

bool Comment::insertItem(const QString &item_name)
{
    bool resualt;
    auto it=map_items.find(item_name);
    if(it == map_items.end())
    {
        foreach(QChar ch,item_name)
        {
            if(ch==' ' || ch=='\n')
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



Comment::Comment(const QString& sender_id, const QString &description)
{
    this->sender_id=sender_id;

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
            xml_writer.writeAttribute(it.key(),QString::number(it.value()));
        }

       xml_writer.writeTextElement("sender_id",this->sender_id);

       xml_writer.writeTextElement("description",this->description);
    xml_writer.writeEndElement();
}




#include "question.h"


QString Question::toQString(const QVector<QString> &replys_id)
{
    if(replys_id.isEmpty()==true)
    {
        return QString("");
    }
    QString resualt;
    auto it=replys_id.cbegin();
    resualt=*it;
    if(it != replys_id.cend())
     it++;
    for(;it != replys_id.cend();it++)
    {
        resualt.append(",");
        resualt.append(*it);
    }
    return  resualt;
}

QString Question::readReply()const
{
  if(this->replys_it == this->replys.begin() || this->replys.isEmpty()==true )
  {
      return  "";
  }
  else
  {
      this->replys_it--;
      return replys_it.value();

  }
}

void Question::setReplySeekBegin()const
{
   this->replys_it=this->replys.end();

}

bool Question::replySeekAtEnd()const
{
    if(this->replys_it == this->replys.begin())
    {
        return true;
    }
    else
    {
        return false;
    }
}





Question::Question(const QDate &date_create, const QString &id, const QString &sender_id, const QString &content)
    :DiscussionItem(date_create,id,sender_id,content)
{

}

Question::~Question()
{

}

bool Question::existReply(const QString &reply_id)const
{
    auto it=replys_id.find(reply_id);
    if(it != this->replys_id.end())
    {
        return true;
    }
    return false;
}

bool Question::addReply(const QString &reply_id)
{

    if(this->existReply(reply_id)==true)
    {
        return false;
    }
    else
    {
        this->replys_id.insert(reply_id,true);
        this->replys.insert(0,reply_id);
        return true;
    }

}

bool Question::changeReplyLike(const QString &reply_id, unsigned int reply_like_number)
{
 if(this->existReply(reply_id)==false)
     return false;
 else
 {
     auto it=this->replys.begin();
     for(;it != this->replys.end();it++)
     {
         if(it.value()==reply_id)
             break;
     }
     ////
     /// Creat key & value varible because when you want to remove a elemnt form QMultiMap check and remove all
     /// elemnt with this key and value so when you send it.value as an arg in function remove it and then want to compare this content by itself iterator
     ///

     unsigned int key=it.key();
     QString value=it.value();


     if(it.key()==reply_like_number)
     {
        ;
     }
     else
     {

        this->replys.remove(key,value);
         this->replys.insert(reply_like_number,value);
         this->setReplySeekBegin();
     }

     return true;
 }
}

unsigned int Question::getReplyNumber()const
{
    return this->replys_id.size();
}

void Question::addToFile(QXmlStreamWriter &xml_writer)
{
    xml_writer.writeStartElement("question");
       xml_writer.writeTextElement("id",this->id);
       xml_writer.writeTextElement("sender_id",this->sender_id);
       xml_writer.writeTextElement("date",file_QDate::toQString(this->date_create));
       xml_writer.writeTextElement("content",this->content);
      // xml_writer.writeTextElement("replys_id",xml_QMap::toQString(this->replys));
    xml_writer.writeEndElement();
}

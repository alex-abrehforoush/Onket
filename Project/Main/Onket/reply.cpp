#include "reply.h"

QString Reply::toQString(const QMap<QString, bool>& input)
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

QMap<QString, bool> Reply::toQMap(const QString &input)
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

unsigned int Reply::getLikeNumber()
{
    return this->like;
}

unsigned int Reply::getDisLikeNumber()
{
    return this->dislike;
}

Reply::Reply(const QDate &date_create, const QString &id, const QString &sender_id, const QString &content)
    :DiscussionItem(date_create,id,sender_id,content)
{

}

void Reply::addLike(const QString &sender_id)
{
    auto it= users_like.find(sender_id);
    if(it != users_like.end())
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

void Reply::addDisLike(const QString &sender_id)
{
    auto it= users_like.find(sender_id);
    if(it != users_like.end())
    {
        if(users_like[sender_id] == true)
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

bool Reply::find(const QString &sender_id)
{
    auto it=users_like.find(sender_id);
    if(it != users_like.cend())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Reply::getLikeMode(const QString &sender_id)
{
    if(this->find(sender_id)==true)
    {
        return users_like[sender_id];
    }
    else
    {
        return true;
    }
}





void Reply::addToFile(QXmlStreamWriter &xml_writer)
{
    xml_writer.writeStartElement("reply");
        xml_writer.writeAttribute("like",QString::number(this->like));
        xml_writer.writeAttribute("dislike",QString::number(this->dislike));
        xml_writer.writeTextElement("id",this->id);
        xml_writer.writeTextElement("sender_id",this->sender_id);
        xml_writer.writeTextElement("date",DiscussionItem::toQString(this->date_create));
        xml_writer.writeTextElement("content",this->content);
        xml_writer.writeTextElement("users_like",Reply::toQString(this->users_like));
    xml_writer.writeEndElement();
}



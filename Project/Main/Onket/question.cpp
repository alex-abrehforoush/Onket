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

QVector<QString> Question::toVector(const QString &input)
{
    QVector<QString>resualt;
    QString str;
    for(auto it=input.cbegin();it!=input.cend();it++)
    {
        if(*it==',')
        {
            resualt.push_back(str);
            str.clear();

        }
        else
        {
            str.append(*it);
        }

    }
    return  resualt;
}

QVector<QString> Question::getReplysId()
{
    return this->replys_id;
}

Question::Question(const QDate &date_create, const QString &id, const QString &sender_id, const QString &content)
    :DiscussionItem(date_create,id,sender_id,content)
{

}

Question::~Question()
{

}

bool Question::addReply(const QString &reply_id)
{

    int index=this->replys_id.indexOf(reply_id);
    if(index <= this->replys_id.size() && index>0)
        return false;

    else
    {
        this->replys_id.push_back(reply_id);

        return true;
    }


}

void Question::addToFile(QXmlStreamWriter &xml_writer)
{
    xml_writer.writeStartElement("question");
       xml_writer.writeTextElement("id",this->id);
       xml_writer.writeTextElement("sender_id",this->sender_id);
       xml_writer.writeTextElement("date",DiscussionItem::toQString(this->date_create));
       xml_writer.writeTextElement("content",this->content);
       xml_writer.writeTextElement("replys_id",Question::toQString(this->replys_id));
    xml_writer.writeEndElement();
}

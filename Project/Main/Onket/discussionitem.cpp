#include "discussionitem.h"


bool DiscussionItem::isValidInXml(const QString &input)
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



bool DiscussionItem::setContent(const QString &content)
{
    if(this->isValidInXml(content) == false)
    {
        return false;
    }
    this->content=content;
    return true;
}

QString DiscussionItem::getId()
{
    return this->id;

}

QString DiscussionItem::getSenderId()
{
    return  this->sender_id;
}

QString DiscussionItem::getContent()
{
    return  this->content;
}

QDate DiscussionItem::getDateCreate()
{
    return this->date_create;
}



DiscussionItem::DiscussionItem(const QDate& date_create, const QString &id, const QString &sender_id, const QString &content)
    :date_create(date_create)
{
    this->id=id;
    this->sender_id=sender_id;
    this->setContent(content);
}

DiscussionItem::~DiscussionItem()
{

}






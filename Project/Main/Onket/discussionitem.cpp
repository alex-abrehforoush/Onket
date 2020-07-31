#include "discussionitem.h"

void DiscussionItem::setContent(const QString &content)
{
    this->content=content;
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

DiscussionItem::DiscussionItem(const QString &id, const QString &sender_id, const QString &content)
{
    this->id=id;
    this->sender_id=sender_id;
    this->content=content;
}

DiscussionItem::~DiscussionItem()
{

}



#ifndef DISCUSSIONITEM_H
#define DISCUSSIONITEM_H
#include <QString>
#include <QDate>
#include <QXmlStreamWriter>

class DiscussionItem
{
    QString id;
    QString sender_id;
    QString content;
    QDate date_create;
public:
    void setContent(const QString& content);

    QString getId();
    QString getSenderId();
    QString getContent();
    QDate getDateCreate();
    DiscussionItem(const QDate& date_create, const QString& id,const QString& sender_id,const QString& content );
    ~DiscussionItem();
    virtual void addToFile(QXmlStreamWriter & xml_writer)=0;
};

#endif // DISCUSSIONITEM_H

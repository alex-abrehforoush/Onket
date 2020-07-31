#ifndef REPLY_H
#define REPLY_H

#include <QMap>
#include "discussionitem.h"

class Reply: public DiscussionItem
{
    unsigned int like=0,dislike=0;
    QMap<QString,bool>users_like;

public:
    static QString toQString(const QMap<QString,bool> & input);
    static QMap<QString,bool> toQMap(const QString& input);

    unsigned int getLike();
    unsigned int getDisLike();



    Reply(const QDate& date_create, const QString& id,const QString& sender_id,const QString& content);
    bool addBoolianComment(const QString& sender_id,bool like);
    virtual void addToFile(QXmlStreamWriter &xml_writer) override;
};

#endif // REPLY_H

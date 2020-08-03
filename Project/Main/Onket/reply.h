#ifndef REPLY_H
#define REPLY_H

#include <QMap>
#include "discussionitem.h"

class Reply: public DiscussionItem
{
    unsigned int like=0,dislike=0;
    QMap<QString,bool>users_like;

public:


    unsigned int getLikeNumber()const;
    unsigned int getDisLikeNumber()const;



    explicit Reply(const QDate& date_create, const QString& id,const QString& sender_id,const QString& content);
    void addLike(const QString& sender_id);
    void addDisLike(const QString& sender_id);
    bool exist(const QString& sender_id);
    bool getLikeMode(const QString& sender_id)const;

    virtual void addToFile(QXmlStreamWriter &xml_writer) override;
};

#endif // REPLY_H

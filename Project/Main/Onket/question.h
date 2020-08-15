
#ifndef QUESTION_H
#define QUESTION_H

#include "discussionitem.h"
#include <QMultiMap>
#include <QMap>

class Question :public DiscussionItem
{
    QMap<QString,bool> replys_id;
    QMultiMap<unsigned int,QString> replys;
    mutable QMultiMap<unsigned int,QString> ::const_iterator replys_it=replys.end();

public:
    static QString toQString(const QVector<QString> & replys_id);
    QString readReply()const;// return a reply_id
    void setReplySeekBegin()const;
    bool replySeekAtEnd()const;

   const  QVector<QString>& getReplysId()const;
     explicit Question(const QDate& date_create, const QString& id,const QString& sender_id,const QString& content);
    ~Question();
     bool existReply(const QString& reply_id)const;
     bool addReply(const QString & reply_id) ;
        bool changeReplyLike(const QString& reply_id,unsigned int reply_like_number);

     unsigned int getReplyNumber()const;
    virtual void addToFile(QXmlStreamWriter &xml_writer) override;
};

#endif // QUESTION_H


#ifndef QUESTION_H
#define QUESTION_H

#include "discussionitem.h"
#include <QVector>

class Question :public DiscussionItem
{
    QVector<QString> replys_id;

public:
    static QString toQString(const QVector<QString> & replys_id);
    static QVector<QString> toVector(const QString& input);

    Question(const QDate& date_create, const QString& id,const QString& sender_id,const QString& content);
    ~Question();
    virtual bool addView(const QString & reply_id, bool) override;
    virtual void addToFile(QXmlStreamWriter &xml_writer) override;
};

#endif // QUESTION_H

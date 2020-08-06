#ifndef GOOD_H
#define GOOD_H

#include <QMultiMap>
#include <QMap>
#include <map>


#include "filefunctions.h"

#include "comment.h"
#include "question.h"
#include "reply.h"


class Good
{
    QString id;
    QString type_id;
    QString maker_id;

    unsigned  int price;
    double discount_percent=0.0;
    QMap<QString,QString> properties;


    QMultiMap<QString,Comment>comments;//first field is sort part name
    QMap<QString,bool>comments_id;//save comment sender_id  the secend part igonre
    QMultiMap<QString,Comment>::iterator comments_it=comments.end();
    QString comments_sort_by = "date";

    QMultiMap<QString,Question> questions;//first field is sort part name
    QMap<QString,bool> questions_id;//save question id  the secend part igonre
    QMultiMap<QString,Question>::iterator question_it=questions.end();
    QString question_sort_by = "date";

    QMap<QString,Reply> replys;


    Question& getQuestionPrivate(const QString& question_id);
     Reply &getReplyPrivate(const QString& reply_id);
    static QString toQString(unsigned int input);

public:
    void setPrice(unsigned int price);
    void setFinalPrice(unsigned int final_price);
    bool setDiscountPercent(double discount_percent);
    unsigned int getPrice();
    unsigned int getFinalPrice();
    double getFinalDiscountPrice();

    bool existProperty(const QString& property_name);
    bool insertProperty(const QString& property_name);
    bool setPropertyValue(const QString& property_name,const QString& property_value);

    bool existCommentSender(const QString& sender_id);
    Comment& getComment(const QString& sender_id);
    Comment& readComment();
    void setCommentSeekBegin();
    bool commentSeekAtEnd();
    bool addComment(const Comment& new_comment);
    bool changeComment(const Comment& input_comment);

//    bool existQuestion(const QString& question_id);
//    const Question& getQuestion(const QString & question_id);
    bool existQuestionContent(const QString& content);
    bool existQuestionId(const QString& question_id);
    QString getIdQustion(const QString& content);
    const Question& getQuestion(const QString& question_id);
    const Question& readQuestion();
    void setQuestionSeekBegin();
    bool QuestionSeekAtEnd();
    QString addQuestion(const QDate& date_create,const QString& sender_id, const QString& content);//return question_id
   const Reply& getReply(const QString& reply_id);

    bool existReply(const QString& sender_id,const QString& question_id);
    bool existReply(const QString& reply_id);
    QString addReply(const QString& question_id,const QDate& date_create,const QString& sender_id,const QString& content);
    bool addReplyLike(const QString& reply_id,const QString& sender_id);
    bool addReplyDisLike(const QString& reply_id,const QString& sender_id);

    void commentSortByDate();
    void commentSortByLike();
    void commentSortByView();

    void QuestionSortByDate();
    void QuestionSortyByReplyNumber();

    Good();
};

#endif // GOOD_H

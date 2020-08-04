#ifndef GOOD_H
#define GOOD_H

#include <QMultiMap>
#include <QMap>


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

    QMultiMap<QString,Comment> comments;//first field is sort part name
    QMap<QString,bool>comments_id;//save comment sender_id  the secend part igonre
    QMap<QString,Comment>::iterator comments_it=comments.begin();
    QString comments_sort_by = "date";

    QMultiMap<QString,Question> questions;//first field is sort part name
    QMap<QString,bool> questions_id;//save question id  the secend part igonre
    QMap<QString,Question>::iterator question_it=questions.begin();
    QString question_sort_by = "date";

    QMap<QString,Reply> replys;



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
    bool existQuestion(const QString& content);
    QString getIdQustion(const QString& content);
    Question& getQuestion(const QString& question_id);
    Question& readQuestion();
    void setQuestionSeekBegin();
    bool QuestionSeekAtEnd();
    QString addQuestion(const QDate& date_create,const QString& sender_id, const QString& content);//return question_id
    Reply& getReply(const QString& reply_id);
    bool existReply(const QString& sender_id,const QString& question_id);
    QString addReply(const QString& question_id,const QDate& date_create,const QString& sender_id,const QString& content);
    Good();
};

#endif // GOOD_H

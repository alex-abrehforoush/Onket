#ifndef GOOD_H
#define GOOD_H

#include <QMultiMap>
#include <QMap>
#include <map>
#include <QFile>
#include <QDir>



#include "filefunctions.h"

#include "comment.h"
#include "question.h"
#include "reply.h"

#include "type.h"



class Good
{

    static QMap<QString,Good> goods_id;
    static QMap<QString,bool> goods_name;

    QString id;
    QString name;
    QString type_id;
    QString maker_id;

    unsigned  int price;
    double discount_percent=0.0;
    QMap<QString,QString> properties;
    mutable QMap<QString,QString>::const_iterator property_it=properties.begin();

    QMultiMap<QString,Comment>comments;//first field is sort part name
    QMap<QString,double>comments_item;
    mutable QMap<QString,double>::const_iterator comments_item_it=comments_item.begin();
    QMap<QString,bool>comments_id;//save comment sender_id  the secend part igonre
    QMultiMap<QString,Comment>::iterator comments_it=comments.end();
    QString comments_sort_by = "date";

    QMultiMap<QString,Question> questions;//first field is sort part name
    QMap<QString,bool> questions_id;//save question id  the secend part igonre
    QMultiMap<QString,Question>::iterator question_it=questions.end();
    QString question_sort_by = "date";

    QMap<QString,Reply> replys;

    void controlItemscomment(Comment& input);
    Comment& getCommentPrivate(const QString& sender_id);
    Question& getQuestionPrivate(const QString& question_id);
     Reply &getReplyPrivate(const QString& reply_id);
    static QString toQString(unsigned int input);



public:

    static bool  existGoodId(const QString& good_id);
    static Good& getGood(const QString& good_id);
    static bool existGoodName(const QString& good_name);

    QString getId()const;
    QString getName()const;

    static bool readFile();
    static bool WriteFile();



    void setPrice(unsigned int price);
    void setFinalPrice(unsigned int final_price);
    bool setDiscountPercent(double discount_percent);
    unsigned int getPrice();
    unsigned int getFinalPrice();
    double getDiscountpercent();

    bool existProperty(const QString& property_name)const;
    bool addProperty(const QString& property_name);
    bool setPropertyValue(const QString& property_name,const QString& property_value);
    QString getPropertyValue(const QString& property_name)const;
    void setPropertySeekBegin()const;
    QString readPropertyName()const;
    bool propertySeekAtEnd()const;


    bool existCommentSender(const QString& sender_id);
    bool existCommentItem(const QString& item_name)const;
    bool addCommentItem(const QString& item_name);
    void commentAddLike(const QString& comment_sender,const QString& liker_id);
    void commentAddDisLike(const QString& comment_sender,const QString& disliker_id);
    bool commentRemoveLiker(const QString& comment_sender,const QString& liker_id);
    bool CommentSetItemValue(const QString& comment_sender,const QString& item_name,const double& item_value);
    double CommentGetItemValue(const QString& comment_sender,const QString& item_name);
    double CommentGetItemValue(const QString& item_name);
    const Comment& getComment(const QString& sender_id);
    const Comment& readComment();
    void setCommentSeekBegin();
    bool commentSeekAtEnd();
    void setCommentItemSeekBegein()const;
    QString readCommentsItem()const;
    bool CommentItemSeekAtEnd()const;


    bool addComment( Comment new_comment);
    //bool changeComment(const Comment& input_comment);

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

    void commentsReadFile();
    void commentsWriteToFile();
    void QuestionReadFile();
    void QUestionWriteToFile();
    void ReplyReadFile();
    void ReplyWriteToFile();

    explicit Good(const QString& name,const QString& type_id,const QString& maker_id,unsigned int price);
    explicit Good(const QString& line);

    void addToFile( QTextStream& txt_stream);

};

#endif // GOOD_H



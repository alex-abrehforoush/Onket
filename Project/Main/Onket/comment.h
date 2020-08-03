#ifndef COMMENT_H
#define COMMENT_H


#include <QString>
#include <QDate>

#include <QVector>
#include <QMap>

#include <QXmlStreamWriter>

#include "filefunctions.h"


class Comment
{
    static const QVector<double> grades;
    QString sender_id;
    QDate date_create;
    QMap<QString,double>map_items;//the key is item name & the value is item value
    QMap<QString,bool>users_like;
    unsigned int like=0,dislike=0;
    QString advantages,disadvantages;
    QString description;

    QString itemToXml(const QString& item_name);
    bool isValidInxml(const QString& input);
public:


    static QString xmlToItem(const QString& xml);



    bool setAdvantages(const QString &advantages);
    bool setDisAdvantages(const QString & disadvantages);
    bool setDescription(const QString& description);

    QString getSenderId();
    QDate getDateCreate();

    QString getAdvantages();
    QString getDisadvantages();
    QString getDescription();

    unsigned int getLikeNumber();
    unsigned int getDisLikeNumber();
    unsigned int getViewNumber();
    bool exist(const QString& sender_id);
    void addLike(const QString& sender_id);
    void addDisLike(const QString& sender_id);
    bool getLikeMode(const QString& sender_id);

    bool insertItem(const QString& item_name);
    bool removeItem(const QString& item_name);
    bool setItemValue(const QString& item_name,double item_value);

    explicit Comment(const QDate& date_create,const QString& sender_id,const QString& advantages,const QString& disadvatages,const QString & description);
    ~Comment();

    void addToFile(QXmlStreamWriter & xml_writer);

};



#endif // COMMENT_H

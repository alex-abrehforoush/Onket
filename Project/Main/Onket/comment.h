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
    QMap<QString,double>map_items;
    mutable QMap<QString,double>::const_iterator map_it=map_items.cbegin();
   ///the key is item name & the value is item value
    QMap<QString,bool>users_like;
    unsigned int like=0,dislike=0;
    mutable QString advantages;
    mutable QString disadvantages;
   mutable QString description;

    static QString itemToXml(const QString& item_name);
    static bool isValidInxml(const QString& input);
public:


    static QString xmlToItem(const QString& xml);
    static bool isValidGrade(double item_value);


    bool setAdvantages(const QString &advantages)const;
    bool setDisAdvantages(const QString & disadvantages)const;
    bool setDescription(const QString& description)const;

    QString getSenderId()const ;
    QDate getDateCreate()const ;

    QString getAdvantages()const;
    QString getDisadvantages()const;
    QString getDescription()const;

    unsigned int getLikeNumber()const;
    unsigned int getDisLikeNumber()const;
    unsigned int getViewNumber()const;
    bool exist(const QString& liker_id);
    void addLike(const QString& sender_id);
    void addDisLike(const QString& sender_id);
    bool getLikeMode(const QString& sender_id);

    bool insertItem(const QString& item_name);
    bool removeItem(const QString& item_name);
    bool existItem(const QString& item_name)const;
    bool setItemValue(const QString& item_name,double item_value);
    double getItemValue(const QString& item_name)const;
    void setItemSeekBegin()const;

    bool ItemSeekAtEnd();
    QString readItemName()const;

    explicit Comment(const QDate& date_create,const QString& sender_id,const QString& advantages,const QString& disadvatages,const QString & description);
    ~Comment();

    void addToFile(QXmlStreamWriter & xml_writer);

};



#endif // COMMENT_H



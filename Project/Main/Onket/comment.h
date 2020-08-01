#ifndef COMMENT_H
#define COMMENT_H
#include <QString>
#include <QVector>
#include <QMap>
#include <QXmlStreamWriter>


class Comment
{
    static const QVector<double> grades;
    QString sender_id;
    QMap<QString,double>map_items;//the key is item name & the value is item value
    QMap<QString,bool>users_like;
    QString advantages,disadvantages;
    QString description;
    QString itemToXml(const QString& item_name);
    static QString toQString(const QMap<QString,bool>& input);
public:
    static QString xmlToItem(const QString& xml);

    static QMap<QString,bool> toQMap(const QString & input);

    void setAdvantages(const QString &advantages);
    void setDisAdvantages(const QString & disadvantages);
    void setDescription(const QString& description);

    QString getSenderId();

    QString getAdvantages();
    QString getDisadvantages();
    QString getDescription();

    bool find(const QString& sender_id);
    void addLike(const QString& sender_id);
    void addDisLike(const QString& sender_id);
    bool getLikeMode(const QString& sender_id);

    bool insertItem(const QString& item_name);
    bool removeItem(const QString& item_name);
    bool setItemValue(const QString& item_name,double item_value);

    Comment(const QString& sender_id,const QString& advantages,const QString& disadvatages,const QString & description);
    ~Comment();

    void addToFile(QXmlStreamWriter & xml_writer);

};



#endif // COMMENT_H

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
    QString description;
public:

    void setDescription(const QString& description);

    QString getSenderId();

    QString getDescription();

    bool insertItem(const QString& item_name);
    bool removeItem(const QString& item_name);
    bool setItemValue(const QString& item_name,double item_value);

    Comment(const QString& sender_id,const QString & description);
    ~Comment();

    void addToFile(QXmlStreamWriter & xml_writer);

};

#endif // COMMENT_H

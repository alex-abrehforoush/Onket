#ifndef COMMENT_H
#define COMMENT_H
#include <QString>
#include <QVector>
#include <QXmlStreamWriter>

class Comment
{
    static const QVector<QString> grades;
    QString sender_id;
     QString quality_grad="mediom",price_grade="mediom";
     QString description;
public:
    void setQuality(const QString& quality);
    void setPrice(const QString& price);
    void setDescription(const QString& description);

    QString getSenderId();
    QString getQuality();
    QString getPrice();
    QString getDescription();

    Comment(const QString& sender_id,const QString& quality,const QString& price,const QString & description);
    ~Comment();

    void addToFile(QXmlStreamWriter & xml_writer);

};

#endif // COMMENT_H

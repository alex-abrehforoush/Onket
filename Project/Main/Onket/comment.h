#ifndef COMMENT_H
#define COMMENT_H
#include <QString>
#include <QVector>

class Comment
{
    static const QVector<QString> grades;
     QString quality_grad="mediom",price_grade="mediom";
     QString description;
public:
    void setQuality(const QString& quality);
    void setPrice(const QString& price);
    void setDescription(const QString& description);

    QString getQuality();
    QString getPrice();
    QString getDescription();
    /////
    Comment(const QString& quality,const QString& price,const QString & description);
    ~Comment();

};

#endif // COMMENT_H

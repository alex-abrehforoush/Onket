#ifndef COMMENT_H
#define COMMENT_H
#include <QString>
#include <QVector>
#include <QXmlStreamWriter>

class Comment
{
    static const QVector<double> grades;
    QString sender_id;
    double quality_grad=0.5,price_grade=0.5;
    QString description;
public:
    void setQuality(const double& quality);
    void setPrice(const double& price);
    void setDescription(const QString& description);

    QString getSenderId();
    double getQuality();
    double getPrice();
    QString getDescription();

    Comment(const QString& sender_id,const double& quality,const double& price,const QString & description);
    ~Comment();

    void addToFile(QXmlStreamWriter & xml_writer);

};

#endif // COMMENT_H

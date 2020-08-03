#ifndef GOOD_H
#define GOOD_H

#include <QMultiMap>
#include <QMap>

#include "filefunctions.h"

#include "comment.h"
#include "question.h"
#include "reply.h"
#

class Good
{
    QString id;
    QString type_id;
    QString maker_id;

    unsigned  int price;
    double discount_percent=0.0;
    QMap<QString,QString> properties;




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
    Good();
};

#endif // GOOD_H

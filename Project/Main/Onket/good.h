#ifndef GOOD_H
#define GOOD_H

#include <QMultiMap>

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


public:
    void setPrice(unsigned int price);
    void setFinalPrice(unsigned int final_price);
    bool setDiscountPercent(double discount_percent);
    unsigned int getPrice();
    unsigned int getFinalPrice();
    double getFinalDiscountPrice();

    Good();
};

#endif // GOOD_H

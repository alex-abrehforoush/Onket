#include "comment.h"
const QVector<QString> Comment::grades={"very bad","bad","mediom","good","excellent"};

void Comment::setQuality(const QString &quality)
{
    for(auto it :grades)
    {
        if(quality == it)
        {
            this->quality_grad=quality;
            break;
        }
    }
}

void Comment::setPrice(const QString &price)
{
    for(auto it : grades)
    {
        if(price == it)
        {
            this->price_grade=price;
            break;
        }
    }
}

void Comment::setDescription(const QString &description)
{
    this->description=description;
}

QString Comment::getQuality()
{
    return this->quality_grad;
}

QString Comment::getPrice()
{
    return this->price_grade;
}

QString Comment::getDescription()
{
    return this->description;
}

Comment::Comment(const QString &quality, const QString &price, const QString &description)
{
    this->setQuality(quality);
    this->setPrice(price);
    this->setDescription(description);
}

Comment::~Comment()
{

}



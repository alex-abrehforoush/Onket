#include "comment.h"
const QVector<double> Comment::grades={0.0,0.25,0.5,0.75,1.0};
/////
void Comment::setQuality(const double &quality)
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

void Comment::setPrice(const double &price)
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

QString Comment::getSenderId()
{
    return this->sender_id;
}

double Comment::getQuality()
{
    return this->quality_grad;
}

double Comment::getPrice()
{
    return this->price_grade;
}

QString Comment::getDescription()
{
    return this->description;
}

Comment::Comment(const QString& sender_id,const double &quality, const double &price, const QString &description)
{
    this->sender_id=sender_id;
    this->setQuality(quality);
    this->setPrice(price);
    this->setDescription(description);
}

Comment::~Comment()
{


}

void Comment::addToFile(QXmlStreamWriter &xml_writer)
{
    xml_writer.writeStartElement("comment");

        xml_writer.writeAttribute("quality_grade",QString:: number(this->quality_grad));
        xml_writer.writeAttribute("price_grade",QString::number(this->price_grade));

       xml_writer.writeTextElement("sender_id",this->sender_id);

       xml_writer.writeTextElement("description",this->description);
    xml_writer.writeEndElement();
}



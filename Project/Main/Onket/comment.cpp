#include "comment.h"
const QVector<QString> Comment::grades={"very bad","bad","mediom","good","excellent"};
/////
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

QString Comment::getSenderId()
{
    return this->sender_id;
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

Comment::Comment(const QString& sender_id,const QString &quality, const QString &price, const QString &description)
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

        xml_writer.writeAttribute("quality_grade",this->quality_grad);
        xml_writer.writeAttribute("price_grade",this->price_grade);

       xml_writer.writeTextElement("sender_id",this->sender_id);

       xml_writer.writeTextElement("description",this->description);
    xml_writer.writeEndElement();
}



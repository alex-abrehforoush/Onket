#include "good.h"

void Good::setPrice(unsigned int  price)
{
    this->price=price;
}

void Good::setFinalPrice(unsigned int final_price)
{
    if(final_price>this->price)
    {
        this->price=final_price;
        this->discount_percent=0.0;
    }
    else
    {
        this->discount_percent=1.0-( long double)(final_price)/(long double)(this->price);
    }
}

bool Good::setDiscountPercent(double discount_percent)
{
    if(discount_percent < 1.0 && discount_percent >=0)
    {
        this->discount_percent=discount_percent;
    }
    return  false;
}

unsigned int Good::getPrice()
{
    return this->price;
}

unsigned int Good::getFinalPrice()
{
    return this->price *(1.0-discount_percent);
}

double Good::getFinalDiscountPrice()
{
    return this->discount_percent;
}

bool Good::existProperty(const QString &property_name)
{
    auto it=this->properties.find(property_name);
    if(it== this->properties.end())
    {

        return  false;
    }
    else
    {
        return true;
    }
}

bool Good::insertProperty(const QString &property_name)
{
    if(this->existProperty(property_name)==true)
    {
        return  false;
    }
    else
    {
        this->properties.insert(property_name,"");
        return  true;
    }
}

bool Good::setPropertyValue(const QString &property_name, const QString &property_value)
{
    if(this->existProperty(property_name)==false)
    {
        return false;
    }
    else
    {
        if(csv_validator::isValidInCsv(property_name)==false)
        {
            return false;
        }
        this->properties[property_name]=property_value;
        return true;

    }
}



Good::Good()
{

}

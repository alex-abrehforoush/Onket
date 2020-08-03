#include "good.h"

void Good::setPrice(unsigned  price)
{
    this->price=price;
}

void Good::setFinalPrice(unsigned  final_price)
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

Good::Good()
{

}

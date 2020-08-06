#include "Commodity.h"

Commodity::Commodity(QString id_of_good)
	:id_of_good(id_of_good)
{
}

void Commodity::add(QString color, unsigned int number)
{
	unsigned int temp = this->color.value(color);
	this->color.insert(color, number + temp);
}

void Commodity::remove(QString color, unsigned int number)
{
	if (this->color.value(color) >= number)
	{
		this->color.insert(color, this->color.value(color) - number);
	}
}

unsigned long long int Commodity::inventory()
{
	unsigned long long int temp = 0;
	for each (int value in this->color)
	{
		temp += value;
	}
	return temp;
}

unsigned long long int Commodity::inventoryOf(QString color)
{
	if (this->color.contains(color)) return this->color.value(color);
	else return 0;
}

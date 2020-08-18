#include "Commodity.h"

Commodity::Commodity(QString id_of_good)
	:id_of_good(id_of_good)
{
}

QString Commodity::getCommodityId() const
{
    return this->id_of_good;
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

int Commodity::commodityExist(QString good_id)
{
    int flag = 0;
    QFile file("Database/Commodity/commodity_list.csv");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) return 0;
    QTextStream in(&file);
    const QString content = in.readAll();
    QStringList list_1;
    list_1 << content.split("\n");
    for(int i = 0; i<list_1.size(); i++)
    {
        QStringList list_2;
        list_2 << list_1.at(i).split(",");
        if(list_2.at(0)==good_id)
        {
            flag = 1;
            break;
        }
    }
    file.close();
    return flag;
}

Commodity Commodity::getCommodity(QString good_id)
{
    Commodity nl("");
    QFile data("Database/Commodity/" + good_id + ".csv");
    if(data.exists())
    {
        if(data.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            Commodity return_commodity(good_id);
            QTextStream in(&data);
            QString content = in.readAll();
            QStringList list_1 = content.split("\n");
            for(int i = 0; i<list_1.size(); i++)
            {
                QStringList list_2 = list_1.at(i).split(",");
                return_commodity.add(list_2.at(0), list_2.at(1).toUInt());
            }
            return return_commodity;
        }
        else return nl;
    }
    else return nl;
}

int Commodity::addCommodity(Commodity new_commodity)
{
    QDir data;
    data.mkpath("Database/Commodity");
    if(!commodityExist(new_commodity.getCommodityId()))
    {
        QFile commodity_list("Database/Commodity/commodity_list.csv");
        if(commodity_list.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        {
            QTextStream out(&commodity_list);
            out << new_commodity.getCommodityId() << ",";
            commodity_list.close();
        }
        else return 0;
    }
    QFile commodity_personal("Database/Commodity/" + new_commodity.getCommodityId() + ".csv");
    if(commodity_personal.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&commodity_personal);
        for(auto e : new_commodity.color.keys())
        {
            out << e << "," << new_commodity.color.value(e) << "\n";
        }
        commodity_personal.close();
    }
    else return 0;//file didn't open
    return 1;//file created
}

unsigned long long int Commodity::inventory()
{
	unsigned long long int temp = 0;
    foreach (int value, this->color)
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

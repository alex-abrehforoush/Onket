#ifndef COMMODITY_XCSFBE
#define COMMODITY_XCSFBE
#include <QMap>
#include <QFile>
#include <QDir>
#include <QTextStream>

class Commodity
{
protected:
private:
	QString id_of_good;
    QMap<QString, unsigned int> color;
    //static QFile commodity_data("Database/Commodity/commodity_list");
public:
    Commodity(QString id_of_good = QString::number(0));
    QString getCommodityId() const;
    QMap<QString, unsigned int> getColor() const;
	void add(QString color, unsigned int number = 1);
	void remove(QString color, unsigned int number = 1);
    static int commodityExist(QString good_id);
    static Commodity getCommodity(QString good_id);
    static int addCommodity(Commodity new_commodity);
    static int removeCommodity(Commodity old_commodity);
    static QString colorToFarsi(QString clr);
    static QString colorToEnglish(QString clr);
	unsigned long long int inventory();
	unsigned long long int inventoryOf(QString color);
};

#endif

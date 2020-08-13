#ifndef COMMODITY_XCSFBE
#define COMMODITY_XCSFBE
#include <QMap>
class Commodity
{
protected:
private:
	QString id_of_good;
    QMap<QString, unsigned int> color;
public:
	Commodity(QString id_of_good = 0);
    QString getCommodityId() const;
	void add(QString color, unsigned int number = 1);
	void remove(QString color, unsigned int number = 1);
    static int commodityExist(QString good_id);
    static Commodity getCommodity(QString good_id);
    static int addCommodity(Commodity new_commodity);
	unsigned long long int inventory();
	unsigned long long int inventoryOf(QString color);
};

#endif

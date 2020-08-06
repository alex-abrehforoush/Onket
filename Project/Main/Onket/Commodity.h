#ifndef COMMODITY_XCSFBE
#define COMMODITY_XCSFBE
#include <qmap>
class Commodity
{
protected:
private:
	QString id_of_good;
	QMap<QString, unsigned int> color;
public:
	Commodity(QString id_of_good = 0);
	void add(QString color, unsigned int number = 1);
	void remove(QString color, unsigned int number = 1);
	unsigned long long int inventory();
	unsigned long long int inventoryOf(QString color);
};

#endif
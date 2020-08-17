#ifndef ITEM_HIUFQ
#define ITEM_HIUFQ
#include <QString>
class Item
{
protected:
private:
    QString good_id;
    QString color;
    int number;
public:
    Item(QString good_id, QString color, int number);
    QString getItemId() const;
    QString getItemColor() const;
    int getNumber() const;
    void setItemId(QString id);
    void setItemColor(QString color);
    void setItemNumber(int number);
    bool operator==(const Item& itm);
};

#endif

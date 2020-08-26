#ifndef BASKETVIEWITEM_H
#define BASKETVIEWITEM_H

#include <QWidget>

#include "good.h"
#include "Commodity.h"
#include "item.h"

namespace Ui {
class BasketViewItem;
}

class BasketViewItem : public QWidget
{
    Q_OBJECT
    QString good_id;
    int nmbr;

public:
    explicit BasketViewItem(const Item& input, QWidget *parent = nullptr);
    ~BasketViewItem();

private slots:
    void on_item_number_valueChanged(const QString &arg1);

    void on_remove_clicked();

private:
    Ui::BasketViewItem *ui;
signals:
    void itemRemoved(const Item& itm);
};

#endif // BASKETVIEWITEM_H

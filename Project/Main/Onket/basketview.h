#ifndef BASKETVIEW_H
#define BASKETVIEW_H

#include <QScrollArea>
#include <QGridLayout>
#include <QPushButton>
#include <QVector>

#include "basketviewitem.h"

namespace Ui {
class BasketView;
}

class BasketView : public QScrollArea
{
    Q_OBJECT
    QWidget* center_widget = nullptr;
    QPushButton* btn_buy = nullptr;
    QGridLayout* main_lay = nullptr;
    QVector<BasketViewItem*> items_widget;
    bool info_valid = false;
    int row_index = 0;

public slots:
    void update();
public:
    void addItem(const Item& itm);
    explicit BasketView(QWidget *parent = nullptr);
    ~BasketView();
private slots:
    void removedItem(const Item&);
private:
    Ui::BasketView *ui;

};

#endif // BASKETVIEW_H

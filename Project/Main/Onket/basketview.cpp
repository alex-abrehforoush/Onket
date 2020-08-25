#include "mainwindow.h"
#include "basketview.h"
#include "ui_basketview.h"

void BasketView::update()
{
    if(info_valid==false) return;
    row_index = 0;
    ///clear widget
    for(auto it = this->items_widget.begin(); it != this->items_widget.end(); it++)
    {
        this->main_lay->removeWidget(*it);
    }
    this->main_lay->removeWidget(btn_buy);
    for(auto it = this->items_widget.begin(); it != this->items_widget.end(); it++)
    {
        delete *it;
        *it=nullptr;
    }
    this->items_widget.clear();

    QVector<Item> temp = MainWindow::getCurrentUser()->getBasket();
    for(auto it : temp)
    {
        this->addItem(it);

    }
    this->main_lay->addWidget(btn_buy,row_index,0);
}

void BasketView::addItem(const Item &itm)
{
    //
    Item kemp = itm;
    //
    BasketViewItem* temp = new BasketViewItem(itm, this);
    main_lay->addWidget(temp, row_index, 0);
    this->items_widget.push_back(temp);
    row_index++;
    connect(temp, SIGNAL(itemRemoved(const Item&)), this, SLOT(removedItem(const Item&)));
}

BasketView::BasketView(QWidget *parent) :
    QScrollArea(parent)
    , center_widget(new QWidget(this))
    , main_lay(new QGridLayout(this))
    , btn_buy(new QPushButton("اتمام خرید", this))
    , ui(new Ui::BasketView)
{
    this->center_widget->setLayout(main_lay);
    this->setWidget(center_widget);
    this->setWidgetResizable(true);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    this->horizontalScrollBar()->setStyleSheet("background-color: rgb(214, 214, 214);");
    this->verticalScrollBar()->setStyleSheet("background-color: rgb(214, 214, 214);");

    if(MainWindow::getCurrentUser()->getMode() != 0) return;
    info_valid = true;
    btn_buy->setStyleSheet("background-color: rgb(255, 47, 47);");
    btn_buy->setFixedSize(200, 40);
    this->update();
    this->setFixedSize(1480, 790);
    ui->setupUi(this);
}

BasketView::~BasketView()
{
    delete ui;
}

void BasketView::removedItem(const Item &)
{
    this->update();
    return;
}

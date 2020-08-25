#include "basketviewitem.h"
#include "ui_basketviewitem.h"
#include "mainwindow.h"
#include <QImage>

BasketViewItem::BasketViewItem(const Item& input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BasketViewItem)
{
    ui->setupUi(this);

    Good::readFile();
    this->good_id = input.getItemId();
    if(Good::existGoodId(input.getItemId())==false)
    {
        return;
    }
    else
    {
        Good& g = Good::getGood(good_id);
        ui->item_name->setText(g.getName());
        ui->total_price->setText(QString::number(g.getFinalPrice()*ui->item_number->value()));
        ui->seller_code->setText(g.getMakerId());
        ui->color->setText(input.getItemColor());
        Commodity current=MainWindow::getOnketRepository().getCommodityOf(input.getItemId());
        int max = current.inventoryOf(Commodity::colorToEnglish(input.getItemColor()));
        ui->item_number->setRange(1, max);
        ui->item_number->setValue(input.getNumber());
        ui->inventory->setText(QString::number(MainWindow::getOnketRepository().getCommodityOf(input.getItemId()).inventoryOf(input.getItemColor())) + "عدد در انبار موجود است");
        QString path="Database/GoodPicture/"+g.getId()+".png";
        QImage img;
        if(img.load(path)==false)
        {
            ui->item_picture->setText("محل عکس");
        }
        else
        {
            ui->item_picture->setPixmap(QPixmap::fromImage(img));
            ui->item_picture->setScaledContents(true);
        }
        this->setFixedSize(1500,350);
    }
}

BasketViewItem::~BasketViewItem()
{
    delete ui;
}

void BasketViewItem::on_item_number_valueChanged(const QString &arg1)
{
    Good& g=Good::getGood(good_id);
    ui->total_price->setText(QString::number(g.getFinalPrice()*ui->item_number->value()));
}

void BasketViewItem::on_remove_clicked()
{
    Item temp(good_id, ui->color->text(), ui->item_number->value());
    MainWindow::getCurrentUser()->removeFromBasket(temp);
    emit itemRemoved(temp);
    return;
}

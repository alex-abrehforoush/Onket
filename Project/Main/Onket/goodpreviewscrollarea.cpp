#include "goodpreviewscrollarea.h"


#include "ui_goodpreviewscrollarea.h"


QMap<QString,GoodPreviewWidget*> GoodPreviewScrollArea::good_preview;

bool GoodPreviewScrollArea::existGood(const QString &good_id)const
{
    auto it =this->good_preview.find(good_id);
    if(it == this->good_preview.cend())
    {
        return false;
    }

    return true;
}

void GoodPreviewScrollArea::addGood(const QString &good_id)
{
    if(this->existGood(good_id)==false)
    {
        GoodPreviewWidget* good_preview_item=new GoodPreviewWidget(good_id,this);
        this->good_preview.insert(good_id,good_preview_item);
        this->main_lay->addWidget(good_preview_item);
    }
}

bool GoodPreviewScrollArea::removeGood(const QString &good_id)
{
    if(this->existGood(good_id)==false)
    {
        return false;
    }
    else

    {
        auto it=this->good_preview.find(good_id);
        this->main_lay->removeWidget(it.value());
        delete it.value();
        this->good_preview.remove(it.key());
        return true;
    }
}

GoodPreviewWidget &GoodPreviewScrollArea::getGoodPreviewWidget(const QString &good_id)
{
    auto it=this->good_preview.find(good_id);
    return *(it.value());
}

void GoodPreviewScrollArea::update()
{
    for(auto it: this->good_preview)
    {
        it->update();
    }
}

GoodPreviewScrollArea::GoodPreviewScrollArea(QWidget *parent) :
    QScrollArea(parent)
    ,center_widget(new QWidget(this))
    ,main_lay(new QHBoxLayout(this))
    ,ui(new Ui::GoodPreviewScrollArea)
{
    this->center_widget->setLayout(main_lay);

    this->setWidget(center_widget);
    this->setWidgetResizable(true);

    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    this->setFixedHeight(370);

    this->horizontalScrollBar()->setStyleSheet("background-color: rgb(214, 214, 214);");
    this->verticalScrollBar()->setStyleSheet("background-color: rgb(214, 214, 214);");


    ui->setupUi(this);
}

GoodPreviewScrollArea::~GoodPreviewScrollArea()
{
    delete ui;
}

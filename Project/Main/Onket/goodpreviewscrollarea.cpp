#include "goodpreviewscrollarea.h"


#include "ui_goodpreviewscrollarea.h"



bool GoodPreviewScrollArea::existGood(const QString &good_id)const
{
    auto it =this->good_preview.find(good_id);
    if(it == this->good_preview.cend())
    {
        return false;
    }

    return true;
}

void GoodPreviewScrollArea::addGood(const QString &good_id,bool hide)
{
    if(this->existGood(good_id)==false)
    {
        GoodPreviewWidget* good_preview_item=new GoodPreviewWidget(good_id,hide,this);
        this->good_preview.insert(good_id,good_preview_item);
        this->main_lay->addWidget(good_preview_item);
        connect(good_preview_item, SIGNAL(on_good_preview_clicked(const QString&)), this, SLOT(on_good_preview_clicked(const QString& )));
        connect(good_preview_item, SIGNAL(showCompareButton()), this, SLOT(show_compare_button()));
        connect(good_preview_item, SIGNAL(hideCompareButton()), this, SLOT(hide_compare_button()));
    }
}

void GoodPreviewScrollArea::addGoodSortedByPrice(const QString &type_id,bool hide)
{
    Type::readFile();
    Good::readFile();
    if(Type::existTypeId(type_id)==false)return;
    const Type& t=Type::getType(type_id);

    QVector<QString>good_id;
    for(t.setGoodSeekBegin();t.GoodSeekAtEnd()==false;)
    {
        good_id.push_back(t.readGoodId());
    }
    {
        QVector<QString>temp=Good::getSortByPrice(good_id,true);
        for(auto it : temp)
        {
            this->addGood(it,hide);
        }
    }
    good_id.clear();
}

void GoodPreviewScrollArea::addGoodSortedByDiscount(const QString &type_id,bool hide)
{
    Type::readFile();
    Good::readFile();
    if(Type::existTypeId(type_id)==false)return;
    const Type& t=Type::getType(type_id);

    QVector<QString>good_id;
    for(t.setGoodSeekBegin();t.GoodSeekAtEnd()==false;)
    {
        good_id.push_back(t.readGoodId());
    }
    {
        QVector<QString>temp=Good::getSortByDiscount(good_id,false);
        for(auto it : temp)
        {
            this->addGood(it,hide);
        }
    }
    good_id.clear();
}

void GoodPreviewScrollArea::addGoodSortedByWillingness(const QString &type_id,bool hide)
{
    Type::readFile();
    Good::readFile();
    if(Type::existTypeId(type_id)==false)return;
    const Type& t=Type::getType(type_id);

    QVector<QString>good_id;
    for(t.setGoodSeekBegin();t.GoodSeekAtEnd()==false;)
    {
        good_id.push_back(t.readGoodId());
    }
    {
        QVector<QString>temp=Good::getSortByWillingness(good_id,true);
        for(auto it : temp)
        {
            this->addGood(it,hide);
        }
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

void GoodPreviewScrollArea::on_good_preview_clicked(const QString &good_id)
{
    emit this->onGoodPreviewClicked(good_id);
}

void GoodPreviewScrollArea::show_compare_button()
{
    emit this->showCompareButton();
}

void GoodPreviewScrollArea::hide_compare_button()
{
    emit this->hideCompareButton();
}

void GoodPreviewScrollArea::update()
{
    for(auto it: this->good_preview)
    {
        it->update();
    }
}

void GoodPreviewScrollArea::clear()
{

    for(auto it=this->good_preview.begin();it != this->good_preview.end();it++)
    {
        this->main_lay->removeWidget(it.value());
        delete it.value();

    }
    this->good_preview.clear();
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

#include "goodmainviewwidget.h"
#include "ui_goodmainviewwidget.h"

goodMainViewWidget::goodMainViewWidget(const QString& good_id,const QString& user_id,QWidget *parent) :
    QScrollArea(parent)
    ,center_widget(new QWidget(this))
    ,bnt_add_to_basket(new QPushButton("افزودن به سبد خرید",this))
    ,lab_img(new QLabel(this))
  ,c_status(new CommentItemStatus(good_id,this))
  ,main_lay(new QHBoxLayout(this))
  ,lay_picture(new QVBoxLayout(this)),lay_body(new QVBoxLayout(this)),lay_comment_items(new QVBoxLayout(this)),lay_buy(new QVBoxLayout(this))
   , ui(new Ui::goodMainviewWidget)
{

    ui->setupUi(this);
    this->good_id=good_id;
    this->user_id=user_id;

    this->center_widget->setLayout(main_lay);
    this->setWidget(center_widget);
    this->setWidgetResizable(true);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
      this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    if(Good::existGoodId(good_id)==false)
    {
        return;
    }
    this->info_valid=true;
    this->setupSTyleSheet();
    this->setupLayout();


}

void goodMainViewWidget::setupSTyleSheet()
{
    this->bnt_add_to_basket->setStyleSheet("background-color: rgb(255, 0, 255);color: rgb(255, 255, 255);");
    this->bnt_add_to_basket->setFixedSize(100,100);
    this->lab_img->setFixedSize(300,300);

}

void goodMainViewWidget::setupLayout()
{
    if(this->info_valid==false)
    {
        return;
    }
    Good& g=Good::getGood(good_id);

     this->main_lay->addLayout(lay_buy,0);
    this->main_lay->addLayout(lay_comment_items,1);
     this->main_lay->addLayout(lay_body,2);
     this->main_lay->addLayout(lay_picture,3);


     this->lay_picture->addWidget(lab_img);
    this->lay_body->addWidget(new QLabel(g.getName(),this),0);
    this->lay_body->addWidget(new QLabel("مشخصات",this),1);

    for(g.setPropertySeekBegin();g.propertySeekAtEnd()==false;)
    {
        QString property_name=g.readPropertyName();
        QString content=property_name;content.append(" : ");
        content.append(g.getPropertyValue(property_name));

        this->lay_body->addWidget(new QLabel(content,this));


    }

    this->lay_comment_items->addWidget(new QLabel("",this),0);
    this->lay_comment_items->addWidget(this->c_status,1);


    this->lay_buy->addWidget(this->bnt_add_to_basket);



}

goodMainViewWidget::~goodMainViewWidget()
{
    delete ui;
}

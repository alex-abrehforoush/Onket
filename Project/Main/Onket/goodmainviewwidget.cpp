#include "goodmainviewwidget.h"
#include "ui_goodmainviewwidget.h"

goodMainViewWidget::goodMainViewWidget(const QString& good_id,const QString& user_id,QWidget *parent) :
    QScrollArea(parent)
    ,center_widget(new QWidget(this))
    ,bnt_add_to_basket(new QPushButton("افزودن به سبد خرید",this))

  ,g_properties(new GoodPropertyWidget(good_id,this))
  ,c_status(new CommentItemStatus(good_id,this))
 ,lab_img(new QLabel(this))
  ,g_general(new GoodGenralInfoWidget(good_id,this))
  ,main_lay(new QGridLayout(this))
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
    QDir d;
    if(d.exists("Database/GoodPicture")==false)
    {
        d.mkpath("Database/GoodPicture");
    }

    Good & g=Good::getGood(good_id);
    QString path="Database/GoodPicture/";
    path.append(good_id);
    path.append(".png");
    QImage img;
   if(QFile::exists(path)==false)
   {
       img.load("Database/GoodPicture/default.jpg");
       this->lab_img->setPixmap(QPixmap::fromImage(img));
   }

  QString bnt_add_content="افزودن به سبد خرید";
  bnt_add_content.append(" )");
  bnt_add_content.append(QString::number(g.getFinalPrice()));
  bnt_add_content.append("  تومان  )");
  this->bnt_add_to_basket->setText(bnt_add_content);



    this->info_valid=true;
    this->setupSTyleSheet();
    this->setupLayout();
    this->lab_img->setFixedSize(300,300);
    this->setFixedSize(1500,800);

}

void goodMainViewWidget::setupSTyleSheet()
{
    this->bnt_add_to_basket->setStyleSheet("background-color: rgb(255, 0, 0);color: rgb(255, 255, 255);");
   // this->bnt_add_to_basket->setFixedSize(100,100);


}

void goodMainViewWidget::setupLayout()
{
    if(this->info_valid==false)
    {
        return;
    }
    Good& g=Good::getGood(good_id);

     this->main_lay->addLayout(lay_buy,0,0);


     this->main_lay->addLayout(lay_picture,0,1);
    this->main_lay->addLayout(lay_comment_items,1,0);
     this->main_lay->addLayout(lay_body,1,1);



     this->lay_picture->addWidget(lab_img);
    QLabel* lab_name=new QLabel(g.getName(),this);
    lab_name->setStyleSheet("color: rgb(255, 0, 0);background-color: rgb(255, 255, 255);");
    lab_name->setFixedSize(200,40);
    lab_name->setAlignment(Qt::AlignCenter);


    this->lay_body->addWidget(g_properties,0,Qt::AlignCenter);


    this->lay_comment_items->addWidget(this->c_status,0,Qt::AlignCenter);

    this->lay_buy->addWidget(this->g_general);
    this->lay_buy->addWidget(this->bnt_add_to_basket,1);



}

void goodMainViewWidget::update()
{
 this->c_status->update();
}

goodMainViewWidget::~goodMainViewWidget()
{
    delete ui;
}

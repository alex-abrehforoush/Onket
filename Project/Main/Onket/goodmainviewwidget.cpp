#include "goodmainviewwidget.h"
#include "ui_goodmainviewwidget.h"
#include "mainwindow.h"

goodMainViewWidget::goodMainViewWidget(const QString& good_id,const QString& user_id,QWidget *parent) :
    QScrollArea(parent)
    ,center_widget(new QWidget(this))
    ,bnt_return(new QPushButton(this))
    ,bnt_comment(new QPushButton("نمایش نظرات",this))
    ,bnt_discussion(new QPushButton("نمایش پرسش ها"))
    ,bnt_add_to_basket(new QPushButton("افزودن به سبد خرید",this))
    ,g_properties(new GoodPropertyWidget(good_id,this))
    ,c_status(new CommentItemStatus(good_id,this))
    ,comments_area(new CommentListWidget(good_id,MainWindow::getCurrentUser()->getUsername()))
    ,discussion_area(new DiscussionListWidget(good_id,MainWindow::getCurrentUser()->getUsername()))
    ,color_selection(new QComboBox(this))
    ,item_number(new QSpinBox(this))
    ,lab_img(new QLabel(this))
    ,g_general(new GoodGenralInfoWidget(good_id,this))
    ,main_lay(new QGridLayout(this))
    ,lay_buttons(new QHBoxLayout(this))
    ,lay_return(new QVBoxLayout(this)),lay_picture(new QVBoxLayout(this)),lay_body(new QVBoxLayout(this)),lay_comment_items(new QVBoxLayout(this)),lay_buy(new QVBoxLayout(this)),lay_area(new QVBoxLayout(this))
    ,ui(new Ui::goodMainviewWidget)
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
    g.commentsReadFile();
    QString path="Database/GoodPicture/";
    path.append(good_id);
    path.append(".png");
    QImage img;
   if(QFile::exists(path)==false)
   {
       img.load("Database/GoodPicture/default.jpg");
       this->lab_img->setPixmap(QPixmap::fromImage(img));
       this->lab_img->setScaledContents(true);
   }
   else
   {
      img.load(path);
      this->lab_img->setPixmap(QPixmap::fromImage(img));
      this->lab_img->setScaledContents(true);

   }

   QString bnt_add_content="افزودن به سبد خرید";
   bnt_add_content.append(" )");
   bnt_add_content.append(price::number(g.getFinalPrice()));
   bnt_add_content.append("  تومان  )");
   this->bnt_add_to_basket->setText(bnt_add_content);

   this->comments_area->hide();
   this->discussion_area->hide();



    this->info_valid=true;
    this->setupSTyleSheet();
    this->setupLayout();
    this->setupComboBox();
    this->lab_img->setFixedSize(300,300);
    this->setFixedSize(1490,790);


    connect(this->bnt_return,SIGNAL(clicked()),this,SLOT(on_bnt_return_clicked()));
    connect(this->bnt_add_to_basket,SIGNAL(clicked()),this,SLOT(on_bnt_add_to_basket_clicked()));
    connect(this->bnt_comment,SIGNAL(clicked()),this,SLOT(on_bnt_comment_clicked()));
    connect(this->bnt_discussion,SIGNAL(clicked()),this,SLOT(on_bnt_discussion_clicked()));
    connect(this->color_selection,SIGNAL(currentTextChanged(const QString&)),this,SLOT(color_section_current_text_chenged(const QString&)));
    connect(this->comments_area,SIGNAL(commentsChanged()),this->c_status,SLOT(update()));
}

void goodMainViewWidget::setupSTyleSheet()
{
    this->horizontalScrollBar()->setStyleSheet("background-color: rgb(200, 200, 200)");
    this->verticalScrollBar()->setStyleSheet("background-color: rgb(200, 200, 200)");

    this->bnt_add_to_basket->setStyleSheet("background-color: rgb(255, 0, 0);color: rgb(255, 255, 255);");

    this->bnt_return->setIcon(QIcon("Database/Icons/RightArrow.png"));
    this->bnt_return->setText("بازگشت");

    this->bnt_comment->setStyleSheet("background-color: rgb(0, 0, 127);\ncolor: rgb(255, 255, 255);");
    this->bnt_discussion->setStyleSheet("background-color: rgb(0, 0, 127);\ncolor: rgb(255, 255, 255);");
    this->color_selection->setStyleSheet("background-color: rgb(0, 0, 0);\ncolor: rgb(255, 255, 255);");

    this->color_selection->setFixedSize(100,30);
    this->bnt_comment->setFixedSize(300,50);
    this->bnt_discussion->setFixedSize(300,50);
    this->item_number->setFixedSize(100,20);
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
     this->main_lay->addLayout(lay_return,0,2);
     this->main_lay->addLayout(lay_comment_items,1,0);
     this->main_lay->addLayout(lay_body,1,1);
     this->main_lay->addLayout(lay_buttons,2,0);
     this->main_lay->addLayout(lay_area,3,0);

     this->lay_picture->addWidget(lab_img);



    this->lay_body->addWidget(g_properties,0,Qt::AlignCenter);
    this->lay_return->addWidget(bnt_return,0,Qt::AlignCenter);

    this->lay_comment_items->addWidget(this->c_status,0,Qt::AlignCenter);

    this->lay_buy->addWidget(this->g_general);
    this->lay_buy->addWidget(this->color_selection);
    this->lay_buy->addWidget(this->item_number);
    this->lay_buy->addWidget(this->bnt_add_to_basket);

    this->lay_buttons->addWidget(bnt_comment,0);
    this->lay_buttons->addWidget(bnt_discussion,1);

    this->lay_area->addWidget(comments_area,0);
    this->lay_area->addWidget(discussion_area,0);

}

void goodMainViewWidget::setupComboBox()
{
    Commodity temp = MainWindow::getOnketRepository().getCommodityOf(this->good_id);
    QMap<QString,unsigned int> color=temp.getColor();
    for(auto it =color.cbegin();it != color.cend();it++)
    {
        if(it.value()>0)
        this->color_selection->addItem(Commodity::colorToFarsi(it.key()));
    }
    if(this->color_selection->currentText().isEmpty()==false)
    {
        this->item_number->setRange(1,temp.inventoryOf(Commodity::colorToEnglish(color_selection->currentText())));
    }
}

void goodMainViewWidget::on_bnt_return_clicked()
{
    this->hide();
    Good::WriteFile();
    if(info_valid==true)
    Good::getGood(good_id).commentsWriteToFile();
    emit this->updateGoodsRequest();
}

void goodMainViewWidget::on_bnt_add_to_basket_clicked()
{
    if(MainWindow::getCurrentUser()->getMode() != 0)
    {
        QMessageBox::information(this,"پیام","شما دسترسی لازم برای خرید کالا را ندارید");
        return;
    }
    else
    {
        Item temp(this->good_id, this->color_selection->currentText(), this->item_number->value());
        MainWindow::getCurrentUser()->addToBasket(temp);
        this->item_number->setMaximum(item_number->maximum()-item_number->value());
        this->item_number->setValue(1);
        QMessageBox::information(this, "پیام", "کالای مورد نظر به سبد خرید اضافه شد");
    }
}

void goodMainViewWidget::on_bnt_comment_clicked()
{
    User* current_user=MainWindow::getCurrentUser();
    if(current_user->getMode()==-1)
    {
        QMessageBox::information(this,"پیام","شما هنوز وارد حساب کاربری نشده اید");
        return;
    }
    this->comments_area->changeUser(current_user->getUsername());
    this->discussion_area->hide();
    this->bnt_discussion->setText("نمایش پرسش ها");

    if(this->bnt_comment->text()=="نمایش نظرات")
    {
        this->comments_area->show();
        this->bnt_comment->setText("مخفی نمودن نظرات");
    }
    else
    {
        this->comments_area->hide();
        this->bnt_comment->setText("نمایش نظرات");
    }

}

void goodMainViewWidget::on_bnt_discussion_clicked()
{
    User* current_user=MainWindow::getCurrentUser();
    if(current_user->getMode()==-1)
    {
        QMessageBox::information(this,"پیام","شما هنوز وارد حساب کاربری نشده اید");
        return;
    }
}

void goodMainViewWidget::color_section_current_text_chenged(const QString &current_color)
{
    Commodity temp = MainWindow::getOnketRepository().getCommodityOf(this->good_id);
    int max=temp.inventoryOf(Commodity::colorToEnglish(current_color));
    this->item_number->setRange(1,max);
}

void goodMainViewWidget::update()
{
 this->c_status->update();
}

goodMainViewWidget::~goodMainViewWidget()
{
    delete ui;
}

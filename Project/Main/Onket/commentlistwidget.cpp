#include "commentlistwidget.h"
#include "ui_commentlistwidget.h"

void CommentListWidget::update()
{

   //clear main_widget
    if(id_valid==false)
    {
        return;
    }
    this->main_lay->removeWidget(bnt_add_comment);
    for(auto it: this->widgets)
    {

        this->main_lay->removeWidget(it);
        delete it;
        it=nullptr;
    }
    this->widgets.clear();

    Good &g=Good::getGood(good_id);
   this->main_lay->addWidget(bnt_add_comment);

    for( g.setCommentSeekBegin();g.commentSeekAtEnd()==false;)
    {
      QString sender_id=g.readComment().getSenderId();
      CommentListWidgetItem* cwItem=new CommentListWidgetItem(user_id,good_id,sender_id,this);
        this->widgets.insert(sender_id,cwItem);
      this->main_lay->addWidget(cwItem);
    }
    this->setFixedHeight(320*widgets.size()+100);



}

void CommentListWidget::changeUser(const QString &user_id)
{
    this->user_id= user_id;
    this->update();
}

void CommentListWidget::CommentFinished()
{
 this->c_widget->close();
 delete this->c_widget;
  this->c_widget=nullptr;
    this->update();

}

void CommentListWidget::commentAdded()
{
    if(this->c_widget!=nullptr)
    {
        return;
    }
    else
    {
        this->c_widget=new CommentWidget(good_id,user_id);
        c_widget->show();
        connect(c_widget,SIGNAL(commentEditingFinished()),this,SLOT(CommentFinished()));
    }
}

bool CommentListWidget::existCommentSender(const QString &comment_sender)const
{
    if(id_valid==false)
    {
        return false;
    }
    auto it=this->widgets.find(comment_sender);
    if(it == this->widgets.cend())
    {
        return false;
    }
    else
    {
        return true;
    }


}

CommentListWidgetItem &CommentListWidget::getItem(const QString &comment_sender)
{
   auto it=this->widgets.find(comment_sender);
   return *(it.value());
}



CommentListWidget::CommentListWidget(const QString& good_id,const QString& user_id ,QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::CommentListWidget)
  ,center_widget(new QWidget(this))
  ,bnt_add_comment(new QPushButton("+ افزودن نظر",this))
  ,main_lay(new QVBoxLayout(this))
{
    Good::readFile();

    this->bnt_add_comment->setStyleSheet("background-color: rgb(0, 0, 255);\ncolor: rgb(255,255,255);");
    connect(this->bnt_add_comment,SIGNAL(clicked()),this,SLOT(commentAdded()));
    ui->setupUi(this);
    this->user_id=user_id;
    this->good_id=good_id;
    this->id_valid=Good::existGoodId(good_id);
    if(id_valid==false)
    {
        return;
    }
    Good& g=Good::getGood(good_id);
    g.readComment();
    center_widget->setLayout(main_lay);
    this->setWidget(center_widget);
    this->setWidgetResizable(true);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->horizontalScrollBar()->setStyleSheet("background-color: rgb(210, 210, 210);");
    this->verticalScrollBar()->setStyleSheet("background-color: rgb(210, 210, 210);");
    this->setFixedWidth(700);

    this->update();
}

CommentListWidget::~CommentListWidget()
{
    delete ui;
}

#include "commentlistwidget.h"
#include "ui_commentlistwidget.h"

void CommentListWidget::update()
{
   //clear main_widget
    if(id_valid==false)
    {
        return;
    }
    for(auto it: this->widgets)
    {

        this->main_lay->removeWidget(it);
    }
    this->widgets.clear();

    Good &g=Good::getGood(good_id);

    for( g.setCommentSeekBegin();g.commentSeekAtEnd()==false;)
    {
      QString sender_id=g.readComment().getSenderId();
      CommentListWidgetItem* cwItem=new CommentListWidgetItem(user_id,good_id,sender_id,this);
        this->widgets.insert(sender_id,cwItem);
      this->main_lay->addWidget(cwItem);
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
  ,main_lay(new QVBoxLayout(this))
{

    ui->setupUi(this);
    this->user_id=user_id;
    this->good_id=good_id;
    this->id_valid=Good::existGoodId(good_id);
    if(id_valid==false)
    {
        return;
    }
    center_widget->setLayout(main_lay);
    this->setWidget(center_widget);
    this->setWidgetResizable(true);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    this->horizontalScrollBar()->setStyleSheet("background-color: rgb(210, 210, 210);");
    this->verticalScrollBar()->setStyleSheet("background-color: rgb(210, 210, 210);");
    this->setFixedWidth(1200);

    this->update();
}

CommentListWidget::~CommentListWidget()
{
    delete ui;
}

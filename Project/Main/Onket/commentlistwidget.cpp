#include "commentlistwidget.h"
#include "ui_commentlistwidget.h"
#include "mainwindow.h"

void CommentListWidget::update()
{

   //clear main_widget
    if(id_valid==false)
    {
        return;
    }
    this->main_lay->removeWidget(bnt_add_comment);
    this->main_lay->removeWidget(bnt_sort);
    for(auto it: this->widgets)
    {

        this->main_lay->removeWidget(it);
        delete it;
        it=nullptr;
    }
    this->widgets.clear();

    Good &g=Good::getGood(good_id);
    g.commentsReadFile();
   this->main_lay->addWidget(bnt_add_comment);
   this->main_lay->addWidget(bnt_sort);
    QVector<QString> sender_id;
    for( g.setCommentSeekBegin();g.commentSeekAtEnd()==false;)
    {
        sender_id.push_front(g.readComment().getSenderId());

    }
    for(auto it : sender_id)
    {
        CommentListWidgetItem* cwItem=new CommentListWidgetItem(user_id,good_id,it,this);
        this->widgets.insert(it,cwItem);
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
    emit this->commentsChanged();


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

void CommentListWidget::action_sort_by_date_triggered()
{
    this->bnt_sort->setText("مرتب سازی بر اساس جدید ترین");
    if(id_valid==false)return;
    Good& g=Good::getGood(good_id);
    g.commentSortByDate();
    this->update();
}

void CommentListWidget::action_sort_by_like_triggered()
{
    this->bnt_sort->setText("مرتب سازی بر اساس بیشترین لایک");
    if(id_valid==false)return;
    Good& g=Good::getGood(good_id);
    g.commentSortByLike();
    this->update();
}

void CommentListWidget::action_sort_by_view_triggered()
{
    this->bnt_sort->setText("مرتب سازی بر اساس بیشترین مشاهده");
    if(id_valid==false)return;
    Good& g=Good::getGood(good_id);
    g.commentSortByView();
    this->update();
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
  ,bnt_sort(new QPushButton("مرتب سازی بر اساس جدید ترین",this))
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
    center_widget->setLayout(main_lay);
    this->setWidget(center_widget);
    this->setWidgetResizable(true);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->horizontalScrollBar()->setStyleSheet("background-color: rgb(210, 210, 210);");
    this->verticalScrollBar()->setStyleSheet("background-color: rgb(210, 210, 210);");
    this->setFixedWidth(700);

    this->bnt_sort->setStyleSheet("background-color: rgb(255, 47, 47);");

    QMenu* menu_bnt_sort=new QMenu(this);
    menu_bnt_sort->setStyleSheet("background-color: rgb(255, 47, 47);");
    QAction* act_sort_by_date=new QAction("جدید ترین",this);
    QAction* act_sort_by_like=new QAction("بیشترین لایک",this);
    QAction* act_sort_by_view=new QAction("بیشترین مشاهده ",this);
    this->bnt_sort->setMenu(menu_bnt_sort);
    menu_bnt_sort->addAction(act_sort_by_date);
    menu_bnt_sort->addAction(act_sort_by_like);
    menu_bnt_sort->addAction(act_sort_by_view);

    connect(act_sort_by_date,SIGNAL(triggered()),this,SLOT(action_sort_by_date_triggered()));
    connect(act_sort_by_like,SIGNAL(triggered()),this,SLOT(action_sort_by_like_triggered()));
    connect(act_sort_by_view,SIGNAL(triggered()),this,SLOT(action_sort_by_view_triggered()));
    this->update();
}

CommentListWidget::~CommentListWidget()
{
    delete ui;
}

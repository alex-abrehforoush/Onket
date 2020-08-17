#include "discussionlistwidget.h"
#include "ui_discussionlistwidget.h"


void DiscussionListWidget::showReplys(const QString &good_id, const QString &question_id)
{

    if(info_valid==false)
    {
        return;
    }

    Good& g=Good::getGood(good_id);
    if(g.existQuestionId(question_id)==false)
    {
        return;
    }
    else
    {
        const Question& q=g.getQuestion(question_id);
        for(q.setReplySeekBegin();q.replySeekAtEnd()==false;)
        {
            QString reply_id=q.readReply();
            auto it=this->discussion_items.find(reply_id);
            if(it == this->discussion_items.cend())
            {
                return;
            }
            it.value()->show();
            it.value()->setHidden(false);
        }
    }
}

void DiscussionListWidget::hideReplys(const QString &good_id, const QString &question_id)
{

    if(info_valid==false)
    {
        return;
    }

    Good& g=Good::getGood(good_id);
    if(g.existQuestionId(question_id)==false)
    {
        return;
    }
    else
    {
        const Question& q=g.getQuestion(question_id);
        for(q.setReplySeekBegin();q.replySeekAtEnd()==false;)
        {
            QString reply_id=q.readReply();
            auto it=this->discussion_items.find(reply_id);
            if(it == this->discussion_items.cend())
            {
                return;
            }
            it.value()->hide();
            it.value()->setHidden(true);
        }
    }
}

void DiscussionListWidget::update()
{
    if(this->info_valid==false)
    {
        return;
    }
    for(auto it : this->discussion_items)
    {
        this->main_lay->removeWidget(it);
        delete it;
        it=nullptr;

    }
    this->discussion_items.clear();


    Good& g=Good::getGood(good_id);
    this->main_lay->addWidget(this->bnt_add_question,0);
    int cnt=1;
    for(g.setQuestionSeekBegin();g.QuestionSeekAtEnd()==false;)
    {
        const Question& q=g.readQuestion();
        QuestionViewItem* q_item=new QuestionViewItem(user_id,good_id,q.getId(),this);
        this->main_lay->addWidget(q_item,cnt,Qt::AlignRight);

        this->discussion_items.insert(q.getId(),q_item);
      connect(q_item,SIGNAL(replyAdded()),this,SLOT(update()));

      connect(q_item,SIGNAL(showReplyRequsted(const QString& ,const QString& )),this,SLOT(showReplys(const QString& ,const QString&)));
      connect(q_item,SIGNAL(hideReplyRequsted(const QString& ,const QString& )),this,SLOT(hideReplys(const QString& ,const QString&)));
        cnt++;
        for(q.setReplySeekBegin();q.replySeekAtEnd()==false;)
        {
            QString reply_id=q.readReply();
            ReplyViewItem* r_item=new ReplyViewItem(user_id,good_id,reply_id,this);

            this->main_lay->addWidget(r_item,cnt,Qt::AlignRight);
            this->discussion_items.insert(reply_id,r_item);
             r_item->hide();

            cnt++;
        }

    }
}

void DiscussionListWidget::addQuestion()
{
    if(this->question != nullptr)
    {
        return;
    }
    this->question=new QuestionInputWidget(good_id,user_id);
    question->show();
    connect(this->question,SIGNAL(questionEditingFinished(const QString&)),this,SLOT(QuestionFinished(const QString&)));
}

void DiscussionListWidget::QuestionFinished(const QString& mode)
{
    this->question->close();
   delete this->question;
   this->question=nullptr;
    if(mode.isEmpty()==true)
    {

        this->update();
    }

}

DiscussionListWidget::DiscussionListWidget(const QString& good_id,const QString& user_id,QWidget *parent) :
    QScrollArea(parent)

    ,center_widget(new QWidget(this))
  ,main_lay(new QVBoxLayout(this))
  ,bnt_add_question(new QPushButton("+ اضافه کردن پرسش",this))
    ,ui(new Ui::DiscussionListWidget)


{
    ui->setupUi(this);

    bnt_add_question->setStyleSheet("background-color: rgb(0, 0, 255);\ncolor: rgb(255,255,255);");
    bnt_add_question->setFixedSize(120,120);
    connect(this->bnt_add_question,SIGNAL(clicked()),this,SLOT(addQuestion()));

    this->good_id=good_id;
   this->user_id=user_id;
    if(Good::existGoodId(good_id)==false /*|| User::userExist(user_id)==false*/)
    {
        this->info_valid=false;
        return;
    }
    this->info_valid=true;

    this->center_widget->setLayout(main_lay);
    this->setWidget(center_widget);
    this->setWidgetResizable(true);

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->verticalScrollBar()->setStyleSheet("background-color: rgb(210, 210, 210);");
    this->horizontalScrollBar()->setStyleSheet("background-color: rgb(210, 210, 210);");

   // this->setFixedSize(1200,400);

}

DiscussionListWidget::~DiscussionListWidget()
{
    delete ui;
}

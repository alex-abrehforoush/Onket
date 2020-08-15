#include "questionviewitem.h"
#include "ui_questionviewitem.h"

void QuestionViewItem::update()
{
    if(info_valid==false)
    {
        return;
    }
    else
    {
        Good& g=Good::getGood(good_id);
        const Question& q=g.getQuestion(question_id);

        this->ui->txt_content->setText(q.getContent());
        QString number=QString::number(q.getReplyNumber());
        number.append(" نفر به این سوال پاسخ دادند");

        this->ui->txt_content->setReadOnly(true);
        this->ui->txt_content->setText(q.getContent());
        this->ui->lab_reply_number->setText(number);
        this->ui->lab_date->setText(q.getDateCreate().toString());


    }
}

QuestionViewItem::QuestionViewItem(const QString & user_id,const QString & good_id,const QString& question_id,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuestionViewItem)

{
    this->ui->setupUi(this);
    this->user_id=user_id;
    this->good_id=good_id;
    this->question_id=question_id;
    if(Good::existGoodId(good_id)==false)
    {
        this->info_valid=false;
        return;
    }
    Good& g=Good::getGood(good_id);
    if(g.existQuestionId(question_id)==false)
    {
        this->info_valid=false;
        return;
    }

    this->info_valid=true;
    this->ui->bnt_icon->setIcon(QIcon("Icons/Question.png"));

    this->update();

    this->setFixedSize(1200,300);

}

QuestionViewItem::~QuestionViewItem()
{
    delete ui;
}

void QuestionViewItem::on_bnt_add_reply_clicked()
{

    if(info_valid==false)
    {
        return;
    }
    Good& g=Good::getGood(good_id);
    const Question& q=g.getQuestion(question_id);
    for(q.setReplySeekBegin();q.replySeekAtEnd()==false;)
    {
        QString reply_id=q.readReply();

        if(g.getReply(reply_id).getSenderId()==user_id)
        {

            QMessageBox::information(this,"در خواست نا معتبر","شما قبلا پاسخ این سوال را داده اید",QMessageBox::Ok,0);

            return;
        }
    }


    emit this->addReply(user_id,good_id,question_id);

}

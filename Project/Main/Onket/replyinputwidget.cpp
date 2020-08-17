#include "replyinputwidget.h"
#include "ui_replyinputwidget.h"

ReplyInputWidget::ReplyInputWidget(const QString& good_id,const QString& question_id,const QString & sender_id,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReplyInputWidget)
{
    ui->setupUi(this);
    this->good_id=good_id;
   this->question_id=question_id;
    this->sender_id=sender_id;
    if(Good::existGoodId(good_id)==false /*||User::userExist(sender_id)==false*/)
    {
        this->info_valid=false;
        return;
    }
    Good & g=Good::getGood(good_id);
    if(g.existQuestionId(question_id)==false)
    {
        this->info_valid=false;
        return;
    }
    const Question& q=g.getQuestion(question_id);
    if(g.existReply(sender_id,question_id)==true)
    {
        this->info_valid=false;
        return;
    }
    this->info_valid=true;

    this->ui->txt_question->setReadOnly(true);
    this->ui->bnt_icon_question->setIcon(QIcon("Icons/Question.png"));
    this->ui->bnt_icon_reply->setIcon(QIcon("Icons/Reply.png"));
    this->ui->txt_reply->setPlaceholderText("پاسخ خود را وارد کنید");

    this->ui->txt_question->setText(q.getContent());

}

ReplyInputWidget::~ReplyInputWidget()
{
    delete ui;
}




void ReplyInputWidget::on_bnt_cancel_clicked()
{
    emit this->replyEditingFinished();

}

void ReplyInputWidget::on_bnt_ok_clicked()
{
    if(info_valid==false)
    {
        this->close();
        return;

    }
    else
    {
        Good& g=Good::getGood(good_id);
        g.addReply(question_id,QDate::currentDate(),sender_id,ui->txt_reply->toPlainText());
        emit this->replyEditingFinished();
    }

}

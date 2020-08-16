#include "questioninputwidget.h"
#include "ui_questioninputwidget.h"

QuestionInputWidget::QuestionInputWidget(const QString& good_id,const QString& sender_id,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuestionInputWidget)
{
    ui->setupUi(this);
    this->good_id=good_id;
    this->sender_id=sender_id;
    if(Good::existGoodId(good_id)==false )//|| /*User::userExist(sender_id)==false*/
    {
        this->info_valid=false;
        return;
    }


    this->info_valid=true;
    this->ui->txt_content->setPlaceholderText("سوال خود را بنویسید");
    this->setFixedSize(900,270);

}

QuestionInputWidget::~QuestionInputWidget()
{
    delete ui;
}



void QuestionInputWidget::on_bnt_cancel_clicked()
{

   emit this->questionEditingFinished("");
    this->close();

}


void QuestionInputWidget::on_bnt_ok_clicked()
{
    if(info_valid==false)
    {
        return;
    }
    Good & g=Good::getGood(good_id);
    QString content=ui->txt_content->toPlainText();
    if(g.existQuestionContent(content)==true)
    {
        emit this->questionEditingFinished(g.getIdQustion(content));
        this->close();
        return;
    }
    else
    {
        g.addQuestion(QDate::currentDate(),sender_id,content);
        emit this->questionEditingFinished("");
    }
    this->close();
}

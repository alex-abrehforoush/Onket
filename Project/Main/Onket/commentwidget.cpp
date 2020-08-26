#include "commentwidget.h"
#include "ui_commentwidget.h"

CommentWidget::CommentWidget(const QString& good_id,const QString& comment_seder,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommentWidget)
{
    ui->setupUi(this);
    this->good_id=good_id;
    this->comment_sender=comment_seder;
   if( Good::existGoodId(good_id)==false)
   {
       this->valid_info=false;
       return;
   }

   Good& g=Good::getGood(good_id);
   this->valid_info=true;
   if(g.existCommentSender(comment_seder)==false)
   {
      int cnt=0;
       for(g.setCommentItemSeekBegein();g.CommentItemSeekAtEnd()==false;cnt++)
       {
           QString item_name=g.readCommentsItem();
           CommentWidgetField* cwf=new CommentWidgetField(item_name,this);
           this->fields.insert(item_name,cwf);
           this->ui->field_lay->addWidget(cwf,cnt);

       }
       this->ui->txt_content->setPlaceholderText("نظر خود را وارد کنید");

       return;
   }
   else
   {
    const Comment& c=g.getComment(comment_seder);
        this->ui->txt_content->setText(c.getDescription());
        this->ui->le_adv->setText(c.getAdvantages());
        this->ui->le_disadv->setText(c.getDisadvantages());

    int cnt=0;
    for(g.setCommentItemSeekBegein();g.CommentItemSeekAtEnd()==false;cnt++)
    {
        QString item_name=g.readCommentsItem();
        CommentWidgetField* cwf=new CommentWidgetField(item_name,this);
        this->fields.insert(item_name,cwf);
        cwf->setVlaue(g.CommentGetItemValue(comment_seder,item_name));
        this->ui->field_lay->addWidget(cwf,cnt);

    }

   }





}

Comment CommentWidget::getComment()
{
  Comment temp(QDate::currentDate(),comment_sender,ui->le_adv->text(),ui->le_disadv->text(),ui->txt_content->toPlainText())  ;
  return temp;
}

CommentWidget::~CommentWidget()
{
    delete ui;
}

void CommentWidget::on_bnt_cancel_clicked()
{
    emit this->commentEditingFinished();

}

void CommentWidget::on_bnt_save_clicked()
{

    if(valid_info==false)
    {
        return;
    }
    Good& g=Good::getGood(good_id);
    if(g.existCommentSender(comment_sender)==false)
    {
       Comment c(QDate::currentDate(),comment_sender,ui->le_adv->text(),ui->le_disadv->text(),ui->txt_content->toPlainText());
       for(auto it = this->fields.cbegin();it != this->fields.cend();it++)
       {
           QString item_name=it.key();
           c.insertItem(item_name);
           c.setItemValue(item_name,(*it)->getValue());
       }
       g.addComment(c);

    }
    else
    {
        const Comment& c=g.getComment(comment_sender);
        c.setDescription(ui->txt_content->toPlainText());
        c.setAdvantages(ui->le_adv->text());
        c.setDisAdvantages(ui->le_disadv->text());


      for(auto it : this->fields)
      {
          g.CommentSetItemValue(comment_sender,it->getName(),it->getValue());
      }

    }
    g.commentsWriteToFile();
    Good::WriteFile();
    emit this->commentEditingFinished();

}

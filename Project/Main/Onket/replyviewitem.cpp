#include "replyviewitem.h"
#include "ui_replyviewitem.h"

void ReplyViewItem::update()
{
    if(this->info_valid==false)
    {
        return;
    }
    else
    {
         Good& g=Good::getGood(good_id);
          const Reply& r=g.getReply(reply_id);

          this->ui->bnt_like->setIcon(QIcon("Icons/LikeBlank.png"));
          this->ui->bnt_dislike->setIcon(QIcon("Icons/DisLikeBlank.png"));

          this->ui->bnt_like->setText(QString::number(r.getLikeNumber()));
          this->ui->bnt_dislike->setText(QString::number(r.getDisLikeNumber()));

          if(r.exist(user_id)==true)
          {
              if(r.getLikeMode(user_id)==true)
              {
                  this->ui->bnt_like->setIcon(QIcon("Icons/LikeFill.png"));
              }
              else
              {
                   this->ui->bnt_dislike->setIcon(QIcon("Icons/DisLikeFill.png"));
              }
          }
    }
}

ReplyViewItem::ReplyViewItem(const QString& user_id,const QString& good_id,const QString& reply_id,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReplyViewItem)
{
    ui->setupUi(this);
//    if(User::userExist(user_id)==false)
//    {
//        this->info_valid=false;
//        return;
//    }
    this->user_id=user_id;
    this->good_id=good_id;
    this->reply_id=reply_id;
    if(Good::existGoodId(good_id)==false)
    {
        this->info_valid=false;
        return;
    }
    Good& g=Good::getGood(good_id);
    if(g.existReply(reply_id)==false)
    {
        this->info_valid=false;
        return;
    }
    else
    {
        this->info_valid=true;
       const Reply& r=g.getReply(reply_id);
       this->ui->bnt_icon->setIcon(QIcon("Icons/Reply.png"));
       this->ui->txt_content->setReadOnly(true);
       this->ui->txt_content->setText(r.getContent());
       this->ui->lab_date->setText(r.getDateCreate().toString());
       QString sender_id="ارسال شده از  ";
       sender_id.append(r.getSenderId());
       this->ui->lab_sender->setText(sender_id);

        this->update();


    this->ui->txt_content->setFixedSize(700,250);
    this->setFixedSize(1100,300);

    }

}

ReplyViewItem::~ReplyViewItem()
{
    delete ui;
}

void ReplyViewItem::on_bnt_like_clicked()
{
    if(info_valid==false)
    {
        return;
    }


    Good& g=Good::getGood(good_id);
    const Reply & r=g.getReply(reply_id);

    if(r.exist(user_id)==false)
    {

        g.addReplyLike(reply_id,user_id);
        this->ui->bnt_like->setIcon(QIcon("Icons/LikeFill.png"));
        this->ui->bnt_like->setText(QString::number(r.getLikeNumber()));
        return;
    }
    else
    {
       if(r.getLikeMode(user_id)==true)
       {
           g.replyRemoveLiker(reply_id,user_id);
           this->ui->bnt_like->setIcon(QIcon("Icons/LikeBlank.png"));
           this->ui->bnt_like->setText(QString::number(r.getLikeNumber()));
           return;
       }
       else
       {
           g.addReplyLike(reply_id,user_id);

           this->ui->bnt_like->setIcon(QIcon("Icons/LikeFill.png"));
           this->ui->bnt_dislike->setIcon(QIcon("Icons/DisLikeBlank.png"));

           this->ui->bnt_like->setText(QString::number(r.getLikeNumber()));
            this->ui->bnt_dislike->setText(QString::number(r.getDisLikeNumber()));
           return;
       }
    }
}

void ReplyViewItem::on_bnt_dislike_clicked()
{
    if(info_valid==false)
    {
        return;
    }


    Good& g=Good::getGood(good_id);
    const Reply & r=g.getReply(reply_id);

    if(r.exist(user_id)==false)
    {

        g.addReplyDisLike(reply_id,user_id);
        this->ui->bnt_dislike->setIcon(QIcon("Icons/DisLikeFill.png"));
        this->ui->bnt_dislike->setText(QString::number(r.getDisLikeNumber()));
        return;
    }
    else
    {

       if(r.getLikeMode(user_id)==false)
       {

           g.replyRemoveLiker(reply_id,user_id);
           this->ui->bnt_dislike->setIcon(QIcon("Icons/DisLikeBlank.png"));
           this->ui->bnt_dislike->setText(QString::number(r.getDisLikeNumber()));
           return;
       }
       else
       {
           g.addReplyDisLike(reply_id,user_id);

           this->ui->bnt_like->setIcon(QIcon("Icons/LikeBlank.png"));
           this->ui->bnt_dislike->setIcon(QIcon("Icons/DisLikeFill.png"));

           this->ui->bnt_like->setText(QString::number(r.getLikeNumber()));
            this->ui->bnt_dislike->setText(QString::number(r.getDisLikeNumber()));
           return;
       }
    }
}




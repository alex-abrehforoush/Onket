#include "commentlistwidgetitem.h"
#include "ui_commentlistwidgetitem.h"

void CommentListWidgetItem::update()
{
 if(info_valid==false)
 {
     return;
 }
Good& g=Good::getGood(good_id);
 const Comment& c=g.getComment(comment_sender);
 this->ui->txt_description->setText(c.getDescription());
 this->ui->lab_adv_content->setText(c.getAdvantages());
 this->ui->lab_disadv_content->setText(c.getDisadvantages());
 this->ui->bnt_like->setIcon(QIcon("Database/LikeBlank.png"));
 this->ui->bnt_like->setText(QString::number(c.getLikeNumber()));
 this->ui->bnt_dislike->setIcon(QIcon("Database/Icons/DislikeBlank.png"));
 this->ui->bnt_dislike->setText(QString::number(c.getDisLikeNumber()));

 if(c.existLiker(user_id)==true)
 {
     bool like_mode=c.getLikeMode(user_id);
     if(like_mode)
     {
         this->ui->bnt_like->setIcon(QIcon("Database/Icons/LikeFill.png"));
     }
     else
     {
         this->ui->bnt_dislike->setIcon(QIcon("Database/Icons/DislikeFill.png"));
     }
 }


}

CommentListWidgetItem::CommentListWidgetItem(const QString& user_id,const QString& good_id, const QString& comment_sender,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommentListWidgetItem)
{


    ui->setupUi(this);
    this->good_id=good_id;
    this->user_id=user_id;
    this->comment_sender=comment_sender;
    ui->txt_description->setReadOnly(true);
    if(Good::existGoodId(good_id)==false )
    {
        info_valid=false;
        return ;
    }
    else
    {
        Good& g=Good::getGood(good_id);
        if(g.existCommentSender(comment_sender)==false)
        {
            info_valid=false;
            return;
        }

        info_valid=true;

        this->update();



    }

}

CommentListWidgetItem::~CommentListWidgetItem()
{
    delete ui;
}

void CommentListWidgetItem::on_bnt_like_clicked()
{

    if(info_valid==false)
    {

        return;
    }
    else
    {
       const  Comment& c=Good::getGood(good_id).getComment(comment_sender);
       if(c.existLiker(user_id)==false)
       {
           Good::getGood(good_id).commentAddLike(comment_sender,user_id);
           this->ui->bnt_like->setIcon(QIcon("Database/Icons/LikeFill.png"));

           this->ui->bnt_like->setText(QString::number(c.getLikeNumber()));

           return;
       }
       bool like_mode=c.getLikeMode(user_id);
       if(like_mode==true)
       {
           Good::getGood(good_id).commentRemoveLiker(comment_sender,user_id);


           this->ui->bnt_like->setIcon(QIcon("Database/Icons/LikeBlank.png"));


           this->ui->bnt_like->setText(QString::number(c.getLikeNumber()));

       }
       if(like_mode==false)
       {
           Good::getGood(good_id).commentAddLike(comment_sender,user_id);
           this->ui->bnt_like->setIcon(QIcon("Database/Icons/LikeFill.png"));
           this->ui->bnt_dislike->setIcon(QIcon("Database/Icons/DislikeBlank.png"));
          this->ui->bnt_like->setText(QString::number(c.getLikeNumber()));
           this->ui->bnt_dislike->setText(QString::number(c.getDisLikeNumber()));



       }

    }
}

void CommentListWidgetItem::on_bnt_dislike_clicked()
{
    if(info_valid==false)
    {

        return;
    }
    else
    {
       const  Comment& c=Good::getGood(good_id).getComment(comment_sender);
       if(c.existLiker(user_id)==false)
       {
           Good ::getGood(good_id).commentAddDisLike(comment_sender,user_id);
           this->ui->bnt_dislike->setIcon(QIcon("Database/Icons/DislikeFill.png"));
           this->ui->bnt_dislike->setText(QString::number(c.getDisLikeNumber()));

       }
       else
       {
           bool like_mode=c.getLikeMode(user_id);
           if(like_mode==false)
           {
               Good::getGood(good_id).commentRemoveLiker(comment_sender,user_id);
               this->ui->bnt_dislike->setIcon(QIcon("Database/Icons/DislikeBlank.png"));
                this->ui->bnt_dislike->setText(QString::number(c.getDisLikeNumber()));

           }
           else
           {
               Good::getGood(good_id).commentAddDisLike(comment_sender,user_id);
               this->ui->bnt_like->setIcon(QIcon("Database/Icons/LikeBlank.png"));
               this->ui->bnt_dislike->setIcon(QIcon("Database/Icons/DislikeFill.png"));
              this->ui->bnt_like->setText(QString::number(c.getLikeNumber()));
               this->ui->bnt_dislike->setText(QString::number(c.getDisLikeNumber()));


           }
       }

    }


}

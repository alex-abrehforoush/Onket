#include "commentitemstatus.h"

void CommentItemStatus::update()
{
    if(id_valid==false)return;
    Good& g=Good::getGood(good_id);
    g.commentsReadFile();
    for(g.setCommentItemSeekBegein();g.CommentItemSeekAtEnd()==false;)
    {
        QString itm_name=g.readCommentsItem();
        if(this->fields.contains(itm_name)==true)
        {

            this->fields[itm_name]->setupPercent(g.CommentGetItemValue(itm_name)*100);
        }
    }
}

CommentItemStatus::CommentItemStatus(const QString& good_id,QWidget *parent) :
    QWidget(parent)
    ,main_lay(new QVBoxLayout(this))
{

     this->setStyleSheet("background-color: rgb(255, 255, 255);");
    this->setLayout(main_lay);
    this->good_id=good_id;
    if(Good::existGoodId(good_id)==false)
    {
        this->id_valid=false;
        return;
    }
    this->id_valid=true;
    Good& g=Good::getGood(good_id);
    QLabel* lab_name=new QLabel("نظرات کاربران",this);
    lab_name->setAlignment(Qt::AlignCenter);
    lab_name->setFixedHeight(40);
    lab_name->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(0, 0, 255);");
    this->main_lay->addWidget(lab_name);

    int cnt=1;
    for(g.setCommentItemSeekBegein();g.CommentItemSeekAtEnd()==false;cnt++)
    {
        QString item_name=g.readCommentsItem();
        CommentItemStatusField* cf=new CommentItemStatusField(item_name,g.CommentGetItemValue(item_name)*100,this);
        this->main_lay->addWidget(cf,cnt);
        this->fields.insert(item_name,cf);
    }

    this->setFixedSize(900,100*cnt);


}

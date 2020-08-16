#include "commentitemstatus.h"

CommentItemStatus::CommentItemStatus(const QString& good_id,QWidget *parent) :
    QWidget(parent)
    ,main_lay(new QVBoxLayout(this))
{

    this->setLayout(main_lay);
    this->good_id=good_id;
    if(Good::existGoodId(good_id)==false)
    {
        this->id_valid=false;
        return;
    }
    this->id_valid=true;
    Good& g=Good::getGood(good_id);

    int cnt=0;
    for(g.setCommentItemSeekBegein();g.CommentItemSeekAtEnd()==false;cnt++)
    {
        QString item_name=g.readCommentsItem();
        CommentItemStatusField* cf=new CommentItemStatusField(item_name,g.CommentGetItemValue(item_name)*100,this);
        this->main_lay->addWidget(cf,cnt);
    }

    this->setFixedSize(900,100*cnt);
    this->setStyleSheet("background-color: rgb(255, 255, 255)");

}

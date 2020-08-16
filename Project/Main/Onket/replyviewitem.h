#ifndef REPLYVIEWITEM_H
#define REPLYVIEWITEM_H

#include <QWidget>
#include "good.h"
#include "User.h"

namespace Ui {
class ReplyViewItem;
}

class ReplyViewItem : public QWidget
{
    Q_OBJECT


 QString good_id;
 QString user_id;
 QString reply_id;
 bool info_valid=false;
public slots:
 void update();
public:
    explicit ReplyViewItem(const QString& user_id,const QString& good_id,const QString& reply_id,QWidget *parent = nullptr);
    ~ReplyViewItem();

private slots:
 void on_bnt_like_clicked();

 void on_bnt_dislike_clicked();


private:
    Ui::ReplyViewItem *ui;
};

#endif // REPLYVIEWITEM_H

#ifndef COMMENTLISTWIDGETITEM_H
#define COMMENTLISTWIDGETITEM_H

#include <QWidget>
#include "comment.h"
#include "good.h"
#include "User.h"

namespace Ui {
class CommentListWidgetItem;
}

class CommentListWidgetItem : public QWidget
{
    Q_OBJECT

    bool info_valid;
    QString user_id;
    QString good_id;
    QString comment_sender;




public:
    explicit CommentListWidgetItem(const QString& user_id,const QString& good_id, const QString& comment_sender,QWidget *parent = nullptr);
    ~CommentListWidgetItem();

private slots:
    void on_bnt_like_clicked();

    void on_bnt_dislike_clicked();

private:
    Ui::CommentListWidgetItem *ui;
};

#endif // COMMENTLISTWIDGETITEM_H

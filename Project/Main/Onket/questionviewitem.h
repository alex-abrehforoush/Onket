#ifndef QUESTIONVIEWITEM_H
#define QUESTIONVIEWITEM_H

#include <QWidget>
#include <QMessageBox>
#

#include "good.h"


namespace Ui {
class QuestionViewItem;
}

class QuestionViewItem : public QWidget
{
    Q_OBJECT

    QString good_id;
    QString user_id;
    QString question_id;

    bool info_valid=false;
public slots:
    void update();
public:
    explicit QuestionViewItem(const QString & user_id,const QString & good_id,const QString& question_id,QWidget *parent = nullptr);
    ~QuestionViewItem();

signals:
    void addReply(const QString& user_id,const QString& good_id,const QString& question_id);
private slots:
    void on_bnt_add_reply_clicked();

private:
    Ui::QuestionViewItem *ui;
};

#endif // QUESTIONVIEWITEM_H

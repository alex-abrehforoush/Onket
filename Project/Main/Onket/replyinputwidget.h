#ifndef REPLYINPUTWIDGET_H
#define REPLYINPUTWIDGET_H

#include <QWidget>

#include "good.h"
#include "User.h"

namespace Ui {
class ReplyInputWidget;
}

class ReplyInputWidget : public QWidget
{
    Q_OBJECT
    QString good_id;
    QString question_id;
    QString sender_id;
    bool info_valid;

signals:
    void replyEditingFinished();
public:
    explicit ReplyInputWidget(const QString& good_id,const QString& question_id,const QString & sender_id,QWidget *parent = nullptr);
    ~ReplyInputWidget();

private slots:
    void on_bnt_ok_clicked();

    void on_bnt_cancel_clicked();

private:
    Ui::ReplyInputWidget *ui;
};

#endif // REPLYINPUTWIDGET_H

#ifndef COMMENTWIDGET_H
#define COMMENTWIDGET_H

#include <QWidget>
#include <QMap>

#include "comment.h"
#include "good.h"
#include "commentwidgetfield.h"


namespace Ui {
class CommentWidget;
}

class CommentWidget : public QWidget
{
    Q_OBJECT
    QString good_id;
    QString comment_sender;
    bool valid_info=false;

    QMap<QString,CommentWidgetField*> fields;
signals:
    void commentEditingFinished();

public:
    explicit CommentWidget(const QString& good_id,const QString& comment_seder,QWidget *parent = nullptr);
    Comment getComment();
    ~CommentWidget();

private slots:
    void on_bnt_cancel_clicked();

    void on_bnt_save_clicked();

private:
    Ui::CommentWidget *ui;
};

#endif // COMMENTWIDGET_H

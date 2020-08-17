#ifndef COMMENTLISTWIDGET_H
#define COMMENTLISTWIDGET_H

#include <QScrollArea>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QMap>
#include <QPushButton>
#include "commentlistwidgetitem.h"
#include "commentwidget.h"

namespace Ui {
class CommentListWidget;
}

class CommentListWidget : public QScrollArea
{
    Q_OBJECT
    QWidget* center_widget=nullptr;
    QVBoxLayout* main_lay=nullptr;
    QString good_id;
    QString user_id;
    bool id_valid=false;
    QMap<QString,CommentListWidgetItem*> widgets;
    CommentWidget* c_widget=nullptr;
    QPushButton* bnt_add_comment=nullptr;

public slots:
   void update();
private slots:
   void CommentFinished();
   void commentAdded();
public:

    bool existCommentSender(const QString& comment_sender)const;
    CommentListWidgetItem& getItem(const QString& comment_sender);
    explicit CommentListWidget(const QString& good_id ,const QString& user_id,QWidget *parent = nullptr);
    ~CommentListWidget();

private:
    Ui::CommentListWidget *ui;
};

#endif // COMMENTLISTWIDGET_H

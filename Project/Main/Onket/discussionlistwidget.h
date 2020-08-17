#ifndef DISCUSSIONLISTWIDGET_H
#define DISCUSSIONLISTWIDGET_H

#include <QScrollArea>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QMap>
#include <QPushButton>

#include "good.h"
#include "User.h"
#include "questionviewitem.h"
#include "replyviewitem.h"
#include "questioninputwidget.h"
#include "replyinputwidget.h"

namespace Ui {
class DiscussionListWidget;
}

class DiscussionListWidget : public QScrollArea
{
    Q_OBJECT
    QString good_id;
    QString user_id;
    bool info_valid=false;

    QWidget* center_widget=nullptr;
    QVBoxLayout* main_lay=nullptr;

    QMap<QString,QWidget*> discussion_items;
    QPushButton* bnt_add_question=nullptr;
    QWidget* question=nullptr,*Reply=nullptr;
private slots:
    void showReplys(const QString& good_id,const QString& question_id);
     void hideReplys(const QString& good_id,const QString& question_id);

public slots:
    void update();
private slots:
    void QuestionFinished(const QString& mode);
    void addQuestion();



public:
    explicit DiscussionListWidget(const QString& good_id,const QString& user_id,QWidget *parent = nullptr);
    ~DiscussionListWidget();

private:
    Ui::DiscussionListWidget *ui;
};

#endif // DISCUSSIONLISTWIDGET_H

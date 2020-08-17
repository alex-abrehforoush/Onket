#ifndef DISCUSSIONLISTWIDGET_H
#define DISCUSSIONLISTWIDGET_H

#include <QScrollArea>

namespace Ui {
class DiscussionListWidget;
}

class DiscussionListWidget : public QScrollArea
{
    Q_OBJECT

public:
    explicit DiscussionListWidget(QWidget *parent = nullptr);
    ~DiscussionListWidget();

private:
    Ui::DiscussionListWidget *ui;
};

#endif // DISCUSSIONLISTWIDGET_H

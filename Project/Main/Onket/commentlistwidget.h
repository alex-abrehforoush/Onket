#ifndef COMMENTLISTWIDGET_H
#define COMMENTLISTWIDGET_H

#include <QScrollArea>

namespace Ui {
class CommentListWidget;
}

class CommentListWidget : public QScrollArea
{
    Q_OBJECT

public:
    explicit CommentListWidget(QWidget *parent = nullptr);
    ~CommentListWidget();

private:
    Ui::CommentListWidget *ui;
};

#endif // COMMENTLISTWIDGET_H

#ifndef COMMENTLISTWIDGETITEM_H
#define COMMENTLISTWIDGETITEM_H

#include <QWidget>

namespace Ui {
class CommentListWidgetItem;
}

class CommentListWidgetItem : public QWidget
{
    Q_OBJECT

public:
    explicit CommentListWidgetItem(QWidget *parent = nullptr);
    ~CommentListWidgetItem();

private:
    Ui::CommentListWidgetItem *ui;
};

#endif // COMMENTLISTWIDGETITEM_H

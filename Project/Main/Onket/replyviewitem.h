#ifndef REPLYVIEWITEM_H
#define REPLYVIEWITEM_H

#include <QWidget>

namespace Ui {
class ReplyViewItem;
}

class ReplyViewItem : public QWidget
{
    Q_OBJECT

public:
    explicit ReplyViewItem(QWidget *parent = nullptr);
    ~ReplyViewItem();

private:
    Ui::ReplyViewItem *ui;
};

#endif // REPLYVIEWITEM_H

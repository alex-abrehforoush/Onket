#ifndef REPLYINPUTWIDGET_H
#define REPLYINPUTWIDGET_H

#include <QWidget>

namespace Ui {
class ReplyInputWidget;
}

class ReplyInputWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ReplyInputWidget(QWidget *parent = nullptr);
    ~ReplyInputWidget();

private:
    Ui::ReplyInputWidget *ui;
};

#endif // REPLYINPUTWIDGET_H

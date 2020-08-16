#ifndef QUESTIONINPUTWIDGET_H
#define QUESTIONINPUTWIDGET_H

#include <QWidget>

namespace Ui {
class QuestionInputWidget;
}

class QuestionInputWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QuestionInputWidget(QWidget *parent = nullptr);
    ~QuestionInputWidget();

private:
    Ui::QuestionInputWidget *ui;
};

#endif // QUESTIONINPUTWIDGET_H

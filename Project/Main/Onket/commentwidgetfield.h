#ifndef COMMENTWIDGETFIELD_H
#define COMMENTWIDGETFIELD_H

#include <QWidget>

namespace Ui {
class CommentWidgetField;
}

class CommentWidgetField : public QWidget
{
    Q_OBJECT

public:
    explicit CommentWidgetField(QWidget *parent = nullptr);
    ~CommentWidgetField();

private:
    Ui::CommentWidgetField *ui;
};

#endif // COMMENTWIDGETFIELD_H

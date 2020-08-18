#ifndef GOODMAINVIEWWIDGET_H
#define GOODMAINVIEWWIDGET_H

#include <QScrollArea>

namespace Ui {
class goodMainviewWidget;
}

class goodMainviewWidget : public QScrollArea
{
    Q_OBJECT

public:
    explicit goodMainviewWidget(QWidget *parent = nullptr);
    ~goodMainviewWidget();

private:
    Ui::goodMainviewWidget *ui;
};

#endif // GOODMAINVIEWWIDGET_H

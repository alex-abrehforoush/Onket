#ifndef GOODPROPERTYWIDGET_H
#define GOODPROPERTYWIDGET_H

#include <QWidget>

namespace Ui {
class GoodPropertyWidget;
}

class GoodPropertyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GoodPropertyWidget(QWidget *parent = nullptr);
    ~GoodPropertyWidget();

private:
    Ui::GoodPropertyWidget *ui;
};

#endif // GOODPROPERTYWIDGET_H

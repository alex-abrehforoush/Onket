#ifndef GOODPROPERTYWIDGET_H
#define GOODPROPERTYWIDGET_H

#include <QWidget>
#include "good.h"

namespace Ui {
class GoodPropertyWidget;
}

class GoodPropertyWidget : public QWidget
{
    Q_OBJECT

    QString good_id;
    bool info_valid=false;
public:
    explicit GoodPropertyWidget(const QString& good_id,QWidget *parent = nullptr);
    ~GoodPropertyWidget();

private:
    Ui::GoodPropertyWidget *ui;
};

#endif // GOODPROPERTYWIDGET_H

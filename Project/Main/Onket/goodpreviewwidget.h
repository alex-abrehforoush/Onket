#ifndef GOODPREVIEWWIDGET_H
#define GOODPREVIEWWIDGET_H

#include <QWidget>

namespace Ui {
class GoodPreviewWidget;
}

class GoodPreviewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GoodPreviewWidget(QWidget *parent = nullptr);
    ~GoodPreviewWidget();

private:
    Ui::GoodPreviewWidget *ui;
};

#endif // GOODPREVIEWWIDGET_H

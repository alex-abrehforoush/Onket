#ifndef GOODPREVIEWSCROLLAREA_H
#define GOODPREVIEWSCROLLAREA_H

#include <QScrollArea>
#include <QScrollBar>
#include <QMap>
#include "goodpreviewwidget.h"
#include <QHBoxLayout>

namespace Ui {
class GoodPreviewScrollArea;
}

class GoodPreviewScrollArea : public QScrollArea
{
    static QMap<QString,GoodPreviewWidget* > good_preview;
    QWidget* center_widget=nullptr;
    QHBoxLayout* main_lay=nullptr;

    Q_OBJECT

public:
    bool existGood(const QString& good_id)const ;
    void addGood(const QString& good_id);
    bool removeGood(const QString& good_id);
    GoodPreviewWidget& getGoodPreviewWidget(const QString& good_id);
    void update();
    explicit GoodPreviewScrollArea(QWidget *parent = nullptr);
    ~GoodPreviewScrollArea();

private:
    Ui::GoodPreviewScrollArea *ui;
};

#endif // GOODPREVIEWSCROLLAREA_H

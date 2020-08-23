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
    QMap<QString,GoodPreviewWidget* > good_preview;
    QWidget* center_widget=nullptr;
    QHBoxLayout* main_lay=nullptr;

    Q_OBJECT
signals:
    void onGoodPreviewClicked(const QString& good_id);
    void showCompareButton();
    void hideCompareButton();
private slots:
    void on_good_preview_clicked(const QString& good_id);
    void show_compare_button();
    void hide_compare_button();

public slots:
    void update();
    void clear();

public:
    bool existGood(const QString& good_id)const ;
    void addGood(const QString& good_id);
    void addGoodSortedByPrice(const QString& type_id);
    void addGoodSortedByDiscount(const QString& type_id);
    void addGoodSortedByWillingness(const QString& type_id);
    bool removeGood(const QString& good_id);
    GoodPreviewWidget& getGoodPreviewWidget(const QString& good_id);
    explicit GoodPreviewScrollArea(QWidget *parent = nullptr);
    ~GoodPreviewScrollArea();

private:
    Ui::GoodPreviewScrollArea *ui;
};

#endif // GOODPREVIEWSCROLLAREA_H

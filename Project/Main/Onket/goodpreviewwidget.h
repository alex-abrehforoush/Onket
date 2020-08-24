#ifndef GOODPREVIEWWIDGET_H
#define GOODPREVIEWWIDGET_H

#include <QWidget>
#include <QVector>
#include <QMap>
#include <QImage>
#include <QPixmap>
#include <QMouseEvent>
#include <QPushButton>

#include "good.h"

namespace Ui {
class GoodPreviewWidget;
}

class GoodPreviewWidget : public QWidget
{
     Q_OBJECT
    static QVector<QString> style_sheet;
    static QString style_error;
    static int style_index;
    static QMap<QString,GoodPreviewWidget*> compare;

    QString good_id;
    bool id_valid;
    bool load_picture;
    static void increaseStyleIndex();
    static QString number(unsigned int input);

    void showAll();


signals:
    void on_good_preview_clicked(const QString& good_id);
    void showCompareButton();
    void hideCompareButton();
protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override;

public:
    static QVector<QString> getCompareList();
    static void clearCompareList();
    QString getGoodId();
    bool getIdValidMode();
    bool getLoadPictureMode();
    void changeCheckedState(bool mode);
    void update();
    explicit GoodPreviewWidget(const QString& good_id,QWidget *parent = nullptr);
    ~GoodPreviewWidget();

private slots:
    void on_checkBox_compare_stateChanged();

private:
    Ui::GoodPreviewWidget *ui;
};

#endif // GOODPREVIEWWIDGET_H

#ifndef GOODPREVIEWWIDGET_H
#define GOODPREVIEWWIDGET_H

#include <QWidget>
#include <QVector>
#include <QImage>
#include <QPixmap>
#include <QMouseEvent>

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

    QString good_id;
    bool id_valid;
    bool load_picture;
    static void increaseStyleIndex();
    static QString number(unsigned int input);

    void showAll();


 signals:
    void on_Good_preview_clicke(const QString& good_id);
protected:
    void mouseDoubleClickEvent(QMouseEvent *event) override;

public:
    QString getGoodId();
    bool getIdValidMode();
    bool getLoadPictureMode();
    void update();
    explicit GoodPreviewWidget(const QString& good_id,QWidget *parent = nullptr);
    ~GoodPreviewWidget();

private:
    Ui::GoodPreviewWidget *ui;
};

#endif // GOODPREVIEWWIDGET_H

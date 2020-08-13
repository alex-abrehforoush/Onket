#ifndef GOODPREVIEWSCROLLAREA_H
#define GOODPREVIEWSCROLLAREA_H

#include <QScrollArea>

namespace Ui {
class GoodPreviewScrollArea;
}

class GoodPreviewScrollArea : public QScrollArea
{
    Q_OBJECT

public:
    explicit GoodPreviewScrollArea(QWidget *parent = nullptr);
    ~GoodPreviewScrollArea();

private:
    Ui::GoodPreviewScrollArea *ui;
};

#endif // GOODPREVIEWSCROLLAREA_H

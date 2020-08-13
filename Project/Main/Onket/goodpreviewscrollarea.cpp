#include "goodpreviewscrollarea.h"
#include "ui_goodpreviewscrollarea.h"

GoodPreviewScrollArea::GoodPreviewScrollArea(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::GoodPreviewScrollArea)
{
    ui->setupUi(this);
}

GoodPreviewScrollArea::~GoodPreviewScrollArea()
{
    delete ui;
}

#include "goodpreviewwidget.h"
#include "ui_goodpreviewwidget.h"

GoodPreviewWidget::GoodPreviewWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GoodPreviewWidget)
{
    ui->setupUi(this);
}

GoodPreviewWidget::~GoodPreviewWidget()
{
    delete ui;
}

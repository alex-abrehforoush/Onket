#include "goodpropertywidget.h"
#include "ui_goodpropertywidget.h"

GoodPropertyWidget::GoodPropertyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GoodPropertyWidget)
{
    ui->setupUi(this);
}

GoodPropertyWidget::~GoodPropertyWidget()
{
    delete ui;
}

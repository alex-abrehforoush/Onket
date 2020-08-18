#include "goodmainviewwidget.h"
#include "ui_goodmainviewwidget.h"

goodMainviewWidget::goodMainviewWidget(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::goodMainviewWidget)
{
    ui->setupUi(this);
}

goodMainviewWidget::~goodMainviewWidget()
{
    delete ui;
}

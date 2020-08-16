#include "replyinputwidget.h"
#include "ui_replyinputwidget.h"

ReplyInputWidget::ReplyInputWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReplyInputWidget)
{
    ui->setupUi(this);
}

ReplyInputWidget::~ReplyInputWidget()
{
    delete ui;
}

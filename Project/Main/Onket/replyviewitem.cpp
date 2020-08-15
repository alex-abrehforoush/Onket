#include "replyviewitem.h"
#include "ui_replyviewitem.h"

ReplyViewItem::ReplyViewItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReplyViewItem)
{
    ui->setupUi(this);
}

ReplyViewItem::~ReplyViewItem()
{
    delete ui;
}

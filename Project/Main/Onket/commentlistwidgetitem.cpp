#include "commentlistwidgetitem.h"
#include "ui_commentlistwidgetitem.h"

CommentListWidgetItem::CommentListWidgetItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommentListWidgetItem)
{
    ui->setupUi(this);
}

CommentListWidgetItem::~CommentListWidgetItem()
{
    delete ui;
}

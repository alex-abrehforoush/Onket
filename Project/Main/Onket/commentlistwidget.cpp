#include "commentlistwidget.h"
#include "ui_commentlistwidget.h"

CommentListWidget::CommentListWidget(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::CommentListWidget)
{
    ui->setupUi(this);
}

CommentListWidget::~CommentListWidget()
{
    delete ui;
}

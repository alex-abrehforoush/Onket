#include "commentwidgetfield.h"
#include "ui_commentwidgetfield.h"

CommentWidgetField::CommentWidgetField(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommentWidgetField)
{
    ui->setupUi(this);
}

CommentWidgetField::~CommentWidgetField()
{
    delete ui;
}

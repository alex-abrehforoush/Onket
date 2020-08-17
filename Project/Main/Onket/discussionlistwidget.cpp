#include "discussionlistwidget.h"
#include "ui_discussionlistwidget.h"

DiscussionListWidget::DiscussionListWidget(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::DiscussionListWidget)
{
    ui->setupUi(this);
}

DiscussionListWidget::~DiscussionListWidget()
{
    delete ui;
}

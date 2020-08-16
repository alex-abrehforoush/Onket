#include "questioninputwidget.h"
#include "ui_questioninputwidget.h"

QuestionInputWidget::QuestionInputWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuestionInputWidget)
{
    ui->setupUi(this);
}

QuestionInputWidget::~QuestionInputWidget()
{
    delete ui;
}

#include "tamrini.h"
#include "ui_tamrini.h"

Tamrini::Tamrini(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tamrini)
{
    ui->setupUi(this);
}

Tamrini::~Tamrini()
{
    delete ui;
}

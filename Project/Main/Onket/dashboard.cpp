#include "dashboard.h"
#include "ui_dashboard.h"

Dashboard::Dashboard(int mode, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    ui->my_orders->hide();
    ui->lists->hide();
    ui->comments->hide();
    ui->addresses->hide();
    ui->messages->hide();
    ui->last_activities->hide();
    ui->account_info->hide();
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_pushButton_9_clicked()
{
    ui->my_orders->show();
    ui->lists->hide();
    ui->comments->hide();
    ui->addresses->hide();
    ui->messages->hide();
    ui->last_activities->hide();
    ui->account_info->hide();
}

void Dashboard::on_pushButton_10_clicked()
{
    ui->my_orders->hide();
    ui->lists->show();
    ui->comments->hide();
    ui->addresses->hide();
    ui->messages->hide();
    ui->last_activities->hide();
    ui->account_info->hide();
}

void Dashboard::on_pushButton_11_clicked()
{
    ui->my_orders->hide();
    ui->lists->hide();
    ui->comments->show();
    ui->addresses->hide();
    ui->messages->hide();
    ui->last_activities->hide();
    ui->account_info->hide();
}

void Dashboard::on_pushButton_12_clicked()
{
    ui->my_orders->hide();
    ui->lists->hide();
    ui->comments->hide();
    ui->addresses->show();
    ui->messages->hide();
    ui->last_activities->hide();
    ui->account_info->hide();
}

void Dashboard::on_pushButton_13_clicked()
{
    ui->my_orders->hide();
    ui->lists->hide();
    ui->comments->hide();
    ui->addresses->hide();
    ui->messages->show();
    ui->last_activities->hide();
    ui->account_info->hide();
}

void Dashboard::on_pushButton_14_clicked()
{
    ui->my_orders->hide();
    ui->lists->hide();
    ui->comments->hide();
    ui->addresses->hide();
    ui->messages->hide();
    ui->last_activities->show();
    ui->account_info->hide();
}

void Dashboard::on_pushButton_15_clicked()
{
    ui->my_orders->hide();
    ui->lists->hide();
    ui->comments->hide();
    ui->addresses->hide();
    ui->messages->hide();
    ui->last_activities->hide();
    ui->account_info->show();
}

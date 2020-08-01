#include "loginpage.h"
#include "ui_loginpage.h"

LoginPage::LoginPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

LoginPage::~LoginPage()
{
    delete ui;
}

QSize LoginPage::sizeHint() const
{
    return QSize(1500, 800);
}

void LoginPage::on_commandLinkButton_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->checkBox->setCheckState(Qt::Unchecked);
    ui->checkBox_2->setCheckState(Qt::Unchecked);
    this->close();
}

void LoginPage::on_checkBox_stateChanged()
{
    if(ui->checkBox->isChecked()==false)
    {
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    }
    else
    {
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    }

}

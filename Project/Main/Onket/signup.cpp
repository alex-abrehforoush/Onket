#include "signup.h"
#include "ui_signup.h"

signup::signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
}

signup::~signup()
{
    delete ui;
}

QSize signup::sizeHint() const
{
    return QSize(1500, 800);
}

void signup::on_lineEdit_3_editingFinished()
{
    if((ui->lineEdit_2->text() != "") && ui->lineEdit_2->text() != ui->lineEdit_3->text()) ui->label_5->setText("کلمه عبور با تکرار آن یکسان نیست");
    else ui->label_5->setText("");
}

void signup::on_lineEdit_editingFinished()
{
    if(ui->lineEdit->text() == "") ui->label_7->setText("ایمیل را وارد کنید");
    else if(!(ui->lineEdit->text().contains("@") &&  (ui->lineEdit->text().endsWith(".com") || ui->lineEdit->text().endsWith(".ir")))) ui->label_7->setText("ایمیل وارد شده نامعتبر است");
    else ui->label_7->setText("");
}

void signup::on_lineEdit_2_editingFinished()
{
    if(ui->lineEdit_2->text() == "") ui->label_6->setText("کلمه عبور را وارد کنید");
    else if(ui->lineEdit_2->text().length() < 8) ui->label_6->setText("کلمه عبور ضعیف است");
    else ui->label_6->setText("");
}

void signup::on_checkBox_stateChanged()
{
    if(ui->checkBox->isChecked())
    {
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
        ui->lineEdit_3->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
        ui->lineEdit_3->setEchoMode(QLineEdit::Password);
    }
}

void signup::on_commandLinkButton_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->checkBox->setCheckState(Qt::Unchecked);
    ui->label_5->clear();
    ui->label_6->clear();
    ui->label_7->clear();
    this->close();
}

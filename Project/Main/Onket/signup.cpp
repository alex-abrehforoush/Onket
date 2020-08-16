#include "signup.h"
#include "ui_signup.h"
#include "User.h"
#include "Customer.h"

signup::signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    ui->password_line_edit->setEchoMode(QLineEdit::Password);
    ui->repeat_password_line_edit->setEchoMode(QLineEdit::Password);
}

signup::~signup()
{
    delete ui;
}

QSize signup::sizeHint() const
{
    return QSize(1500, 800);
}

void signup::on_repeat_password_line_edit_editingFinished()
{
    if((ui->password_line_edit->text() != "") && ui->password_line_edit->text() != ui->repeat_password_line_edit->text()) ui->label_5->setText("کلمه عبور با تکرار آن یکسان نیست");
    else ui->label_5->setText("");
}

void signup::on_username_line_edit_editingFinished()
{
    if(ui->username_line_edit->text() == "") ui->label_7->setText("ایمیل را وارد کنید");
    else if(!(ui->username_line_edit->text().contains("@") &&  (ui->username_line_edit->text().endsWith(".com") || ui->username_line_edit->text().endsWith(".ir")))) ui->label_7->setText("ایمیل وارد شده نامعتبر است");
    else ui->label_7->setText("");
}

void signup::on_password_line_edit_editingFinished()
{
    if(ui->password_line_edit->text() == "") ui->label_6->setText("کلمه عبور را وارد کنید");
    else if(ui->password_line_edit->text().length() < 8) ui->label_6->setText("کلمه عبور ضعیف است");
    else ui->label_6->setText("");
}

void signup::on_show_password_stateChanged()
{
    if(ui->show_password->isChecked())
    {
        ui->password_line_edit->setEchoMode(QLineEdit::Normal);
        ui->repeat_password_line_edit->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->password_line_edit->setEchoMode(QLineEdit::Password);
        ui->repeat_password_line_edit->setEchoMode(QLineEdit::Password);
    }
}

void signup::on_back_clicked()
{
    ui->username_line_edit->clear();
    ui->password_line_edit->clear();
    ui->repeat_password_line_edit->clear();
    ui->show_password->setCheckState(Qt::Unchecked);
    ui->label_5->clear();
    ui->label_6->clear();
    ui->label_7->clear();
    this->close();
}

void signup::on_signup_button_clicked()
{
    if(this->ui->label_5->text() == "" && this->ui->label_6->text() == "" && this->ui->label_7->text() == "")
    {
        Customer temp(this->ui->username_line_edit->text(), this->ui->password_line_edit->text());
        User::addUser(&temp);
    }
    else return;
}

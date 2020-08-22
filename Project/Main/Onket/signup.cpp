#include "signup.h"
#include "ui_signup.h"
#include "User.h"
#include "Customer.h"
#include <QString>
#include <QMessageBox>
#include "mainwindow.h"

signup::signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    ui->password_line_edit->setEchoMode(QLineEdit::Password);
    ui->repeat_password_line_edit->setEchoMode(QLineEdit::Password);
    ui->signup_second_step->close();
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
    if((!ui->password_line_edit->text().isEmpty()) && ui->password_line_edit->text() != ui->repeat_password_line_edit->text()) ui->label_5->setText("کلمه عبور با تکرار آن یکسان نیست");
    else ui->label_5->clear();
}

void signup::on_username_line_edit_editingFinished()
{
    if(ui->username_line_edit->text().isEmpty()) ui->label_7->setText("ایمیل را وارد کنید");
    else if(!(ui->username_line_edit->text().contains("@") &&  (ui->username_line_edit->text().endsWith(".com") || ui->username_line_edit->text().endsWith(".ir")))) ui->label_7->setText("ایمیل وارد شده نامعتبر است");
    else ui->label_7->clear();
}

void signup::on_password_line_edit_editingFinished()
{
    if(ui->password_line_edit->text().isEmpty()) ui->label_6->setText("کلمه عبور را وارد کنید");
    else if(ui->password_line_edit->text().length() < 8) ui->label_6->setText("کلمه عبور ضعیف است");
    else ui->label_6->clear();
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
    MainWindow::setSignupPage(nullptr);
    MainWindow::showMainScrollArea();
}

void signup::on_signup_button_clicked()
{
    if(this->ui->label_5->text().isEmpty() && this->ui->label_6->text().isEmpty() && this->ui->label_7->text().isEmpty())
    {
        this->user_creator = new Customer(this->ui->username_line_edit->text(), this->ui->password_line_edit->text());
        this->ui->signup_first_step->close();
        this->ui->signup_second_step->show();
    }
    else return;
}

void signup::on_firstname_line_edit_editingFinished()
{
    if(this->ui->firstname_line_edit->text().isEmpty())
    {
        this->ui->firstname_is_empty->setText("نام را وارد کنید");
    }
    else
    {
        this->ui->firstname_is_empty->clear();
    }
}

void signup::on_lastname_line_edit_editingFinished()
{
    if(this->ui->lastname_line_edit->text().isEmpty())
    {
        this->ui->lastname_is_empty->setText("نام خانوادگی را وارد کنید");
    }
    else
    {
        this->ui->lastname_is_empty->clear();
    }
}

void signup::on_phone_number_line_edit_editingFinished()
{
    if(this->ui->phone_number_line_edit->text().isEmpty())
    {
        this->ui->phone_is_empty->setText("شماره تلفن همراه را وارد کنید");
    }
    else
    {
        this->ui->phone_is_empty->clear();
    }
}

void signup::on_address_line_edit_editingFinished()
{
    if(this->ui->address_line_edit->text().isEmpty())
    {
        this->ui->no_address->setText("حداقل یک آدرس را ثبت کنید");
    }
    else
    {
        this->ui->no_address->clear();
    }
}

void signup::on_add_address_button_clicked()
{
    if(!user_creator->getAddresses().contains(this->ui->address_line_edit->text()))
    {
        this->user_creator->addAddress(this->ui->address_line_edit->text());
        this->ui->address_line_edit->clear();
    }
    else
    {
        QMessageBox::information(this, "پیام", "این آدرس وجود دارد");
    }
}

void signup::on_create_account_clicked()
{
    if(this->ui->firstname_is_empty->text().isEmpty() && this->ui->lastname_is_empty->text().isEmpty()
            && this->ui->phone_is_empty->text().isEmpty() && this->ui->no_address->text().isEmpty())
    {
        user_creator->setFirstname(this->ui->firstname_line_edit->text());
        user_creator->setLastname(this->ui->lastname_line_edit->text());
        user_creator->setPhoneNumber(this->ui->phone_number_line_edit->text());
        user_creator->setBirthday(this->ui->birthday_edit->date());
        User::addUser(user_creator);
        delete user_creator;
        user_creator = nullptr;
        QMessageBox::information(this, "پیام", "حساب کاربری با موفقیت ایجاد شد");
        this->ui->back->click();
    }
}

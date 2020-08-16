#include "loginpage.h"
#include "ui_loginpage.h"
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>

LoginPage::LoginPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    ui->password_line_edit->setEchoMode(QLineEdit::Password);

}

LoginPage::~LoginPage()
{
    delete ui;
}

QSize LoginPage::sizeHint() const
{
    return QSize(1500, 800);
}

void LoginPage::on_back_clicked()
{
    ui->username_line_edit->clear();
    ui->password_line_edit->clear();
    ui->password_is_empty->setText("");
    ui->username_is_empty->setText("");
    ui->username_or_password_is_wrong->setText("");
    ui->show_password->setCheckState(Qt::Unchecked);
    ui->save_login_info->setCheckState(Qt::Unchecked);
    this->close();
}

void LoginPage::on_show_password_stateChanged()
{
    if(ui->show_password->isChecked()==false)
    {
        ui->password_line_edit->setEchoMode(QLineEdit::Password);
    }
    else
    {
        ui->password_line_edit->setEchoMode(QLineEdit::Normal);
    }
}

User* LoginPage::on_enter_button_clicked()
{
    if(!ui->username_line_edit->text().isEmpty() && !ui->password_line_edit->text().isEmpty())
    {
        User* temp = nullptr;
        temp = User::getUser(ui->username_line_edit->text());
        if(User::userExist(ui->username_line_edit->text()))
        {
            if(User::encryptPassword(ui->password_line_edit->text()) == temp->getPassword())
            {
                QFile data_read("Database/User/" + ui->username_line_edit->text() + ".csv");
                if(data_read.open(QIODevice::ReadOnly | QIODevice::Text))
                {
                    QTextStream in(&data_read);
                    QString content = in.readAll();
                    data_read.close();
                    QStringList list_1 = content.split("\n");
                    list_1[2].append(QDateTime::currentDateTime().toString() + "─");
                    QFile data_write("Database/User/" + ui->username_line_edit->text() + ".csv");
                    if(data_write.open(QIODevice::WriteOnly | QIODevice::Text))
                    {
                        QTextStream out(&data_write);
                        out << list_1.at(0) << "\n" << list_1.at(1) << "\n" << list_1.at(2);
                        data_write.close();
                    }
                }
                emit successfulLogin();
                MainWindow::setCurrentUser(temp);
                ui->back->click();
                return temp;
            }
            else
            {
                ui->username_or_password_is_wrong->setText("کلمه عبور وارد شده نادرست می باشد");
                return nullptr;
            }
        }
        else
        {
            ui->username_or_password_is_wrong->setText("کاربری با نام کاربری وارد شده وجود ندارد");
            return nullptr;
        }
    }
    return nullptr;
}

void LoginPage::on_signup_button_clicked()
{
    emit signup();
    ui->back->click();
}

void LoginPage::on_username_line_edit_editingFinished()
{
    if(ui->username_line_edit->text().isEmpty()) ui->username_is_empty->setText("نام کاربری را وارد کنید");
    else ui->username_is_empty->setText("");
}

void LoginPage::on_password_line_edit_editingFinished()
{
    if(ui->password_line_edit->text().isEmpty()) ui->password_is_empty->setText("کلمه عبور را وارد کنید");
    else ui->password_is_empty->setText("");
}

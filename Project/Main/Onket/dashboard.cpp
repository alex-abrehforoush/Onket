#include "dashboard.h"
#include "ui_dashboard.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

Dashboard::Dashboard(User* current_user, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    if(current_user->getMode() == 0)
    {
        ui->admin->hide();
        ui->customer->show();

        ui->my_orders->hide();
        ui->lists->hide();
        ui->comments->hide();
        ui->addresses->hide();
        ui->messages->hide();
        ui->last_activities->hide();
        ui->customer_account_info->hide();

        ui->customer_account_edit->hide();

        ui->customer_firstname_line_edit->setText(MainWindow::getCurrentUser()->getFirstname());
        ui->customer_lastname_line_edit->setText(MainWindow::getCurrentUser()->getLastname());
        ui->customer_username_line_edit->setText(MainWindow::getCurrentUser()->getUsername());
        ui->customer_password_line_edit->setText(MainWindow::getCurrentUser()->getPassword());
        ui->customer_birthday_edit->setDate(MainWindow::getCurrentUser()->getBirthday());
        ui->customer_email_line_edit->setText(MainWindow::getCurrentUser()->getUsername());
        ui->customer_phone_number_line_edit->setText(MainWindow::getCurrentUser()->getPhoneNumber());

        ui->customer_password_line_edit->setEchoMode(QLineEdit::Password);
        ui->customer_address_number->setRange(1, MainWindow::getCurrentUser()->getAddresses().size());
        ui->customer_show_address->setText(MainWindow::getCurrentUser()->getAddresses().at(0));
        ui->customer_address_number_edit->setRange(1, MainWindow::getCurrentUser()->getAddresses().size());
        ui->customer_addresses_to_be_removed->setText(MainWindow::getCurrentUser()->getAddresses().at(0));

        for(int i = 0; i < MainWindow::getCurrentUser()->getLastActivities().size(); i++)
        {
            ui->customer_last_activities->insertPlainText(MainWindow::getCurrentUser()->getLastActivities().at(i).toString());
            if(i%2 == 0 && i != MainWindow::getCurrentUser()->getLastActivities().size() - 1) ui->customer_last_activities->insertPlainText("─");
            if(i%2 == 1 && i != MainWindow::getCurrentUser()->getLastActivities().size() - 1) ui->customer_last_activities->insertPlainText("\n");
        }

    }
    else if(current_user->getMode() == 1)
    {
        ui->admin->show();
        ui->customer->hide();

        ui->goods_management->hide();
        ui->user_management->hide();
        ui->site_settings->hide();
        ui->finance->hide();
        ui->employeement->hide();
        ui->treaties->hide();
        ui->customer_account_info->hide();
        ui->foreign_connections->hide();
    }
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
    ui->customer_account_info->hide();
}

void Dashboard::on_pushButton_10_clicked()
{
    ui->my_orders->hide();
    ui->lists->show();
    ui->comments->hide();
    ui->addresses->hide();
    ui->messages->hide();
    ui->last_activities->hide();
    ui->customer_account_info->hide();
}

void Dashboard::on_pushButton_11_clicked()
{
    ui->my_orders->hide();
    ui->lists->hide();
    ui->comments->show();
    ui->addresses->hide();
    ui->messages->hide();
    ui->last_activities->hide();
    ui->customer_account_info->hide();
}

void Dashboard::on_pushButton_12_clicked()
{
    ui->my_orders->hide();
    ui->lists->hide();
    ui->comments->hide();
    ui->addresses->show();
    ui->messages->hide();
    ui->last_activities->hide();
    ui->customer_account_info->hide();
}

void Dashboard::on_pushButton_13_clicked()
{
    ui->my_orders->hide();
    ui->lists->hide();
    ui->comments->hide();
    ui->addresses->hide();
    ui->messages->show();
    ui->last_activities->hide();
    ui->customer_account_info->hide();
}

void Dashboard::on_pushButton_14_clicked()
{
    ui->my_orders->hide();
    ui->lists->hide();
    ui->comments->hide();
    ui->addresses->hide();
    ui->messages->hide();
    ui->last_activities->show();
    ui->customer_account_info->hide();
}

void Dashboard::on_pushButton_15_clicked()
{
    ui->my_orders->hide();
    ui->lists->hide();
    ui->comments->hide();
    ui->addresses->hide();
    ui->messages->hide();
    ui->last_activities->hide();
    ui->customer_account_info->show();

    ui->customer_account_edit->hide();

    ui->customer_first_and_last_name->setText(MainWindow::getCurrentUser()->getFirstname() + " " + MainWindow::getCurrentUser()->getLastname());
    ui->customer_username->setText(MainWindow::getCurrentUser()->getUsername());
    ui->customer_password->setText(MainWindow::getCurrentUser()->getPassword());
    ui->customer_phone_number->setText(MainWindow::getCurrentUser()->getPhoneNumber());
    ui->customer_birthday->setText(MainWindow::getCurrentUser()->getBirthday().toString());
    ui->customer_email->setText(MainWindow::getCurrentUser()->getUsername());
    ui->customer_show_address->setText(MainWindow::getCurrentUser()->getAddresses().at(ui->customer_address_number->value() - 1));

    ui->customer_address_number_edit->clear();
}

void Dashboard::on_pushButton_clicked()
{
    ui->goods_management->show();
    ui->user_management->hide();
    ui->site_settings->hide();
    ui->finance->hide();
    ui->employeement->hide();
    ui->treaties->hide();
    ui->customer_account_info->hide();
    ui->foreign_connections->hide();
}

void Dashboard::on_pushButton_2_clicked()
{
    ui->goods_management->hide();
    ui->user_management->show();
    ui->site_settings->hide();
    ui->finance->hide();
    ui->employeement->hide();
    ui->treaties->hide();
    ui->customer_account_info->hide();
    ui->foreign_connections->hide();
}

void Dashboard::on_pushButton_3_clicked()
{
    ui->goods_management->hide();
    ui->user_management->hide();
    ui->site_settings->show();
    ui->finance->hide();
    ui->employeement->hide();
    ui->treaties->hide();
    ui->customer_account_info->hide();
    ui->foreign_connections->hide();
}

void Dashboard::on_pushButton_4_clicked()
{
    ui->goods_management->hide();
    ui->user_management->hide();
    ui->site_settings->hide();
    ui->finance->show();
    ui->employeement->hide();
    ui->treaties->hide();
    ui->customer_account_info->hide();
    ui->foreign_connections->hide();
}

void Dashboard::on_pushButton_5_clicked()
{
    ui->goods_management->hide();
    ui->user_management->hide();
    ui->site_settings->hide();
    ui->finance->hide();
    ui->employeement->show();
    ui->treaties->hide();
    ui->customer_account_info->hide();
    ui->foreign_connections->hide();
}

void Dashboard::on_pushButton_6_clicked()
{
    ui->goods_management->hide();
    ui->user_management->hide();
    ui->site_settings->hide();
    ui->finance->hide();
    ui->employeement->hide();
    ui->treaties->show();
    ui->customer_account_info->hide();
    ui->foreign_connections->hide();
}

void Dashboard::on_pushButton_7_clicked()
{
    ui->goods_management->hide();
    ui->user_management->hide();
    ui->site_settings->hide();
    ui->finance->hide();
    ui->employeement->hide();
    ui->treaties->hide();
    ui->customer_account_info->show();
    ui->foreign_connections->hide();
}

void Dashboard::on_pushButton_8_clicked()
{
    ui->goods_management->hide();
    ui->user_management->hide();
    ui->site_settings->hide();
    ui->finance->hide();
    ui->employeement->hide();
    ui->treaties->hide();
    ui->customer_account_info->hide();
    ui->foreign_connections->show();
}

void Dashboard::on_customer_address_edit_of_valueChanged(int arg1)
{
    this->ui->customer_addresses_to_be_removed->setText(MainWindow::getCurrentUser()->getAddresses().at(arg1-1));
}

void Dashboard::on_remove_this_address_button_clicked()
{
    if(MainWindow::getCurrentUser()->getAddresses().size() != 1)
    {
        MainWindow::getCurrentUser()->getAddresses().remove(this->ui->customer_address_number_edit->value() - 1);
        QMessageBox::information(this, "پیام", "آدرس مورد نظر حذف شد");
        this->ui->customer_addresses_to_be_removed->clear();
        this->ui->customer_address_number->setRange(1, MainWindow::getCurrentUser()->getAddresses().size());
        this->ui->customer_address_number_edit->setRange(1, MainWindow::getCurrentUser()->getAddresses().size());
    }
    else
    {
        QMessageBox::information(this, "پیام", "حداقل یک آدرس را وارد کنید");
    }
}

void Dashboard::on_customer_address_number_edit_valueChanged(int arg1)
{
    this->ui->customer_addresses_to_be_removed->setText(MainWindow::getCurrentUser()->getAddresses().at(arg1 - 1));
}

void Dashboard::on_add_this_address_button_clicked()
{
    if(!this->ui->add_address_line_edit->text().isEmpty() && !MainWindow::getCurrentUser()->getAddresses().contains(this->ui->add_address_line_edit->text()))
    {
        MainWindow::getCurrentUser()->addAddress(this->ui->add_address_line_edit->text());
        QMessageBox::information(this, "پیام", "آدرس جدید با موفقیت اضافه شد");
        this->ui->add_address_line_edit->clear();
        this->ui->customer_address_number->setRange(1, MainWindow::getCurrentUser()->getAddresses().size());
        this->ui->customer_address_number_edit->setRange(1, MainWindow::getCurrentUser()->getAddresses().size());
    }
}

void Dashboard::on_customer_apply_changes_button_clicked()
{
    QFile data_remove("Database/User/" + MainWindow::getCurrentUser()->getUsername() + ".csv");
    data_remove.remove();
    MainWindow::getCurrentUser()->setFirstname(this->ui->customer_firstname_line_edit->text());
    MainWindow::getCurrentUser()->setLastname(this->ui->customer_lastname_line_edit->text());
    MainWindow::getCurrentUser()->setUsername(this->ui->customer_username_line_edit->text());
    MainWindow::getCurrentUser()->setPassword(this->ui->customer_password_line_edit->text());
    MainWindow::getCurrentUser()->setBirthday(this->ui->customer_birthday_edit->date());
    MainWindow::getCurrentUser()->setPhoneNumber(this->ui->customer_phone_number->text());
    User::addUser(MainWindow::getCurrentUser());
}

void Dashboard::on_show_password_checkBox_stateChanged(int arg1)
{
    if(arg1 == 0) ui->customer_password_line_edit->setEchoMode(QLineEdit::Password);
    else ui->customer_password_line_edit->setEchoMode(QLineEdit::Normal);
}

void Dashboard::on_customer_edit_clicked()
{
    this->ui->customer_account_info->hide();
    ui->customer_firstname_line_edit->setText(MainWindow::getCurrentUser()->getFirstname());
    ui->customer_lastname_line_edit->setText(MainWindow::getCurrentUser()->getLastname());
    ui->customer_username_line_edit->setText(MainWindow::getCurrentUser()->getUsername());
    ui->customer_password_line_edit->setText(MainWindow::getCurrentUser()->getPassword());
    ui->customer_birthday_edit->setDate(MainWindow::getCurrentUser()->getBirthday());
    ui->customer_email_line_edit->setText(MainWindow::getCurrentUser()->getUsername());
    ui->customer_phone_number_line_edit->setText(MainWindow::getCurrentUser()->getPhoneNumber());
    this->ui->customer_account_edit->show();
}

void Dashboard::on_back_clicked()
{
    ui->show_password_checkBox->setCheckState(Qt::Unchecked);
    ui->customer_account_info->hide();
    ui->customer_account_edit->hide();
    this->close();
}

void Dashboard::on_customer_address_number_valueChanged(int arg1)
{
    ui->customer_show_address->setText(MainWindow::getCurrentUser()->getAddresses().at(/*arg1 - 1*/ui->customer_address_number->value() - 1));
    return;
}

void Dashboard::on_logout_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "پیام", "آیا می خواهید خارج شوید؟", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        MainWindow::getCurrentUser()->getLastActivities().push_back(QDateTime::currentDateTime());
        this->ui->back->click();
        delete MainWindow::getCurrentUser();
        MainWindow::setCurrentUser(nullptr);
        MainWindow::setCurrentUser(new Guest);
    }
    else
    {

    }
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "Admin.h"
#include "Customer.h"
#include "Guest.h"
#include "signup.h"

User* MainWindow::current_user;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,ui(new Ui::MainWindow)
    ,login_page(nullptr)
    ,signup_page(nullptr)
    ,dashboard(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("Onket | An Online Market");
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
    current_user = new Guest();
}

void MainWindow::setCurrentUser(User *crnt)
{
    delete current_user;
    current_user = nullptr;
    current_user = crnt;
    return;
}

User *MainWindow::getCurrentUser() const
{
    return this->current_user;
}

MainWindow::~MainWindow()
{
    delete ui;

    delete login_page;
    login_page = nullptr;

}

void MainWindow::on_action_10_triggered()
{
    if(current_user->getMode()==-1)
    {
        if(login_page == nullptr)
        {
            login_page = new LoginPage(this);
            connect(login_page, SIGNAL(signup()), this, SLOT(on_action_11_triggered()));
        }
        login_page->show();
    }
    else
    {
        QMessageBox::information(this, "پیام", "شما وارد شده اید");
    }
}

void MainWindow::on_action_11_triggered()
{
    if(current_user->getMode()==-1)
    {
        if(signup_page == nullptr) signup_page = new signup(this);
        signup_page->show();
    }
    else
    {
        QMessageBox::information(this, "پیام", "شما وارد شده اید");
    }
}

void MainWindow::on_action_triggered()
{
    if(current_user->getMode()==-1)
    {
        QMessageBox::information(this, "پیام", "لطفا وارد شوید یا ثبت نام کنید");
    }
    else
    {
        if(this->dashboard==nullptr) dashboard = new Dashboard(current_user, this);
    }
}

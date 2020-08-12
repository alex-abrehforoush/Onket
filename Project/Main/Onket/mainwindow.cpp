#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "Admin.h"
#include "Customer.h"
#include "Guest.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,ui(new Ui::MainWindow)
    ,login_page(nullptr)
    ,signup_page(nullptr)
    ,dashboard(nullptr)
    ,current_user(new Guest())//for testing
{
    ui->setupUi(this);
    setWindowTitle("Onket | An Online Market");
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
    current_user->addUser(current_user);//for testing
}

MainWindow::~MainWindow()
{
    delete ui;

    delete login_page;
    login_page = nullptr;

}

void MainWindow::on_action_10_triggered()
{
    if(login_page == nullptr) login_page = new LoginPage(this);
    login_page->show();
}

void MainWindow::on_action_11_triggered()
{
    if(signup_page == nullptr) signup_page = new signup(this);
    signup_page->show();
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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "Admin.h"
#include "Customer.h"
#include "Guest.h"
#include "signup.h"
#include "menutype.h"

LoginPage* MainWindow::login_page;
signup* MainWindow::signup_page;
Dashboard* MainWindow::dashboard;
User* MainWindow::current_user;
Storage MainWindow::onket_repository;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Onket | An Online Market");
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
    current_user = new Guest();

    if(!User::userExist("wwe_alireza.abc2015@yahoo.com"))
    {
        Admin alireza("wwe_alireza.abc2015@yahoo.com", "***REMOVED***");
        alireza.setFirstname("علیرضا");
        alireza.setLastname("ابره فروش");
        User::addUser(&alireza);
    }
    if(!User::userExist("moeinferdavani1380@gmail.com"))
    {
        Admin moein("moeinferdavani1380@gmail.com", "123456789");
        moein.setFirstname("معین");
        moein.setLastname("خراسانی فردوانی");
        User::addUser(&moein);
    }
    if(!User::userExist("adel.karshen@gmail.com"))
    {
        Admin adel("adel.karshen@gmail.com", "123456789");
        adel.setFirstname("عادل");
        adel.setLastname("کارشناس");
        User::addUser(&adel);
    }

    //MenuType::setUpMenu(ui->menu);


    //onket_repository.loadStorage();
}

void MainWindow::setCurrentUser(User *crnt)
{
    if(current_user != nullptr) delete current_user;
    current_user = nullptr;
    current_user = crnt;
    return;
}

User *MainWindow::getCurrentUser()
{
    return current_user;
}

Storage &MainWindow::getOnketRepository()
{
    return onket_repository;
}

void MainWindow::setLoginPage(LoginPage *lgnpg)
{
    delete login_page;
    login_page = lgnpg;
}

void MainWindow::setSignupPage(signup *sinup)
{
    delete signup_page;
    signup_page = sinup;
}

void MainWindow::setDashboard(Dashboard *dshbrd)
{
    delete dashboard;
    dashboard = dshbrd;
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
        dashboard->show();
    }
}

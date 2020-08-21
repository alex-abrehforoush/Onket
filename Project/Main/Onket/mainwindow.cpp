#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "Admin.h"
#include "Customer.h"
#include "Guest.h"
#include "signup.h"

LoginPage* MainWindow::login_page;
signup* MainWindow::signup_page;
Dashboard* MainWindow::dashboard;
User* MainWindow::current_user;
Storage MainWindow::onket_repository;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    ,main_lay(new QGridLayout(this))
    ,main_center_widget(new QWidget(this))
    ,scroll_price(new GoodPreviewScrollArea(this))
    ,scroll_discount(new GoodPreviewScrollArea(this))
    ,scroll_willingness(new GoodPreviewScrollArea(this))
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

    this->setupDynomicMenu(ui->menu);

    this->main_center_widget->setLayout(main_lay);
    ui->main_scroll_area->setWidget(main_center_widget);
    ui->main_scroll_area->setWidgetResizable(true);
    ui->main_scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->main_scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->updateScrollAreas("none");

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
        ui->main_scroll_area->hide();
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

void MainWindow::updateScrollAreas(const QString &type_id)
{
    Type::readFile();
    if(Type::existTypeId(type_id)==false && type_id!="none")return;
//    this->main_lay->removeWidget(scroll_price);
//    this->main_lay->removeWidget(scroll_discount);
//    this->main_lay->removeWidget(scroll_willingness);
//    delete this->scroll_price;
//    delete this->scroll_discount;
//    delete this->scroll_willingness;
//    scroll_price=new GoodPreviewScrollArea(this);
//    scroll_discount=new GoodPreviewScrollArea(this);
//    scroll_willingness=new GoodPreviewScrollArea(this);
    scroll_price->clear();
    scroll_discount->clear();
    scroll_willingness->clear();
    if(type_id=="none")
    {
        QVector<QString>base_type=Type::getBaseTypeId();
        for(auto it : base_type)
        {
            scroll_price->addGoodSortedByPrice(it);
            scroll_discount->addGoodSortedByDiscount(it);
            scroll_willingness->addGoodSortedByWillingness(it);
        }


    }
    scroll_price->addGoodSortedByPrice(type_id);
    scroll_discount->addGoodSortedByDiscount(type_id);
    scroll_willingness->addGoodSortedByWillingness(type_id);

    this->main_lay->addWidget(scroll_price,0,0);
    this->main_lay->addWidget(scroll_discount,1,0);
    this->main_lay->addWidget(scroll_willingness,2,0);
}

void MainWindow::setupDynomicMenu(QMenu *menu)
{
    delete base_menu;
    base_menu=new MenuType("");
    base_menu->setUpMenu(menu);
    connect(base_menu,SIGNAL(actionTriggered(const QString& )),this,SLOT(updateScrollAreas(const QString& )));
}

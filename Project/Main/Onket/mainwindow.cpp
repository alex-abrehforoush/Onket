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
QScrollArea* MainWindow::main_scroll_area = nullptr;
QLabel* MainWindow::logo_fa = nullptr;
QLabel* MainWindow::logo_en = nullptr;
QLineEdit* MainWindow::search_line_edit = nullptr;
QPushButton* MainWindow::show_basket = nullptr;
QListWidget* MainWindow::search_results = nullptr;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    main_lay(new QGridLayout(this)),
    main_center_widget(new QWidget(this)),
    scroll_price(new GoodPreviewScrollArea(this)),
    scroll_discount(new GoodPreviewScrollArea(this)),
    scroll_willingness(new GoodPreviewScrollArea(this)),
    lab_price(new QLabel("ارزان ترین ها",this)),
    lab_discount(new QLabel("پر تخفیف ترین ها",this)),
    lab_willingnes(new QLabel("محبوب ترین ها",this)),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Onket | An Online Market");
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
    setFixedSize(1500, 800);
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

    if(logo_fa == nullptr)
    {
        logo_fa = new QLabel("آنکت", this);
        logo_fa->setStyleSheet("font: 32pt \"B Arshia\";\ncolor: rgb(255, 0, 0);");
        logo_fa->setGeometry(1420, 30, 61, 41);
    }

    if(logo_en == nullptr)
    {
        logo_en = new QLabel("Onket", this);
        logo_en->setStyleSheet("color: rgb(255, 0, 0);\nfont: 16pt \"Pristina\";");
        logo_en->setGeometry(1420, 70, 61, 31);
    }

    if(search_line_edit == nullptr)
    {
        search_line_edit = new QLineEdit(this);
        search_line_edit->setStyleSheet("font: 11pt \"MS Shell Dlg 2\";");
        search_line_edit->setPlaceholderText("نام کالای مورد نظر را وارد کنید ...");
        search_line_edit->setGeometry(180, 43, 1231, 41);
    }

    if(show_basket == nullptr)
    {
        show_basket = new QPushButton("سبد خرید", this);
        show_basket->setStyleSheet("background-color: rgb(255, 0, 0);");
        show_basket->setGeometry(20, 43, 151, 41);
    }

    if(main_scroll_area == nullptr)
    {
        main_scroll_area = new QScrollArea(this);
    }
    else
    {
        main_scroll_area->setParent(this);
    }
    main_scroll_area->setGeometry(0, 105, 1500, 770);

    this->setupDynamicMenu(ui->menu);

    this->bnt_compare=new QPushButton("مقایسه",this);
    {

        if(search_results!=nullptr)
        {
            delete search_results;
        }
        search_results = new QListWidget(this);
        search_results->hide();
        search_results->setGeometry(180, 43, 1231, 41);

    }
    this->setupSearchResults("none");

    this->main_center_widget->setLayout(main_lay);
    main_scroll_area->setWidget(main_center_widget);
    main_scroll_area->setWidgetResizable(true);
    main_scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    main_scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    this->updatePrviewScrollAreas("none");
    this->lab_willingnes->setStyleSheet("background-color: rgb(255, 0, 127);\ncolor: rgb(255, 255, 255);\nfont: 10pt \"MS Shell Dlg 2\";");
    this->lab_discount->setStyleSheet("background-color: rgb(0, 255, 0);\ncolor: rgb(255, 255, 255);\nfont: 10pt \"MS Shell Dlg 2\";");
    this->lab_price->setStyleSheet("background-color: rgb(0, 170, 255);\ncolor: rgb(255, 255, 255);\nfont: 10pt \"MS Shell Dlg 2\";");
    this->bnt_compare->setStyleSheet("background-color: rgb(255, 0, 0);");
    this->lab_willingnes->setAlignment(Qt::AlignCenter);
    this->lab_discount->setAlignment(Qt::AlignCenter);
    this->lab_price->setAlignment(Qt::AlignCenter);
    main_scroll_area->show();

    this->bnt_compare->setGeometry(0,760,200,40);
    MainWindow::search_results->setGeometry(180, 90, 1231, 31);
    this->bnt_compare->hide();




    connect(scroll_price,SIGNAL(onGoodPreviewClicked(const QString&)),this,SLOT(showGood(const QString& )));
    connect(scroll_discount,SIGNAL(onGoodPreviewClicked(const QString&)),this,SLOT(showGood(const QString& )));
    connect(scroll_willingness,SIGNAL(onGoodPreviewClicked(const QString&)),this,SLOT(showGood(const QString& )));
    connect(scroll_price,SIGNAL(showCompareButton()),this,SLOT(show_compare_button()));
    connect(scroll_discount,SIGNAL(showCompareButton()),this,SLOT(show_compare_button()));
    connect(scroll_willingness,SIGNAL(showCompareButton()),this,SLOT(show_compare_button()));
    connect(scroll_price,SIGNAL(hideCompareButton()),this,SLOT(hide_compare_button()));
    connect(scroll_discount,SIGNAL(hideCompareButton()),this,SLOT(hide_compare_button()));
    connect(scroll_willingness,SIGNAL(hideCompareButton()),this,SLOT(hide_compare_button()));
    connect(bnt_compare,SIGNAL(clicked()),this,SLOT(on_bnt_compare_clicked()));
    connect(MainWindow::search_results, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onSearchResultItemClicked(QListWidgetItem*)));
    connect(MainWindow::search_line_edit, SIGNAL(editingFinished()), this, SLOT(on_search_line_edit_editingFinished()));
    connect(MainWindow::search_line_edit, SIGNAL(textChanged(const QString&)), this, SLOT(on_search_line_edit_textChanged(const QString&)));
    connect(MainWindow::show_basket, SIGNAL(clicked()), this, SLOT(on_show_basket_clicked()));

    onket_repository.loadStorage();
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

void MainWindow::hideMainScrollArea()
{
    main_scroll_area->hide();
    logo_fa->hide();
    logo_en->hide();
    show_basket->hide();
    search_line_edit->hide();
    search_results->hide();
    return;
}

void MainWindow::showMainScrollArea()
{
    main_scroll_area->show();
    logo_fa->show();
    logo_en->show();
    show_basket->show();
    search_line_edit->show();
    search_results->hide();
    return;
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

        MainWindow::hideMainScrollArea();

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
        MainWindow::hideMainScrollArea();
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
        if(this->dashboard==nullptr)
        {
            dashboard = new Dashboard(current_user, this);
            connect(dashboard, SIGNAL(updateGoodsRequest(const QString&)),this,SLOT(updatePrviewScrollAreas(const QString&)));
            connect(dashboard, SIGNAL(updateTypesRequest()),this, SLOT(setupDynamicMenu()));
            connect(dashboard, SIGNAL(updateGoodsRequest(const QString&)), this, SLOT(setupSearchResults(const QString&)));

        }

        MainWindow::hideMainScrollArea();
        dashboard->show();
    }
}

void MainWindow::showGood(const QString &good_id)
{

    this->hidePreviewScrollAreas();
    goodMainViewWidget* good_main_view=new goodMainViewWidget(good_id,current_user->getUsername(),this);
    connect(good_main_view,SIGNAL(updateGoodsRequest()),this,SLOT(showPreviwScrollAreas()));
    this->main_lay->addWidget(good_main_view,0,0);
    MainWindow::main_scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    MainWindow::main_scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

void MainWindow::show_compare_button()
{
    this->bnt_compare->show();
}

void MainWindow::hide_compare_button()
{
    this->bnt_compare->hide();
    GoodPreviewWidget::clearCompareList();
}

void MainWindow::comapre_closed()
{
    this->compare_table->hide();
    delete this->compare_table;
    this->compare_table=nullptr;
    this->showPreviwScrollAreas();

}

void MainWindow::on_bnt_compare_clicked()
{
    this->hidePreviewScrollAreas();
    if(compare_table!=nullptr)
    {
        compare_table->show();
        return;
    }
    QVector<QString> compare_list=GoodPreviewWidget::getCompareList();
    compare_table=new CompareWidget(compare_list);
    this->main_lay->addWidget(compare_table,0,0);
    compare_table->show();
    connect(compare_table,SIGNAL(comparingFinished()),this,SLOT(comapre_closed()));
    this->hide_compare_button();

}

void MainWindow::basket_closed()
{
    basket_view->hide();
    delete this->basket_view;
    this->basket_view=nullptr;
    this->showPreviwScrollAreas();
    MainWindow::main_scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    MainWindow::main_scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
}

void MainWindow::on_show_basket_clicked()
{
    if(MainWindow::getCurrentUser()->getMode() != 0)
    {
        QMessageBox::information(this, "پیام", "شما دسترسی لازم را ندارید");
        return;
    }
    if(this->basket_view != nullptr) return;
    this->hidePreviewScrollAreas();
    this->basket_view = new BasketView(this);
    this->main_lay->addWidget(basket_view,0,0);
    MainWindow::main_scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    MainWindow::main_scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    connect(basket_view,SIGNAL(returningRequested()),this,SLOT(basket_closed()));
}

void MainWindow::setupSearchResults(const QString &type_id)
{
    MainWindow::search_results->clear();
    Good::readFile();
    QVector<QString>temp=Good::getGoodNameList();
    for(auto it: temp)
    {
        MainWindow::search_results->addItem(it);
    }
    MainWindow::search_results->hide();
}

void MainWindow::updatePrviewScrollAreas(const QString &type_id)
{
    Type::readFile();
    Good::readFile();
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
       QVector<QString>good_ids=Good::getGoodIdList();
       QVector<QString> temp_1 = Good::getSortByPrice(good_ids, true);
       QVector<QString> temp_2 = Good::getSortByDiscount(good_ids, false);
       QVector<QString> temp_3 = Good::getSortByWillingness(good_ids, false);
       for(auto it : temp_1)
       {
           scroll_price->addGood(it, true);
       }
       for(auto it : temp_2)
       {
           scroll_discount->addGood(it, true);
       }
       for(auto it : temp_3)
       {
           scroll_willingness->addGood(it, true);
       }
    }
    else
    {
        scroll_price->addGoodSortedByPrice(type_id);
        scroll_discount->addGoodSortedByDiscount(type_id);
        scroll_willingness->addGoodSortedByWillingness(type_id);
    }
    this->main_lay->addWidget(lab_willingnes,0,0);
    this->main_lay->addWidget(lab_discount,1,0);
    this->main_lay->addWidget(lab_price,2,0);
    this->main_lay->addWidget(scroll_willingness,0,1);
    this->main_lay->addWidget(scroll_discount,1,1);
    this->main_lay->addWidget(scroll_price,2,1);






}

void MainWindow::hidePreviewScrollAreas()
{
    MainWindow::logo_fa->hide();
    MainWindow::logo_en->hide();
    MainWindow::show_basket->hide();
    MainWindow::search_line_edit->hide();
    MainWindow::search_results->hide();
    this->lab_price->hide();
    this->lab_discount->hide();
    this->lab_willingnes->hide();
    this->scroll_price->hide();
    this->scroll_discount->hide();
    this->lab_willingnes->hide();
    main_scroll_area->setGeometry(0, 35, 1500, 770);

}

void MainWindow::showPreviwScrollAreas()
{
    MainWindow::logo_en->show();
    MainWindow::logo_fa->show();
    MainWindow::search_line_edit->show();
    MainWindow::show_basket->show();
    MainWindow::search_results->hide();

    this->lab_price->show();
    this->lab_discount->show();
    this->lab_willingnes->show();
    this->scroll_price->show();
    this->scroll_discount->show();
    this->lab_willingnes->show();

    this->updatePrviewScrollAreas(Type::getCurrentTypeId());

    MainWindow::main_scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    MainWindow::main_scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    main_scroll_area->setGeometry(0, 105, 1500, 770);
}

void MainWindow::setupDynamicMenu()
{
    this->setupDynamicMenu(ui->menu);
}

void MainWindow::onSearchResultItemClicked(QListWidgetItem *itm)
{
    MainWindow::search_line_edit->setText(itm->text());
    MainWindow::search_results->hide();
}

void MainWindow::setupDynamicMenu(QMenu *menu)
{
    delete base_menu;
    base_menu=new MenuType("");
    base_menu->setUpMenu(menu);
    connect(base_menu,SIGNAL(actionTriggered(const QString& )),this,SLOT(updatePrviewScrollAreas(const QString& )));
}

void MainWindow::on_search_line_edit_editingFinished()
{
    scroll_price->clear();
    scroll_discount->clear();
    scroll_willingness->clear();
    QVector<QString>good_ids;

    for(int cnt=0;cnt <MainWindow::search_results->count();cnt++)
    {
        if(MainWindow::search_results->item(cnt)->isHidden()==false)
        {
            QString good_name = MainWindow::search_results->item(cnt)->text();
            good_ids.push_back(Good::getIdFromName(good_name));
        }
    }

    QVector<QString> temp_1 = Good::getSortByPrice(good_ids, true);
    for(auto it : temp_1)
    {
        scroll_price->addGood(it,true);
    }
    QVector<QString>temp_2=Good::getSortByDiscount(good_ids,false);
    for(auto it : temp_2)
    {
        scroll_discount->addGood(it,true);
    }
    QVector<QString> temp_3=Good::getSortByWillingness(good_ids,false);
    for(auto it : temp_3)
    {
        scroll_willingness->addGood(it,true);
    }
}

void MainWindow::on_search_line_edit_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        MainWindow::search_results->hide();
        return;
    }
    else
    {
        MainWindow::search_results->show();
        int show_items = 0;
        for(int cnt=0;cnt<MainWindow::search_results->count();cnt++)
        {
            if(MainWindow::search_results->item(cnt)->text().contains(arg1))
            {
                MainWindow::search_results->item(cnt)->setHidden(false);
                show_items++;
            }
            else
            {
                MainWindow::search_results->item(cnt)->setHidden(true);
            }
        }
        if(show_items <= 10)
        {
            MainWindow::search_results->setFixedHeight(show_items * 25);
        }
        else
        {
            MainWindow::search_results->setFixedHeight(250);
        }
    }
}

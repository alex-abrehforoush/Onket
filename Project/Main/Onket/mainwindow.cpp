#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    if(dashboard == nullptr) dashboard = new Dashboard(-1, this);
    dashboard->show();
}

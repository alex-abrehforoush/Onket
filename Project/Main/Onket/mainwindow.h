#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "User.h"
#include "Admin.h"
#include "Customer.h"
#include "Guest.h"
#include "loginpage.h"
#include "signup.h"
#include "dashboard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:


public:
    MainWindow(QWidget *parent = nullptr);
    static void setCurrentUser(User* crnt);
    User* getCurrentUser() const;
    ~MainWindow();

private slots:
    void on_action_10_triggered();

    void on_action_11_triggered();

    void on_action_triggered();

private:
    Ui::MainWindow* ui;
    LoginPage* login_page;
    signup* signup_page;
    Dashboard* dashboard;
    static User* current_user;
};
#endif // MAINWINDOW_H

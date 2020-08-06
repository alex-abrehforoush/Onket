#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginpage.h"
#include "signup.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_10_triggered();

    void on_action_11_triggered();

private:
    Ui::MainWindow* ui;
    LoginPage* login_page;
    signup* signup_page;
};
#endif // MAINWINDOW_H

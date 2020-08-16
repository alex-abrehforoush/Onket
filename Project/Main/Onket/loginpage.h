#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include <User.h>

namespace Ui {
class LoginPage;
}

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

private slots:
    void on_back_clicked();

    void on_show_password_stateChanged();

    User* on_enter_button_clicked();

    void on_signup_button_clicked();

private:
    Ui::LoginPage *ui;
    QSize sizeHint() const;

signals:
    void signup();
    void successfulLogin();
};

#endif // LOGINPAGE_H

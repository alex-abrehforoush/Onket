#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>

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
    void on_commandLinkButton_clicked();

    void on_checkBox_stateChanged();

private:
    Ui::LoginPage *ui;
    QSize sizeHint() const;
};

#endif // LOGINPAGE_H

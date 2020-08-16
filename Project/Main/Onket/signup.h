#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include "Customer.h"

namespace Ui {
class signup;
}

class signup : public QWidget
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

private slots:
    void on_repeat_password_line_edit_editingFinished();

    void on_username_line_edit_editingFinished();

    void on_password_line_edit_editingFinished();

    void on_show_password_stateChanged();

    void on_back_clicked();

    void on_signup_button_clicked();

    void on_firstname_line_edit_editingFinished();

    void on_lastname_line_edit_editingFinished();

    void on_phone_number_line_edit_editingFinished();

    void on_address_line_edit_editingFinished();

    void on_add_address_button_clicked();

    void on_create_account_clicked();

private:
    Ui::signup *ui;
    QSize sizeHint() const;
    User* user_creator;
};

#endif // SIGNUP_H

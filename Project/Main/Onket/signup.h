#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>

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

private:
    Ui::signup *ui;
    QSize sizeHint() const;
};

#endif // SIGNUP_H

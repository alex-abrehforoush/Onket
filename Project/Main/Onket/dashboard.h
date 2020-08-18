#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include "User.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dashboard; }
QT_END_NAMESPACE

class Dashboard : public QWidget
{
    Q_OBJECT

public:
    Dashboard(User* current_user, QWidget *parent = nullptr);
    ~Dashboard();

private slots:
    void on_pushButton_15_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_7_clicked();

    void on_goods_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_send_message_clicked();

    void on_pushButton_8_clicked();

    void on_customer_address_edit_of_valueChanged(int arg1);

    void on_remove_this_address_button_clicked();

    void on_customer_address_number_edit_valueChanged(int arg1);

    void on_add_this_address_button_clicked();

    void on_customer_apply_changes_button_clicked();

    void on_show_password_checkBox_stateChanged(int arg1);

    void on_customer_edit_clicked();

    void on_back_clicked();

    void on_customer_address_number_valueChanged(int arg1);

    void on_logout_clicked();

    void on_send_clicked();

    void on_add_to_storage_clicked();

private:
    Ui::Dashboard *ui;
};
#endif // DASHBOARD_H

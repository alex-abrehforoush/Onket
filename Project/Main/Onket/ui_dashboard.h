/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dashboard
{
public:
    QWidget *admin;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QWidget *goods_management;
    QWidget *user_management;
    QWidget *site_settings;
    QWidget *finance;
    QWidget *employeement;
    QWidget *treaties;
    QPushButton *pushButton_18;
    QWidget *foreign_connections;
    QWidget *admin_account_info;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *first_and_lastname;
    QLabel *label_24;
    QLabel *username;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *password;
    QPushButton *edit_button;
    QWidget *customer;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QWidget *my_orders;
    QWidget *lists;
    QWidget *comments;
    QWidget *addresses;
    QWidget *messages;
    QWidget *last_activities;
    QWidget *customer_account_info;
    QLabel *label;
    QLabel *label_2;
    QPushButton *customer_edit;
    QLabel *customer_show_address;
    QLabel *customer_addresses;
    QSpinBox *customer_address_number;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_12;
    QLabel *label_6;
    QLabel *label_3;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_6;
    QLabel *customer_password;
    QLabel *customer_username;
    QLabel *customer_first_and_last_name;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_9;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *customer_email;
    QLabel *customer_birthday;
    QLabel *customer_phone_number;
    QWidget *customer_account_edit;
    QLabel *label_5;
    QLabel *label_8;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout;
    QLineEdit *customer_password_line_edit;
    QLineEdit *customer_username_line_edit;
    QLineEdit *customer_lastname_line_edit;
    QLineEdit *customer_firstname_line_edit;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_15;
    QLabel *label_7;
    QLabel *label_17;
    QLabel *label_4;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_16;
    QLabel *label_13;
    QLabel *label_14;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *customer_email_line_edit;
    QDateEdit *customer_birthday_edit;
    QLineEdit *customer_phone_number_line_edit;
    QPushButton *remove_this_address_button;
    QLabel *customer_addresses_to_be_removed;
    QSpinBox *customer_address_number_edit;
    QLabel *customer_addresses_edit;
    QPushButton *add_this_address_button;
    QLineEdit *add_address_line_edit;
    QPushButton *customer_apply_changes_button;
    QCheckBox *show_password_checkBox;
    QCommandLinkButton *back;

    void setupUi(QWidget *Dashboard)
    {
        if (Dashboard->objectName().isEmpty())
            Dashboard->setObjectName(QString::fromUtf8("Dashboard"));
        Dashboard->resize(1500, 800);
        admin = new QWidget(Dashboard);
        admin->setObjectName(QString::fromUtf8("admin"));
        admin->setGeometry(QRect(1510, 0, 1500, 800));
        pushButton = new QPushButton(admin);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1270, 160, 200, 40));
        pushButton->setLayoutDirection(Qt::RightToLeft);
        pushButton_2 = new QPushButton(admin);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(1270, 220, 200, 40));
        pushButton_2->setLayoutDirection(Qt::RightToLeft);
        pushButton_3 = new QPushButton(admin);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(1270, 280, 200, 40));
        pushButton_3->setLayoutDirection(Qt::RightToLeft);
        pushButton_4 = new QPushButton(admin);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(1270, 340, 200, 40));
        pushButton_4->setLayoutDirection(Qt::RightToLeft);
        pushButton_5 = new QPushButton(admin);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(1270, 400, 200, 40));
        pushButton_5->setLayoutDirection(Qt::RightToLeft);
        pushButton_6 = new QPushButton(admin);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(1270, 460, 200, 40));
        pushButton_6->setLayoutDirection(Qt::RightToLeft);
        pushButton_7 = new QPushButton(admin);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(1270, 520, 200, 40));
        pushButton_7->setLayoutDirection(Qt::RightToLeft);
        pushButton_8 = new QPushButton(admin);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(1270, 580, 200, 40));
        pushButton_8->setLayoutDirection(Qt::RightToLeft);
        goods_management = new QWidget(admin);
        goods_management->setObjectName(QString::fromUtf8("goods_management"));
        goods_management->setGeometry(QRect(40, 140, 1130, 500));
        user_management = new QWidget(admin);
        user_management->setObjectName(QString::fromUtf8("user_management"));
        user_management->setGeometry(QRect(40, 140, 1130, 500));
        site_settings = new QWidget(admin);
        site_settings->setObjectName(QString::fromUtf8("site_settings"));
        site_settings->setGeometry(QRect(40, 140, 1130, 500));
        finance = new QWidget(admin);
        finance->setObjectName(QString::fromUtf8("finance"));
        finance->setGeometry(QRect(40, 140, 1130, 500));
        employeement = new QWidget(admin);
        employeement->setObjectName(QString::fromUtf8("employeement"));
        employeement->setGeometry(QRect(40, 140, 1130, 500));
        treaties = new QWidget(admin);
        treaties->setObjectName(QString::fromUtf8("treaties"));
        treaties->setGeometry(QRect(40, 140, 1130, 500));
        pushButton_18 = new QPushButton(admin);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        pushButton_18->setGeometry(QRect(1270, 650, 200, 40));
        pushButton_18->setLayoutDirection(Qt::RightToLeft);
        pushButton_18->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 82, 82);"));
        foreign_connections = new QWidget(admin);
        foreign_connections->setObjectName(QString::fromUtf8("foreign_connections"));
        foreign_connections->setGeometry(QRect(40, 810, 1130, 500));
        admin_account_info = new QWidget(admin);
        admin_account_info->setObjectName(QString::fromUtf8("admin_account_info"));
        admin_account_info->setGeometry(QRect(40, 140, 1130, 500));
        label_20 = new QLabel(admin_account_info);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(906, 40, 161, 20));
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        label_21 = new QLabel(admin_account_info);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(530, 110, 71, 20));
        label_21->setStyleSheet(QString::fromUtf8("font: 75 10pt \"MS Shell Dlg 2\";"));
        first_and_lastname = new QLabel(admin_account_info);
        first_and_lastname->setObjectName(QString::fromUtf8("first_and_lastname"));
        first_and_lastname->setGeometry(QRect(800, 150, 310, 20));
        first_and_lastname->setLayoutDirection(Qt::RightToLeft);
        label_24 = new QLabel(admin_account_info);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(910, 110, 131, 20));
        label_24->setStyleSheet(QString::fromUtf8("font: 75 10pt \"MS Shell Dlg 2\";"));
        username = new QLabel(admin_account_info);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(370, 150, 400, 20));
        username->setLayoutDirection(Qt::RightToLeft);
        label_26 = new QLabel(admin_account_info);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(906, 10, 160, 40));
        label_26->setLayoutDirection(Qt::RightToLeft);
        label_26->setStyleSheet(QString::fromUtf8("font: 18pt \"B Homa\";\n"
"color: rgb(0, 0, 0);"));
        label_27 = new QLabel(admin_account_info);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(130, 110, 71, 20));
        label_27->setStyleSheet(QString::fromUtf8("font: 75 10pt \"MS Shell Dlg 2\";"));
        password = new QLabel(admin_account_info);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(20, 150, 310, 20));
        password->setLayoutDirection(Qt::RightToLeft);
        edit_button = new QPushButton(admin_account_info);
        edit_button->setObjectName(QString::fromUtf8("edit_button"));
        edit_button->setGeometry(QRect(500, 260, 141, 41));
        customer = new QWidget(Dashboard);
        customer->setObjectName(QString::fromUtf8("customer"));
        customer->setGeometry(QRect(0, 0, 1500, 800));
        pushButton_9 = new QPushButton(customer);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(1270, 200, 200, 40));
        pushButton_9->setLayoutDirection(Qt::RightToLeft);
        pushButton_10 = new QPushButton(customer);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(1270, 260, 200, 40));
        pushButton_10->setLayoutDirection(Qt::RightToLeft);
        pushButton_11 = new QPushButton(customer);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(1270, 320, 200, 40));
        pushButton_11->setLayoutDirection(Qt::RightToLeft);
        pushButton_13 = new QPushButton(customer);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setGeometry(QRect(1270, 380, 200, 40));
        pushButton_13->setLayoutDirection(Qt::RightToLeft);
        pushButton_14 = new QPushButton(customer);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setGeometry(QRect(1270, 440, 200, 40));
        pushButton_14->setLayoutDirection(Qt::RightToLeft);
        pushButton_15 = new QPushButton(customer);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setGeometry(QRect(1270, 500, 200, 40));
        pushButton_15->setLayoutDirection(Qt::RightToLeft);
        pushButton_16 = new QPushButton(customer);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setGeometry(QRect(1270, 560, 200, 40));
        pushButton_16->setLayoutDirection(Qt::RightToLeft);
        pushButton_16->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 82, 82);"));
        my_orders = new QWidget(customer);
        my_orders->setObjectName(QString::fromUtf8("my_orders"));
        my_orders->setGeometry(QRect(40, 140, 1130, 500));
        lists = new QWidget(customer);
        lists->setObjectName(QString::fromUtf8("lists"));
        lists->setGeometry(QRect(40, 140, 1130, 500));
        comments = new QWidget(customer);
        comments->setObjectName(QString::fromUtf8("comments"));
        comments->setGeometry(QRect(40, 140, 1130, 500));
        addresses = new QWidget(customer);
        addresses->setObjectName(QString::fromUtf8("addresses"));
        addresses->setGeometry(QRect(40, 140, 1130, 500));
        messages = new QWidget(customer);
        messages->setObjectName(QString::fromUtf8("messages"));
        messages->setGeometry(QRect(40, 140, 1130, 500));
        last_activities = new QWidget(customer);
        last_activities->setObjectName(QString::fromUtf8("last_activities"));
        last_activities->setGeometry(QRect(40, 140, 1130, 500));
        customer_account_info = new QWidget(customer);
        customer_account_info->setObjectName(QString::fromUtf8("customer_account_info"));
        customer_account_info->setGeometry(QRect(40, 140, 1130, 500));
        customer_account_info->setLayoutDirection(Qt::LeftToRight);
        label = new QLabel(customer_account_info);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(920, 10, 160, 40));
        label->setLayoutDirection(Qt::RightToLeft);
        label->setStyleSheet(QString::fromUtf8("font: 18pt \"B Homa\";\n"
"color: rgb(0, 0, 0);"));
        label_2 = new QLabel(customer_account_info);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(923, 40, 161, 20));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        customer_edit = new QPushButton(customer_account_info);
        customer_edit->setObjectName(QString::fromUtf8("customer_edit"));
        customer_edit->setGeometry(QRect(530, 430, 141, 41));
        customer_show_address = new QLabel(customer_account_info);
        customer_show_address->setObjectName(QString::fromUtf8("customer_show_address"));
        customer_show_address->setGeometry(QRect(20, 340, 941, 25));
        customer_show_address->setLayoutDirection(Qt::RightToLeft);
        customer_addresses = new QLabel(customer_account_info);
        customer_addresses->setObjectName(QString::fromUtf8("customer_addresses"));
        customer_addresses->setGeometry(QRect(1018, 340, 91, 25));
        customer_addresses->setLayoutDirection(Qt::RightToLeft);
        customer_addresses->setStyleSheet(QString::fromUtf8("font: 75 10pt \"MS Shell Dlg 2\";"));
        customer_address_number = new QSpinBox(customer_account_info);
        customer_address_number->setObjectName(QString::fromUtf8("customer_address_number"));
        customer_address_number->setGeometry(QRect(975, 330, 41, 41));
        customer_address_number->setLayoutDirection(Qt::RightToLeft);
        customer_address_number->setMinimum(1);
        customer_address_number->setMaximum(100);
        layoutWidget = new QWidget(customer_account_info);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 100, 1091, 23));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("font: 75 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_5->addWidget(label_12);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 75 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_5->addWidget(label_6);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 75 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_5->addWidget(label_3);

        layoutWidget1 = new QWidget(customer_account_info);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 130, 1091, 31));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        customer_password = new QLabel(layoutWidget1);
        customer_password->setObjectName(QString::fromUtf8("customer_password"));
        customer_password->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_6->addWidget(customer_password);

        customer_username = new QLabel(layoutWidget1);
        customer_username->setObjectName(QString::fromUtf8("customer_username"));
        customer_username->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_6->addWidget(customer_username);

        customer_first_and_last_name = new QLabel(layoutWidget1);
        customer_first_and_last_name->setObjectName(QString::fromUtf8("customer_first_and_last_name"));
        customer_first_and_last_name->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_6->addWidget(customer_first_and_last_name);

        layoutWidget2 = new QWidget(customer_account_info);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 220, 1091, 23));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setStyleSheet(QString::fromUtf8("font: 75 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_7->addWidget(label_11);

        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("font: 75 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_7->addWidget(label_10);

        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("font: 75 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_7->addWidget(label_9);

        layoutWidget3 = new QWidget(customer_account_info);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(20, 250, 1091, 31));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        customer_email = new QLabel(layoutWidget3);
        customer_email->setObjectName(QString::fromUtf8("customer_email"));
        customer_email->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_8->addWidget(customer_email);

        customer_birthday = new QLabel(layoutWidget3);
        customer_birthday->setObjectName(QString::fromUtf8("customer_birthday"));
        customer_birthday->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_8->addWidget(customer_birthday);

        customer_phone_number = new QLabel(layoutWidget3);
        customer_phone_number->setObjectName(QString::fromUtf8("customer_phone_number"));
        customer_phone_number->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_8->addWidget(customer_phone_number);

        customer_account_edit = new QWidget(customer);
        customer_account_edit->setObjectName(QString::fromUtf8("customer_account_edit"));
        customer_account_edit->setGeometry(QRect(1510, 140, 1130, 500));
        customer_account_edit->setLayoutDirection(Qt::LeftToRight);
        label_5 = new QLabel(customer_account_edit);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(819, 10, 261, 40));
        label_5->setLayoutDirection(Qt::RightToLeft);
        label_5->setStyleSheet(QString::fromUtf8("font: 18pt \"B Homa\";\n"
"color: rgb(0, 0, 0);"));
        label_8 = new QLabel(customer_account_edit);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(819, 40, 261, 20));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        layoutWidget4 = new QWidget(customer_account_edit);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(20, 150, 1091, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        customer_password_line_edit = new QLineEdit(layoutWidget4);
        customer_password_line_edit->setObjectName(QString::fromUtf8("customer_password_line_edit"));
        customer_password_line_edit->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout->addWidget(customer_password_line_edit);

        customer_username_line_edit = new QLineEdit(layoutWidget4);
        customer_username_line_edit->setObjectName(QString::fromUtf8("customer_username_line_edit"));
        customer_username_line_edit->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout->addWidget(customer_username_line_edit);

        customer_lastname_line_edit = new QLineEdit(layoutWidget4);
        customer_lastname_line_edit->setObjectName(QString::fromUtf8("customer_lastname_line_edit"));
        customer_lastname_line_edit->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout->addWidget(customer_lastname_line_edit);

        customer_firstname_line_edit = new QLineEdit(layoutWidget4);
        customer_firstname_line_edit->setObjectName(QString::fromUtf8("customer_firstname_line_edit"));
        customer_firstname_line_edit->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout->addWidget(customer_firstname_line_edit);

        layoutWidget5 = new QWidget(customer_account_edit);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(20, 120, 1091, 23));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(layoutWidget5);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setLayoutDirection(Qt::RightToLeft);
        label_15->setStyleSheet(QString::fromUtf8("font: 75 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_2->addWidget(label_15);

        label_7 = new QLabel(layoutWidget5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setLayoutDirection(Qt::RightToLeft);
        label_7->setStyleSheet(QString::fromUtf8("font: 75 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_2->addWidget(label_7);

        label_17 = new QLabel(layoutWidget5);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setLayoutDirection(Qt::RightToLeft);
        label_17->setStyleSheet(QString::fromUtf8("font: 75 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_2->addWidget(label_17);

        label_4 = new QLabel(layoutWidget5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setLayoutDirection(Qt::RightToLeft);
        label_4->setStyleSheet(QString::fromUtf8("font: 75 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_2->addWidget(label_4);

        layoutWidget6 = new QWidget(customer_account_edit);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(20, 240, 891, 23));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(layoutWidget6);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setLayoutDirection(Qt::RightToLeft);
        label_16->setStyleSheet(QString::fromUtf8("font: 75 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_3->addWidget(label_16);

        label_13 = new QLabel(layoutWidget6);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setLayoutDirection(Qt::RightToLeft);
        label_13->setStyleSheet(QString::fromUtf8("font: 75 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_3->addWidget(label_13);

        label_14 = new QLabel(layoutWidget6);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setLayoutDirection(Qt::RightToLeft);
        label_14->setStyleSheet(QString::fromUtf8("font: 75 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_3->addWidget(label_14);

        layoutWidget7 = new QWidget(customer_account_edit);
        layoutWidget7->setObjectName(QString::fromUtf8("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(20, 270, 1091, 27));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        customer_email_line_edit = new QLineEdit(layoutWidget7);
        customer_email_line_edit->setObjectName(QString::fromUtf8("customer_email_line_edit"));
        customer_email_line_edit->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_4->addWidget(customer_email_line_edit);

        customer_birthday_edit = new QDateEdit(layoutWidget7);
        customer_birthday_edit->setObjectName(QString::fromUtf8("customer_birthday_edit"));
        customer_birthday_edit->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_4->addWidget(customer_birthday_edit);

        customer_phone_number_line_edit = new QLineEdit(layoutWidget7);
        customer_phone_number_line_edit->setObjectName(QString::fromUtf8("customer_phone_number_line_edit"));
        customer_phone_number_line_edit->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_4->addWidget(customer_phone_number_line_edit);

        remove_this_address_button = new QPushButton(customer_account_edit);
        remove_this_address_button->setObjectName(QString::fromUtf8("remove_this_address_button"));
        remove_this_address_button->setGeometry(QRect(40, 330, 31, 31));
        QFont font;
        font.setPointSize(14);
        remove_this_address_button->setFont(font);
        remove_this_address_button->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        customer_addresses_to_be_removed = new QLabel(customer_account_edit);
        customer_addresses_to_be_removed->setObjectName(QString::fromUtf8("customer_addresses_to_be_removed"));
        customer_addresses_to_be_removed->setGeometry(QRect(81, 328, 881, 31));
        customer_addresses_to_be_removed->setLayoutDirection(Qt::RightToLeft);
        customer_address_number_edit = new QSpinBox(customer_account_edit);
        customer_address_number_edit->setObjectName(QString::fromUtf8("customer_address_number_edit"));
        customer_address_number_edit->setGeometry(QRect(973, 328, 49, 31));
        customer_address_number_edit->setMinimum(1);
        customer_address_number_edit->setMaximum(100);
        customer_addresses_edit = new QLabel(customer_account_edit);
        customer_addresses_edit->setObjectName(QString::fromUtf8("customer_addresses_edit"));
        customer_addresses_edit->setGeometry(QRect(1064, 340, 51, 49));
        customer_addresses_edit->setStyleSheet(QString::fromUtf8("font: 75 10pt \"MS Shell Dlg 2\";"));
        add_this_address_button = new QPushButton(customer_account_edit);
        add_this_address_button->setObjectName(QString::fromUtf8("add_this_address_button"));
        add_this_address_button->setGeometry(QRect(40, 370, 31, 31));
        QFont font1;
        font1.setPointSize(20);
        add_this_address_button->setFont(font1);
        add_this_address_button->setStyleSheet(QString::fromUtf8("color: rgb(0, 159, 0);"));
        add_address_line_edit = new QLineEdit(customer_account_edit);
        add_address_line_edit->setObjectName(QString::fromUtf8("add_address_line_edit"));
        add_address_line_edit->setGeometry(QRect(80, 370, 881, 31));
        add_address_line_edit->setLayoutDirection(Qt::RightToLeft);
        customer_apply_changes_button = new QPushButton(customer_account_edit);
        customer_apply_changes_button->setObjectName(QString::fromUtf8("customer_apply_changes_button"));
        customer_apply_changes_button->setGeometry(QRect(490, 440, 141, 41));
        show_password_checkBox = new QCheckBox(customer_account_edit);
        show_password_checkBox->setObjectName(QString::fromUtf8("show_password_checkBox"));
        show_password_checkBox->setGeometry(QRect(160, 180, 121, 22));
        show_password_checkBox->setLayoutDirection(Qt::RightToLeft);
        back = new QCommandLinkButton(customer);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(10, 30, 80, 40));
        QFont font2;
        font2.setPointSize(7);
        back->setFont(font2);
        back->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(Dashboard);

        QMetaObject::connectSlotsByName(Dashboard);
    } // setupUi

    void retranslateUi(QWidget *Dashboard)
    {
        Dashboard->setWindowTitle(QCoreApplication::translate("Dashboard", "kir", nullptr));
        pushButton->setText(QCoreApplication::translate("Dashboard", "\331\205\330\257\333\214\330\261\333\214\330\252 \332\251\330\247\331\204\330\247\331\207\330\247", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dashboard", "\331\205\330\257\333\214\330\261\333\214\330\252 \332\251\330\247\330\261\330\250\330\261\330\247\331\206", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Dashboard", "\330\252\331\206\330\270\333\214\331\205\330\247\330\252 \330\263\330\247\333\214\330\252", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Dashboard", "\330\247\331\205\331\210\330\261 \331\205\330\247\331\204\333\214", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Dashboard", "\330\247\330\263\330\252\330\256\330\257\330\247\331\205", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Dashboard", "\331\202\330\261\330\247\330\261\330\257\330\247\330\257\331\207\330\247", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Dashboard", "\330\247\330\267\331\204\330\247\330\271\330\247\330\252 \330\255\330\263\330\247\330\250", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Dashboard", "\330\261\331\210\330\247\330\250\330\267 \330\271\331\205\331\210\331\205\333\214", nullptr));
        pushButton_18->setText(QCoreApplication::translate("Dashboard", "\330\256\330\261\331\210\330\254", nullptr));
        label_20->setText(QCoreApplication::translate("Dashboard", "____________________________", nullptr));
        label_21->setText(QCoreApplication::translate("Dashboard", "\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214", nullptr));
        first_and_lastname->setText(QString());
        label_24->setText(QCoreApplication::translate("Dashboard", "\331\206\330\247\331\205 \331\210 \331\206\330\247\331\205 \330\256\330\247\331\206\331\210\330\247\330\257\332\257\333\214", nullptr));
        username->setText(QString());
        label_26->setText(QCoreApplication::translate("Dashboard", "\330\247\330\267\331\204\330\247\330\271\330\247\330\252 \330\264\330\256\330\265\333\214", nullptr));
        label_27->setText(QCoreApplication::translate("Dashboard", "\332\251\331\204\331\205\331\207 \330\271\330\250\331\210\330\261", nullptr));
        password->setText(QString());
        edit_button->setText(QCoreApplication::translate("Dashboard", "\331\210\333\214\330\261\330\247\333\214\330\264 \330\247\330\267\331\204\330\247\330\271\330\247\330\252 \330\264\330\256\330\265\333\214", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Dashboard", "\330\263\331\201\330\247\330\261\330\264 \331\207\330\247\333\214 \331\205\331\206", nullptr));
        pushButton_10->setText(QCoreApplication::translate("Dashboard", "\331\204\333\214\330\263\330\252 \331\207\330\247", nullptr));
        pushButton_11->setText(QCoreApplication::translate("Dashboard", "\331\206\330\270\330\261\330\247\330\252", nullptr));
        pushButton_13->setText(QCoreApplication::translate("Dashboard", "\331\276\333\214\330\272\330\247\331\205 \331\207\330\247", nullptr));
        pushButton_14->setText(QCoreApplication::translate("Dashboard", "\330\250\330\247\330\262\330\257\333\214\330\257\331\207\330\247\333\214 \330\247\330\256\333\214\330\261", nullptr));
        pushButton_15->setText(QCoreApplication::translate("Dashboard", "\330\247\330\267\331\204\330\247\330\271\330\247\330\252 \330\255\330\263\330\247\330\250", nullptr));
        pushButton_16->setText(QCoreApplication::translate("Dashboard", "\330\256\330\261\331\210\330\254", nullptr));
        label->setText(QCoreApplication::translate("Dashboard", "\330\247\330\267\331\204\330\247\330\271\330\247\330\252 \330\264\330\256\330\265\333\214", nullptr));
        label_2->setText(QCoreApplication::translate("Dashboard", "____________________________", nullptr));
        customer_edit->setText(QCoreApplication::translate("Dashboard", "\331\210\333\214\330\261\330\247\333\214\330\264 \330\247\330\267\331\204\330\247\330\271\330\247\330\252 \330\264\330\256\330\265\333\214", nullptr));
        customer_show_address->setText(QString());
        customer_addresses->setText(QCoreApplication::translate("Dashboard", "\330\242\330\257\330\261\330\263 \330\264\331\205\330\247\330\261\331\207", nullptr));
        label_12->setText(QCoreApplication::translate("Dashboard", "\332\251\331\204\331\205\331\207 \330\271\330\250\331\210\330\261", nullptr));
        label_6->setText(QCoreApplication::translate("Dashboard", "\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214", nullptr));
        label_3->setText(QCoreApplication::translate("Dashboard", "\331\206\330\247\331\205 \331\210 \331\206\330\247\331\205 \330\256\330\247\331\206\331\210\330\247\330\257\332\257\333\214", nullptr));
        customer_password->setText(QString());
        customer_username->setText(QString());
        customer_first_and_last_name->setText(QString());
        label_11->setText(QCoreApplication::translate("Dashboard", "\331\276\330\263\330\252 \330\247\331\204\332\251\330\252\330\261\331\210\331\206\333\214\332\251\333\214", nullptr));
        label_10->setText(QCoreApplication::translate("Dashboard", "\330\252\330\247\330\261\333\214\330\256 \330\252\331\210\331\204\330\257", nullptr));
        label_9->setText(QCoreApplication::translate("Dashboard", "\330\264\331\205\330\247\330\261\331\207 \330\252\331\204\331\201\331\206 \331\207\331\205\330\261\330\247\331\207", nullptr));
        customer_email->setText(QString());
        customer_birthday->setText(QString());
        customer_phone_number->setText(QString());
        label_5->setText(QCoreApplication::translate("Dashboard", "\330\247\330\267\331\204\330\247\330\271\330\247\330\252 \330\264\330\256\330\265\333\214/\331\210\333\214\330\261\330\247\333\214\330\264", nullptr));
        label_8->setText(QCoreApplication::translate("Dashboard", "__________________________________________________", nullptr));
        label_15->setText(QCoreApplication::translate("Dashboard", "\332\251\331\204\331\205\331\207 \330\271\330\250\331\210\330\261", nullptr));
        label_7->setText(QCoreApplication::translate("Dashboard", "\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214", nullptr));
        label_17->setText(QCoreApplication::translate("Dashboard", "\331\206\330\247\331\205 \330\256\330\247\331\206\331\210\330\247\330\257\332\257\333\214", nullptr));
        label_4->setText(QCoreApplication::translate("Dashboard", "\331\206\330\247\331\205", nullptr));
        label_16->setText(QCoreApplication::translate("Dashboard", "\331\276\330\263\330\252 \330\247\331\204\332\251\330\252\330\261\331\210\331\206\333\214\332\251\333\214", nullptr));
        label_13->setText(QCoreApplication::translate("Dashboard", "\330\252\330\247\330\261\333\214\330\256 \330\252\331\210\331\204\330\257", nullptr));
        label_14->setText(QCoreApplication::translate("Dashboard", "\330\264\331\205\330\247\330\261\331\207 \330\252\331\204\331\201\331\206 \331\207\331\205\330\261\330\247\331\207", nullptr));
        remove_this_address_button->setText(QCoreApplication::translate("Dashboard", "\342\224\200", nullptr));
        customer_addresses_to_be_removed->setText(QString());
        customer_addresses_edit->setText(QCoreApplication::translate("Dashboard", "\330\242\330\257\330\261\330\263:", nullptr));
        add_this_address_button->setText(QCoreApplication::translate("Dashboard", "+", nullptr));
        customer_apply_changes_button->setText(QCoreApplication::translate("Dashboard", "\330\253\330\250\330\252", nullptr));
        show_password_checkBox->setText(QCoreApplication::translate("Dashboard", "\331\206\331\205\330\247\333\214\330\264 \332\251\331\204\331\205\331\207 \330\271\330\250\331\210\330\261", nullptr));
        back->setText(QCoreApplication::translate("Dashboard", "\330\250\330\247\330\262\332\257\330\264\330\252", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dashboard: public Ui_Dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H

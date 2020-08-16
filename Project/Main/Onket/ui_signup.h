/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signup
{
public:
    QCommandLinkButton *back;
    QWidget *signup_first_step;
    QLabel *label_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *username_line_edit;
    QCheckBox *show_password;
    QLineEdit *password_line_edit;
    QLineEdit *repeat_password_line_edit;
    QPushButton *signup_button;
    QLabel *label_4;
    QWidget *signup_second_step;
    QLineEdit *phone_number_line_edit;
    QLineEdit *firstname_line_edit;
    QLabel *lastname;
    QLabel *firstname;
    QLabel *label_10;
    QLineEdit *lastname_line_edit;
    QLabel *birthday;
    QDateEdit *birthday_edit;
    QLabel *address;
    QLineEdit *address_line_edit;
    QPushButton *add_address_button;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *firstname_is_empty;
    QLabel *lastname_is_empty;
    QLabel *phone_is_empty;
    QLabel *no_address;
    QPushButton *create_account;

    void setupUi(QWidget *signup)
    {
        if (signup->objectName().isEmpty())
            signup->setObjectName(QString::fromUtf8("signup"));
        signup->resize(1500, 800);
        back = new QCommandLinkButton(signup);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(10, 30, 80, 40));
        QFont font;
        font.setPointSize(7);
        back->setFont(font);
        signup_first_step = new QWidget(signup);
        signup_first_step->setObjectName(QString::fromUtf8("signup_first_step"));
        signup_first_step->setGeometry(QRect(0, 69, 1500, 731));
        label_3 = new QLabel(signup_first_step);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(970, 240, 81, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 15pt \"B Nazanin\";\n"
"color: rgb(0, 0, 0);"));
        layoutWidget = new QWidget(signup_first_step);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(540, 450, 421, 84));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        verticalLayout->addWidget(label_5);

        label = new QLabel(signup_first_step);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(705, 75, 111, 51));
        label->setStyleSheet(QString::fromUtf8("font: 24pt \"B Homa\";\n"
"color: rgb(255, 0, 0);"));
        label_2 = new QLabel(signup_first_step);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(970, 165, 141, 31));
        label_2->setLayoutDirection(Qt::RightToLeft);
        label_2->setStyleSheet(QString::fromUtf8("font: 15pt \"B Nazanin\";\n"
"color: rgb(0, 0, 0);"));
        username_line_edit = new QLineEdit(signup_first_step);
        username_line_edit->setObjectName(QString::fromUtf8("username_line_edit"));
        username_line_edit->setGeometry(QRect(540, 163, 421, 41));
        QFont font1;
        font1.setPointSize(11);
        username_line_edit->setFont(font1);
        show_password = new QCheckBox(signup_first_step);
        show_password->setObjectName(QString::fromUtf8("show_password"));
        show_password->setGeometry(QRect(782, 390, 171, 22));
        show_password->setLayoutDirection(Qt::RightToLeft);
        password_line_edit = new QLineEdit(signup_first_step);
        password_line_edit->setObjectName(QString::fromUtf8("password_line_edit"));
        password_line_edit->setGeometry(QRect(540, 240, 421, 41));
        password_line_edit->setFont(font1);
        repeat_password_line_edit = new QLineEdit(signup_first_step);
        repeat_password_line_edit->setObjectName(QString::fromUtf8("repeat_password_line_edit"));
        repeat_password_line_edit->setGeometry(QRect(540, 310, 421, 41));
        repeat_password_line_edit->setFont(font1);
        signup_button = new QPushButton(signup_first_step);
        signup_button->setObjectName(QString::fromUtf8("signup_button"));
        signup_button->setGeometry(QRect(690, 600, 151, 51));
        signup_button->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 47, 47);"));
        label_4 = new QLabel(signup_first_step);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(970, 320, 121, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 15pt \"B Nazanin\";\n"
"color: rgb(0, 0, 0);"));
        signup_second_step = new QWidget(signup);
        signup_second_step->setObjectName(QString::fromUtf8("signup_second_step"));
        signup_second_step->setGeometry(QRect(0, 69, 1500, 731));
        phone_number_line_edit = new QLineEdit(signup_second_step);
        phone_number_line_edit->setObjectName(QString::fromUtf8("phone_number_line_edit"));
        phone_number_line_edit->setGeometry(QRect(540, 200, 421, 41));
        phone_number_line_edit->setFont(font1);
        phone_number_line_edit->setStyleSheet(QString::fromUtf8(""));
        firstname_line_edit = new QLineEdit(signup_second_step);
        firstname_line_edit->setObjectName(QString::fromUtf8("firstname_line_edit"));
        firstname_line_edit->setGeometry(QRect(540, 63, 421, 41));
        firstname_line_edit->setFont(font1);
        firstname_line_edit->setLayoutDirection(Qt::RightToLeft);
        firstname_line_edit->setStyleSheet(QString::fromUtf8(""));
        lastname = new QLabel(signup_second_step);
        lastname->setObjectName(QString::fromUtf8("lastname"));
        lastname->setGeometry(QRect(970, 130, 101, 31));
        lastname->setStyleSheet(QString::fromUtf8("font: 15pt \"B Nazanin\";\n"
"color: rgb(0, 0, 0);"));
        firstname = new QLabel(signup_second_step);
        firstname->setObjectName(QString::fromUtf8("firstname"));
        firstname->setGeometry(QRect(970, 65, 21, 31));
        firstname->setLayoutDirection(Qt::RightToLeft);
        firstname->setStyleSheet(QString::fromUtf8("font: 15pt \"B Nazanin\";\n"
"color: rgb(0, 0, 0);"));
        label_10 = new QLabel(signup_second_step);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(970, 200, 141, 31));
        label_10->setStyleSheet(QString::fromUtf8("font: 15pt \"B Nazanin\";\n"
"color: rgb(0, 0, 0);"));
        lastname_line_edit = new QLineEdit(signup_second_step);
        lastname_line_edit->setObjectName(QString::fromUtf8("lastname_line_edit"));
        lastname_line_edit->setGeometry(QRect(540, 130, 421, 41));
        lastname_line_edit->setFont(font1);
        lastname_line_edit->setLayoutDirection(Qt::RightToLeft);
        lastname_line_edit->setStyleSheet(QString::fromUtf8(""));
        birthday = new QLabel(signup_second_step);
        birthday->setObjectName(QString::fromUtf8("birthday"));
        birthday->setGeometry(QRect(970, 270, 81, 31));
        birthday->setStyleSheet(QString::fromUtf8("font: 15pt \"B Nazanin\";\n"
"color: rgb(0, 0, 0);"));
        birthday_edit = new QDateEdit(signup_second_step);
        birthday_edit->setObjectName(QString::fromUtf8("birthday_edit"));
        birthday_edit->setGeometry(QRect(789, 270, 171, 41));
        birthday_edit->setFont(font1);
        birthday_edit->setLayoutDirection(Qt::LeftToRight);
        birthday_edit->setStyleSheet(QString::fromUtf8(""));
        birthday_edit->setTimeSpec(Qt::LocalTime);
        address = new QLabel(signup_second_step);
        address->setObjectName(QString::fromUtf8("address"));
        address->setGeometry(QRect(970, 340, 51, 31));
        address->setStyleSheet(QString::fromUtf8("font: 15pt \"B Nazanin\";\n"
"color: rgb(0, 0, 0);"));
        address_line_edit = new QLineEdit(signup_second_step);
        address_line_edit->setObjectName(QString::fromUtf8("address_line_edit"));
        address_line_edit->setGeometry(QRect(540, 340, 421, 41));
        address_line_edit->setFont(font1);
        address_line_edit->setLayoutDirection(Qt::RightToLeft);
        address_line_edit->setStyleSheet(QString::fromUtf8(""));
        add_address_button = new QPushButton(signup_second_step);
        add_address_button->setObjectName(QString::fromUtf8("add_address_button"));
        add_address_button->setGeometry(QRect(490, 340, 41, 41));
        add_address_button->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));
        widget = new QWidget(signup_second_step);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(600, 440, 361, 101));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        firstname_is_empty = new QLabel(widget);
        firstname_is_empty->setObjectName(QString::fromUtf8("firstname_is_empty"));
        firstname_is_empty->setLayoutDirection(Qt::RightToLeft);
        firstname_is_empty->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        verticalLayout_2->addWidget(firstname_is_empty);

        lastname_is_empty = new QLabel(widget);
        lastname_is_empty->setObjectName(QString::fromUtf8("lastname_is_empty"));
        lastname_is_empty->setLayoutDirection(Qt::RightToLeft);
        lastname_is_empty->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        verticalLayout_2->addWidget(lastname_is_empty);

        phone_is_empty = new QLabel(widget);
        phone_is_empty->setObjectName(QString::fromUtf8("phone_is_empty"));
        phone_is_empty->setLayoutDirection(Qt::RightToLeft);
        phone_is_empty->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        verticalLayout_2->addWidget(phone_is_empty);

        no_address = new QLabel(widget);
        no_address->setObjectName(QString::fromUtf8("no_address"));
        no_address->setLayoutDirection(Qt::RightToLeft);
        no_address->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        verticalLayout_2->addWidget(no_address);

        create_account = new QPushButton(signup_second_step);
        create_account->setObjectName(QString::fromUtf8("create_account"));
        create_account->setGeometry(QRect(680, 620, 151, 51));
        create_account->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 47, 47);"));

        retranslateUi(signup);

        QMetaObject::connectSlotsByName(signup);
    } // setupUi

    void retranslateUi(QWidget *signup)
    {
        signup->setWindowTitle(QCoreApplication::translate("signup", "Form", nullptr));
        back->setText(QCoreApplication::translate("signup", "\330\250\330\247\330\262\332\257\330\264\330\252", nullptr));
        label_3->setText(QCoreApplication::translate("signup", "\332\251\331\204\331\205\331\207 \330\271\330\250\331\210\330\261:", nullptr));
        layoutWidget->setStyleSheet(QCoreApplication::translate("signup", "color: rgb(255, 0, 0);", nullptr));
        label_7->setStyleSheet(QCoreApplication::translate("signup", "color: rgb(255, 0, 0);", nullptr));
        label_7->setText(QString());
        label_6->setStyleSheet(QCoreApplication::translate("signup", "color: rgb(255, 0, 0);", nullptr));
        label_6->setText(QString());
        label_5->setText(QString());
        label->setText(QCoreApplication::translate("signup", "\330\253\330\250\330\252 \331\206\330\247\331\205", nullptr));
        label_2->setText(QCoreApplication::translate("signup", "\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214(\330\247\333\214\331\205\333\214\331\204):", nullptr));
        show_password->setText(QCoreApplication::translate("signup", "\332\251\331\204\331\205\331\207 \330\271\330\250\331\210\330\261 \331\206\331\205\330\247\330\264 \330\257\330\247\330\257\331\207 \330\264\331\210\330\257", nullptr));
        signup_button->setText(QCoreApplication::translate("signup", "\330\253\330\250\330\252 \331\206\330\247\331\205", nullptr));
        label_4->setText(QCoreApplication::translate("signup", "\330\252\332\251\330\261\330\247\330\261 \332\251\331\204\331\205\331\207 \330\271\330\250\331\210\330\261:", nullptr));
        lastname->setText(QCoreApplication::translate("signup", "\331\206\330\247\331\205 \330\256\330\247\331\206\331\210\330\247\330\257\332\257\333\214:", nullptr));
        firstname->setText(QCoreApplication::translate("signup", "\331\206\330\247\331\205:", nullptr));
        label_10->setText(QCoreApplication::translate("signup", "\330\264\331\205\330\247\330\261\331\207 \330\252\331\204\331\201\331\206 \331\207\331\205\330\261\330\247\331\207:", nullptr));
        birthday->setText(QCoreApplication::translate("signup", "\330\252\330\247\330\261\333\214\330\256 \330\252\331\210\331\204\330\257:", nullptr));
        address->setText(QCoreApplication::translate("signup", "\331\206\330\264\330\247\331\206\333\214:", nullptr));
        add_address_button->setText(QCoreApplication::translate("signup", "+", nullptr));
        firstname_is_empty->setText(QString());
        lastname_is_empty->setText(QString());
        phone_is_empty->setText(QString());
        no_address->setText(QString());
        create_account->setText(QCoreApplication::translate("signup", "\330\252\330\247\333\214\333\214\330\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signup: public Ui_signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H

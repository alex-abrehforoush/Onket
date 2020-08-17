/********************************************************************************
** Form generated from reading UI file 'loginpage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginPage
{
public:
    QPushButton *signup_button;
    QPushButton *enter_button;
    QLineEdit *username_line_edit;
    QLineEdit *password_line_edit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *username;
    QLabel *password;
    QLabel *enter_or_signup;
    QLabel *logo_fa;
    QLabel *logo_en;
    QCommandLinkButton *back;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *show_password;
    QCheckBox *save_login_info;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *username_or_password_is_wrong;
    QLabel *username_is_empty;
    QLabel *password_is_empty;

    void setupUi(QWidget *LoginPage)
    {
        if (LoginPage->objectName().isEmpty())
            LoginPage->setObjectName(QString::fromUtf8("LoginPage"));
        LoginPage->resize(1500, 800);
        signup_button = new QPushButton(LoginPage);
        signup_button->setObjectName(QString::fromUtf8("signup_button"));
        signup_button->setGeometry(QRect(750, 620, 150, 50));
        QFont font;
        font.setPointSize(11);
        signup_button->setFont(font);
        signup_button->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 47, 47);"));
        enter_button = new QPushButton(LoginPage);
        enter_button->setObjectName(QString::fromUtf8("enter_button"));
        enter_button->setGeometry(QRect(600, 620, 150, 50));
        enter_button->setFont(font);
        enter_button->setStyleSheet(QString::fromUtf8(""));
        username_line_edit = new QLineEdit(LoginPage);
        username_line_edit->setObjectName(QString::fromUtf8("username_line_edit"));
        username_line_edit->setGeometry(QRect(510, 393, 441, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(11);
        username_line_edit->setFont(font1);
        username_line_edit->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(255, 111, 111);"));
        password_line_edit = new QLineEdit(LoginPage);
        password_line_edit->setObjectName(QString::fromUtf8("password_line_edit"));
        password_line_edit->setGeometry(QRect(510, 463, 441, 51));
        password_line_edit->setFont(font1);
        password_line_edit->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(255, 111, 111);"));
        password_line_edit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        layoutWidget = new QWidget(LoginPage);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(960, 380, 71, 141));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        username = new QLabel(layoutWidget);
        username->setObjectName(QString::fromUtf8("username"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 127));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        username->setPalette(palette);
        QFont font2;
        font2.setPointSize(9);
        username->setFont(font2);

        verticalLayout->addWidget(username);

        password = new QLabel(layoutWidget);
        password->setObjectName(QString::fromUtf8("password"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        password->setPalette(palette1);
        password->setFont(font2);

        verticalLayout->addWidget(password);

        enter_or_signup = new QLabel(LoginPage);
        enter_or_signup->setObjectName(QString::fromUtf8("enter_or_signup"));
        enter_or_signup->setGeometry(QRect(860, 300, 154, 57));
        enter_or_signup->setStyleSheet(QString::fromUtf8("font: 18pt \"B Homa\";\n"
"color: rgb(0, 0, 0);"));
        logo_fa = new QLabel(LoginPage);
        logo_fa->setObjectName(QString::fromUtf8("logo_fa"));
        logo_fa->setGeometry(QRect(680, 120, 143, 139));
        QFont font3;
        font3.setFamily(QString::fromUtf8("B Arshia"));
        font3.setPointSize(72);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        logo_fa->setFont(font3);
        logo_fa->setStyleSheet(QString::fromUtf8("font: 72pt \"B Arshia\";\n"
"color: rgb(255, 0, 0);"));
        logo_en = new QLabel(LoginPage);
        logo_en->setObjectName(QString::fromUtf8("logo_en"));
        logo_en->setGeometry(QRect(710, 240, 87, 57));
        logo_en->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 26pt \"Pristina\";"));
        back = new QCommandLinkButton(LoginPage);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(10, 30, 80, 40));
        QFont font4;
        font4.setPointSize(7);
        back->setFont(font4);
        back->setStyleSheet(QString::fromUtf8(""));
        layoutWidget1 = new QWidget(LoginPage);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(707, 540, 241, 52));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        show_password = new QCheckBox(layoutWidget1);
        show_password->setObjectName(QString::fromUtf8("show_password"));
        show_password->setLayoutDirection(Qt::RightToLeft);
        show_password->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(show_password);

        save_login_info = new QCheckBox(layoutWidget1);
        save_login_info->setObjectName(QString::fromUtf8("save_login_info"));
        save_login_info->setLayoutDirection(Qt::RightToLeft);
        save_login_info->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(save_login_info);

        layoutWidget2 = new QWidget(LoginPage);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(706, 700, 321, 62));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        username_or_password_is_wrong = new QLabel(layoutWidget2);
        username_or_password_is_wrong->setObjectName(QString::fromUtf8("username_or_password_is_wrong"));
        username_or_password_is_wrong->setLayoutDirection(Qt::RightToLeft);
        username_or_password_is_wrong->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        verticalLayout_3->addWidget(username_or_password_is_wrong);

        username_is_empty = new QLabel(layoutWidget2);
        username_is_empty->setObjectName(QString::fromUtf8("username_is_empty"));
        username_is_empty->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        verticalLayout_3->addWidget(username_is_empty);

        password_is_empty = new QLabel(layoutWidget2);
        password_is_empty->setObjectName(QString::fromUtf8("password_is_empty"));
        password_is_empty->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        verticalLayout_3->addWidget(password_is_empty);


        retranslateUi(LoginPage);

        QMetaObject::connectSlotsByName(LoginPage);
    } // setupUi

    void retranslateUi(QWidget *LoginPage)
    {
        LoginPage->setWindowTitle(QCoreApplication::translate("LoginPage", "Form", nullptr));
        signup_button->setText(QCoreApplication::translate("LoginPage", "\330\253\330\250\330\252 \331\206\330\247\331\205", nullptr));
        enter_button->setText(QCoreApplication::translate("LoginPage", "\331\210\330\261\331\210\330\257", nullptr));
        username->setText(QCoreApplication::translate("LoginPage", "\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214:", nullptr));
        password->setText(QCoreApplication::translate("LoginPage", "\332\251\331\204\331\205\331\207 \330\271\330\250\331\210\330\261:", nullptr));
        enter_or_signup->setText(QCoreApplication::translate("LoginPage", "\331\210\330\261\331\210\330\257 / \330\253\330\250\330\252 \331\206\330\247\331\205", nullptr));
        logo_fa->setText(QCoreApplication::translate("LoginPage", "\330\242\331\206\332\251\330\252", nullptr));
        logo_en->setText(QCoreApplication::translate("LoginPage", "Onket", nullptr));
        back->setText(QCoreApplication::translate("LoginPage", "\330\250\330\247\330\262\332\257\330\264\330\252", nullptr));
        show_password->setText(QCoreApplication::translate("LoginPage", "\331\206\331\205\330\247\333\214\330\264 \332\251\331\204\331\205\331\207 \330\271\330\250\331\210\330\261", nullptr));
        save_login_info->setText(QCoreApplication::translate("LoginPage", "\330\260\330\256\333\214\330\261\331\207 \330\247\330\267\331\204\330\247\330\271\330\247\330\252 \332\251\330\247\330\261\330\250\330\261", nullptr));
        username_or_password_is_wrong->setText(QString());
        username_is_empty->setText(QString());
        password_is_empty->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginPage: public Ui_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H

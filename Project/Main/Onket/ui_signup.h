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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signup
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *username_line_edit;
    QLabel *label_3;
    QLineEdit *password_line_edit;
    QLabel *label_4;
    QLineEdit *repeat_password_line_edit;
    QCheckBox *show_password;
    QPushButton *signup_button;
    QCommandLinkButton *back;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_5;

    void setupUi(QWidget *signup)
    {
        if (signup->objectName().isEmpty())
            signup->setObjectName(QString::fromUtf8("signup"));
        signup->resize(1500, 800);
        label = new QLabel(signup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(675, 105, 111, 51));
        label->setStyleSheet(QString::fromUtf8("font: 24pt \"B Homa\";\n"
"color: rgb(255, 0, 0);"));
        label_2 = new QLabel(signup);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(930, 195, 151, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 15pt \"B Nazanin\";\n"
"color: rgb(0, 0, 0);"));
        username_line_edit = new QLineEdit(signup);
        username_line_edit->setObjectName(QString::fromUtf8("username_line_edit"));
        username_line_edit->setGeometry(QRect(510, 193, 421, 41));
        label_3 = new QLabel(signup);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(940, 270, 81, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 15pt \"B Nazanin\";\n"
"color: rgb(0, 0, 0);"));
        password_line_edit = new QLineEdit(signup);
        password_line_edit->setObjectName(QString::fromUtf8("password_line_edit"));
        password_line_edit->setGeometry(QRect(510, 270, 421, 41));
        label_4 = new QLabel(signup);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(940, 350, 121, 21));
        label_4->setStyleSheet(QString::fromUtf8("font: 15pt \"B Nazanin\";\n"
"color: rgb(0, 0, 0);"));
        repeat_password_line_edit = new QLineEdit(signup);
        repeat_password_line_edit->setObjectName(QString::fromUtf8("repeat_password_line_edit"));
        repeat_password_line_edit->setGeometry(QRect(510, 340, 421, 41));
        show_password = new QCheckBox(signup);
        show_password->setObjectName(QString::fromUtf8("show_password"));
        show_password->setGeometry(QRect(752, 420, 171, 22));
        show_password->setLayoutDirection(Qt::RightToLeft);
        signup_button = new QPushButton(signup);
        signup_button->setObjectName(QString::fromUtf8("signup_button"));
        signup_button->setGeometry(QRect(660, 630, 151, 51));
        signup_button->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 47, 47);"));
        back = new QCommandLinkButton(signup);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(10, 30, 80, 40));
        QFont font;
        font.setPointSize(7);
        back->setFont(font);
        layoutWidget = new QWidget(signup);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(510, 480, 421, 84));
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


        retranslateUi(signup);

        QMetaObject::connectSlotsByName(signup);
    } // setupUi

    void retranslateUi(QWidget *signup)
    {
        signup->setWindowTitle(QCoreApplication::translate("signup", "Form", nullptr));
        label->setText(QCoreApplication::translate("signup", "\330\253\330\250\330\252 \331\206\330\247\331\205", nullptr));
        label_2->setText(QCoreApplication::translate("signup", "\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214(\330\247\333\214\331\205\333\214\331\204):", nullptr));
        label_3->setText(QCoreApplication::translate("signup", "\332\251\331\204\331\205\331\207 \330\271\330\250\331\210\330\261:", nullptr));
        label_4->setText(QCoreApplication::translate("signup", "\330\252\332\251\330\261\330\247\330\261 \332\251\331\204\331\205\331\207 \330\271\330\250\331\210\330\261:", nullptr));
        show_password->setText(QCoreApplication::translate("signup", "\332\251\331\204\331\205\331\207 \330\271\330\250\331\210\330\261 \331\206\331\205\330\247\330\264 \330\257\330\247\330\257\331\207 \330\264\331\210\330\257", nullptr));
        signup_button->setText(QCoreApplication::translate("signup", "\330\253\330\250\330\252 \331\206\330\247\331\205", nullptr));
        back->setText(QCoreApplication::translate("signup", "\330\250\330\247\330\262\332\257\330\264\330\252", nullptr));
        layoutWidget->setStyleSheet(QCoreApplication::translate("signup", "color: rgb(255, 0, 0);", nullptr));
        label_7->setStyleSheet(QCoreApplication::translate("signup", "color: rgb(255, 0, 0);", nullptr));
        label_7->setText(QString());
        label_6->setStyleSheet(QCoreApplication::translate("signup", "color: rgb(255, 0, 0);", nullptr));
        label_6->setText(QString());
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class signup: public Ui_signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H

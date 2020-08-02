/********************************************************************************
** Form generated from reading UI file 'loginpage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
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
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_4;
    QCommandLinkButton *commandLinkButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;

    void setupUi(QWidget *LoginPage)
    {
        if (LoginPage->objectName().isEmpty())
            LoginPage->setObjectName(QString::fromUtf8("LoginPage"));
        LoginPage->resize(1500, 800);
        pushButton = new QPushButton(LoginPage);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(750, 620, 150, 50));
        QFont font;
        font.setPointSize(11);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(LoginPage);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(600, 620, 150, 50));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 47, 47);"));
        lineEdit = new QLineEdit(LoginPage);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(510, 393, 441, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial Narrow"));
        font1.setPointSize(14);
        lineEdit->setFont(font1);
        lineEdit->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(255, 111, 111);"));
        lineEdit_2 = new QLineEdit(LoginPage);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(510, 463, 441, 51));
        lineEdit_2->setFont(font1);
        lineEdit_2->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(255, 111, 111);"));
        lineEdit_2->setEchoMode(QLineEdit::PasswordEchoOnEdit);
        layoutWidget = new QWidget(LoginPage);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(960, 380, 71, 141));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 127));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label->setPalette(palette);
        QFont font2;
        font2.setPointSize(9);
        label->setFont(font2);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_2->setPalette(palette1);
        label_2->setFont(font2);

        verticalLayout->addWidget(label_2);

        label_5 = new QLabel(LoginPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(860, 300, 154, 57));
        label_5->setStyleSheet(QString::fromUtf8("font: 18pt \"B Homa\";\n"
"color: rgb(0, 0, 0);"));
        label_3 = new QLabel(LoginPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(680, 120, 143, 139));
        QFont font3;
        font3.setFamily(QString::fromUtf8("B Arshia"));
        font3.setPointSize(72);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        label_3->setFont(font3);
        label_3->setStyleSheet(QString::fromUtf8("font: 72pt \"B Arshia\";\n"
"color: rgb(255, 0, 0);"));
        label_4 = new QLabel(LoginPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(710, 240, 87, 57));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"font: 26pt \"Pristina\";"));
        commandLinkButton = new QCommandLinkButton(LoginPage);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(10, 30, 30, 40));
        QFont font4;
        font4.setPointSize(7);
        commandLinkButton->setFont(font4);
        commandLinkButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        layoutWidget1 = new QWidget(LoginPage);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(707, 540, 241, 52));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBox = new QCheckBox(layoutWidget1);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setLayoutDirection(Qt::RightToLeft);
        checkBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(checkBox);

        checkBox_2 = new QCheckBox(layoutWidget1);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setLayoutDirection(Qt::RightToLeft);
        checkBox_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout_2->addWidget(checkBox_2);


        retranslateUi(LoginPage);

        QMetaObject::connectSlotsByName(LoginPage);
    } // setupUi

    void retranslateUi(QWidget *LoginPage)
    {
        LoginPage->setWindowTitle(QCoreApplication::translate("LoginPage", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("LoginPage", "\330\253\330\250\330\252 \331\206\330\247\331\205", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LoginPage", "\331\210\330\261\331\210\330\257", nullptr));
        label->setText(QCoreApplication::translate("LoginPage", "\331\206\330\247\331\205 \332\251\330\247\330\261\330\250\330\261\333\214:", nullptr));
        label_2->setText(QCoreApplication::translate("LoginPage", "\332\251\331\204\331\205\331\207 \330\271\330\250\331\210\330\261:", nullptr));
        label_5->setText(QCoreApplication::translate("LoginPage", "\331\210\330\261\331\210\330\257 / \330\253\330\250\330\252 \331\206\330\247\331\205", nullptr));
        label_3->setText(QCoreApplication::translate("LoginPage", "\330\242\331\206\332\251\330\252", nullptr));
        label_4->setText(QCoreApplication::translate("LoginPage", "Onket", nullptr));
        commandLinkButton->setText(QString());
        checkBox->setText(QCoreApplication::translate("LoginPage", "\331\206\331\205\330\247\333\214\330\264 \332\251\331\204\331\205\331\207 \330\271\330\250\331\210\330\261", nullptr));
        checkBox_2->setText(QCoreApplication::translate("LoginPage", "\330\260\330\256\333\214\330\261\331\207 \330\247\330\267\331\204\330\247\330\271\330\247\330\252 \332\251\330\247\330\261\330\250\330\261", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginPage: public Ui_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H

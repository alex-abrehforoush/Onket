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
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QCommandLinkButton *commandLinkButton;
    QWidget *widget;
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
        label_2->setGeometry(QRect(930, 195, 61, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 15pt \"B Nazanin\";\n"
"color: rgb(0, 0, 0);"));
        lineEdit = new QLineEdit(signup);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(510, 193, 421, 41));
        label_3 = new QLabel(signup);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(940, 270, 81, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 15pt \"B Nazanin\";\n"
"color: rgb(0, 0, 0);"));
        lineEdit_2 = new QLineEdit(signup);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(510, 270, 421, 41));
        label_4 = new QLabel(signup);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(940, 350, 121, 21));
        label_4->setStyleSheet(QString::fromUtf8("font: 15pt \"B Nazanin\";\n"
"color: rgb(0, 0, 0);"));
        lineEdit_3 = new QLineEdit(signup);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(510, 340, 421, 41));
        checkBox = new QCheckBox(signup);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(752, 420, 171, 22));
        checkBox->setLayoutDirection(Qt::RightToLeft);
        pushButton = new QPushButton(signup);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(660, 630, 151, 51));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 47, 47);"));
        commandLinkButton = new QCommandLinkButton(signup);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(10, 30, 80, 40));
        QFont font;
        font.setPointSize(7);
        commandLinkButton->setFont(font);
        widget = new QWidget(signup);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(510, 480, 421, 84));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        label_5 = new QLabel(widget);
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
        label_2->setText(QCoreApplication::translate("signup", "\330\247\333\214\331\205\333\214\331\204:", nullptr));
        label_3->setText(QCoreApplication::translate("signup", "\332\251\331\204\331\205\331\207 \330\271\330\250\331\210\330\261:", nullptr));
        label_4->setText(QCoreApplication::translate("signup", "\330\252\332\251\330\261\330\247\330\261 \332\251\331\204\331\205\331\207 \330\271\330\250\331\210\330\261:", nullptr));
        checkBox->setText(QCoreApplication::translate("signup", "\332\251\331\204\331\205\331\207 \330\271\330\250\331\210\330\261 \331\206\331\205\330\247\330\264 \330\257\330\247\330\257\331\207 \330\264\331\210\330\257", nullptr));
        pushButton->setText(QCoreApplication::translate("signup", "\330\253\330\250\330\252 \331\206\330\247\331\205", nullptr));
        commandLinkButton->setText(QCoreApplication::translate("signup", "\330\250\330\247\330\262\332\257\330\264\330\252", nullptr));
        widget->setStyleSheet(QCoreApplication::translate("signup", "color: rgb(255, 0, 0);", nullptr));
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

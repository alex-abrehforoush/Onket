/********************************************************************************
** Form generated from reading UI file 'questionviewitem.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONVIEWITEM_H
#define UI_QUESTIONVIEWITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuestionViewItem
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *lab_date;
    QLabel *lab_reply_number;
    QPushButton *bnt_icon;
    QCommandLinkButton *bnt_add_reply;
    QPushButton *bnt_show_replys;
    QTextEdit *txt_content;

    void setupUi(QWidget *QuestionViewItem)
    {
        if (QuestionViewItem->objectName().isEmpty())
            QuestionViewItem->setObjectName(QString::fromUtf8("QuestionViewItem"));
        QuestionViewItem->resize(1267, 397);
        QuestionViewItem->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        layoutWidget = new QWidget(QuestionViewItem);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 60, 1061, 211));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lab_date = new QLabel(layoutWidget);
        lab_date->setObjectName(QString::fromUtf8("lab_date"));
        lab_date->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);\n"
"font: 10pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(lab_date, 2, 3, 1, 1);

        lab_reply_number = new QLabel(layoutWidget);
        lab_reply_number->setObjectName(QString::fromUtf8("lab_reply_number"));
        lab_reply_number->setStyleSheet(QString::fromUtf8("font: 9pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(lab_reply_number, 0, 0, 1, 1);

        bnt_icon = new QPushButton(layoutWidget);
        bnt_icon->setObjectName(QString::fromUtf8("bnt_icon"));
        bnt_icon->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(bnt_icon, 1, 3, 1, 1);

        bnt_add_reply = new QCommandLinkButton(layoutWidget);
        bnt_add_reply->setObjectName(QString::fromUtf8("bnt_add_reply"));
        bnt_add_reply->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));

        gridLayout->addWidget(bnt_add_reply, 2, 0, 1, 1);

        bnt_show_replys = new QPushButton(layoutWidget);
        bnt_show_replys->setObjectName(QString::fromUtf8("bnt_show_replys"));
        bnt_show_replys->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 255);\n"
"color: rgb(255, 255, 255);\n"
"font: 9pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(bnt_show_replys, 1, 0, 1, 1);

        txt_content = new QTextEdit(layoutWidget);
        txt_content->setObjectName(QString::fromUtf8("txt_content"));
        txt_content->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";\n"
"background-color: rgb(170, 255, 255);"));

        gridLayout->addWidget(txt_content, 0, 2, 3, 1);


        retranslateUi(QuestionViewItem);

        QMetaObject::connectSlotsByName(QuestionViewItem);
    } // setupUi

    void retranslateUi(QWidget *QuestionViewItem)
    {
        QuestionViewItem->setWindowTitle(QCoreApplication::translate("QuestionViewItem", "Form", nullptr));
        lab_date->setText(QCoreApplication::translate("QuestionViewItem", "TextLabel", nullptr));
        lab_reply_number->setText(QCoreApplication::translate("QuestionViewItem", "TextLabel", nullptr));
        bnt_icon->setText(QString());
        bnt_add_reply->setText(QCoreApplication::translate("QuestionViewItem", "\330\250\331\207 \330\247\333\214\331\206 \330\263\331\210\330\247\331\204 \331\276\330\247 \330\263\330\256 \330\257\331\207\333\214\330\257", nullptr));
        bnt_show_replys->setText(QCoreApplication::translate("QuestionViewItem", "\331\206\331\205\330\247\333\214\330\264 \331\276\330\247\330\263\330\256 \331\207\330\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuestionViewItem: public Ui_QuestionViewItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONVIEWITEM_H

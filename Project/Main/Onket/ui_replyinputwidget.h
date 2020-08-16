/********************************************************************************
** Form generated from reading UI file 'replyinputwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLYINPUTWIDGET_H
#define UI_REPLYINPUTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReplyInputWidget
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QTextEdit *txt_question;
    QPushButton *bnt_icon_question;
    QTextEdit *txt_reply;
    QPushButton *bnt_icon_reply;
    QPushButton *bnt_cancel;
    QPushButton *bnt_ok;

    void setupUi(QWidget *ReplyInputWidget)
    {
        if (ReplyInputWidget->objectName().isEmpty())
            ReplyInputWidget->setObjectName(QString::fromUtf8("ReplyInputWidget"));
        ReplyInputWidget->resize(816, 543);
        ReplyInputWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        widget = new QWidget(ReplyInputWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(85, 50, 671, 351));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        txt_question = new QTextEdit(widget);
        txt_question->setObjectName(QString::fromUtf8("txt_question"));
        txt_question->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(txt_question, 0, 1, 1, 1);

        bnt_icon_question = new QPushButton(widget);
        bnt_icon_question->setObjectName(QString::fromUtf8("bnt_icon_question"));
        bnt_icon_question->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(bnt_icon_question, 0, 2, 1, 1);

        txt_reply = new QTextEdit(widget);
        txt_reply->setObjectName(QString::fromUtf8("txt_reply"));
        txt_reply->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(txt_reply, 1, 1, 1, 1);

        bnt_icon_reply = new QPushButton(widget);
        bnt_icon_reply->setObjectName(QString::fromUtf8("bnt_icon_reply"));
        bnt_icon_reply->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(bnt_icon_reply, 1, 2, 1, 1);

        bnt_cancel = new QPushButton(widget);
        bnt_cancel->setObjectName(QString::fromUtf8("bnt_cancel"));
        bnt_cancel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(bnt_cancel, 2, 0, 1, 1);

        bnt_ok = new QPushButton(widget);
        bnt_ok->setObjectName(QString::fromUtf8("bnt_ok"));
        bnt_ok->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(bnt_ok, 2, 1, 1, 1);


        retranslateUi(ReplyInputWidget);

        QMetaObject::connectSlotsByName(ReplyInputWidget);
    } // setupUi

    void retranslateUi(QWidget *ReplyInputWidget)
    {
        ReplyInputWidget->setWindowTitle(QCoreApplication::translate("ReplyInputWidget", "Form", nullptr));
        bnt_icon_question->setText(QString());
        bnt_icon_reply->setText(QString());
        bnt_cancel->setText(QCoreApplication::translate("ReplyInputWidget", "\330\247\331\206\330\265\330\261\330\247\331\201", nullptr));
        bnt_ok->setText(QCoreApplication::translate("ReplyInputWidget", "\330\253\330\250\330\252 \331\276\330\247\330\263\330\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReplyInputWidget: public Ui_ReplyInputWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLYINPUTWIDGET_H

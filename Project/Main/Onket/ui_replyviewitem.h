/********************************************************************************
** Form generated from reading UI file 'replyviewitem.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLYVIEWITEM_H
#define UI_REPLYVIEWITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReplyViewItem
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *bnt_dislike;
    QPushButton *bnt_like;
    QLabel *label_3;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *lab_date;
    QTextEdit *txt_content;
    QLabel *lab_sender;
    QLabel *label;
    QPushButton *bnt_icon;

    void setupUi(QWidget *ReplyViewItem)
    {
        if (ReplyViewItem->objectName().isEmpty())
            ReplyViewItem->setObjectName(QString::fromUtf8("ReplyViewItem"));
        ReplyViewItem->resize(656, 344);
        ReplyViewItem->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        layoutWidget = new QWidget(ReplyViewItem);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 250, 571, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        bnt_dislike = new QPushButton(layoutWidget);
        bnt_dislike->setObjectName(QString::fromUtf8("bnt_dislike"));
        bnt_dislike->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);"));

        horizontalLayout_2->addWidget(bnt_dislike);

        bnt_like = new QPushButton(layoutWidget);
        bnt_like->setObjectName(QString::fromUtf8("bnt_like"));
        bnt_like->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);"));

        horizontalLayout_2->addWidget(bnt_like);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        layoutWidget1 = new QWidget(ReplyViewItem);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(40, 20, 571, 221));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lab_date = new QLabel(layoutWidget1);
        lab_date->setObjectName(QString::fromUtf8("lab_date"));
        lab_date->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));

        gridLayout->addWidget(lab_date, 0, 0, 1, 1);

        txt_content = new QTextEdit(layoutWidget1);
        txt_content->setObjectName(QString::fromUtf8("txt_content"));
        txt_content->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(txt_content, 0, 1, 2, 1);

        lab_sender = new QLabel(layoutWidget1);
        lab_sender->setObjectName(QString::fromUtf8("lab_sender"));
        lab_sender->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));

        gridLayout->addWidget(lab_sender, 1, 0, 1, 1);

        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label, 1, 2, 1, 1);

        bnt_icon = new QPushButton(layoutWidget1);
        bnt_icon->setObjectName(QString::fromUtf8("bnt_icon"));
        bnt_icon->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(bnt_icon, 0, 2, 1, 1);


        retranslateUi(ReplyViewItem);

        QMetaObject::connectSlotsByName(ReplyViewItem);
    } // setupUi

    void retranslateUi(QWidget *ReplyViewItem)
    {
        ReplyViewItem->setWindowTitle(QCoreApplication::translate("ReplyViewItem", "Form", nullptr));
        bnt_dislike->setText(QString());
        bnt_like->setText(QString());
        label_3->setText(QCoreApplication::translate("ReplyViewItem", "\330\242\333\214\330\247 \330\247\333\214\331\206 \331\276\330\247\330\263\330\256 \330\250\330\261\330\247\333\214 \330\264\331\205\330\247 \331\205\331\201\333\214\330\257 \330\250\331\210\330\257\330\237", nullptr));
        lab_date->setText(QCoreApplication::translate("ReplyViewItem", "TextLabel", nullptr));
        lab_sender->setText(QCoreApplication::translate("ReplyViewItem", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("ReplyViewItem", " \331\276\330\247\330\263\330\256 ", nullptr));
        bnt_icon->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ReplyViewItem: public Ui_ReplyViewItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLYVIEWITEM_H

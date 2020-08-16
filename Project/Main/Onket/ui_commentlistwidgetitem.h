/********************************************************************************
** Form generated from reading UI file 'commentlistwidgetitem.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMENTLISTWIDGETITEM_H
#define UI_COMMENTLISTWIDGETITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommentListWidgetItem
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QTextEdit *txt_description;
    QLabel *lab_disadv_content;
    QLabel *lab_adv_content;
    QLabel *lab_disadv;
    QLabel *lab_adv;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QPushButton *bnt_dislike;
    QPushButton *bnt_like;
    QLabel *label_5;

    void setupUi(QWidget *CommentListWidgetItem)
    {
        if (CommentListWidgetItem->objectName().isEmpty())
            CommentListWidgetItem->setObjectName(QString::fromUtf8("CommentListWidgetItem"));
        CommentListWidgetItem->resize(570, 255);
        CommentListWidgetItem->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        layoutWidget = new QWidget(CommentListWidgetItem);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 501, 138));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        txt_description = new QTextEdit(layoutWidget);
        txt_description->setObjectName(QString::fromUtf8("txt_description"));
        txt_description->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);\n"
"font: 75 8pt \"8514oem\";\n"
"font: 12pt \"8514oem\";\n"
"font: 12pt \"MS UI Gothic\";\n"
"font: 75 10pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(txt_description, 0, 0, 1, 2);

        lab_disadv_content = new QLabel(layoutWidget);
        lab_disadv_content->setObjectName(QString::fromUtf8("lab_disadv_content"));
        lab_disadv_content->setStyleSheet(QString::fromUtf8("font: 75 10pt \"MS Shell Dlg 2\";\n"
"background-color: rgb(255, 226, 233);\n"
"gridline-color: rgb(0, 255, 0);"));

        gridLayout->addWidget(lab_disadv_content, 2, 0, 1, 1);

        lab_adv_content = new QLabel(layoutWidget);
        lab_adv_content->setObjectName(QString::fromUtf8("lab_adv_content"));
        lab_adv_content->setStyleSheet(QString::fromUtf8("font: 75 10pt \"MS Shell Dlg 2\";\n"
"background-color: rgb(202, 255, 202);"));

        gridLayout->addWidget(lab_adv_content, 2, 1, 1, 1);

        lab_disadv = new QLabel(layoutWidget);
        lab_disadv->setObjectName(QString::fromUtf8("lab_disadv"));
        lab_disadv->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(255, 0, 0);"));

        gridLayout->addWidget(lab_disadv, 1, 0, 1, 1);

        lab_adv = new QLabel(layoutWidget);
        lab_adv->setObjectName(QString::fromUtf8("lab_adv"));
        lab_adv->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 255, 0);"));

        gridLayout->addWidget(lab_adv, 1, 1, 1, 1);

        layoutWidget1 = new QWidget(CommentListWidgetItem);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 170, 491, 30));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        bnt_dislike = new QPushButton(layoutWidget1);
        bnt_dislike->setObjectName(QString::fromUtf8("bnt_dislike"));
        bnt_dislike->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);"));

        gridLayout_2->addWidget(bnt_dislike, 0, 0, 1, 1);

        bnt_like = new QPushButton(layoutWidget1);
        bnt_like->setObjectName(QString::fromUtf8("bnt_like"));
        bnt_like->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 170, 255);"));

        gridLayout_2->addWidget(bnt_like, 0, 1, 1, 1);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 2, 1, 1);


        retranslateUi(CommentListWidgetItem);

        QMetaObject::connectSlotsByName(CommentListWidgetItem);
    } // setupUi

    void retranslateUi(QWidget *CommentListWidgetItem)
    {
        CommentListWidgetItem->setWindowTitle(QCoreApplication::translate("CommentListWidgetItem", "Form", nullptr));
        txt_description->setHtml(QCoreApplication::translate("CommentListWidgetItem", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:10pt; font-weight:72; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:7.8pt; font-weight:400;\">\331\205\330\255\330\252\331\210\330\247\333\214 \331\205\330\252\331\206</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:7.8pt; font-weight:400;\"><br /></p></body></html>", nullptr));
        lab_disadv_content->setText(QCoreApplication::translate("CommentListWidgetItem", "\331\205\330\271\330\247\333\214\330\250", nullptr));
        lab_adv_content->setText(QCoreApplication::translate("CommentListWidgetItem", "\331\205\330\262\330\247\333\214\330\247 ", nullptr));
        lab_disadv->setText(QCoreApplication::translate("CommentListWidgetItem", "\331\206\331\202\330\247\330\267 \330\266\330\271\331\201", nullptr));
        lab_adv->setText(QCoreApplication::translate("CommentListWidgetItem", "\331\206\331\202\330\247\330\267 \331\202\331\210\330\252", nullptr));
        bnt_dislike->setText(QString());
        bnt_like->setText(QString());
        label_5->setText(QCoreApplication::translate("CommentListWidgetItem", "\330\247\333\214\330\247 \330\247\333\214\331\206 \331\206\330\270\330\261 \330\261\330\247 \331\205\333\214 \331\276\330\263\331\206\330\257\333\214\330\257\330\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommentListWidgetItem: public Ui_CommentListWidgetItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMENTLISTWIDGETITEM_H

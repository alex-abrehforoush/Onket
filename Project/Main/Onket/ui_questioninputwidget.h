/********************************************************************************
** Form generated from reading UI file 'questioninputwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONINPUTWIDGET_H
#define UI_QUESTIONINPUTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuestionInputWidget
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QTextEdit *txt_content;
    QPushButton *bnt_ok;
    QPushButton *bnt_cancel;

    void setupUi(QWidget *QuestionInputWidget)
    {
        if (QuestionInputWidget->objectName().isEmpty())
            QuestionInputWidget->setObjectName(QString::fromUtf8("QuestionInputWidget"));
        QuestionInputWidget->resize(874, 237);
        QuestionInputWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        widget = new QWidget(QuestionInputWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 10, 741, 191));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        txt_content = new QTextEdit(widget);
        txt_content->setObjectName(QString::fromUtf8("txt_content"));
        txt_content->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(txt_content, 0, 0, 1, 2);

        bnt_ok = new QPushButton(widget);
        bnt_ok->setObjectName(QString::fromUtf8("bnt_ok"));
        bnt_ok->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);\n"
"color: rgb(0, 0, 0);"));

        gridLayout->addWidget(bnt_ok, 1, 0, 1, 1);

        bnt_cancel = new QPushButton(widget);
        bnt_cancel->setObjectName(QString::fromUtf8("bnt_cancel"));
        bnt_cancel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(bnt_cancel, 1, 1, 1, 1);


        retranslateUi(QuestionInputWidget);

        QMetaObject::connectSlotsByName(QuestionInputWidget);
    } // setupUi

    void retranslateUi(QWidget *QuestionInputWidget)
    {
        QuestionInputWidget->setWindowTitle(QCoreApplication::translate("QuestionInputWidget", "Form", nullptr));
        bnt_ok->setText(QCoreApplication::translate("QuestionInputWidget", "\330\253\330\250\330\252 \331\276\330\261\330\263\330\264", nullptr));
        bnt_cancel->setText(QCoreApplication::translate("QuestionInputWidget", "\330\247\331\206\330\265\330\261\330\247\331\201 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuestionInputWidget: public Ui_QuestionInputWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONINPUTWIDGET_H

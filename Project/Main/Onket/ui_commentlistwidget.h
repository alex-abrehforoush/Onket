/********************************************************************************
** Form generated from reading UI file 'commentlistwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMENTLISTWIDGET_H
#define UI_COMMENTLISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>

QT_BEGIN_NAMESPACE

class Ui_CommentListWidget
{
public:

    void setupUi(QScrollArea *CommentListWidget)
    {
        if (CommentListWidget->objectName().isEmpty())
            CommentListWidget->setObjectName(QString::fromUtf8("CommentListWidget"));
        CommentListWidget->resize(400, 300);
        CommentListWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        retranslateUi(CommentListWidget);

        QMetaObject::connectSlotsByName(CommentListWidget);
    } // setupUi

    void retranslateUi(QScrollArea *CommentListWidget)
    {
        CommentListWidget->setWindowTitle(QCoreApplication::translate("CommentListWidget", "ScrollArea", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommentListWidget: public Ui_CommentListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMENTLISTWIDGET_H

/********************************************************************************
** Form generated from reading UI file 'discussionlistwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISCUSSIONLISTWIDGET_H
#define UI_DISCUSSIONLISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>

QT_BEGIN_NAMESPACE

class Ui_DiscussionListWidget
{
public:

    void setupUi(QScrollArea *DiscussionListWidget)
    {
        if (DiscussionListWidget->objectName().isEmpty())
            DiscussionListWidget->setObjectName(QString::fromUtf8("DiscussionListWidget"));
        DiscussionListWidget->resize(400, 300);
        DiscussionListWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        retranslateUi(DiscussionListWidget);

        QMetaObject::connectSlotsByName(DiscussionListWidget);
    } // setupUi

    void retranslateUi(QScrollArea *DiscussionListWidget)
    {
        DiscussionListWidget->setWindowTitle(QCoreApplication::translate("DiscussionListWidget", "ScrollArea", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DiscussionListWidget: public Ui_DiscussionListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISCUSSIONLISTWIDGET_H

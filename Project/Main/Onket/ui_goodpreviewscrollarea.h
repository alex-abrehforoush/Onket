/********************************************************************************
** Form generated from reading UI file 'goodpreviewscrollarea.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOODPREVIEWSCROLLAREA_H
#define UI_GOODPREVIEWSCROLLAREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>

QT_BEGIN_NAMESPACE

class Ui_GoodPreviewScrollArea
{
public:

    void setupUi(QScrollArea *GoodPreviewScrollArea)
    {
        if (GoodPreviewScrollArea->objectName().isEmpty())
            GoodPreviewScrollArea->setObjectName(QString::fromUtf8("GoodPreviewScrollArea"));
        GoodPreviewScrollArea->resize(400, 300);
        GoodPreviewScrollArea->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        retranslateUi(GoodPreviewScrollArea);

        QMetaObject::connectSlotsByName(GoodPreviewScrollArea);
    } // setupUi

    void retranslateUi(QScrollArea *GoodPreviewScrollArea)
    {
        GoodPreviewScrollArea->setWindowTitle(QCoreApplication::translate("GoodPreviewScrollArea", "ScrollArea", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GoodPreviewScrollArea: public Ui_GoodPreviewScrollArea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOODPREVIEWSCROLLAREA_H

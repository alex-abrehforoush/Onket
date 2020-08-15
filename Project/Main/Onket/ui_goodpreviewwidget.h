/********************************************************************************
** Form generated from reading UI file 'goodpreviewwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOODPREVIEWWIDGET_H
#define UI_GOODPREVIEWWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GoodPreviewWidget
{
public:
    QLabel *lab_img;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *lab_final_price;
    QLabel *lab_discount;
    QLabel *lab_price;

    void setupUi(QWidget *GoodPreviewWidget)
    {
        if (GoodPreviewWidget->objectName().isEmpty())
            GoodPreviewWidget->setObjectName(QString::fromUtf8("GoodPreviewWidget"));
        GoodPreviewWidget->resize(332, 333);
        GoodPreviewWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 239, 239);"));
        lab_img = new QLabel(GoodPreviewWidget);
        lab_img->setObjectName(QString::fromUtf8("lab_img"));
        lab_img->setGeometry(QRect(30, 10, 281, 211));
        lab_img->setStyleSheet(QString::fromUtf8("font: 12pt \"Myanmar Text\";\n"
"background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"\n"
""));
        widget = new QWidget(GoodPreviewWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 230, 171, 81));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lab_final_price = new QLabel(widget);
        lab_final_price->setObjectName(QString::fromUtf8("lab_final_price"));
        lab_final_price->setStyleSheet(QString::fromUtf8("font: 75 10pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(lab_final_price, 2, 0, 1, 1);

        lab_discount = new QLabel(widget);
        lab_discount->setObjectName(QString::fromUtf8("lab_discount"));
        lab_discount->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"font: 75 13pt \"Agency FB\";"));

        gridLayout->addWidget(lab_discount, 0, 0, 1, 1);

        lab_price = new QLabel(widget);
        lab_price->setObjectName(QString::fromUtf8("lab_price"));
        lab_price->setStyleSheet(QString::fromUtf8("color: rgb(122, 122, 122);\n"
"font: 10pt \"MS UI Gothic\";\n"
"text-decoration: line-through;"));

        gridLayout->addWidget(lab_price, 1, 0, 1, 1);


        retranslateUi(GoodPreviewWidget);

        QMetaObject::connectSlotsByName(GoodPreviewWidget);
    } // setupUi

    void retranslateUi(QWidget *GoodPreviewWidget)
    {
        GoodPreviewWidget->setWindowTitle(QCoreApplication::translate("GoodPreviewWidget", "Form", nullptr));
        lab_img->setText(QCoreApplication::translate("GoodPreviewWidget", "TextLabel", nullptr));
        lab_final_price->setText(QCoreApplication::translate("GoodPreviewWidget", "TextLabel", nullptr));
        lab_discount->setText(QCoreApplication::translate("GoodPreviewWidget", "20%", nullptr));
        lab_price->setText(QCoreApplication::translate("GoodPreviewWidget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GoodPreviewWidget: public Ui_GoodPreviewWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOODPREVIEWWIDGET_H

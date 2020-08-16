/********************************************************************************
** Form generated from reading UI file 'commentwidgetfield.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMENTWIDGETFIELD_H
#define UI_COMMENTWIDGETFIELD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommentWidgetField
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *bnt_level;
    QSlider *horizontalSlider;
    QLabel *lab_field_name;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *CommentWidgetField)
    {
        if (CommentWidgetField->objectName().isEmpty())
            CommentWidgetField->setObjectName(QString::fromUtf8("CommentWidgetField"));
        CommentWidgetField->resize(441, 135);
        widget = new QWidget(CommentWidgetField);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 50, 431, 52));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        bnt_level = new QPushButton(widget);
        bnt_level->setObjectName(QString::fromUtf8("bnt_level"));
        bnt_level->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 255);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(bnt_level, 0, 0, 1, 1);

        horizontalSlider = new QSlider(widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 0, 2, 1, 1);

        lab_field_name = new QLabel(widget);
        lab_field_name->setObjectName(QString::fromUtf8("lab_field_name"));
        lab_field_name->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        gridLayout->addWidget(lab_field_name, 0, 4, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);


        retranslateUi(CommentWidgetField);

        QMetaObject::connectSlotsByName(CommentWidgetField);
    } // setupUi

    void retranslateUi(QWidget *CommentWidgetField)
    {
        CommentWidgetField->setWindowTitle(QCoreApplication::translate("CommentWidgetField", "Form", nullptr));
        bnt_level->setText(QCoreApplication::translate("CommentWidgetField", "PushButton", nullptr));
        lab_field_name->setText(QCoreApplication::translate("CommentWidgetField", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("CommentWidgetField", "0", nullptr));
        label_2->setText(QCoreApplication::translate("CommentWidgetField", "100", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommentWidgetField: public Ui_CommentWidgetField {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMENTWIDGETFIELD_H

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
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QPushButton *bnt_level;
    QSlider *horizontalSlider;
    QLabel *lab_field_name;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *CommentWidgetField)
    {
        if (CommentWidgetField->objectName().isEmpty())
            CommentWidgetField->setObjectName(QString::fromUtf8("CommentWidgetField"));
        CommentWidgetField->resize(441, 135);
        layoutWidget = new QWidget(CommentWidgetField);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 431, 52));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        bnt_level = new QPushButton(layoutWidget);
        bnt_level->setObjectName(QString::fromUtf8("bnt_level"));
        bnt_level->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 255);\n"
"color: rgb(255, 255, 255);"));

        gridLayout_2->addWidget(bnt_level, 0, 0, 1, 1);

        horizontalSlider = new QSlider(layoutWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider, 0, 2, 1, 1);

        lab_field_name = new QLabel(layoutWidget);
        lab_field_name->setObjectName(QString::fromUtf8("lab_field_name"));
        lab_field_name->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        gridLayout_2->addWidget(lab_field_name, 0, 4, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 3, 1, 1);


        retranslateUi(CommentWidgetField);

        QMetaObject::connectSlotsByName(CommentWidgetField);
    } // setupUi

    void retranslateUi(QWidget *CommentWidgetField)
    {
        CommentWidgetField->setWindowTitle(QCoreApplication::translate("CommentWidgetField", "Form", nullptr));
        bnt_level->setText(QCoreApplication::translate("CommentWidgetField", "PushButton", nullptr));
        lab_field_name->setText(QCoreApplication::translate("CommentWidgetField", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("CommentWidgetField", "0", nullptr));
        label_4->setText(QCoreApplication::translate("CommentWidgetField", "100", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommentWidgetField: public Ui_CommentWidgetField {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMENTWIDGETFIELD_H

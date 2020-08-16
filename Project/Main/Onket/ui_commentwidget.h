/********************************************************************************
** Form generated from reading UI file 'commentwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMENTWIDGET_H
#define UI_COMMENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommentWidget
{
public:
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *field_lay;
    QWidget *widget;
    QGridLayout *main_lay;
    QLabel *label;
    QLineEdit *le_disadv;
    QLineEdit *le_adv;
    QLabel *label_2;
    QTextEdit *txt_content;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QPushButton *bnt_cancel;
    QPushButton *bnt_save;

    void setupUi(QWidget *CommentWidget)
    {
        if (CommentWidget->objectName().isEmpty())
            CommentWidget->setObjectName(QString::fromUtf8("CommentWidget"));
        CommentWidget->resize(537, 683);
        verticalLayoutWidget_2 = new QWidget(CommentWidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(20, 30, 481, 271));
        field_lay = new QVBoxLayout(verticalLayoutWidget_2);
        field_lay->setObjectName(QString::fromUtf8("field_lay"));
        field_lay->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(CommentWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(220, 330, 258, 280));
        main_lay = new QGridLayout(widget);
        main_lay->setObjectName(QString::fromUtf8("main_lay"));
        main_lay->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        main_lay->addWidget(label, 3, 1, 1, 1);

        le_disadv = new QLineEdit(widget);
        le_disadv->setObjectName(QString::fromUtf8("le_disadv"));

        main_lay->addWidget(le_disadv, 5, 0, 1, 1);

        le_adv = new QLineEdit(widget);
        le_adv->setObjectName(QString::fromUtf8("le_adv"));

        main_lay->addWidget(le_adv, 3, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        main_lay->addWidget(label_2, 5, 1, 1, 1);

        txt_content = new QTextEdit(widget);
        txt_content->setObjectName(QString::fromUtf8("txt_content"));
        txt_content->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        main_lay->addWidget(txt_content, 0, 0, 1, 3);

        widget1 = new QWidget(CommentWidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 570, 194, 64));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        bnt_cancel = new QPushButton(widget1);
        bnt_cancel->setObjectName(QString::fromUtf8("bnt_cancel"));
        bnt_cancel->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 0, 0);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(bnt_cancel, 0, 1, 1, 1);

        bnt_save = new QPushButton(widget1);
        bnt_save->setObjectName(QString::fromUtf8("bnt_save"));
        bnt_save->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 239, 0);\n"
"color: rgb(255, 255, 255);"));

        gridLayout->addWidget(bnt_save, 0, 0, 1, 1);


        retranslateUi(CommentWidget);

        QMetaObject::connectSlotsByName(CommentWidget);
    } // setupUi

    void retranslateUi(QWidget *CommentWidget)
    {
        CommentWidget->setWindowTitle(QCoreApplication::translate("CommentWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("CommentWidget", "\331\206\331\202\330\247\330\267 \331\202\331\210\330\252", nullptr));
        label_2->setText(QCoreApplication::translate("CommentWidget", "\331\206\331\202\330\247\330\267 \330\266\330\271\331\201", nullptr));
        bnt_cancel->setText(QCoreApplication::translate("CommentWidget", "\330\247\331\206\330\265\330\261\330\247\331\201", nullptr));
        bnt_save->setText(QCoreApplication::translate("CommentWidget", "\330\253\330\250\330\252 \331\206\330\270\330\261", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommentWidget: public Ui_CommentWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMENTWIDGET_H

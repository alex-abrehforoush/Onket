#ifndef GOODGENRALINFOWIDGET_H
#define GOODGENRALINFOWIDGET_H

#include <QWidget>


#include "good.h"
#include "User.h"

namespace Ui {
class GoodGenralInfoWidget;
}

class GoodGenralInfoWidget : public QWidget
{
    Q_OBJECT
//    static QString font_regular;
//    static QString font_skriteout;
    QString font_regular="background-color: rgb(255, 255, 255);\nfont: 75 11pt \"MS Shell Dlg 2\";";
    QString font_skriteout="background-color: rgb(255, 255, 255);\nfont: 75 11pt \"MS Shell Dlg 2\";\ntext-decoration: line-through;";


    QString good_id;
    bool info_valid=false;
public slots:
    void update();

public:
    explicit GoodGenralInfoWidget(const QString& good_id,QWidget *parent = nullptr);
    ~GoodGenralInfoWidget();

private:
    Ui::GoodGenralInfoWidget *ui;
};

#endif // GOODGENRALINFOWIDGET_H

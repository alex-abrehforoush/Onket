#ifndef GOODMAINVIEWWIDGET_H
#define GOODMAINVIEWWIDGET_H

#include <QScrollArea>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDir>



#include "good.h"
#include "User.h"
#include "commentitemstatus.h"
#include "goodpropertywidget.h"
#include "goodgenralinfowidget.h"




namespace Ui {
class goodMainviewWidget;
}

class goodMainViewWidget : public QScrollArea
{
    Q_OBJECT
    QString good_id,user_id;
    bool info_valid=false;
    QWidget* center_widget=nullptr;
    QGridLayout* main_lay=nullptr;
    QVBoxLayout* lay_picture=nullptr,*lay_body=nullptr,*lay_comment_items=nullptr,*lay_buy=nullptr;
    QLabel* lab_img=nullptr;
    QPushButton* bnt_add_to_basket=nullptr;
    GoodPropertyWidget* g_properties=nullptr;
    CommentItemStatus* c_status;
    GoodGenralInfoWidget* g_general=nullptr;
    void setupSTyleSheet();
    void setupLayout();
public slots:
    void update();
public:
    explicit goodMainViewWidget(const QString& good_id,const QString& user_id,QWidget *parent = nullptr);
    ~goodMainViewWidget();

private:
    Ui::goodMainviewWidget *ui;
};

#endif // GOODMAINVIEWWIDGET_H

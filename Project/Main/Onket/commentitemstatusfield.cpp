#include "commentitemstatusfield.h"

void CommentItemStatusField::setPercent(unsigned int percent)
{
    if(percent<=100)
    {
        this->percent=percent;
    }
}

QString CommentItemStatusField::toQString(unsigned int percent)
{
    QString res=QString::number(percent);
    res.append("%");
    return res;
}

CommentItemStatusField::CommentItemStatusField(const QString& field_name,unsigned int percent,QWidget *parent) : QWidget(parent)
  ,lab_name(new QLabel(this)),lab_rect(new QLabel(this)),lab_space(new QLabel(this)),lab_percent(new QLabel(this))
   ,main_lay(new QHBoxLayout(this))

{
    this->setStyleSheet("background-color: rgb(255, 255, 255)");
    this->lab_percent->setStyleSheet("color: rgb(0, 0, 255)");
    this->field_name=field_name;
    this->setPercent(percent);
    this->setLayout(main_lay);
    lab_name->setFixedSize(150,50);
    lab_percent->setFixedSize(150,20);
    lab_rect->setFixedSize(this->percent*3,20);
    lab_space->setFixedSize(300-this->percent*3,20);
    this->setFixedSize(800,70);
   QString style=this->styleSheet();
   lab_space->setStyleSheet(style);
   lab_name->setText(this->field_name);
   lab_percent->setText(CommentItemStatusField::toQString(this->percent));
   lab_rect->setStyleSheet("background-color: rgb(0, 0, 255);");


    QLabel* lab_zero=new QLabel("0",this);
    QLabel* lab_hudred=new QLabel("100",this);


    lab_zero->setStyleSheet("color: rgb(0, 0, 255);");
    lab_hudred->setStyleSheet("color: rgb(0, 0, 255);");

    lab_zero->setFixedSize(50,50);
    lab_hudred->setFixedSize(50,50);



   this->main_lay->addWidget(lab_percent,0);
   this->main_lay->addWidget(lab_hudred,1);


   this->main_lay->addWidget(lab_space,2);

   this->main_lay->addWidget(lab_rect,3);
    this->main_lay->addWidget(lab_zero,4);
    this->main_lay->addWidget(lab_name,5);


}

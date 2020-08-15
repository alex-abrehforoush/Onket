#include "commentwidgetfield.h"
#include "ui_commentwidgetfield.h"



void CommentWidgetField::act_bad_triggered()
{
   this->ui->bnt_level->setText("بد");
    this->ui->horizontalSlider->setValue(10);
}

void CommentWidgetField::act_week_triggered()
{
    this->ui->bnt_level->setText("ضعیف");
    this->ui->horizontalSlider->setValue(30);
}

void CommentWidgetField::act_mediom_triggered()
{
    this->ui->bnt_level->setText("متوسط");
    this->ui->horizontalSlider->setValue(50);
}

void CommentWidgetField::act_good_triggered()
{
    this->ui->bnt_level->setText("خوب");
    this->ui->horizontalSlider->setValue(70);
}

void CommentWidgetField::act_excellent_triggered()
{
    this->ui->bnt_level->setText("عالی");
     this->ui->horizontalSlider->setValue(100);
}


CommentWidgetField::CommentWidgetField(const QString& field_name,QWidget *parent) :
    QWidget(parent),
    bnt_menu(new QMenu(this)),
    ui(new Ui::CommentWidgetField)

{
    ui->setupUi(this);

    act_levels.push_back(new QAction("بد",this));
     act_levels.push_back(new QAction("ضعیف",this));
      act_levels.push_back(new QAction("متوسط",this));
       act_levels.push_back(new QAction("خوب",this));
        act_levels.push_back(new QAction("عالی",this));

        for(auto it : act_levels)
        {
            this->bnt_menu->addAction(it);

        }


    connect(act_levels[0],SIGNAL(triggered()),this,SLOT(act_bad_triggered()));
     connect(act_levels[1],SIGNAL(triggered()),this,SLOT(act_week_triggered()));
      connect(act_levels[2],SIGNAL(triggered()),this,SLOT(act_mediom_triggered()));
       connect(act_levels[3],SIGNAL(triggered()),this,SLOT(act_good_triggered()));
        connect(act_levels[4],SIGNAL(triggered()),this,SLOT(act_excellent_triggered()));

    this->ui->bnt_level->setMenu(bnt_menu);

    this->ui->lab_field_name->setText(field_name);
    this->ui->bnt_level->setText("متوسط");
    this->ui->horizontalSlider->setValue(50);

    this->setFixedSize(450,150);

}

CommentWidgetField::~CommentWidgetField()
{
    delete ui;
}

void CommentWidgetField::on_horizontalSlider_valueChanged(int value)
{
    if(0<= value &&value<20)
    {
        this->ui->bnt_level->setText("بد");
    }
    else if(20<=value && value<40)
    {
        this->ui->bnt_level->setText("ضعیف");
    }
    else if(40<=value && value<60)
    {
        this->ui->bnt_level->setText("متوسط");
    }
    else if(60<=value && value<80)
    {
        this->ui->bnt_level->setText("خوب");
    }
    else if(80<=value && value<=100)
    {
        this->ui->bnt_level->setText("عالی");
    }
    else;
}

void CommentWidgetField::setVlaue(double value)
{
    int var=value*100;
    switch (var)
    {
     case(0):
        this->act_bad_triggered();
        break;
      case(25):
        this->act_week_triggered();
        break;
       case(50):
        this->act_mediom_triggered();
        break;
       case(75):
        this->act_good_triggered();
        break;
    case(100):
        this->act_excellent_triggered();
        break;
    default:
        break;

    }
}


double CommentWidgetField::getValue()
{
    QString level=ui->bnt_level->text();
    if(level=="بد")
    {
        return 0.0;
    }
    else if(level =="ضعیف")
    {
        return 0.25;
    }
    else if(level =="متوسط")
    {
        return 0.5;
    }
    else if(level =="خوب")
    {
        return 0.75;
    }
    else if(level =="عالی")
    {
        return 1.0;
    }
    else
    {
        return 0.0;
    }


}

QString CommentWidgetField::getName()
{
    return this->ui->lab_field_name->text();
}




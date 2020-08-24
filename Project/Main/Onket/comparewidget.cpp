#include "comparewidget.h"
#include "ui_comparewidget.h"

void CompareWidget::on_bnt_return_clicked()
{
    emit this->comparingFinished();
}

CompareWidget::CompareWidget(const QVector<QString>& goods_id,QWidget *parent) :
    QWidget(parent),
    bnt_return(new QPushButton(this)),
    compare_table(new Compare(goods_id,this)),
    main_lay(new QGridLayout(this)),
    ui(new Ui::CompareWidget)
{
    ui->setupUi(this);

    bnt_return->setIcon(QIcon("Database/Icons/RightArrow.png"));
    bnt_return->setText("بازگشت");
//    bnt_return->setStyleSheet("background-color: rgb(255, 255, 255)");
//    this->setStyleSheet("background-color: rgb(255, 255, 255)");
    bnt_return->setFixedSize(200,40);

    this->setLayout(main_lay);
    main_lay->addWidget(compare_table,0,0);
    main_lay->addWidget(bnt_return,1,0);

    this->setFixedSize(1500,800);

    connect(this->bnt_return,SIGNAL(clicked()),SLOT(on_bnt_return_clicked()));
}

CompareWidget::~CompareWidget()
{
    delete ui;
}

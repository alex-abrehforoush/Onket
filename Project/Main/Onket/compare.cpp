#include "compare.h"
#include "QBrush"
#include <QFile>

QString Compare::style_header="QTableWidget{background-color: rgb(255, 0, 0);}";
QString Compare::style_1="background-color: rgb(255, 255, 255);\ncolor: rgb(0, 0, 0);";
QString Compare::style_2="background-color: rgb(200, 200, 200);\ncolor: rgb(0, 0, 0);";

void Compare::setHorizentalHeader(const QString &header_name, int column)
{

    this->setHorizontalHeaderItem(column,new QTableWidgetItem(header_name));
}

void Compare::setVerticalHeader(const QString &header_name, int row)
{
    this->setVerticalHeaderItem(row,new QTableWidgetItem(header_name));
}

void Compare::setupImageRow()
{
    int column=0;
    this->setIconSize(QSize(100,100));
    for(auto it : this->good_ids)
    {
        if(Good::existGoodId(it)==false)continue;
        Good& g=Good::getGood(it);


        QString path="Database/GoodPicture/"+g.getId()+".png";
        QTableWidgetItem* temp=new QTableWidgetItem;
        temp->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        temp->setSizeHint(QSize(100,100));
        temp->setIcon(QIcon(path));
        this->setItem(0,column,temp);
        column++;

    }
}

void Compare::addProperty(const QString &property_name, int row)
{
    int column=0;
    for(auto it : this->good_ids)
    {
        if(Good::existGoodId(it)==false)continue;
        else
        {
            Good& g=Good::getGood(it);

            QTableWidgetItem* temp=new QTableWidgetItem(g.getPropertyValue(property_name));
            temp->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            temp->setTextAlignment(Qt::AlignCenter);
            this->setItem(row,column,temp);
            column++;

        }
    }
}

void Compare::addCommentItem(const QString &item_name, int row)
{
    int column=0;
    for(auto it : this->good_ids)
    {
        if(Good::existGoodId(it)==false)continue;
        else
        {
            Good& g=Good::getGood(it);
            QIcon c;

            QString content=QString::number(g.CommentGetItemValue(item_name)*100)+"%";
            QTableWidgetItem* temp=new QTableWidgetItem(content);
            temp->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
            temp->setTextAlignment(Qt::AlignCenter);
            this->setItem(row,column,temp);
            column++;

        }

    }
}

Compare::Compare(const QVector<QString>& goods_id, QWidget *parent) : QTableWidget(parent)
{
    Type::readFile();
    Good ::readFile();

    this->good_ids = goods_id;
    QString type_id=Type::getCurrentTypeId();
    if(type_id=="none")return;
    const Type& t=Type::getType(type_id);
    int property_size=0;
    QVector<QString> property;
    for(t.setPropertySeekBegin();t.PropertySeekAtEnd()==false;property_size++)
    {
        property.push_back(t.readPropertyName());
    }
    int comment_size=0;
    QVector<QString> comment;
    for(t.setCommentSeekBegin();t.CommentSeekAtEnd()==false;comment_size++)
    {
        comment.push_back(t.readCommentItem());
    }

    this->setColumnCount(goods_id.size());
    this->setRowCount(property_size+comment_size+3);
    int c_cnt=0;

    for(auto it: this->good_ids)
    {
        Good& g=Good::getGood(it);
        this->setHorizentalHeader(g.getName(),c_cnt);
        c_cnt++;
    }

    this->setVerticalHeader("تصویر",0);
    this->setVerticalHeader("کد فروشنده",1);
    this->setVerticalHeader("قیمت به تومان ",2);

    this->setupImageRow();

    for(auto it : goods_id)
    {
        static int column=0;
        if(Good::existGoodId(it)==false)continue;
        Good& g=Good::getGood(it);
        QTableWidgetItem* seller=new QTableWidgetItem(g.getMakerId()),*price=new QTableWidgetItem(QString::number(g.getFinalPrice()));
        seller->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);price->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        seller->setTextAlignment(Qt::AlignCenter);price->setTextAlignment(Qt::AlignCenter);
        this->setItem(1,column,seller);this->setItem(2,column,price);
        column++;

    }
    int row_cnt=3;
    for(auto it : property)
    {
        this->setVerticalHeader(it,row_cnt);
        row_cnt++;
    }
    for(auto it : comment)
    {
        QString temp="رضایت مشتری از "+it;
        this->setVerticalHeader(temp,row_cnt);
        row_cnt++;
    }

    int row=3;
    for(auto it:property)
    {
        this->addProperty(it,row);
        row++;
    }
    for(auto it :comment)
    {
        this->addCommentItem(it,row);
        row++;
    }


    this->setAlternatingRowColors(true);
    this->setSelectionBehavior(QAbstractItemView::SelectColumns);
    this->verticalHeader()->setMinimumWidth(300);
    this->verticalHeader()->setVisible(true);
    this->horizontalHeader()->setVisible(true);
    this->verticalHeader()->resizeSection(0,100);
    this->setFixedSize(this->columnCount()*70+500,this->rowCount()*40+100);
    this->setWindowTitle("جدول مقایسه");

    //this->item(0,0)->setData(Qt::BackgroundRole, QVariant(QColor(Qt::yellow)) );


}

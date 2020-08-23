#include "compare.h"

QString Compare::style_header="background-color: rgb(255, 0, 0);\ncolor: rgb(255, 255, 255);";
QString Compare::style_1="background-color: rgb(255, 255, 255);\ncolor: rgb(0, 0, 0);";
QString Compare::style_2="background-color: rgb(200, 200, 200);\ncolor: rgb(0, 0, 0);";

void Compare::addHeader(const QString &header_name, int column)
{

    this->setHorizontalHeaderItem(column,new QTableWidgetItem(header_name));
    //this->horizontalHeader().
}

Compare::Compare(QVector<QString> goods_id, QWidget *parent) : QTableWidget(parent)
{
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
    this->good_ids = goods_id;
    this->setColumnCount(goods_id.size());
    this->setRowCount(property_size+comment_size+3);


}

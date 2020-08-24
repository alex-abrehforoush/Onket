#ifndef COMPARE_H
#define COMPARE_H

#include <QObject>
#include <QWidget>
#include <QTableWidget>
#include <QHeaderView>
#include <QTableWidget>
#include <QAbstractItemView>
#include <QVector>

#include <type.h>
#include <good.h>
#include <QImage>
#include <QIcon>

class Compare : public QTableWidget
{
    Q_OBJECT
private:
    QVector<QString> good_ids;
    static QString style_header;
    static QString style_1;
    static QString style_2;

    void setHorizentalHeader(const QString& header_name,int column);
    void setVerticalHeader(const QString& header_name,int row);
    void setupImageRow();
    void addProperty(const QString& property_name,int row);
    void addCommentItem(const QString& item_name,int row);



public:
    explicit Compare(const QVector<QString>& goods_id, QWidget *parent = nullptr);


};

#endif // COMPARE_H

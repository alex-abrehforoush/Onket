#ifndef COMPARE_H
#define COMPARE_H

#include <QObject>
#include <QWidget>
#include <QTableWidget>
#include <QVector>

#include <type.h>
#include <good.h>

class Compare : public QTableWidget
{
    Q_OBJECT
private:
    QVector<QString> good_ids;
    static QString style_header;
    static QString style_1;
    static QString style_2;

    void addHeader(const QString& header_name,int column);


public:
    explicit Compare(QVector<QString> goods_id, QWidget *parent = nullptr);

signals:

};

#endif // COMPARE_H

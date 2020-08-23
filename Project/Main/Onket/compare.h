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
public:
    explicit Compare(QVector<QString> goods_id, QWidget *parent = nullptr);

signals:

};

#endif // COMPARE_H

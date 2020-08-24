#ifndef COMPAREWIDGET_H
#define COMPAREWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

#include "compare.h"

namespace Ui {
class CompareWidget;
}

class CompareWidget : public QWidget
{
    Q_OBJECT

    QPushButton* bnt_return=nullptr;
    Compare* compare_table=nullptr;
    QGridLayout* main_lay=nullptr;

signals:
    void comparingFinished();
private slots:
    void on_bnt_return_clicked();

public:
    explicit CompareWidget(const QVector<QString>& goods_id,QWidget *parent = nullptr);
    ~CompareWidget();

private:
    Ui::CompareWidget *ui;
};

#endif // COMPAREWIDGET_H

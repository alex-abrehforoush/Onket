#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Dashboard; }
QT_END_NAMESPACE

class Dashboard : public QWidget
{
    Q_OBJECT

public:
    Dashboard(int mode = -1, QWidget *parent = nullptr);
    ~Dashboard();

private slots:
    void on_pushButton_15_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

private:
    Ui::Dashboard *ui;
};
#endif // DASHBOARD_H

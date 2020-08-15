#ifndef COMMENTWIDGETFIELD_H
#define COMMENTWIDGETFIELD_H

#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QVector>

namespace Ui {
class CommentWidgetField;
}

class CommentWidgetField : public QWidget
{
    Q_OBJECT
    QMenu* bnt_menu =nullptr;
    QVector<QAction*> act_levels;

private slots:
    void act_bad_triggered();
    void act_week_triggered();
    void act_mediom_triggered();
    void act_good_triggered();
    void act_excellent_triggered();

    void on_horizontalSlider_valueChanged(int value);



public:
     void setVlaue(double value);
    double getValue();
    QString getName();
    explicit CommentWidgetField(const QString& field_name,QWidget *parent = nullptr);
    ~CommentWidgetField();

private:
    Ui::CommentWidgetField *ui;
};

#endif // COMMENTWIDGETFIELD_H

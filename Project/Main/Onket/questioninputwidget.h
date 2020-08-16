#ifndef QUESTIONINPUTWIDGET_H
#define QUESTIONINPUTWIDGET_H

#include <QWidget>

#include "good.h"
#include "User.h"


namespace Ui {
class QuestionInputWidget;
}

class QuestionInputWidget : public QWidget
{
    Q_OBJECT
    QString good_id;
    QString sender_id;
    bool info_valid=false;


public:
    explicit QuestionInputWidget(const QString& good_id,const QString& sender_id, QWidget *parent = nullptr);
    ~QuestionInputWidget();

signals:
    void questionEditingFinished(const QString& question_id);



private slots:
    void on_bnt_cancel_clicked();



    void on_bnt_ok_clicked();

private:
    Ui::QuestionInputWidget *ui;
};

#endif // QUESTIONINPUTWIDGET_H

#ifndef COMMENTITEMSTATUS_H
#define COMMENTITEMSTATUS_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>

#include "commentitemstatusfield.h"
#include "good.h"

class CommentItemStatus : public QWidget
{
    Q_OBJECT
    QString good_id;
    bool id_valid=false;
    QVBoxLayout* main_lay=nullptr;
public:
    explicit CommentItemStatus(const QString& good_id,QWidget *parent = nullptr);

signals:

};

#endif // COMMENTITEMSTATUS_H

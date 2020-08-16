#ifndef COMMENTITEMSTATUSFIELD_H
#define COMMENTITEMSTATUSFIELD_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>

class CommentItemStatusField : public QWidget
{
    Q_OBJECT
    QString field_name;

    unsigned int percent=0;

    QLabel* lab_name=nullptr,*lab_rect=nullptr,*lab_space=nullptr,*lab_percent=nullptr;
    QHBoxLayout * main_lay=nullptr;

    void setPercent(unsigned int percent);
    static QString toQString(unsigned int percent);
public:
    explicit CommentItemStatusField(const QString& field_name,unsigned int percent,QWidget *parent = nullptr);


signals:

};

#endif // COMMENTITEMSTATUSFIELD_H

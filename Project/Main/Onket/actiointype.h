#ifndef ACTIOINTYPE_H
#define ACTIOINTYPE_H
#include <QAction>

#include "type.h"


class ActoinType: public QAction
{

    QString type_id;
    bool info_valid=false;
 signals:
    void actionTriggered(const QString& type_id);
private slots:
    void action_triggered();

public:
    ActoinType(const QString& type_id,QWidget* parent=nullptr);
};

#endif // ACTIOINTYPE_H

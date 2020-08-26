#ifndef MENUTYPE_H
#define MENUTYPE_H
#include <QMenu>
#include <QAction>
#include "actiontype.h"
#include "actiontypereturn.h"



class MenuType:public QMenu
{
    Q_OBJECT
    QString type_id;
    bool info_valid=false;
signals:
    void actionTriggered(const QString& type_id);
private slots:
    void action_triggered(const QString& type_id);
public:
    MenuType(const QString& type_id,QWidget* parent=nullptr);
    void setUpMenu(QMenu* menu,QWidget* parent=nullptr);
};

#endif // MENUTYPE_H

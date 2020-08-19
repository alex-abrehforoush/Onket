#ifndef MENUTYPE_H
#define MENUTYPE_H
#include <QMenu>
#include <QAction>
#include "User.h"
#include "actiointype.h"
#include "actionaddtype.h"
#include "actionaddgood.h"


class MenuType:public QMenu
{
    static User* current_user;
    static QMenu* menu_base;
    QString type_id;
    bool info_valid=false;
public:
    MenuType(const QString& type_id,QWidget* parent=nullptr);
    static QMenu* getMenu(User* current_user,QWidget* parent);
};

#endif // MENUTYPE_H

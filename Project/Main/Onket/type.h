#ifndef TYPE_H
#define TYPE_H

#include <QString>
#include <QMap>
#include <QVector>

#include "filefunctions.h"

class Type
{
    static QMap<QString,Type> types;
    static bool existTypeId(const QString& type_id);
    static Type& getType(const QString& type_id);

    QString id;
    QString name;
    QString parent_id;

    QVector<QString>branches_id;
    mutable QVector<QString>::const_iterator branches_it;
    QVector<QString>goods_id;
    mutable QVector<QString>::const_iterator goods_it;

    QVector<QString>property_name;
    mutable QVector<QString>::const_iterator property_it;

    QVector<QString>comment_item;
    mutable QVector<QString>::const_iterator comment_item_it;

public:
    Type(QString type_name,QString parent_id="null");
    QString getId()const;
    QString getName()const;
    QString getParentId()const;
    int getGoodsNumber()const;
    int getBranchNumber()const;


    bool existBranch(const QString branch_name)const;
    Type& addBranch(const QString branch_name);
    bool removeBranch(const QString& branch_name);

    bool existGood(const QString good_id)const;
    bool addGood(const QString& good_id);
    bool removeGood(const QString& good_id);

    bool existProperty(const QString property_name)const;
    bool addProperty(const QString property_name);
    bool removeProperty(const QString property_name);

    bool existCommentItem(const QString& item_name );
    bool addCommentItem(const QString& item_name);
    bool removeCommentItem(const QString& item_name);

};

#endif // TYPE_H

#ifndef TYPE_H
#define TYPE_H

#include <QString>
#include <QMap>
#include <QVector>

#include "filefunctions.h"
#include <QDir>


class Type
{
    static QMap<QString,Type> types;


    QString id;
    QString name;
    QString parent_id;

    QVector<QString>branches_id;
    mutable QVector<QString>::const_iterator branches_it;
    mutable QVector<QString>goods_id;
    mutable QVector<QString>::const_iterator goods_it;

    mutable QVector<QString>property_name;
    mutable QVector<QString>::const_iterator property_it;

    mutable QVector<QString>comment_item;
    mutable QVector<QString>::const_iterator comment_item_it;


    bool addBranch(const QString branch_name);
    static Type& getTypePrivate(const QString& type_id);
public:

    static bool existTypeId(const QString& type_id);
    static const Type& getType(const QString& type_id);
    static QVector<QString>getBaseTypeId();


    QString getId()const;
    QString getName()const;
    QString getParentId()const;
    int getGoodsNumber()const;
    int getBranchNumber()const;


    bool existBranch(const QString branch_name)const;

    bool removeBranch(const QString& branch_name);

    bool existGood(const QString good_id)const;
    bool addGood(const QString& good_id)const;
    bool removeGood(const QString& good_id)const;

    bool existProperty(const QString property_name)const;
    bool addProperty(const QString property_name)const;
    bool removeProperty(const QString property_name)const;

    bool existCommentItem(const QString& item_name )const;
    bool addCommentItem(const QString& item_name)const;
    bool removeCommentItem(const QString& item_name)const;

    void setBranchSeekBegin()const;
    QString readBranchId()const;
    bool BranchSeekAtEnd()const;

    void setGoodSeekBegin()const;
    QString readGoodId()const;
    bool GoodSeekAtEnd()const;

    void setPropertySeekBegin()const;
    QString readPropertyName()const;
    bool PropertySeekAtEnd()const;

    void setCommentSeekBegin()const;
    QString readCommentItem()const;
    bool CommentSeekAtEnd()const;



     Type( QString type_name, QString parent_id );
     Type(const QString& line);
     void addToFile(QTextStream& txt_writer);

     static bool  WriteToFile();
     static bool readFile();

};

#endif // TYPE_H

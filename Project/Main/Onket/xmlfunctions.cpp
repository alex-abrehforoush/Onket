#include "xmlfunctions.h"



QString xml_QMap::toQString(const QMap<QString,bool>& input)
{
    if(input.isEmpty()==true)
    {
        return QString("");
    }

    auto it=input.cbegin();
    QString resault=it.key();
    resault.append("_");
    resault.append(QString::number(*it));

    if(it != input.cend())
        it++;
    for(;it !=  input.cend();it++)
    { resault.append(",");
        resault.append(it.key());
        resault.append("_");
        resault.append(QString::number(*it));

    }
    return resault;
}


QMap<QString,bool> xml_QMap:: toQMap(const QString& input)
{
    QMap<QString,bool>resualt;
    QString sender;
    for(auto it=input.cbegin();it != input.cend(); it++)
    {
        if(*it == '_')
        {
            it++;
            bool mode;
            if(*it=='0')
            {
                mode=false;
            }
            else
            {
                mode=true;
            }
            it++;
            resualt.insert(sender,mode);
            sender.clear();
        }
        else
        {
         sender.append(*it);
        }
    }
    return resualt;
}

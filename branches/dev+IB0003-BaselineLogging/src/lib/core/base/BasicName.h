#ifndef BASICNAME_H
#define BASICNAME_H
#include "BaseLib.h"

#include <QList>
#include <QMap>
#include <QString>


class BASESHARED_EXPORT BasicName
{
public:
    typedef QList<BasicName> List;
    // HOWTO: template <class T> typedef QMap<BasicName, T> Map;

public:
    BasicName(const QString & name=QString());
    bool isNull(void) const;
    void clear(void);
    void set(const QString & name);
    QString sortable(void) const;
    bool operator == (const BasicName & other) const;
    bool operator <  (const BasicName & other) const;
    operator QString (void) const;

private:
    QString mName;
};

typedef BasicName::List BasicNameList;

#endif // BASICNAME_H

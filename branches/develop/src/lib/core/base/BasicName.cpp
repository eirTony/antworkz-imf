/*! @file   BasicName.cpp BaseLib BasicName class definitions
 */

#include "BasicName.h"

#include <QtDebug>

BasicName::BasicName(const QString & name)
{
    set(name);
}

BasicName::BasicName(const char * const name)
{
    set(QString::fromLocal8Bit(name));
}

bool BasicName::isNull(void) const
{
    return mName.isEmpty();
}

void BasicName::clear(void)
{
    mName.clear();
}

void BasicName::set(const QString & name)
{
    mName.clear();
    qWarning("TODO: void BasicName::set(const QString & name)");
    mName.append(name);
}

QString BasicName::sortable(void) const
{
    return mName.toLower();
}

BasicName::operator QString (void) const
{
    return mName;
}

bool BasicName::operator == (const BasicName & other) const
{
    return sortable() == other.sortable();
}

bool BasicName::operator <  (const BasicName & other) const
{
    return sortable() <  other.sortable();
}

#include "LogItem.h"

#include <QDateTime>

#include "ItemFormatBehavior.h"
#include "Severity.h"

DEFINE_DATAPROPS(LogItem, LogItemData)

void LogItem::ctor(void)
{
    setTimeStamp(QDateTime::currentMSecsSinceEpoch());
}

void LogItem::dtor(void) {}

bool LogItem::isNull(void) const
{
    return getSeverity();
}

QVariant LogItem::value(const int index) const
{
    return (index >= 0 && index < mVariantList.size())
            ? mVariantList.at(index)
            : QVariant();
}

QVariantList LogItem::values(void) const
{
    return mVariantList;
}

void LogItem::setValue(const int index,
              const QVariant & var)
{
    /* while (mVariantList.size() <= index)
        mVariantList.append(QVariant()); */
    mVariantList[index] = var;
}

QString LogItem::toString(void) const
{
    static ItemFormatBehavior defaultBehavior;
    return defaultBehavior.formatItem(BasicName("default"), *this);
}

void LogItem::setSeverityToPass(void)
{
    setSeverity(Severity(getSeverity()).pass());
}

bool LogItem::evaluate(const int expectedIndex,
                       const int actualIndex) const
{
    return false;
}

bool LogItem::canConvert(const int expectedIndex,
                         const int actualIndex)
{
    return false;
}

QString LogItem::relationName(void) const
{
    return "rel";
}

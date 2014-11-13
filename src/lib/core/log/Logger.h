#ifndef LOGGER_H
#define LOGGER_H

#include <base/BasicNameMap.h>
#include <base/BasicNameHash.h>
#include <base/FileLinePair.h>
#include <base/FunctionMap.h>

#include "LogItem.h"
#include "Severity.h"

class ItemFormatBehavior;
class LogFork;

class Logger
{
public:
    Logger(void);
    void report(const LogItem item);
    void dump(LogItem item);
    bool boolean(LogItem item);
    bool compare(LogItem item);
    bool pointer(LogItem item);
    bool alloc(LogItem item);
    void troll(const LogItem item);
    void todo(LogItem item);

    LogItem take(void); // one
    LogItem::List take(const int count=-1); // -1=all
    LogItem::List preambleItems(void) const;

    void clearForks(void);
    bool fork(const BasicName & forkName,
              const QUrl & forkUrl);
    bool unfork(const BasicName & forkName);

private: // maybe LoggerBehavior later
    QStringList hexDump(const QByteArray & ba);
    LogItem::Key enqueue(LogItem item);
    void handle(LogItem item);

private:
    Severity mMaxSeverity;
    Severity mQuitSeverity;
    Severity mExceptionSeverity;
    Severity mSignalSeverity;
    LogItem::Queue mItemQueue;
    LogItem::List mPreambleList;
    FileLinePair::Set mFileLineSet;
    FunctionMap mFunctionMap;
    BasicNameHash<ItemFormatBehavior *> mFormatNameBehaviorHash;
    BasicNameMap<LogFork *> mNameForkMap;
};

#endif // LOGGER_H

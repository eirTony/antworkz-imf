#ifndef LOGOUTPUTPLUGIN_H
#define LOGOUTPUTPLUGIN_H
#include "LogLib.h"

#include "LogOutputInterface.h"
#include <base/AbstractPlugin.h>

#include <base/BasicName.h>

class LogFork;

class LOGSHARED_EXPORT LogOutputPlugin
        : public LogOutputInterface
        , public AbstractPlugin
{
    Q_OBJECT
public:
    LogOutputPlugin(const BasicName & name,
                    const BasicNameList &aliases,
                    LogFork * fork,
                    QObject * parent=0);
    LogOutputPlugin(const BasicName & name,
                    LogFork * fork,
                    QObject * parent=0);
    LogOutputPlugin * instance(void) const;
    LogOutputPlugin * operator () (void) const;
    bool isWritable(void) const;

    virtual bool open(void) {}
    virtual bool write(const Severity & sev,
                       const QString & message) {}
    virtual bool write(const LogItem & item) {}
    virtual bool flush(void) {}
    virtual void close(void) {}

signals:

public slots:

protected:
    void setWritable(const bool is=true);

private:
    bool mWritable = false;
};

#endif // LOGOUTPUTPLUGIN_H

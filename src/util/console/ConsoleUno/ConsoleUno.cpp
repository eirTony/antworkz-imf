#include "ConsoleUno.h"
#include "Version.h"
#include <CommonVersion.h>
#ifdef MODULE_NAME
# undef MODULE_NAME
#endif
#define MODULE_NAME "ConsoleUno"

#include <QTimer>

#include <msg/EclipseMessage.h>
#include <msg/EclipseMessageQueue.h>
#include <state/EclipseStateMachine.h>
#include <work/EclipseWorkMessageMachine.h>

ConsoleUno::ConsoleUno(void)
    : mpEWMM(new EclipseWorkMessageMachine(this))
{
    Q_ASSERT(mpEWMM);
    setVersion();
    QObject::setObjectName("ConsoleUno");
}

void ConsoleUno::processChar(const QChar c)
{
    if (false)
        ;
    else if ('e' == c)
        enquiry();
    else if ('q' == c)
        processTerminate(0);
    else
        writeLine("Huh?");
}

void ConsoleUno::processMessage(const EclipseMessage & msg)
{

}

void ConsoleUno::processTerminate(const int exitCode)
{
    mpEWMM->terminate();
}

void ConsoleUno::enquiry(void)
{
    SerialExecutable::writeLine("Version: "+VersionInfo().toString(true));
}

void ConsoleUno::doInitialize(BasicName::VariantMap init)
{
    Q_ASSERT(mpEWMM->initialize(init));
    connect(this, SIGNAL(send(const EclipseMessage &)),
            mpEWMM->queue(), SLOT(incoming(const EclipseMessage &)));
    connect(mpEWMM->queue(), SIGNAL(outgoing(const EclipseMessage &)),
            this, SLOT(receive(const EclipseMessage &)));
    connect(mpEWMM->machine(), SIGNAL(active()),
            this, SLOT(onActive()));
    connect(mpEWMM->machine(), SIGNAL(terminated()),
            this, SLOT(onTerminated()));
}

void ConsoleUno::doSetup(BasicId::VariantMap config)
{
    Q_ASSERT(mpEWMM->configure(config));
}

void ConsoleUno::doStart(void)
{
    EclipseMessage msg;
    msg.insert("Message", "This is a message.");
    emit send(msg);
}

void ConsoleUno::receive(const EclipseMessage & msg)
{
    SerialExecutable::writeLine(msg["Message"].toString());
}

void ConsoleUno::onActive(void)
{
    SerialExecutable::writeLine("Hello from ConsoleUno!");
}

void ConsoleUno::onCharReady(void)
{
    processChar(SerialExecutable::readChar());
}

void ConsoleUno::onTerminated(void)
{
    QTimer::singleShot(10, this, SLOT(quit()));
}

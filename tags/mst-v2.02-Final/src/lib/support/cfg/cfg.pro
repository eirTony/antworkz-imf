
QT       -= gui

TARGET = eirCfg
TEMPLATE = lib

DEFINES += CFG_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

LIBS *= -leirBase

SOURCES += CfgLib.cpp

HEADERS += CfgLib.h \
    cfg_global.h \
    Version.h \
    ../../../CommonVersion.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc


QT       -= gui

TARGET = eirVar
TEMPLATE = lib

DEFINES += VAR_LIBRARY

include (../common.pri)

win32:RC_FILE = WinRes.rc

LIBS *= -leirBase

SOURCES += VarLib.cpp

HEADERS += VarLib.h \
    Version.h \
    ../../../CommonVersion.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

OTHER_FILES += \
    WinRes.rc \
    ../../../CommonWinRes.rc

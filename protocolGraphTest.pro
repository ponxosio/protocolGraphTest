#-------------------------------------------------
#
# Project created by QtCreator 2017-03-14T10:31:39
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_protocolgraphtest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += tst_protocolgraphtest.cpp \
    stringactuatorsinterface.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

debug {
    INCLUDEPATH += X:\protocolGraph\dll_debug\include
    LIBS += -L$$quote(X:\protocolGraph\dll_debug\bin) -lprotocolGraph

    INCLUDEPATH += X:\utils\dll_debug\include
    LIBS += -L$$quote(X:\utils\dll_debug\bin) -lutils
}

!debug {
    INCLUDEPATH += X:\protocolGraph\dll_release\include
    LIBS += -L$$quote(X:\protocolGraph\dll_release\bin) -lprotocolGraph

    INCLUDEPATH += X:\utils\dll_release\include
    LIBS += -L$$quote(X:\utils\dll_release\bin) -lutils
}

INCLUDEPATH += X:\libraries\cereal-1.2.2\include

HEADERS += \
    stringactuatorsinterface.h

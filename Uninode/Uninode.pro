#-------------------------------------------------
#
# Project created by QtCreator 2015-11-06T21:36:30
#
#-------------------------------------------------

QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Uninode
TEMPLATE = app

LIBS += "IPHLPAPI.DLL"

SOURCES += main.cpp\
        mainwindow.cpp \
    getinfo.cpp \
    aboutconfig.cpp

HEADERS  += mainwindow.h \
    getinfo.h \
    aboutconfig.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc

RC_ICONS = uninode.ico

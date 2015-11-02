#-------------------------------------------------
#
# Project created by QtCreator 2015-10-30T16:08:02
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MinhoUDPCOM
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    udpcom.cpp \
    serialport.cpp

HEADERS  += mainwindow.h \
    udpcom.h \
    serialport.h

FORMS    += mainwindow.ui

RESOURCES += \
    rs.qrc

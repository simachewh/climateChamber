#-------------------------------------------------
#
# Project created by QtCreator 2015-05-06T15:39:53
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ControlPCPT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    status.cpp

HEADERS  += mainwindow.h \
    status.h

FORMS    += mainwindow.ui

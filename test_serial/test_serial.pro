#-------------------------------------------------
#
# Project created by QtCreator 2016-01-09T00:26:47
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = test_serial
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    TestSerialController.cpp \
    SerialController.cpp

HEADERS += \
    serial.h \
    SerialController.h

LIBS += -L/usr/lib/x86_64-linux-gnu \
    -lboost_system \
    -lboost_thread \
    -lboost_date_time

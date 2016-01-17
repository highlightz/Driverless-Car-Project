#-------------------------------------------------
#
# Project created by QtCreator 2016-01-09T03:55:23
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = test_hokuyo
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    test_hokuyo_wrapper.cpp \
    hokuyo_wrapper.cpp \
    Connection_information.cpp

HEADERS += \
    hokuyo_wrapper.h \
    Connection_information.h

# Hokuyo Libraries
LIBS += -L/usr/local/lib \
    -lurg_cpp

# OpenCV Libraries
LIBS += -lopencv_core -lopencv_highgui

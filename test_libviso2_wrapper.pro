#-------------------------------------------------
#
# Project created by QtCreator 2016-01-09T04:41:44
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = test_libviso2_wrapper
CONFIG   += console
CONFIG   -= app_bundle

CONFIG += c++11

QMAKE_CXXFLAGS += -msse3

TEMPLATE = app


SOURCES += main.cpp \
    libviso2/filter.cpp \
    libviso2/matcher.cpp \
    libviso2/matrix.cpp \
    libviso2/reconstruction.cpp \
    libviso2/triangle.cpp \
    libviso2/viso.cpp \
    libviso2/viso_mono.cpp \
    libviso2/viso_stereo.cpp \
    stereoBumblebee.cpp \
    libviso2_wrapper.cpp

HEADERS += \
    libviso2/filter.h \
    libviso2/matcher.h \
    libviso2/matrix.h \
    libviso2/reconstruction.h \
    libviso2/timer.h \
    libviso2/triangle.h \
    libviso2/viso.h \
    libviso2/viso_mono.h \
    libviso2/viso_stereo.h \
    stereoBumblebee.h \
    libviso2_wrapper.h

# Bumblebee2 Libraries
INCLUDEPATH += /usr/include/triclops
INCLUDEPATH += /usr/include/flycapture
LIBS += -L/usr/lib \
    -ltriclops \
    -lflycapture \
    -lflycapturegui \
    -lflycapture2bridge \
    -lflycapture-c \
    -lpnmutils \

# OpenCV Libraries
LIBS += -lopencv_core -lopencv_highgui -lopencv_imgproc

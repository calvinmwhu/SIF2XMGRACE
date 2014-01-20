#-------------------------------------------------
#
# Project created by QtCreator 2013-04-23T20:54:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SIF2XMGRACE
TEMPLATE = app


SOURCES += main.cpp\
        sif2xmgrace.cpp \
    curve.cc \
    readSIFs.cc \
    writeXMgrace.cc

HEADERS  += sif2xmgrace.h \
    curve.h \
    readSIFs.h \
    writeXMgrace.h

FORMS    += sif2xmgrace.ui

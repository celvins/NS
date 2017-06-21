#-------------------------------------------------
#
# Project created by QtCreator 2016-02-25T14:56:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    neuron.cpp \
    neuronsety.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    neuron.h \
    neuronsety.h

FORMS    += mainwindow.ui
QT       += printsupport

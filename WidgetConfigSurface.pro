#-------------------------------------------------
#
# Project created by QtCreator 2014-10-27T14:00:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WidgetConfigSurface
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    configurablewidget.cpp \
    common.cpp

HEADERS  += mainwindow.h \
    configurablewidget.h \
    common.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc

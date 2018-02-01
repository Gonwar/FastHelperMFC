#-------------------------------------------------
#
# Project created by QtCreator 2016-07-30T15:13:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FastHelperV2
TEMPLATE = app


SOURCES += main.cpp\
        fasthelper.cpp \
    cdatabase.cpp \
    editdialog.cpp \
    settingdialog.cpp \
    inifiles.cpp

HEADERS  += fasthelper.h \
    cdatabase.h \
    editdialog.h \
    settingdialog.h \
    inifiles.h

FORMS    += fasthelper.ui \
    editdialog.ui \
    settingdialog.ui

RC_FILE = appIcon.rc

#-------------------------------------------------
#
# Project created by QtCreator 2018-03-08T17:49:17
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PacManQt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    actor.cpp \
    painter.cpp \
    pacman.cpp \
    ghost.cpp \
    tile.cpp \
    gameoptions.cpp \
    gamewindow.cpp \
    serverwindow.cpp \
    clientwindow.cpp

HEADERS += \
        mainwindow.h \
    tile.h \
    actor.h \
    painter.h \
    pacman.h \
    ghost.h \
    game_cfg.h \
    gameoptions.h \
    gamewindow.h \
    globaltypes.h \
    serverwindow.h \
    clientwindow.h

FORMS += \
        mainwindow.ui \
    gameoptions.ui \
    gamewindow.ui \
    serverwindow.ui \
    clientwindow.ui

RESOURCES += \
    resource.qrc

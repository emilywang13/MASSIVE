#-------------------------------------------------
#
# Project created by QtCreator 2016-01-26T17:01:29
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Massive
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gameboard.cpp \
    myplayer.cpp \
    mass.cpp \
    enemy.cpp \
    enemymass.cpp \
    score.cpp \
    food.cpp \
    instructions.cpp \
    gameover.cpp

HEADERS  += mainwindow.h \
    gameboard.h \
    myplayer.h \
    mass.h \
    enemy.h \
    enemymass.h \
    score.h \
    food.h \
    instructions.h \
    gameover.h

FORMS    += mainwindow.ui \
    gameboard.ui \
    instructions.ui \
    gameover.ui

RESOURCES += \
    audio.qrc \
    images.qrc \
    audio.qrc


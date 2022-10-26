QT += core
QT -= gui

TARGET = simulation
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    era.cpp \
    fielder.cpp \
    game.cpp \
    pitcher.cpp \
    player.cpp \
    team.cpp

HEADERS += \
    era.h \
    fielder.h \
    game.h \
    pitcher.h \
    player.h \
    team.h


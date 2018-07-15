QT += core
QT -= gui

CONFIG += c++11

TARGET = SaperV3
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    board.cpp

HEADERS += \
    board.h

TEMPLATE = app
TARGET = simple-qt-gui
INCLUDEPATH += .

# Input
HEADERS += mainWindow.h channelWindow.h
SOURCES += main.cpp mainWindow.cpp channelWindow.cpp
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

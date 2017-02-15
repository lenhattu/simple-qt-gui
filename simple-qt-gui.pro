TEMPLATE = app
TARGET = simple-qt-gui
INCLUDEPATH += .

# Input
HEADERS += mainWindow.h
SOURCES += main.cpp mainWindow.cpp
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = simple-qt-gui
INCLUDEPATH += .

# Input
SOURCES += main.cpp
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = Graph-Drawer

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    renderarea.cpp

HEADERS += \
    mainwindow.h \
    renderarea.h

FORMS += \
    mainwindow.ui

TEMPLATE = app
TARGET = Graph-Drawer

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    renderarea.cpp \
    graph.cpp \
    node.cpp \
    edge.cpp \
    mygraphicsview.cpp

HEADERS += \
    mainwindow.h \
    renderarea.h \
    graph.h \
    node.h \
    edge.h \
    mygraphicsview.h

FORMS += \
    mainwindow.ui

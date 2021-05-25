QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    coordinates.cpp \
    draw.cpp \
    edges.cpp \
    error_output.cpp \
    figure.cpp \
    file_processing.cpp \
    graphics.cpp \
    main.cpp \
    mainwindow.cpp \
    operations.cpp \
    task.cpp

HEADERS += \
    const_errors.h \
    coordinates.h \
    draw.h \
    edges.h \
    error_output.h \
    figure.h \
    file_processing.h \
    graphics.h \
    mainwindow.h \
    operations.h \
    task.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    lab_01_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    cube.txt \
    figure.txt

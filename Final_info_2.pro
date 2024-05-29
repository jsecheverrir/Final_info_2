QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    character.cpp \
    enemigo.cpp \
    game_rules.cpp \
    gameobject.cpp \
    main.cpp \
    mainwindow.cpp \
    orbe.cpp \
    picture_management.cpp

HEADERS += \
    character.h \
    enemigo.h \
    game_rules.h \
    gameobject.h \
    macros_game.h \
    mainwindow.h \
    orbe.h \
    picture_management.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    sprites.qrc

DISTFILES += \
    sprites final/mapa 3.jpg

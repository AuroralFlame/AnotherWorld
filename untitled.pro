QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    activeobejct.cpp \
    background.cpp \
    commonobeject.cpp \
    entitybase.cpp \
    gamemenu.cpp \
    gamescence.cpp \
    inactiveobject.cpp \
    livingentity.cpp \
    main.cpp \
    menuwindow.cpp \
    moveentity.cpp \
    permanentobejct.cpp \
    playentity.cpp \
    playeritem.cpp

HEADERS += \
    GameSettings.h \
    GameSettings.h \
    activeobejct.h \
    background.h \
    commonobeject.h \
    entitybase.h \
    gamemenu.h \
    gamescence.h \
    inactiveobject.h \
    livingentity.h \
    menuwindow.h \
    moveentity.h \
    permanentobejct.h \
    playentity.h \
    playeritem.h

FORMS += \
    gamescence.ui \
    gamemenu.ui \
    menuwindow.ui

TRANSLATIONS += \
    untitled_zh_CN.ts
    untitled_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resource.qrc


HEADERS += \
    GameSettings.h \
    entitybase.h \
    gamemenu.h \
    gamescence.h \
    livingentity.h \
    menuwindow.h \
    moveentity.h \
    playentity.h \
    playeritem.h

FORMS += \
    gamescence.ui \
    gamemenu.ui \
    menuwindow.ui

TRANSLATIONS += \
    untitled_zh_CN.ts
    untitled_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resource.qrc

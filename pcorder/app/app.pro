QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle
CONFIG += c++14 console
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        desktop.cpp \
        laptop.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Battery.h \
    CPU.h \
    Computer.h \
    Memory.h \
    PowerSupply.h \
    Screen.h \
    Storage.h \
    desktop.h \
    laptop.h

DISTFILES += \
    output.txt

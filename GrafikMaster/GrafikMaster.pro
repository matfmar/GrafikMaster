QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dbobslugiwaczbazydanych.cpp \
    dto.cpp \
    main.cpp \
    mdyzuranci.cpp \
    mnowegrafiki.cpp \
    pdecydowanieokontynuacjiszukaniagrafikow.cpp \
    pdodawanienowegografiku.cpp \
    pedycjabazydyzurantow.cpp \
    pmain.cpp \
    pprogress.cpp \
    pprzegladaniegrafikowroboczych.cpp \
    ttimerclass.cpp \
    ttimerthread.cpp \
    tworker.cpp \
    uidecydowanieokoniecznosciszukaniagrafikow.cpp \
    uidodawanienowegodyzuranta.cpp \
    uidodawanienowegografiku.cpp \
    uidodawanienowegografikuwstep.cpp \
    uiedycjabazydyzurantow.cpp \
    uimainwindow.cpp \
    uiprzegladaniegrafikowroboczych.cpp \
    uitworzenieprogress.cpp \
    uitworzonegrafiki.cpp

HEADERS += \
    dbobslugiwaczbazydanych.h \
    dto.h \
    mdyzuranci.h \
    mnowegrafiki.h \
    pdecydowanieokontynuacjiszukaniagrafikow.h \
    pdodawanienowegografiku.h \
    pedycjabazydyzurantow.h \
    pmain.h \
    pprogress.h \
    pprzegladaniegrafikowroboczych.h \
    ttimerclass.h \
    ttimerthread.h \
    tworker.h \
    uidecydowanieokoniecznosciszukaniagrafikow.h \
    uidodawanienowegodyzuranta.h \
    uidodawanienowegografiku.h \
    uidodawanienowegografikuwstep.h \
    uiedycjabazydyzurantow.h \
    uimainwindow.h \
    uiprzegladaniegrafikowroboczych.h \
    uitworzenieprogress.h \
    uitworzonegrafiki.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

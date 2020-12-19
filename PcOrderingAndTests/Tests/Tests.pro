QT += testlib
QT -= gui


CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app
INCLUDEPATH += ../App
    SOURCES += ../App/desktop.cpp\
               ../App/laptop.cpp\
                tst_pctests.cpp

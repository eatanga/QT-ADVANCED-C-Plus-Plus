QT += testlib
QT += sql
QT -= gui

CONFIG += c++17 qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../app
SOURCES += ../app/account.cpp \
           ../app/bank.cpp \
           ../app/cli.cpp \
           ../app/counterparty.cpp \
           ../app/database.cpp \
           ../app/transaction.cpp \
           tst_testbank.cpp

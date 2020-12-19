QT += testlib
QT -= gui

CONFIG += c++14 qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../app
SOURCES += ../app/account.cpp \
           ../app/bank.cpp \
           ../app/counterparty.cpp \
           ../app/checkingaccount.cpp\
           ../app/savingsaccount.cpp\
           ../app/transaction.cpp \
           tst_testbank.cpp

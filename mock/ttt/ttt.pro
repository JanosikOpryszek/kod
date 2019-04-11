include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tst_tt.h \
    ../kalkulator/kalkulator.h \
    dod_mock.h \
    ../kalkulator/dodaj.h \
    ../kalkulator/odejmij.h \
    od_mock.h

SOURCES += \
        main.cpp \
    ../kalkulator/kalkulator.cpp \
    dod_mock.cpp \
    ../kalkulator/dodaj.cpp \
    ../kalkulator/odejmij.cpp \
    od_mock.cpp

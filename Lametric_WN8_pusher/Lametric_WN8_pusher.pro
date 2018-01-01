TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    htmlparser.cpp \
    settingsparser.cpp \
    stat.cpp \
    searchstat.cpp \
    statsettingparser.cpp \
    pushscriptgenerator.cpp

HEADERS += \
    htmlparser.h \
    settingsparser.h \
    stat.h \
    searchstat.h \
    statsettingparser.h \
    pushscriptgenerator.h

# File remote_plot_spectrum.pro
# File created : 04 Jul 2017
# Created by : Davit Kalantaryan (davit.kalantaryan@desy.de)
# This file can be used to produce Makefile for daqadcreceiver application
# for PITZ
# CONFIG += TEST
# For making test: '$qmake "CONFIG+=TEST" daqadcreceiver.pro' , then '$make'
include(../../common/common_qt/sys_common.pri)


INCLUDEPATH += ../../../include
INCLUDEPATH += ../../../src/.tmp/include

SOURCES +=  \
    ../../../src/test/main_queue_test.cpp

HEADERS += \
    ../../../src/.tmp/include/openssh_first_include.h

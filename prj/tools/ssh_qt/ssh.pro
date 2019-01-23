# File remote_plot_spectrum.pro
# File created : 04 Jul 2017
# Created by : Davit Kalantaryan (davit.kalantaryan@desy.de)
# This file can be used to produce Makefile for daqadcreceiver application
# for PITZ
# CONFIG += TEST
# For making test: '$qmake "CONFIG+=TEST" daqadcreceiver.pro' , then '$make'
include(../../common/common_qt/sys_common.pri)


INCLUDEPATH += ../../../include
INCLUDEPATH += /usr/include/cdio
INCLUDEPATH += ../../../src/.tmp/include
QMAKE_CXXFLAGS += "-include openssh_first_include.h"
QMAKE_CFLAGS += "-include openssh_first_include.h"

SOURCES +=  \
    ../../../src/original/ssh.c \
    ../../../src/original/readconf.c \
    ../../../src/original/clientloop.c \
    ../../../src/original/sshtty.c \
    ../../../src/original/sshconnect.c \
    ../../../src/original/sshconnect2.c \
    ../../../src/original/mux.c

HEADERS += \
    ../../../src/.tmp/include/openssh_first_include.h

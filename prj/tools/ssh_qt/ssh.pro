# File remote_plot_spectrum.pro
# File created : 04 Jul 2017
# Created by : Davit Kalantaryan (davit.kalantaryan@desy.de)
# This file can be used to produce Makefile for daqadcreceiver application
# for PITZ
# CONFIG += TEST
# For making test: '$qmake "CONFIG+=TEST" daqadcreceiver.pro' , then '$make'
include(../../common/common_qt/sys_common.pri)

LIBS += -lbsd
LIBS += -lgssapi
LIBS += -lkrb5
LIBS += -lasn1
LIBS += -lwind
LIBS += -lroken
LIBS += -lcom_err
LIBS += -lpthread
LIBS += -lheimbase

DEFINES += _GNU_SOURCE

INCLUDEPATH += ../../../include
INCLUDEPATH += /usr/include/cdio
INCLUDEPATH += ../../../src/.tmp/include
QMAKE_CXXFLAGS += "-include openssh_first_include.h"
QMAKE_CFLAGS += "-include openssh_first_include.h"
QMAKE_CXXFLAGS_WARN_ON += -Wno-attributes
QMAKE_CFLAGS_WARN_ON += -Wno-attributes
QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter
QMAKE_CFLAGS_WARN_ON += -Wno-unused-parameter
QMAKE_CXXFLAGS_WARN_ON += -Wno-type-limits
QMAKE_CFLAGS_WARN_ON += -Wno-type-limits

SOURCES +=  \
    ../../../src/original/ssh.c \
    ../../../src/original/readconf.c \
    ../../../src/original/clientloop.c \
    ../../../src/original/sshtty.c \
    ../../../src/original/sshconnect.c \
    ../../../src/original/sshconnect2.c \
    ../../../src/original/mux.c \
    ../../../src/original/atomicio.c \
    ../../../src/original/authfd.c \
    ../../../src/original/compat.c \
    ../../../src/original/dns.c \
    ../../../src/original/fatal.c \
    ../../../src/original/hostfile.c \
    ../../../src/original/msg.c \
    ../../../src/original/readpass.c \
    ../../../src/original/utf8.c

HEADERS += \
    ../../../src/.tmp/include/openssh_first_include.h

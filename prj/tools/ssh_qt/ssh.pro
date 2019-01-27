# File remote_plot_spectrum.pro
# File created : 04 Jul 2017
# Created by : Davit Kalantaryan (davit.kalantaryan@desy.de)
# This file can be used to produce Makefile for daqadcreceiver application
# for PITZ
# CONFIG += TEST
# For making test: '$qmake "CONFIG+=TEST" daqadcreceiver.pro' , then '$make'
include(../../common/common_qt/sys_common.pri)

LIBS += -lbsd
#LIBS += -lgssapi
#LIBS += -lkrb5
#LIBS += -lasn1
#LIBS += -lwind
#LIBS += -lroken
#LIBS += -lcom_err
LIBS += -lpthread
#LIBS += -lheimbase
LIBS += -lutil
LIBS += -lz
LIBS += -lc
#LIBS += -lnss_lwres
LIBS += -llwres
LIBS += -lrt
LIBS += -lresolv


DEFINES += _GNU_SOURCE

INCLUDEPATH += ../../../include
INCLUDEPATH += /usr/include/cdio
INCLUDEPATH += ../../../src/.tmp/include
INCLUDEPATH += ../../../src/.tmp/include/openbsd
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
    ../../../src/original/utf8.c \
    ../../../src/original/misc.c \
    ../../../src/original/log.c \
    ../../../src/original/match.c \
    ../../../src/original/xmalloc.c \
    ../../../src/original/ssherr.c \
    ../../../src/original/packet.c \
    ../../../src/original/channels.c \
    ../../../src/original/opacket.c \
    ../../../src/original/cipher.c \
    ../../../src/original/mac.c \
    ../../../src/original/kex.c \
    ../../../src/original/sshkey.c \
    ../../../src/original/sshbuf.c \
    ../../../src/original/sshbuf-getput-basic.c \
    ../../../src/original/digest-libc.c \
    ../../../src/original/authfile.c \
    ../../../src/.tmp/src/missing_functions_from_ssh.cpp \
    ../../../src/original/nchan.c \
    ../../../src/original/dispatch.c \
    ../../../src/original/ttymodes.c \
    ../../../src/original/monitor_fdpass.c \
    ../../../src/original/kexc25519c.c \
    ../../../src/original/canohost.c \
    ../../../src/original/sshbuf-misc.c \
    ../../../src/original/hmac.c \
    ../../../src/original/addrmatch.c

HEADERS += \
    ../../../src/.tmp/include/openssh_first_include.h \
    ../../../src/original/match.h \
    ../../../src/original/xmalloc.h \
    ../../../src/original/ssherr.h \
    ../../../src/original/packet.h \
    ../../../src/original/channels.h \
    ../../../src/original/opacket.h \
    ../../../src/original/cipher.h \
    ../../../src/original/mac.h \
    ../../../src/original/kex.h \
    ../../../src/original/sshkey.h \
    ../../../src/original/sshbuf.h \
    ../../../src/.tmp/include/openbsd/rmd160.h \
    ../../../src/.tmp/include/openbsd/openbsd_first_include.h \
    ../../../src/original/authfile.h \
    ../../../src/original/dispatch.h \
    ../../../src/original/ttymodes.h \
    ../../../src/original/monitor_fdpass.h \
    ../../../src/original/canohost.h \
    ../../../src/original/hmac.h

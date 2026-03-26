#ident	"@(#)cls4:lib/complex/mk/makefile	1.3"
###############################################################################
#
# C++ source for the C++ Language System, Release 3.0.  This product
# is a new release of the original cfront developed in the computer
# science research center of AT&T Bell Laboratories.
#
# Copyright (c) 1993  UNIX System Laboratories, Inc.
# Copyright (c) 1991, 1992   AT&T and UNIX System Laboratories, Inc.
# Copyright (c) 1984, 1989, 1990 AT&T.  All Rights Reserved.
#
# THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE of AT&T and UNIX System
#
# Laboratories, Inc.  The copyright notice above does not evidence
# any actual or intended publication of such source code.
#
###############################################################################
O_COMPLEX	=	abs.o arg.o cos.o error.o exp.o io.o log.o oper.o \
			polar.o pow.o sin.o sqrt.o
CC	=	../../../CC
CCFLAGS	= $(MSIZE) -Wall -DPRAGMATIC -I../../../incl -fno-builtin-clog

CCOMP = gcc

libcomplex.a:	$(O_COMPLEX)
	ar r libcomplex.a $(O_COMPLEX)
	if test "$(BSD)" ; then ranlib libcomplex.a; fi
	if test -f ../../../$@; then mv ../../../$@ ../../../$@.old; fi
	cp $@ ../../../

libcomplex_b.a:	$(O_COMPLEX)
	ar r libcomplex_b.a $(O_COMPLEX)
	if test "$(BSD)" ; then ranlib libcomplex_b.a; fi

libcomplex_eh.a:	$(O_COMPLEX)
	ar r libcomplex_eh.a $(O_COMPLEX)
	if test "$(BSD)" ; then ranlib libcomplex_eh.a; fi

libcomplex_p.a:	$(O_COMPLEX)
	ar r libcomplex_p.a $(O_COMPLEX)
	if test "$(BSD)" ; then ranlib libcomplex_p.a; fi

abs.o:	../complex/abs.cpp
	$(CC) $(CCFLAGS) -I../complex -c ../complex/abs.cpp

arg.o:	../complex/arg.cpp
	$(CC) $(CCFLAGS) -I../complex -c ../complex/arg.cpp

cos.o:	../complex/cos.cpp
	$(CC) $(CCFLAGS) -I../complex -c ../complex/cos.cpp

error.o:	../complex/error.cpp
	$(CC) $(CCFLAGS) -I../complex -c ../complex/error.cpp

exp.o:	../complex/exp.cpp
	$(CC) $(CCFLAGS) -I../complex -c ../complex/exp.cpp

io.o:	../complex/io.cpp
	$(CC) $(CCFLAGS) -I../complex -c ../complex/io.cpp

log.o:	../complex/log.cpp
	$(CC) $(CCFLAGS) -I../complex -c ../complex/log.cpp

oper.o:	../complex/oper.cpp
	$(CC) $(CCFLAGS) -I../complex -c ../complex/oper.cpp

polar.o:	../complex/polar.cpp
	$(CC) $(CCFLAGS) -I../complex -c ../complex/polar.cpp

pow.o:	../complex/pow.cpp
	$(CC) $(CCFLAGS) -I../complex -c ../complex/pow.cpp

sin.o:	../complex/sin.cpp
	$(CC) $(CCFLAGS) -I../complex -c ../complex/sin.cpp

sqrt.o:	../complex/sqrt.cpp
	$(CC) $(CCFLAGS) -I../complex -c ../complex/sqrt.cpp

clean:
	-@rm -f $(O_COMPLEX)
	-@rm libcomplex*.a
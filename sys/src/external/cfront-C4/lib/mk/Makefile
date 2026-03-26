#ident	"@(#)cls4:lib/mk/makefile	1.3"
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

O_GENERIC	=	generic.o
O_NEW		=	_new.o _delete.o _handler.o _vec.o placenew.o _arr_map.o
O_STATIC	=	_ctor.o _dtor.o _main.o dtors.o pure.o
O_STREAM	=	in.o out.o stream.o fstream.o manip.o cstreams.o \
flt.o strstream.o rawin.o intin.o stdiobuf.o streambuf.o \
filebuf.o  oldformat.o sbuf.dbp.o swstdio.o ios_compat.o _stdio.o 	# exit.o

OFILES	=	$(O_GENERIC) $(O_NEW) $(O_STATIC) $(O_STREAM)
CC	=	CC
override CCFLAGS	= -g -I../../incl -fno-builtin-clog $(MSIZE)

CCOMP = gcc

# have everything depend on this makefile to force recompilation
# when going from patch to munch
DEPEND	= Makefile

#MPDIR	= _patch
MPDIR	= _munch

libC.a:	$(OFILES)
	ar r libC.a $(OFILES)

_stdio.o: _stdio.c
	$(CCOMP) $(MSIZE) -c _stdio.c

generic.o:	../generic/generic.cpp $(DEPEND)
	$(CC) $(CCFLAGS)  -c ../generic/generic.cpp

_delete.o:	../new/_delete.cpp $(DEPEND)
	$(CC) $(CCFLAGS)  -c ../new/_delete.cpp

_handler.o:	../new/_handler.cpp $(DEPEND)
	$(CC) $(CCFLAGS)  -c ../new/_handler.cpp

_new.o:	../new/_new.cpp $(DEPEND)
	$(CC) $(CCFLAGS)  -c ../new/_new.cpp

_vec.o:	../new/_vec.cpp $(DEPEND)
	$(CC) $(CCFLAGS)  -c ../new/_vec.cpp

placenew.o: ../new/placenew.cpp $(DEPEND)
	$(CC) $(CCFLAGS)  -c ../new/placenew.cpp

_arr_map.o: ../new/_arr_map.cpp $(DEPEND)
	$(CC) $(CCFLAGS)  -c ../new/_arr_map.cpp

_ctor.o:	../static/_ctor.cpp $(DEPEND)
	$(CC) $(CCFLAGS)  -c ../static/_ctor.cpp

_dtor.o:	../static/_dtor.cpp $(DEPEND)
	$(CC) $(CCFLAGS)  -c ../static/_dtor.cpp

_main.o:	../../$(MPDIR)/_main.c $(DEPEND)
	$(CCOMP) $(CCFLAGS)  -c ../../$(MPDIR)/_main.c

dtors.o:	../../$(MPDIR)/dtors.c $(DEPEND)
	$(CCOMP) $(CCFLAGS)  -c ../../$(MPDIR)/dtors.c

exit.o:	../static/exit.cpp $(DEPEND)
	$(CC) $(CCFLAGS)  -c ../static/exit.cpp

pure.o: ../static/pure.cpp $(DEPEND)
	$(CC) $(CCFLAGS)  -c ../static/pure.cpp

in.o:	../stream/in.cpp  $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/in.cpp

out.o:	../stream/out.cpp  ../stream/streamdefs.h $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/out.cpp

stream.o:	../stream/stream.cpp $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/stream.cpp

fstream.o:	../stream/fstream.cpp $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/fstream.cpp

manip.o:	../stream/manip.cpp $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/manip.cpp

cstreams.o:	../stream/cstreams.cpp ../stream/streamdefs.h $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/cstreams.cpp

flt.o:	../stream/flt.cpp $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/flt.cpp

strstream.o:	../stream/strstream.cpp $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/strstream.cpp

rawin.o:	../stream/rawin.cpp $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/rawin.cpp

intin.o:	../stream/intin.cpp  $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/intin.cpp

stdiobuf.o:	../stream/stdiobuf.cpp $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/stdiobuf.cpp

streambuf.o:	../stream/streambuf.cpp ../stream/streamdefs.h $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/streambuf.cpp

filebuf.o:	../stream/filebuf.cpp ../stream/streamdefs.h $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/filebuf.cpp

oldformat.o:	../stream/oldformat.cpp ../stream/streamdefs.h $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/oldformat.cpp

sbuf.dbp.o:	../stream/sbuf.dbp.cpp $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/sbuf.dbp.cpp

swstdio.o:	../stream/swstdio.cpp $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/swstdio.cpp

ios_compat.o:	../stream/ios_compat.cpp $(DEPEND)
	$(CC) $(CCFLAGS) -I../stream -c ../stream/ios_compat.cpp

clean:
	$(RM) -f *.o *..c

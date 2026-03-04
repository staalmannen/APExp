#Makefile for the CC translator
#	BSD 4.2 or later should first run bsd.sed in the scratch directory
#	and set CCFLAGS=-DBSD
#	also set BSD=1

MSIZE= #-m32
CCFLAGS=-Os -g
scratchCC ?= gcc

BSD=
PATH:=$(CURDIR):$(PATH)

#For first make (bootstrap):
#	make scratch		#on system V, BSD 4.1 or earlier
#Otherwise:
#	make
#

CC	=	CC

CCOMP = gcc

.PHONY: demo
all: cfront$(EXEEXT) munch$(EXEEXT) libC.a

libC.a:	always
	cd lib/mk && $(MAKE) CC="$(CC)" CCOMP="$(CCOMP)" CCFLAGS="$(CCFLAGS)" MSIZE="$(MSIZE)" BSD=$(BSD)
	mv lib/mk/libC.a .

munch$(EXEEXT):	_munch/munch.c
	$(CCOMP) $(MSIZE) -o munch$(EXEEXT) _munch/munch.c

cfront$(EXEEXT): always
	$(MAKE)   CCOMP="$(CCOMP)" MSIZE="$(MSIZE)" -C src

cfront_c$(EXEEXT):
	-rm src/*.o
	$(MAKE) CXX=`pwd`/CC  CCOMP="$(CCOMP)" MSIZE="$(MSIZE)" -C src cfront_c$(EXEEXT)
	mv src/cfront_c$(EXEEXT) .

demo: all
	$(MAKE)   CCOMP="$(CCOMP)" MSIZE="$(MSIZE)" -C demo/hello
	$(MAKE)   CCOMP="$(CCOMP)" MSIZE="$(MSIZE)" -C demo/generic
	$(MAKE)   CCOMP="$(CCOMP)" MSIZE="$(MSIZE)" -C demo/stream

scratch: always
	cd scratch && $(MAKE) CCOMP="$(CCOMP)" CC=$(scratchCC) BSD=$(BSD) CCFLAGS="$(CCFLAGS)" MSIZE="$(MSIZE)"

#This target will populate the scratch directories with good-old-c
#files.  This is used to port to another machine.

fillscratch:
	make  CCOMP="$(CCOMP)" MSIZE="$(MSIZE)" -C src szal.result y.tab.cpp yystype.h
	cp src/_stdio.c scratch/src/
	cd scratch/src; $(CC) -I../../src         -I../../incl -Fc -..c ../../src/*.cpp;
	cd scratch/lib; $(CC) -I../../lib/complex -I../../incl -Fc -..c ../../lib/new/*.cpp
	cd scratch/lib; $(CC) -I../../lib/complex -I../../incl -Fc -..c ../../lib/static/*.cpp
	cp _munch/*.c scratch/mnch/

always:

clean:
	$(MAKE) -C src clean
	$(MAKE) -C lib/mk clean
	$(MAKE) -C demo/hello clean
	-rm -f munch$(EXEEXT) libC.a


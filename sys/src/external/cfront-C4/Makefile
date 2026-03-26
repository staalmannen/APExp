#Makefile for cfront
#	BSD 4.2 or later set CCFLAGS=-DBSD
#	also set BSD=1

MSIZE= #-m32
CCFLAGS=

BSD=
PATH:=$(CURDIR):$(PATH)

CC	=	cc

CCOMP = cc

.PHONY: demo
all: cfront$(EXEEXT) munch$(EXEEXT) libC.a

libC.a:	always
	cd lib/mk && $(MAKE) CC="$(CC)" CCOMP="$(CCOMP)" CCFLAGS="$(CCFLAGS)" MSIZE="$(MSIZE)" BSD=$(BSD)
	mv lib/mk/libC.a .

munch$(EXEEXT):	tools/_munch/munch.c
	$(CCOMP) $(MSIZE) -o munch$(EXEEXT) tools/_munch/munch.c

cfront$(EXEEXT): always
	$(MAKE)   CCOMP="$(CCOMP)" MSIZE="$(MSIZE)" -C src

demo: all
	$(MAKE)   CCOMP="$(CCOMP)" MSIZE="$(MSIZE)" -C demo/hello
	$(MAKE)   CCOMP="$(CCOMP)" MSIZE="$(MSIZE)" -C demo/generic
	$(MAKE)   CCOMP="$(CCOMP)" MSIZE="$(MSIZE)" -C demo/stream

always:

clean:
	$(MAKE) -C src clean
	$(MAKE) -C lib/mk clean
	$(MAKE) -C demo/hello clean
	-rm -f munch$(EXEEXT) libC.a


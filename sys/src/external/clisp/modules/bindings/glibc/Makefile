# Makefile for CLISP module set bindings/glibc

srcdir = .
CC = gcc
CPPFLAGS =
CFLAGS = -Wall -O2
CLISP = clisp -q -norc
CLISP_LINKKIT = $$($(CLISP) -b)/linkkit

LN = ln
LN_S = ln -s

MAKE = make

SHELL = /bin/sh

GENERATED = linux.o linux.fas wrap.fas link.sh
DISTRIBFILES = Makefile $(GENERATED) $(srcdir)/linux.lisp $(srcdir)/wrap.lisp
distribdir =

# default target: make the module
clisp-module : $(GENERATED)

linux.c linux.fas : $(srcdir)/linux.lisp
	$(CLISP) -c $(srcdir)/linux.lisp -o ./

linux.o : linux.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -I$(CLISP_LINKKIT) -c linux.c

wrap.fas: $(srcdir)/wrap.lisp
	$(CLISP) -c $(srcdir)/wrap.lisp -o ./

link.sh : $(srcdir)/link.sh
	$(LN_S) $(srcdir)/link.sh .

# Make a module distribution into $(distribdir)
clisp-module-distrib : clisp-module force
	$(LN) $(DISTRIBFILES) $(distribdir)

clean : force
	rm -f core *.o *.a *.fas *.lib

distclean : clean

force :


# Makefile for CLISP module set win32

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

# add win32.o if a C file is generated
GENERATED = link.sh win32.fas
DISTRIBFILES = Makefile $(GENERATED) $(srcdir)/win32.lisp
distribdir =

# default target: make the module
clisp-module : $(GENERATED)

win32.c win32.fas : $(srcdir)/win32.lisp
	$(CLISP) -c $(srcdir)/win32.lisp -o ./

win32.o : win32.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -I$(CLISP_LINKKIT) -c win32.c

link.sh : $(srcdir)/link.sh
	$(LN_S) $(srcdir)/link.sh .

# Make a module distribution into $(distribdir)
clisp-module-distrib : clisp-module force
	$(LN) $(DISTRIBFILES) $(distribdir)

clean : force
	rm -f core *.o *.a *.fas *.lib

distclean : clean

force :


# Makefile for the sample CLISP module QUEENS

srcdir = .

# Programs used by "make":
CC = gcc -O
CPPFLAGS =
CFLAGS = -Wall -fomit-frame-pointer -O2
CPP = gcc -O -E -w
CLFLAGS =
CLISP = clisp -q -norc
CLISP_LINKKIT = $$($(CLISP) -b)/linkkit

LN = ln
LN_S = ln -s

MAKE = make

SHELL = /bin/sh

GENERATED = queens.o callqueens.o link.sh
DISTRIBFILES = Makefile $(GENERATED)
distribdir =

# default target: make the module
clisp-module : $(GENERATED)

queens.o : $(srcdir)/queens.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $(srcdir)/queens.c

callqueens.m.c : $(srcdir)/callqueens.c
	$(CLISP) -C $(CLISP_LINKKIT)/modprep $(srcdir)/callqueens.c ./

callqueens.o : callqueens.m.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -I$(CLISP_LINKKIT) \
		-c callqueens.m.c -o callqueens.o

link.sh : $(srcdir)/link.sh
	$(LN_S) $(srcdir)/link.sh .

# Make a module distribution into $(distribdir)
clisp-module-distrib : clisp-module force
	$(LN) $(DISTRIBFILES) $(distribdir)

clean : force
	rm -f core *.o *.a *.m.c *.fas *.lib

distclean : clean

force :


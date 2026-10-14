# Makefile for CLISP module set netica
# <http://norsys.com/netica_c_api.htm>

srcdir = .
CC = gcc
CPPFLAGS =
CFLAGS = -Wall -O2
NETICA = $(NETICA_C_API)/src
CLISP = clisp -q -norc
CLISP_LINKKIT = $$($(CLISP) -b)/linkkit

LN = ln
LN_S = ln -s

MAKE = make

SHELL = /bin/sh

GENERATED = netica.o netica.fas wrap.fas link.sh
DISTRIBFILES = Makefile $(GENERATED) \
	$(srcdir)/netica.lisp $(srcdir)/wrap.lisp $(srcdir)/README
distribdir =

# default target: make the module
clisp-module : $(GENERATED)

netica.c netica.fas : $(srcdir)/netica.lisp
	$(CLISP) -c $(srcdir)/netica.lisp -o ./

netica.o : netica.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -I$(CLISP_LINKKIT) -I$(NETICA) -c netica.c

wrap.fas: $(srcdir)/wrap.lisp
	$(CLISP) -c $< -o ./

link.sh : $(srcdir)/link.sh
	$(LN_S) $(srcdir)/link.sh .

# Make a module distribution into $(distribdir)
clisp-module-distrib : clisp-module force
	$(LN) $(DISTRIBFILES) $(distribdir)

clean : force
	rm -f core *.o *.a *.fas *.lib

distclean : clean

force :


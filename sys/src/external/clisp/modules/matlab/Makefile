# Makefile for CLISP module set matlab
# <http://www.mathworks.com/access/helpdesk/help/techdoc/apiref/apiref.shtml>

srcdir = .
CC = gcc
CPPFLAGS =
CFLAGS = -Wall -O2
# MATLAB = /usr/local/matlab/extern/include
MATLAB = d:/MATLAB7/extern/include
CLISP = clisp -q -norc
CLISP_LINKKIT = $$($(CLISP) -b)/linkkit

LN = ln
LN_S = ln -s

MAKE = make

SHELL = /bin/sh

GENERATED = matlab.fas matlab.o wrap.fas link.sh
DISTRIBFILES = Makefile $(GENERATED) \
	$(srcdir)/matlab.lisp $(srcdir)/wrap.lisp
distribdir =

# default target: make the module
clisp-module : $(GENERATED)

matlab.c matlab.fas : $(srcdir)/matlab.lisp
	$(CLISP) -c $(srcdir)/matlab.lisp -o ./

matlab.o : matlab.c
	$(CC) $(CFLAGS) -I$(CLISP_LINKKIT) -I$(MATLAB) -c matlab.c

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


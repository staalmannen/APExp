
#
# Computer Algebra Kit
# Copyright (c) 1992,2024 Computer Algebra Objects.  All Rights Reserved. 
# $Id: Makefile.in,v 1.8 2025/12/31 18:16:04 stes Exp $
#

#
# This Makefile should work with UNIX make's (like AT&T, BSD, GNU make)
#

SRCDIR=.
BUILDDIR=.
MKDIR=mkdir
SED=sed
OBJC=objc -q
YACC=byacc -d
YTABH=y.tab.h
YTABC=y.tab.c
LEX=flex
LEXYYC=lex.yy.c
RM=rm -f
CP=cp -p
AR=ar cr
INSTALL=/bin/install -c
FINAL_AR=echo
RANLIB=ranlib

DBG_MFLAGS=-DDEBUG -g
OPT_MFLAGS=-DNDEBUG
REFCNTDBG_MFLAGS=-refcnt -DDEBUG -g
REFCNTOPT_MFLAGS=-refcnt -DNDEBUG
EXTRA_MFLAGS=
OBJSUFFIX=o
LIBSUFFIX=a
LIBDIR=/usr/local/lib
IFLAGS=-noI -I$(SRCDIR)/../../include/objcrt -I$(SRCDIR)/ -I.
MFLAGS=$(OPT_MFLAGS)

VPATH=$(SRCDIR)

.SUFFIXES: .m 

LIBRARY=cakit.a
SHLIB=libcakit.so

.m.o:
	$(OBJC) -c $< $(MFLAGS) $(EXTRA_MFLAGS) $(IFLAGS)
	$(AR) $(LIBRARY) $@

OBJFILES=\
	ccltn.o\
	ccltnsq.o\
	ccltnsqr.o\
	ccomplex.o\
	cfloat.o\
	fraction.o\
	integer.o\
	intmodp.o\
	matrix.o\
	 matsq.o\
	 matsqsq.o\
	monomial.o\
	 monomc.o\
	  dmonomc.o\
	  dmonoms.o\
	  smonomc.o\
	cobject.o\
	polynom.o\
	 polyeseq.o\
	 polyrseq.o\
	 polycseq.o\
	polc.o\
	 srspolc.o\
	  osrspolc.o\
	 drspolc.o\
	  odrspolc.o\
	  odrspols.o\
	  idrspolc.o\
	  idrspols.o\
	  mdrspolc.o\
	  mdrspols.o\
	 drdpolc.o\
	  odrdpolc.o\
	  odrdpols.o\
	  idrdpolc.o\
	  idrdpols.o\
	  mdrdpolc.o\
	  mdrdpols.o\
	 sespolc.o\
	  osespolc.o\
	 despolc.o\
	  odespolc.o\
	  odespols.o\
	  idespolc.o\
	  idespols.o\
	  mdespolc.o\
	  mdespols.o\
	cseq.o\
	 cseqc.o\
	symbol.o\
	term.o\
	vector.o\
	 vectorc.o\
	  ovectorc.o\
	  ovectors.o\
	  mvectorc.o\
	  mvectors.o\
	  ivectorc.o\
	  ivectors.o

$(LIBRARY) : $(OBJFILES)
	$(FINAL_AR) $(LIBRARY) $(OBJFILES)
	$(RANLIB) $(LIBRARY)

shlib : $(OBJFILES)
	$(OBJC) -dl $(OBJFILES) -o $(SHLIB)

install : $(LIBRARY)
	test -d $(LIBDIR) || $(MKDIR) $(LIBDIR)
	-$(INSTALL) $(LIBRARY) $(LIBDIR)

cleantmp :
	-$(RM) *.P
	-$(RM) *.c
	-$(RM) *.i

clean : cleantmp
	-$(RM) *.o
	-$(RM) *.a

distclean : clean
	-$(RM) Makefile 
	-$(RM) config.h 


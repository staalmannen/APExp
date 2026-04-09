
#
# Portable Object Compiler (c) 1996-2021. All Rights Reserved.
# $Id: Makefile.in,v 1.13 2025/12/31 18:15:40 stes Exp $
#

#
# This Makefile should work with UNIX make's (like SysV, BSD, GNU make)
#

SRCDIR=.
BUILDDIR=.
MKDIR=mkdir
OBJC=objc -q
RM=rm -f
CP=cp -p
INSTALL=/bin/install -c
# configure AR=echo FINAL_AR='ar cr' if you want a single ar invocation
AR=ar cr
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

LIBRARY=objpak.$(LIBSUFFIX)
SHLIB=libobjpak.so

OBJFILES=\
	ascfiler.$(OBJSUFFIX)\
	  notfound.$(OBJSUFFIX)\
	  outofbnd.$(OBJSUFFIX)\
	  unknownt.$(OBJSUFFIX)\
	  typeinc.$(OBJSUFFIX)\
	  badvers.$(OBJSUFFIX)\
	cltn.$(OBJSUFFIX)\
	  ordcltn.$(OBJSUFFIX)\
	  sortcltn.$(OBJSUFFIX)\
	  set.$(OBJSUFFIX)\
	  bag.$(OBJSUFFIX)\
	  stack.$(OBJSUFFIX)\
	  runarray.$(OBJSUFFIX)\
        dictnary.$(OBJSUFFIX)\
	sequence.$(OBJSUFFIX)\
	array.$(OBJSUFFIX)\
	  ocstring.$(OBJSUFFIX)\
	  idarray.$(OBJSUFFIX)\
	  intarray.$(OBJSUFFIX)\
	rectangl.$(OBJSUFFIX)\
	point.$(OBJSUFFIX)\
	assoc.$(OBJSUFFIX)\
	objgraph.$(OBJSUFFIX)\
	cltnseq.$(OBJSUFFIX)\
	keyseq.$(OBJSUFFIX)\
	valueseq.$(OBJSUFFIX)\
	setseq.$(OBJSUFFIX)\
	bagseq.$(OBJSUFFIX)\
	treeseq.$(OBJSUFFIX)\
	octext.$(OBJSUFFIX)\
	txtstyle.$(OBJSUFFIX)\
	paragrph.$(OBJSUFFIX)\
	txtattr.$(OBJSUFFIX)

.m.o:
	$(OBJC) -c $< $(MFLAGS) $(EXTRA_MFLAGS) $(IFLAGS)
	$(AR) $(LIBRARY) $@ 

$(LIBRARY) : $(OBJFILES)
	$(FINAL_AR) $(LIBRARY) $(OBJFILES)
	$(RANLIB) $(LIBRARY)

$(SHLIB) : $(OBJFILES)
	$(OBJC) -dl $(EXTRA_MFLAGS) $(OBJFILES) -o $(SHLIB)

shlib : $(SHLIB)

install : $(LIBRARY)
	test -d $(LIBDIR) || $(MKDIR) $(LIBDIR)
	-$(INSTALL) $(LIBRARY) $(LIBDIR)

installshlib: $(SHLIB)
	test -d $(LIBDIR) || $(MKDIR) $(LIBDIR)
	-$(INSTALL) $(SHLIB) $(LIBDIR)

cleantmp :
	-$(RM) *.P
	-$(RM) *.c
	-$(RM) *.i

clean : cleantmp
	-$(RM) *.$(OBJSUFFIX)
	-$(RM) *.$(LIBSUFFIX)
	-$(RM) $(SHLIB)

distclean : clean
	-$(RM) Makefile 
	-$(RM) config.h 


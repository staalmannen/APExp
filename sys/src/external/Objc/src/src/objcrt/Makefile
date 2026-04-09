
#
# Portable Object Compiler (c) 1996-2022. All Rights Reserved.
# $Id: Makefile.in,v 1.13 2025/12/31 18:15:52 stes Exp $
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
MFLAGS=$(OPT_MFLAGS)
EXTRA_MFLAGS=
OBJSUFFIX=o
LIBSUFFIX=a
LIBDIR=/usr/local/lib
IFLAGS=-noI -I$(SRCDIR)/ -I.

VPATH=$(SRCDIR)

.SUFFIXES: .m 

LIBRARY=objcrt.$(LIBSUFFIX)
SHLIB=libobjcrt.so

OBJFILES=\
	Object.$(OBJSUFFIX)\
	Block.$(OBJSUFFIX)\
	Message.$(OBJSUFFIX)\
	Exceptn.$(OBJSUFFIX)\
	OutOfMem.$(OBJSUFFIX)\
	objcrt.$(OBJSUFFIX)

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

installshlib : $(SHLIB)
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


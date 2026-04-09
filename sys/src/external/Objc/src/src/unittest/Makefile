
#
# Portable Object Compiler (c) 2025.  All Rights Reserved. 
# $Id: Makefile.in,v 1.9 2025/12/31 18:15:24 stes Exp $
#

#
# This Makefile should work with UNIX make (like SysV, BSD, GNU make)
#

SRCDIR=.
BUILDDIR=.
CD=cd
MKDIR=mkdir
STRIP=strip
CHMOD=chmod
RM=rm -f
CP=cp -p
AR=ar cr
INSTALL=/bin/install -c
FINAL_AR=echo
RANLIB=ranlib

CC=cc
DBG_MFLAGS=-DDEBUG -g
OPT_MFLAGS=-DNDEBUG
REFCNTDBG_MFLAGS=-refcnt -DDEBUG -g
REFCNTOPT_MFLAGS=-refcnt -DNDEBUG
EXTRA_MFLAGS=
OBJSUFFIX=o
LIBSUFFIX=a
BINDIR=/usr/local/bin
LIBDIR=/usr/local/lib
IFLAGS=-noI -I$(SRCDIR)/../../include/objcrt -I$(SRCDIR)/../../include/objpak -I$(SRCDIR)/../../include/cakit -I$(SRCDIR)/ -I.
BOOTLIBS=-noLibs ../cakit/cakit.a ../objpak/objpak.a ../objcrt/objcrt.a
DEPENDLIBS=../objcrt/objcrt.$(LIBSUFFIX) \
           ../objpak/objpak.$(LIBSUFFIX) \
           ../cakit/cakit.$(LIBSUFFIX)

MFLAGS=$(OPT_MFLAGS)

#
# Link the objut test program to BOOTLIBS
# the libraries that are not yet installed;  this is so that "make check"
# can test those libraries before they are installed by "make install"
# use XOBJC for the build (as is used to build objc1 itself)
#

OBJC=/bin/objc

VPATH=$(SRCDIR)

.SUFFIXES: .m

OBJUTPROGRAM=objut

OBJUTFILES=\
	testste.$(OBJSUFFIX)\
	testcase.$(OBJSUFFIX)\
	classcnt.$(OBJSUFFIX)\
	bagtest.$(OBJSUFFIX)\
	factest.$(OBJSUFFIX)\
	ordctest.$(OBJSUFFIX)\
	seqtest.$(OBJSUFFIX)\
	zashaus.$(OBJSUFFIX)\
	quofield.$(OBJSUFFIX)\
	galfield.$(OBJSUFFIX)\
	bigrand.$(OBJSUFFIX)\
	shanks.$(OBJSUFFIX)\
	legendre.$(OBJSUFFIX)\
	bezout.$(OBJSUFFIX)\
	perfect.$(OBJSUFFIX)\
	mvartest.$(OBJSUFFIX)\
	fddtest.$(OBJSUFFIX)\
	lgndtest.$(OBJSUFFIX)\
	objut.$(OBJSUFFIX)

.m.$(OBJSUFFIX):
	$(OBJC) -c $< $(MFLAGS) $(EXTRA_MFLAGS) $(IFLAGS)

check : $(OBJUTPROGRAM)
	$(BUILDDIR)/$(OBJUTPROGRAM)

#because PerfectNumberTest uses cakit and because "make test" is assumed
#to be running before cakit is installed, use BOOTLIBS with -noLibs flag

$(OBJUTPROGRAM) : $(OBJUTFILES) $(DEPENDLIBS)
	$(OBJC) $(EXTRA_MFLAGS) $(OBJUTFILES) $(BOOTLIBS) -o $(OBJUTPROGRAM)

cleantmp :
	-$(RM) *.P
	-$(RM) *.i

clean : cleantmp
	-$(RM) *.$(OBJSUFFIX)
	-$(RM) *.$(LIBSUFFIX)
	-$(RM) $(OBJUTPROGRAM)

distclean : clean
	-$(RM) core 
	-$(RM) Makefile 
	-$(RM) config.h 


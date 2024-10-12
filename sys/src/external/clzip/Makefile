# Makefile for Clzip - LZMA lossless data compressor
# Copyright (C) 2010-2024 Antonio Diaz Diaz.
# This file was generated automatically by configure. Don't edit.
#
# This Makefile is free software: you have unlimited permission
# to copy, distribute, and modify it.

pkgname = clzip
pkgversion = 1.14
progname = clzip
VPATH = .
prefix = /usr/local
exec_prefix = $(prefix)
bindir = $(exec_prefix)/bin
datarootdir = $(prefix)/share
infodir = $(datarootdir)/info
mandir = $(datarootdir)/man
CC = cc
CPPFLAGS = 
CFLAGS = -O2
LDFLAGS = 
MAKEINFO = makeinfo

DISTNAME = $(pkgname)-$(pkgversion)
INSTALL = install
INSTALL_PROGRAM = $(INSTALL) -m 755
INSTALL_DATA = $(INSTALL) -m 644
INSTALL_DIR = $(INSTALL) -d -m 755
SHELL = /bin/sh
CAN_RUN_INSTALLINFO = $(SHELL) -c "install-info --version" > /dev/null 2>&1

objs = carg_parser.o lzip_index.o list.o encoder_base.o encoder.o \
       fast_encoder.o decoder.o main.o


.PHONY : all install install-bin install-info install-man \
         install-strip install-compress install-strip-compress \
         install-bin-strip install-info-compress install-man-compress \
         install-as-lzip \
         uninstall uninstall-bin uninstall-info uninstall-man \
         doc info man check dist clean distclean

all : $(progname)

$(progname) : $(objs)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(objs)

main.o : main.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -DPROGVERSION=\"$(pkgversion)\" -c -o $@ $<

%.o : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

# prevent 'make' from trying to remake source files
$(VPATH)/configure $(VPATH)/Makefile.in $(VPATH)/doc/$(pkgname).texi : ;
%.h %.c : ;

$(objs)        : Makefile
carg_parser.o  : carg_parser.h
decoder.o      : lzip.h decoder.h
encoder_base.o : lzip.h encoder_base.h
encoder.o      : lzip.h encoder_base.h encoder.h
fast_encoder.o : lzip.h encoder_base.h fast_encoder.h
list.o         : lzip.h lzip_index.h
lzip_index.o   : lzip.h lzip_index.h
main.o         : carg_parser.h lzip.h decoder.h encoder_base.h encoder.h fast_encoder.h

doc : info man

info : $(VPATH)/doc/$(pkgname).info

$(VPATH)/doc/$(pkgname).info : $(VPATH)/doc/$(pkgname).texi
	cd $(VPATH)/doc && $(MAKEINFO) $(pkgname).texi

man : $(VPATH)/doc/$(progname).1

$(VPATH)/doc/$(progname).1 : $(progname)
	help2man -n 'reduces the size of files' -o $@ ./$(progname)

Makefile : $(VPATH)/configure $(VPATH)/Makefile.in
	./config.status

check : all
	@$(VPATH)/testsuite/check.sh $(VPATH)/testsuite $(pkgversion)

install : install-bin install-info install-man
install-strip : install-bin-strip install-info install-man
install-compress : install-bin install-info-compress install-man-compress
install-strip-compress : install-bin-strip install-info-compress install-man-compress

install-bin : all
	if [ ! -d "$(DESTDIR)$(bindir)" ] ; then $(INSTALL_DIR) "$(DESTDIR)$(bindir)" ; fi
	$(INSTALL_PROGRAM) ./$(progname) "$(DESTDIR)$(bindir)/$(progname)"

install-bin-strip : all
	$(MAKE) INSTALL_PROGRAM='$(INSTALL_PROGRAM) -s' install-bin

install-info :
	if [ ! -d "$(DESTDIR)$(infodir)" ] ; then $(INSTALL_DIR) "$(DESTDIR)$(infodir)" ; fi
	-rm -f "$(DESTDIR)$(infodir)/$(pkgname).info"*
	$(INSTALL_DATA) $(VPATH)/doc/$(pkgname).info "$(DESTDIR)$(infodir)/$(pkgname).info"
	-if $(CAN_RUN_INSTALLINFO) ; then \
	  install-info --info-dir="$(DESTDIR)$(infodir)" "$(DESTDIR)$(infodir)/$(pkgname).info" ; \
	fi

install-info-compress : install-info
	lzip -v -9 "$(DESTDIR)$(infodir)/$(pkgname).info"

install-man :
	if [ ! -d "$(DESTDIR)$(mandir)/man1" ] ; then $(INSTALL_DIR) "$(DESTDIR)$(mandir)/man1" ; fi
	-rm -f "$(DESTDIR)$(mandir)/man1/$(progname).1"*
	$(INSTALL_DATA) $(VPATH)/doc/$(progname).1 "$(DESTDIR)$(mandir)/man1/$(progname).1"

install-man-compress : install-man
	lzip -v -9 "$(DESTDIR)$(mandir)/man1/$(progname).1"

install-as-lzip : install
	-rm -f "$(DESTDIR)$(bindir)/lzip"
	cd "$(DESTDIR)$(bindir)" && ln -s $(progname) lzip

uninstall : uninstall-man uninstall-info uninstall-bin

uninstall-bin :
	-rm -f "$(DESTDIR)$(bindir)/$(progname)"

uninstall-info :
	-if $(CAN_RUN_INSTALLINFO) ; then \
	  install-info --info-dir="$(DESTDIR)$(infodir)" --remove "$(DESTDIR)$(infodir)/$(pkgname).info" ; \
	fi
	-rm -f "$(DESTDIR)$(infodir)/$(pkgname).info"*

uninstall-man :
	-rm -f "$(DESTDIR)$(mandir)/man1/$(progname).1"*

dist : doc
	ln -sf $(VPATH) $(DISTNAME)
	tar -Hustar --owner=root --group=root -cvf $(DISTNAME).tar \
	  $(DISTNAME)/AUTHORS \
	  $(DISTNAME)/COPYING \
	  $(DISTNAME)/ChangeLog \
	  $(DISTNAME)/INSTALL \
	  $(DISTNAME)/Makefile.in \
	  $(DISTNAME)/NEWS \
	  $(DISTNAME)/README \
	  $(DISTNAME)/configure \
	  $(DISTNAME)/doc/$(progname).1 \
	  $(DISTNAME)/doc/$(pkgname).info \
	  $(DISTNAME)/doc/$(pkgname).texi \
	  $(DISTNAME)/*.h \
	  $(DISTNAME)/*.c \
	  $(DISTNAME)/testsuite/check.sh \
	  $(DISTNAME)/testsuite/test.txt \
	  $(DISTNAME)/testsuite/fox.lz \
	  $(DISTNAME)/testsuite/fox_*.lz \
	  $(DISTNAME)/testsuite/fox6.lz \
	  $(DISTNAME)/testsuite/fox6_mark.lz \
	  $(DISTNAME)/testsuite/test.txt.lz \
	  $(DISTNAME)/testsuite/test_em.txt.lz
	rm -f $(DISTNAME)
	lzip -v -9 $(DISTNAME).tar

clean :
	-rm -f $(progname) $(objs)

distclean : clean
	-rm -f Makefile config.status *.tar *.tar.lz

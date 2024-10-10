#
# Simple makefile for the sample loadable builtins
#
# Copyright (C) 1996-2022 Free Software Foundation, Inc.

#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

PACKAGE = bash
VERSION = 5.2-release

# Include some boilerplate Gnu makefile definitions.
prefix = /usr/local

exec_prefix = ${prefix}
bindir = ${exec_prefix}/bin
libdir = ${exec_prefix}/lib
infodir = ${datarootdir}/info
includedir = ${prefix}/include

datarootdir = ${prefix}/share

loadablesdir = ${libdir}/bash
headersdir = $(includedir)/$(PACKAGE_NAME)

topdir = ../..
BUILD_DIR = /usr/glenda/APExp/sys/src/external/bash
srcdir = .


# Support an alternate destination root directory for package building
DESTDIR =

INSTALL = /bin/install -c
INSTALL_PROGRAM = ${INSTALL}
INSTALL_SCRIPT = ${INSTALL}
INSTALL_DATA = ${INSTALL} -m 644
INSTALLMODE= -m 0755


CC = cc
RM = rm -f

SHELL = /bin/sh

host_os = plan9
host_cpu = x86_64
host_vendor = unknown

STYLE_CFLAGS =  
CFLAGS = -g
LOCAL_CFLAGS = 
DEFS = -DHAVE_CONFIG_H
LOCAL_DEFS = -DSHELL

CPPFLAGS = 

BASHINCDIR = ${topdir}/include

SUPPORT_SRC = $(topdir)/support/

LIBBUILD = ${BUILD_DIR}/lib

INTL_LIBSRC = ${topdir}/lib/intl
INTL_BUILDDIR = ${LIBBUILD}/intl
INTL_INC = -I${INTL_LIBSRC} -I${INTL_BUILDDIR}
LIBINTL_H = ${INTL_BUILDDIR}/libintl.h

CCFLAGS = $(DEFS) $(LOCAL_DEFS) $(LOCAL_CFLAGS) $(CPPFLAGS) $(CFLAGS) $(STYLE_CFLAGS)

#
# These values are generated for configure by ${topdir}/support/shobj-conf.
# If your system is not supported by that script, but includes facilities for
# dynamic loading of shared objects, please update the script and send the
# changes to bash-maintainers@gnu.org.
#
SHOBJ_CC = 
SHOBJ_CFLAGS = 
SHOBJ_LD = 
SHOBJ_LDFLAGS =  
SHOBJ_XLDFLAGS = 
SHOBJ_LIBS = 
SHOBJ_STATUS = unsupported

INC = -I. -I.. -I$(topdir) -I$(topdir)/lib -I$(topdir)/builtins -I${srcdir} \
      -I$(BASHINCDIR) -I$(BUILD_DIR) -I$(LIBBUILD) \
      -I$(BUILD_DIR)/builtins $(INTL_INC)

.c.o:
	$(SHOBJ_CC) $(SHOBJ_CFLAGS) $(CCFLAGS) $(INC) -c -o $@ $<


ALLPROG = print truefalse sleep finfo logname basename dirname fdflags \
	  tty pathchk tee head mkdir rmdir mkfifo mktemp printenv id whoami \
	  uname sync push ln unlink realpath strftime mypid setpgid seq rm \
	  accept csv dsv cut stat getconf
OTHERPROG = necho hello cat pushd asort

all:	$(SHOBJ_STATUS)

supported:	$(ALLPROG)
others:		$(OTHERPROG)

unsupported:
	@echo "Your system (${host_os}) is not supported by the"
	@echo "${topdir}/support/shobj-conf script."
	@echo "If your operating system provides facilities for dynamic"
	@echo "loading of shared objects using the dlopen(3) interface,"
	@echo "please update the script and re-run configure."
	@echo "Please send the changes you made to bash-maintainers@gnu.org"
	@echo "for inclusion in future bash releases."

everything: supported others

print:	print.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ print.o $(SHOBJ_LIBS)

necho:	necho.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ necho.o $(SHOBJ_LIBS)

hello:	hello.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ hello.o $(SHOBJ_LIBS)

truefalse: truefalse.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ truefalse.o $(SHOBJ_LIBS)

accept:	accept.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ accept.o $(SHOBJ_LIBS)

sleep:	sleep.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ sleep.o $(SHOBJ_LIBS)

finfo:	finfo.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ finfo.o $(SHOBJ_LIBS)

cat:	cat.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ cat.o $(SHOBJ_LIBS)

rm:	rm.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ rm.o $(SHOBJ_LIBS)

fdflags:	fdflags.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ fdflags.o $(SHOBJ_LIBS)

seq:	seq.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ seq.o $(SHOBJ_LIBS)

logname:	logname.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ logname.o $(SHOBJ_LIBS)

basename:	basename.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ basename.o $(SHOBJ_LIBS)

dirname:	dirname.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ dirname.o $(SHOBJ_LIBS)

tty:	tty.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ tty.o $(SHOBJ_LIBS)

pathchk:	pathchk.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ pathchk.o $(SHOBJ_LIBS)

tee:	tee.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ tee.o $(SHOBJ_LIBS)

mkdir:	mkdir.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ mkdir.o $(SHOBJ_LIBS)

rmdir:	rmdir.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ rmdir.o $(SHOBJ_LIBS)

mkfifo:	mkfifo.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ mkfifo.o $(SHOBJ_LIBS)

mktemp:	mktemp.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ mktemp.o $(SHOBJ_LIBS)

head:	head.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ head.o $(SHOBJ_LIBS)

printenv:	printenv.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ printenv.o $(SHOBJ_LIBS)

getconf:	getconf.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ getconf.o $(SHOBJ_LIBS)

id:	id.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ id.o $(SHOBJ_LIBS)

whoami:	whoami.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ whoami.o $(SHOBJ_LIBS)

uname:	uname.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ uname.o $(SHOBJ_LIBS)

sync:	sync.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ sync.o $(SHOBJ_LIBS)

push:	push.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ push.o $(SHOBJ_LIBS)

ln:	ln.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ ln.o $(SHOBJ_LIBS)

unlink:	unlink.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ unlink.o $(SHOBJ_LIBS)

realpath:	realpath.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ realpath.o $(SHOBJ_LIBS)

csv:	csv.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ csv.o $(SHOBJ_LIBS)

dsv:	dsv.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ dsv.o $(SHOBJ_LIBS)

cut:	cut.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ cut.o $(SHOBJ_LIBS)

strftime:	strftime.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ strftime.o $(SHOBJ_LIBS)

mypid:	mypid.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ mypid.o $(SHOBJ_LIBS)

setpgid:	setpgid.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ setpgid.o $(SHOBJ_LIBS)

stat:	stat.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ stat.o $(SHOBJ_LIBS)

asort:	asort.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ asort.o $(SHOBJ_LIBS)

# pushd is a special case.  We use the same source that the builtin version
# uses, with special compilation options.
#
pushd.c:	${topdir}/builtins/pushd.def
	$(RM) $@
	${BUILD_DIR}/builtins/mkbuiltins -D ${topdir}/builtins ${topdir}/builtins/pushd.def

pushd.o:	pushd.c
	$(RM) $@
	$(SHOBJ_CC) -Wno-format-security -DHAVE_CONFIG_H -DPUSHD_AND_POPD -DLOADABLE_BUILTIN $(SHOBJ_CFLAGS) $(CFLAGS) $(CPPFLAGS) $(INC) -c -o $@ $<

pushd:	pushd.o
	$(SHOBJ_LD) $(SHOBJ_LDFLAGS) $(SHOBJ_XLDFLAGS) -o $@ pushd.o $(SHOBJ_LIBS)

clean:
	$(RM) $(ALLPROG) $(OTHERPROG) *.o
	-( cd perl && ${MAKE} ${MFLAGS} $@ )

mostlyclean:	clean
	-( cd perl && ${MAKE} ${MFLAGS} $@ )

distclean maintainer-clean: clean
	$(RM) Makefile Makefile.inc Makefile.sample pushd.c
	-( cd perl && ${MAKE} ${MFLAGS} $@ )

installdirs:
	@${SHELL} $(SUPPORT_SRC)mkinstalldirs $(DESTDIR)$(loadablesdir)

install-dev:	installdirs
	@$(INSTALL_DATA) Makefile.inc $(DESTDIR)$(loadablesdir)/Makefile.inc
	@$(INSTALL_DATA) Makefile.sample $(DESTDIR)$(loadablesdir)/Makefile.sample
	@$(INSTALL_DATA) $(srcdir)/loadables.h $(DESTDIR)$(loadablesdir)/loadables.h
	@( cd $(BUILD_DIR) && ${MAKE} ${MFLAGS} DESTDIR="$(DESTDIR)" install-headers)

install-supported:	all installdirs install-dev
	@echo installing example loadable builtins in $(DESTDIR)${loadablesdir}
	@for prog in ${ALLPROG}; do \
		echo $$prog ; \
		$(INSTALL_PROGRAM) $(INSTALLMODE) $$prog $(DESTDIR)$(loadablesdir)/$$prog ;\
	done

uninstall-dev:
	-$(RM) $(DESTDIR)$(loadablesdir)/Makefile.inc $(DESTDIR)$(loadablesdir)/Makefile.sample
	-$(RM) $(DESTDIR)$(loadablesdir)/loadables.h
	-( cd $(BUILD_DIR) && ${MAKE} ${MFLAGS} DESTDIR="$(DESTDIR)" uninstall-headers)

uninstall-supported:	uninstall-dev
	-( cd $(DESTDIR)${loadablesdir} && $(RM) ${ALLPROG} )

install-unsupported:
uninstall-unsupported:

install:	install-$(SHOBJ_STATUS)
uninstall:	uninstall-$(SHOBJ_STATUS)

print.o: print.c
truefalse.o: truefalse.c
accept.o: accept.c
sleep.o: sleep.c
finfo.o: finfo.c
getconf.o: getconf.c getconf.h
logname.o: logname.c
basename.o: basename.c
dirname.o: dirname.c
tty.o: tty.c
pathchk.o: pathchk.c
tee.o: tee.c
head.o: head.c
rmdir.o: rmdir.c
necho.o: necho.c
hello.o: hello.c
cat.o: cat.c
csv.o: csv.c
dsv.o: dsv.c
cut.o: cut.c
printenv.o: printenv.c
id.o: id.c
whoami.o: whoami.c
uname.o: uname.c
sync.o: sync.c
push.o: push.c
mkdir.o: mkdir.c
mktemp.o: mktemp.c
realpath.o: realpath.c
strftime.o: strftime.c
setpgid.o: setpgid.c
stat.o: stat.c
fdflags.o: fdflags.c
seq.o: seq.c
asort.o: asort.c

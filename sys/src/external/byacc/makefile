# $Id: makefile.in,v 1.16 2010/06/09 09:46:37 tom Exp $
#
# UNIX template-makefile for Berkeley Yacc

THIS		= yacc

#### Start of system configuration section. ####

srcdir 		= .


CC		= cc

INSTALL		= /bin/install -c
INSTALL_PROGRAM	= ${INSTALL}
INSTALL_DATA	= ${INSTALL} -m 644
transform	= s,x,x,

DEFINES		=
EXTRA_CFLAGS	= 
CPPFLAGS	= -I. -I$(srcdir) $(DEFINES) -DHAVE_CONFIG_H -DYYPATCH=`cat $(srcdir)/VERSION`   -D_XOPEN_SOURCE=500  -D_POSIX_C_SOURCE=199506L
CFLAGS		= -D_POSIX_SOURCE -D_BSD_EXTENSION $(CPPFLAGS) $(EXTRA_CFLAGS)

LDFLAGS		= 
LIBS		= 

CTAGS		= 
ETAGS		= 
LINT		= 

prefix		= /lib
exec_prefix	= /386/bin

bindir		= $(DESTDIR)/386/bin
mandir		= $(DESTDIR)${prefix}/man/man1
manext		= 1

testdir		= $(srcdir)/test

x		= 
o		= .o

#### End of system configuration section. ####

SHELL		= /bin/sh


H_FILES = \
	defs.h

C_FILES = \
	closure.c \
	error.c \
	graph.c \
	lalr.c \
	lr0.c \
	main.c \
	mkpar.c \
	output.c \
	reader.c \
	skeleton.c \
	symtab.c \
	verbose.c \
	warshall.c

OBJS	= \
	closure$o \
	error$o \
	graph$o \
	lalr$o \
	lr0$o \
	main$o \
	mkpar$o \
	output$o \
	reader$o \
	skeleton$o \
	symtab$o \
	verbose$o \
	warshall$o

TRANSFORM_BIN = sed 's/$x$$//'       |sed '$(transform)'|sed 's/$$/$x/'
TRANSFORM_MAN = sed 's/$(manext)$$//'|sed '$(transform)'|sed 's/$$/$(manext)/'

actual_bin = `echo $(THIS)$x        | $(TRANSFORM_BIN)`
actual_man = `echo $(THIS).$(manext)| $(TRANSFORM_MAN)`

all : $(THIS)$x

install: all installdirs
	$(INSTALL_PROGRAM) $(THIS)$x $(bindir)/$(actual_bin)
	- $(INSTALL_DATA) $(srcdir)/$(THIS).1 $(mandir)/$(actual_man)

installdirs:
	mkdir -p $(bindir)
	- mkdir -p $(mandir)

uninstall:
	- rm -f $(bindir)/$(actual_bin)
	- rm -f $(mandir)/$(actual_man)

################################################################################
.SUFFIXES : $o .i .html .$(manext) .cat .ps .pdf .txt

.c$o:
	
	$(CC) -c $(CFLAGS) $<

.c.i :
	
	$(CPP) -C $(CPPFLAGS) $*.c >$@

.$(manext).cat :
	- nroff -man $(srcdir)/$(THIS).$(manext) >$@

.$(manext).html :
	GROFF_NO_SGR=stupid $(SHELL) -c "tbl $*.$(manext) | groff -Thtml -man" >$@

.$(manext).ps :
	$(SHELL) -c "tbl $*.$(manext) | groff -man" >$@

.$(manext).txt :
	GROFF_NO_SGR=stupid $(SHELL) -c "tbl $*.$(manext) | nroff -Tascii -man | col -bx" >$@

.ps.pdf :
	ps2pdf $*.ps

################################################################################

$(THIS)$x : $(OBJS)
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

mostlyclean :
	- rm -f core .nfs* *$o *.bak *.BAK *.out

clean : mostlyclean
	- rm -f $(THIS)$x

distclean : clean
	- rm -f config.log config.cache config.status config.h makefile
	- rm -f *.html *.cat *.pdf *.ps *.txt
	- cd test && rm -f test-*

realclean: distclean
	- rm -f tags TAGS

################################################################################
docs :: $(THIS).html \
	$(THIS).pdf \
	$(THIS).ps \
	$(THIS).txt
$(THIS).html : $(THIS).$(manext)
$(THIS).pdf : $(THIS).ps
$(THIS).ps : $(THIS).$(manext)
$(THIS).txt : $(THIS).$(manext)
################################################################################
check:	$(THIS)$x
	$(SHELL) $(testdir)/run_test.sh $(testdir)

check_make:
	$(SHELL) $(testdir)/run_make.sh $(testdir)

check_lint:
	$(SHELL) $(testdir)/run_lint.sh $(testdir)
################################################################################
tags: $(H_FILES) $(C_FILES) 
	$(CTAGS) $(C_FILES) $(H_FILES)

lint: $(C_FILES) 
	$(LINT) $(CPPFLAGS) $(C_FILES)

#TAGS: $(H_FILES) $(C_FILES) 
#	$(ETAGS) $(C_FILES) $(H_FILES)

depend:
	makedepend -- $(CPPFLAGS) -- $(C_FILES)

$(OBJS) : defs.h

main$o \
skeleton$o : makefile VERSION

# DO NOT DELETE THIS LINE -- make depend depends on it.

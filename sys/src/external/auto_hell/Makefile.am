noinst_PROGRAMS = satan/satan demiurge/demiurge

AM_CFLAGS = -O2 -Wall -Wextra -std=c99 -D_POSIX_C_SOURCE=200809L -Imacros -Idemiurge

satan_satan_SOURCES = \
	satan/main.c \
	satan/gen.c \
	satan/probe.c \
	satan/am.c \
	satan/conf.c \
	satan/map.c \
	satan/vec.c \
	satan/str.c \
	satan/util.c \
	satan/amparse.y \
	satan/amlex.l

BUILT_SOURCES = satan/amparse.h

demiurge_demiurge_SOURCES = \
	demiurge/demiurge.c \
	demiurge/macro.c \
	macros/builtins.c \
	satan/map.c \
	satan/vec.c \
	satan/str.c \
	satan/util.c \
	satan/conf.c

demiurge_demiurge_CFLAGS = $(AM_CFLAGS) -Isatan

install-exec-local:
	$(INSTALL) -d $(DESTDIR)$(bindir)
	$(INSTALL_PROGRAM) satan/satan $(DESTDIR)$(bindir)/satan
	$(INSTALL_PROGRAM) demiurge/demiurge $(DESTDIR)$(bindir)/demiurge

CLEANFILES = satan/amparse.c satan/amparse.h satan/amlex.c



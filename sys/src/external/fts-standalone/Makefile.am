ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}

LIBFTS_CURRENT=1
LIBFTS_REVISION=0
LIBFTS_AGE=0

lib_LTLIBRARIES = \
        libfts.la

libfts_la_SOURCES =\
	fts.c \
	fts.h \
	fts.sym

libfts_la_CFLAGS = \
        $(AM_CFLAGS) \
        -fvisibility=default

libfts_la_LDFLAGS = \
        $(AM_LDFLAGS) \
        -version-info $(LIBFTS_CURRENT):$(LIBFTS_REVISION):$(LIBFTS_AGE) \
        -Wl,--version-script=$(top_srcdir)/fts.sym

include_HEADERS = \
        fts.h

dist_man_MANS = \
	fts.3

EXTRA_DIST = \
	LICENSE \
	README.md

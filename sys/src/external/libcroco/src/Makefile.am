NULL =

lib_LTLIBRARIES=libcroco-0.6.la

if PLATFORM_WIN32
no_undefined = -no-undefined
endif

#Headers files to be distributed
crocoincdir = $(includedir)/$(PACKAGE)-$(LIBCROCO_MAJOR_VERSION).$(LIBCROCO_MINOR_VERSION)/libcroco
crocoinc_HEADERS = \
	libcroco.h \
	cr-additional-sel.h \
	cr-attr-sel.h \
	cr-cascade.h \
	cr-declaration.h \
	cr-doc-handler.h \
	cr-enc-handler.h \
	cr-input.h \
	cr-num.h \
	cr-om-parser.h \
	cr-parser.h \
	cr-pseudo.h \
	cr-rgb.h \
	cr-selector.h \
	cr-simple-sel.h \
	cr-statement.h \
	cr-stylesheet.h \
	cr-term.h \
	cr-tknzr.h \
	cr-token.h \
	cr-utils.h \
	cr-fonts.h \
	cr-sel-eng.h \
	cr-style.h \
	cr-prop-list.h \
	cr-parsing-location.h \
	cr-string.h \
	libcroco-config.h \
	$(NULL)

libcroco_0_6_la_SOURCES = \
	cr-utils.c \
	cr-utils.h \
	cr-input.c \
	cr-input.h \
	cr-enc-handler.c \
	cr-enc-handler.h \
	cr-num.c \
	cr-num.h \
	cr-rgb.c \
	cr-rgb.h \
	cr-token.c \
	cr-token.h \
	cr-tknzr.c \
	cr-tknzr.h \
	cr-term.c \
	cr-term.h \
	cr-attr-sel.c \
	cr-attr-sel.h \
	cr-pseudo.c \
	cr-pseudo.h \
	cr-additional-sel.c \
	cr-additional-sel.h \
	cr-simple-sel.c \
	cr-simple-sel.h \
	cr-selector.c \
	cr-selector.h \
	cr-doc-handler.c \
	cr-doc-handler.h \
	cr-parser.c \
	cr-parser.h \
	cr-declaration.c \
	cr-declaration.h \
	cr-statement.c \
	cr-statement.h \
	cr-stylesheet.c \
	cr-stylesheet.h \
	cr-cascade.c \
	cr-cascade.h \
	cr-om-parser.c \
	cr-om-parser.h \
	cr-style.c \
	cr-style.h \
	cr-sel-eng.c \
	cr-sel-eng.h \
	cr-fonts.c \
	cr-fonts.h \
	cr-prop-list.c \
	cr-prop-list.h \
	cr-parsing-location.c \
	cr-parsing-location.h \
	cr-string.c \
	cr-string.h \
	$(NULL)

libcroco_0_6_la_CPPFLAGS = \
	-I$(top_srcdir) \
	-I$(top_srcdir)/intl \
	-I$(top_builddir)/src \
	$(AM_CPPFLAGS)

libcroco_0_6_la_CFLAGS = \
	$(CROCO_CFLAGS) \
	$(AM_CFLAGS)

libcroco_0_6_la_LDFLAGS = \
	-version-info @LIBCROCO_VERSION_INFO@ \
	$(no_undefined) \
	$(BSYMBOLIC_LDFLAG) \
	$(AM_LDFLAGS)

libcroco_0_6_la_LIBADD = \
	$(CROCO_LIBS)

EXTRA_DIST = libcroco.symbols

# MSVC Build Items

MSVCPROJS = croco

croco_FILES = $(libcroco_0_6_la_SOURCES)
croco_EXCLUDES = dummy

croco_HEADERS_DIR = $(crocoincdir)
croco_HEADERS_INST = $(crocoinc_HEADERS)
croco_HEADERS_EXCLUDES = dummy

include $(top_srcdir)/win32/Makefile.msvcproj

dist-hook:	\
	$(top_builddir)/win32/vs9/croco.vcproj \
	$(top_builddir)/win32/vs9/croco.headers

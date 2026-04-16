bin_PROGRAMS = csslint-0.6
#man_MANS = csslint.1

csslint_0_6_SOURCES = csslint.c

croco_lib = $(top_builddir)/src/@CROCO_LIB@

csslint_0_6_LDADD = $(croco_lib)

csslint_0_6_CPPFLAGS = \
	-I$(top_srcdir)/intl \
	-I$(top_srcdir)/src \
	-I$(top_builddir)/src \
	$(CROCO_CFLAGS)

csslint_0_6_LDFLAGS=$(CROCO_LIBS)

#EXTRA_DIST = $(man_MANS)

# $MirOS: src/bin/pax/Makefile,v 1.35 2024/08/18 00:17:14 tg Exp $
#-
# Copyright (c) 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010,
#		2011, 2012, 2013, 2014, 2015, 2016, 2017, 2019,
#		2020, 2023, 2024
#	mirabilos <m@mirbsd.org>
# Copyright (c) 2018
#	mirabilos <t.glaser@tarent.de>
#
# Provided that these terms and disclaimer and all copyright notices
# are retained or reproduced in an accompanying document, permission
# is granted to deal in this work without restriction, including un-
# limited rights to use, publicly perform, distribute, sell, modify,
# merge, give away, or sublicence.
#
# This work is provided "AS IS" and WITHOUT WARRANTY of any kind, to
# the utmost extent permitted by applicable law, neither express nor
# implied; without malicious intent or gross negligence. In no event
# may a licensor, author or contributor be held liable for indirect,
# direct, other damage, loss, or other issues arising in any way out
# of dealing in the work, even if advised of the possibility of such
# damage or existence of a defect, except proven that it results out
# of said person's immediate fault when using the work as intended.
#-
# MirMakefile explicitly as part of MirBSD base; use Build.sh if you
# wish to build paxmirabilis (MirCPIO) on anything else, these days.

.ifdef cats
.MAIN: cats
.endif

.include <bsd.own.mk>

SRCDIR=		${.CURDIR}

PROG=		pax
SRCS=		ar.c ar_io.c ar_subs.c buf_subs.c compat.c cpio.c \
		file_subs.c ftree.c gen_subs.c getoldopt.c options.c \
		pat_rep.c pax.c sel_subs.c tables.c tar.c tty_subs.c
SRCS+=		cache.c
MAN=		cpio.1 pax.1 tar.1
LINKS+=		${BINDIR}/pax ${BINDIR}/cpio
LINKS+=		${BINDIR}/pax ${BINDIR}/tar
.if !make(test-build)
# ^K/ mksh /usr/src/contrib/hosted/tg/retab
CPPFLAGS+=	\
		-DHAVE_ATTRIBUTE_BOUNDED=1 -DHAVE_ATTRIBUTE_FORMAT=1 \
		-DHAVE_ATTRIBUTE_NONNULL=1 -DHAVE_ATTRIBUTE_NORETURN=1 \
		-DHAVE_ATTRIBUTE_PURE=1 -DHAVE_ATTRIBUTE_UNUSED=1 \
		-DHAVE_ATTRIBUTE_USED=1 -DHAVE_SYS_TIME_H=1 -DHAVE_TIME_H=1 \
		-DHAVE_BOTH_TIME_H=1 -DHAVE_SYS_MKDEV_H=0 -DHAVE_SYS_MTIO_H=1 \
		-DHAVE_SYS_RESOURCE_H=1 -DHAVE_SYS_SYSMACROS_H=0 \
		-DHAVE_GRP_H=1 -DHAVE_PATHS_H=1 -DHAVE_STDINT_H=1 \
		-DHAVE_STRINGS_H=1 -DHAVE_UTIME_H=1 -DHAVE_UTMP_H=1 \
		-DHAVE_UTMPX_H=0 -DHAVE_VIS_H=1 -DHAVE_CAN_INTTYPES=1 \
		-DHAVE_CAN_UCBINTS=1 -DHAVE_CAN_ULONG=1 -DHAVE_DPRINTF=0 \
		-DHAVE_FCHMODAT=0 -DHAVE_FCHOWNAT=0 -DHAVE_FUTIMENS=0 \
		-DHAVE_LCHMOD=1 -DHAVE_LCHOWN=1 -DHAVE_LINKAT=0 \
		-DHAVE_PLEDGE=0 -DHAVE_REALLOCARRAY=1 -DHAVE_SETPGENT=1 \
		-DHAVE_STRLCPY=1 -DHAVE_STRLCAT=1 -DHAVE_STRMODE=1 \
		-DHAVE_STRTONUM=1 -DHAVE_UG_FROM_UGID=1 -DHAVE_UGID_FROM_UG=0 \
		-DHAVE_UTIMENSAT=0 -DHAVE_UTIMES=1 -DHAVE_LUTIMES=1 \
		-DHAVE_FUTIMES=1 -DHAVE_OFFT_LONG=0 -DHAVE_TIMET_LONG=0 \
		-DHAVE_TIMET_LARGE=1 -DHAVE_ST_MTIMENSEC=1
CPPFLAGS+=	-I.
CPPFLAGS+=	-D_ALL_SOURCE
COPTS+=		-Wall
.endif
COPTS+=		-std=c89 -U__STRICT_ANSI__
# for MirBSD only, for a while
CPPFLAGS+=	-DREALPATH_CAN_ALLOCATE=2

SAFE_PATH=	/bin:/usr/bin:/usr/mpkg/bin:/usr/local/bin
CPPFLAGS+=	-DPAX_SAFE_PATH=\"${SAFE_PATH:Q}\"

TEST_BUILD_ENV:=	TARGET_OS= CPP=
TEST_BUILD_ENV+=	HAVE_PLEDGE=0	# for now, on MirBSD

test-build: .PHONY
	-rm -rf build-dir
	mkdir -p build-dir
	cd build-dir; env CC=${CC:Q} CFLAGS=${CFLAGS:M*:Q} \
	    CPPFLAGS=${CPPFLAGS:M*:Q} LDFLAGS=${LDFLAGS:M*:Q} \
	    LIBS=${LDADD:Q} NOWARN=-Wno-error ${TEST_BUILD_ENV} \
	    /bin/sh ${SRCDIR:Q}/Build.sh -Q -r

cleandir: clean-extra

clean-extra: .PHONY
	-rm -rf build-dir

CLEANFILES+=	${MANALL:S/.cat/.ps/} ${MAN:S/$/.pdf/} ${MANALL:S/$/.gz/}
CLEANFILES+=	${MAN:S/$/.htm/} ${MAN:S/$/.htm.gz/}
CLEANFILES+=	${MAN:S/$/.txt/} ${MAN:S/$/.txt.gz/}

.include <bsd.prog.mk>

CLEANFILES+=	cpio tar
all: cpio tar

cpio:
	ln -sf ${PROG} cpio

tar:
	ln -sf ${PROG} tar

.ifmake cats
V_GROFF!=	pkg_info -e 'groff-[0-9]*'
V_GHOSTSCRIPT!=	pkg_info -e 'ghostscript-[0-9]*'
.  if empty(V_GROFF) || empty(V_GHOSTSCRIPT)
.    error empty V_GROFF=${V_GROFF} or V_GHOSTSCRIPT=${V_GHOSTSCRIPT}
.  endif
.endif

CATS_KW=	cpio, pax, tar
CATS_TITLE_cpio_1=paxcpio - copy file archives in and out
CATS_TITLE_pax_1=pax - read and write file archives and copy directory hierarchies
CATS_TITLE_tar_1=paxtar - Unix tape archiver
CATS_PAGES=	cpio 1 pax 1 tar 1
catsall:=	${MANALL}
.for _m _n in ${CATS_PAGES}
catsall:=	${catsall:N${_m}.cat${_n}}
.endfor
.if "${catsall}" != ""
.  error Adjust here.
.endif
cats: ${MANALL} ${MANALL:S/.cat/.ps/}
.for _m _n in ${CATS_PAGES}
	x=$$(ident ${SRCDIR:Q}/${_m}.${_n} | \
	    awk '/Mir''OS:/ { print $$4$$5; }' | \
	    tr -dc 0-9); (( $${#x} == 14 )) || exit 1; exec \
	    ${MKSH} ${BSDSRCDIR:Q}/contrib/hosted/tg/ps2pdfmir -p pa4 -c \
	    -o ${_m}.${_n}.pdf '[' /Author '(MirBSD)' \
	    /Title '('${CATS_TITLE_${_m}_${_n}:Q}')' \
	    /Subject '(BSD Reference Manual)' /ModDate "(D:$$x)" \
	    /Creator '(GNU groff version ${V_GROFF:S/groff-//} \(MirPorts\))' \
	    /Producer '(Artifex Ghostscript ${V_GHOSTSCRIPT:S/ghostscript-//:S/-artifex//} \(MirPorts\))' \
	    /Keywords '('${CATS_KW:Q}')' /DOCINFO pdfmark \
	    -f ${_m}.ps${_n}
.endfor
	set -e; . ${BSDSRCDIR:Q}/scripts/roff2htm; set_target_absolute; \
	    for m in ${MANALL}; do \
		bn=$${m%.*}; ext=$${m##*.cat}; \
		[[ $$bn != $$m ]]; [[ $$ext != $$m ]]; \
		gzip -n9 <"$$m" >"$$m.gz"; \
		col -bx <"$$m" >"$$bn.$$ext.txt"; \
		rm -f "$$bn.$$ext.txt.gz"; gzip -n9 "$$bn.$$ext.txt"; \
		do_conversion_verbose "$$bn" "$$ext" "$$m" "$$bn.$$ext.htm"; \
		rm -f "$$bn.$$ext.htm.gz"; gzip -n9 "$$bn.$$ext.htm"; \
	done
.ifdef cats
.  for _m _n in ${CATS_PAGES}
	mv -f ${_m}.cat${_n}.gz ${_m}-${cats}.cat${_n}.gz
	mv -f ${_m}.${_n}.htm.gz ${_m}-${cats}.htm.gz
	mv -f ${_m}.${_n}.pdf ${_m}-${cats}.pdf
	mv -f ${_m}.${_n}.txt.gz ${_m}-${cats}.txt.gz
.  endfor
.endif

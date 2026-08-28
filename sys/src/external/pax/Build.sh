#!/bin/sh
srcversion='$MirOS: src/bin/pax/Build.sh,v 1.27 2024/08/17 23:33:49 tg Exp $'
set +evx
#-
# Copyright (c) 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010,
#		2011, 2012, 2013, 2014, 2015, 2016, 2017, 2019,
#		2020, 2021, 2023, 2024
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
# People analysing the output must whitelist conftest.c for any kind
# of compiler warning checks (mirtoconf is by design not quiet).
#
# Used environment documentation is at the end of this file.

LC_ALL=C; LANGUAGE=C
export LC_ALL; unset LANGUAGE

use_ach=x; unset use_ach

case $ZSH_VERSION:$VERSION in
:zsh*) ZSH_VERSION=2 ;;
esac

if test -n "${ZSH_VERSION+x}" && (emulate sh) >/dev/null 2>&1; then
	emulate sh
	NULLCMD=:
fi

if test -d /usr/xpg4/bin/. >/dev/null 2>&1; then
	# Solaris: some of the tools have weird behaviour, use portable ones
	PATH=/usr/xpg4/bin:$PATH
	export PATH
fi

test_tool() {
	x=`echo $2 | $3`
	y=$?

	test x"$y" = x"0" && test x"$x" = x"$4" && return
	echo >&2 "E: your $1 does not work correctly!"
	echo >&2 "N: 'echo $2 | $3' exited $y and returned '$x'; expected '$4'"
	echo >&2 'N: install a better one and prepend its location to $PATH'
	exit 1
}
test_tool grep foobarbaz 'grep bar' foobarbaz
test_tool sed abc 'sed y/ac/AC/' AbC
test_tool tr abc 'tr ac AC' AbC

sp=' '
ht='	'
nl='
'
safeIFS="$sp$ht$nl"
IFS=$safeIFS
allu=QWERTYUIOPASDFGHJKLZXCVBNM
alll=qwertyuiopasdfghjklzxcvbnm
alln=0123456789
alls=______________________________________________________________

test_n() {
	test x"$1" = x"" || return 0
	return 1
}

test_z() {
	test x"$1" = x""
}

case `echo a | tr '\201' X` in
X)
	# EBCDIC build system
	lfcr='\n\r'
	;;
*)
	lfcr='\012\015'
	;;
esac

echo "For the build logs, demonstrate that /dev/null and /dev/tty exist:"
ls -l /dev/null /dev/tty
cat <<EOF
Flags on entry (plus HAVE_* which are not shown here):
- CC        <$CC>
- CFLAGS    <$CFLAGS>
- CPPFLAGS  <$CPPFLAGS>
- LDFLAGS   <$LDFLAGS>
- LIBS      <$LIBS>
- LDSTATIC  <$LDSTATIC>
- TARGET_OS <$TARGET_OS> TARGET_OSREV <$TARGET_OSREV>

EOF

v() {
	$e "$*"
	eval "$@"
}

vv() {
	_c=$1
	shift
	$e "\$ $*" 2>&1
	eval "$@" >vv.out 2>&1
	sed "s^${_c} " <vv.out
}

vq() {
	eval "$@"
}

rmf() {
	for _f in "$@"; do
		case $_f in
		cpio.[1ch]|pax.[1ch]|tar.[1ch]) ;;
		*) rm -f "$_f" ;;
		esac
	done
}

tcfn=no
bi=
ui=
ao=
fx=
me=`basename "$0"`
orig_CFLAGS=$CFLAGS
phase=x

if test -t 1; then
	bi='[1m'
	ui='[4m'
	ao='[0m'
fi

upper() {
	echo :"$@" | sed 's/^://' | tr $alll $allu
}

# clean up after ac_testrun()
ac_testdone() {
	eval HAVE_$fu=$fv
	fr=no
	test 0 = $fv || fr=yes
	$e "$bi==> $fd...$ao $ui$fr$ao$fx"
	fx=
}

# ac_cache label: sets f, fu, fv?=0
ac_cache() {
	f=$1
	fu=`upper $f`
	eval fv=\$HAVE_$fu
	case $fv in
	0|1)
		fx=' (cached)'
		return 0
		;;
	esac
	fv=0
	return 1
}

# ac_testinit label [!] checkif[!]0 [setlabelifcheckis[!]0] useroutput
# returns 1 if value was cached/implied, 0 otherwise: call ac_testdone
ac_testinit() {
	if ac_cache $1; then
		test x"$2" = x"!" && shift
		test x"$2" = x"" || shift
		fd=${3-$f}
		ac_testdone
		return 1
	fi
	fc=0
	if test x"$2" = x""; then
		ft=1
	else
		if test x"$2" = x"!"; then
			fc=1
			shift
		fi
		eval ft=\$HAVE_`upper $2`
		if test_z "$ft"; then
			echo >&2
			echo >&2 "E: test $f depends on $2 which is not defined yet"
			exit 255
		fi
		shift
	fi
	fd=${3-$f}
	if test $fc = "$ft"; then
		fv=$2
		fx=' (implied)'
		ac_testdone
		return 1
	fi
	$e ... $fd
	return 0
}

cat_h_blurb() {
	echo '#ifdef MKSH_USE_AUTOCONF_H
/* things that “should” have been on the command line */
#include "autoconf.h"
#undef MKSH_USE_AUTOCONF_H
#endif

'
	cat
}

# pipe .c | ac_test[n] [!] label [!] checkif[!]0 [setlabelifcheckis[!]0] useroutput
ac_testnndnd() {
	if test x"$1" = x"!"; then
		fr=1
		shift
	else
		fr=0
	fi
	cat_h_blurb >conftest.c
	ac_testinit "$@" || return 1
	vv ']' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN conftest.c $LIBS $ccpr"
	test $tcfn = no && test -f a.out && tcfn=a.out
	test $tcfn = no && test -f a.exe && tcfn=a.exe
	test $tcfn = no && test -f conftest.exe && tcfn=conftest.exe
	test $tcfn = no && test -f conftest && tcfn=conftest
	if test -f $tcfn; then
		test 1 = $fr || fv=1
	else
		test 0 = $fr || fv=1
	fi
	vscan=
	if test $phase = u; then
		case $ct in
		gcc*) vscan='unrecogni[sz]ed' ;;
		hpcc) vscan='unsupported' ;;
		pcc) vscan='unsupported' ;;
		sunpro) vscan='-e ignored -e turned.off' ;;
		esac
	fi
	test_n "$vscan" && grep $vscan vv.out >/dev/null 2>&1 && fv=$fr
	return 0
}
ac_testn() {
	if ac_testnndnd "$@"; then
		rmf conftest.c conftest.o ${tcfn}* vv.out
		ac_testdone
	else
		rm -f conftest.c
	fi
}
ac_testnnd() {
	if ac_testnndnd "$@"; then
		ac_testdone
	fi
}

# ac_ifcpp cppexpr [!] label [!] checkif[!]0 [setlabelifcheckis[!]0] useroutput
ac_ifcpp() {
	expr=$1; shift
	ac_testn "$@" <<-EOF
		#include <unistd.h>
		extern int thiswillneverbedefinedIhope(void);
		int main(void) { return (isatty(0) +
		#$expr
		    0
		#else
		/* force a failure: expr is false */
		    thiswillneverbedefinedIhope()
		#endif
		    ); }
EOF
	test x"$1" = x"!" && shift
	f=$1
	fu=`upper $f`
	eval fv=\$HAVE_$fu
	test x"$fv" = x"1"
}

addtoach() {
	if echo "$1" >>autoconf.h; then
		echo ">>> $1"
	else
		echo >&2 "E: could not write autoconf.h"
		exit 255
	fi
}

# simple only (is IFS-split by shell)
cpp_define() {
	case $use_ach in
	0)
		add_cppflags "-D$1=$2"
		;;
	1)
		addtoach "#define $1 $2"
		;;
	*)
		echo >&2 "E: cpp_define() called too early!"
		exit 255
		;;
	esac
}

add_cppflags() {
	CPPFLAGS="$CPPFLAGS $*"
}

ac_cppflags() {
	test x"$1" = x"" || fu=$1
	fv=$2
	test x"$2" = x"" && eval fv=\$HAVE_$fu
	cpp_define HAVE_$fu $fv
}

ac_test() {
	ac_testn "$@"
	ac_cppflags
}

# ac_flags [-] add varname cflags [text] [ldflags]
ac_flags() {
	if test x"$1" = x"-"; then
		shift
		hf=1
	else
		hf=0
	fi
	fa=$1
	vn=$2
	f=$3
	ft=$4
	fl=$5
	test x"$ft" = x"" && ft="if $f can be used"
	save_CFLAGS=$CFLAGS
	CFLAGS="$CFLAGS $f"
	save_LDFLAGS=$LDFLAGS
	test_z "$fl" || LDFLAGS="$LDFLAGS $fl"
	if test 1 = $hf; then
		ac_testn can_$vn '' "$ft"
	else
		ac_testn can_$vn '' "$ft" <<-'EOF'
			/* evil apo'stroph in comment test */
			#include <unistd.h>
			int main(void) { int t[2]; return (isatty(pipe(t))); }
		EOF
		#'
	fi
	eval fv=\$HAVE_CAN_`upper $vn`
	test_z "$fl" || test 11 = $fa$fv || LDFLAGS=$save_LDFLAGS
	test 11 = $fa$fv || CFLAGS=$save_CFLAGS
}

# ac_header [!] header [prereq ...]
ac_header() {
	if test x"$1" = x"!"; then
		na=1
		shift
	else
		na=0
	fi
	hf=$1; shift
	hv=`echo "$hf" | tr -d "$lfcr" | tr -c $alll$allu$alln $alls`
	echo "/* NeXTstep bug workaround */" >x
	for i
	do
		case $i in
		_time)
			echo '#if HAVE_BOTH_TIME_H' >>x
			echo '#include <sys/time.h>' >>x
			echo '#include <time.h>' >>x
			echo '#elif HAVE_SYS_TIME_H' >>x
			echo '#include <sys/time.h>' >>x
			echo '#elif HAVE_TIME_H' >>x
			echo '#include <time.h>' >>x
			echo '#endif' >>x
			;;
		*)
			echo "#include <$i>" >>x
			;;
		esac
	done
	echo "#include <$hf>" >>x
	echo '#include <unistd.h>' >>x
	echo 'int main(void) { return (isatty(0)); }' >>x
	ac_testn "$hv" "" "<$hf>" <x
	rmf x
	test 1 = $na || ac_cppflags
}

addsrcs() {
	if test x"$1" = x"!"; then
		fr=0
		shift
	else
		fr=1
	fi
	eval i=\$$1
	test $fr = "$i" && case "$sp$SRCS$sp" in
	*"$sp$2$sp"*)	;;
	*)		SRCS="$SRCS$sp$2" ;;
	esac
}

# --- main ---

curdir=`pwd` srcdir=`dirname "$0" 2>/dev/null`
curdisp=.
case x$curdir in
x)
	curdir=.
	;;
*"$sp"*|*"$ht"*|*"$nl"*)
	echo >&2 Current directory should not contain space or tab or newline.
	echo >&2 Errors may occur.
	;;
*"'"*)
	echo >&2 Current directory should not contain single quotes.
	echo >&2 Errors may occur.
	;;
*)
	curdisp=$curdir
	;;
esac
case x$srcdir in
x)
	srcdir=.
	;;
*"$sp"*|*"$ht"*|*"$nl"*)
	echo >&2 Source directory should not contain space or tab or newline.
	echo >&2 Errors may occur.
	;;
*"'"*)
	echo >&2 Source directory must not contain single quotes.
	exit 1
	;;
esac
srcdisp=`cd "$srcdir" && pwd` || srcdisp=
test_n "$srcdisp" || srcdisp=$srcdir
if test x"$srcdisp" = x"$curdir"; then
	srcdisp=
else
	srcdisp=$srcdir/
fi
dstversion=`sed -n '/define MIRCPIO_VERSION/s/^.*"\([^"]*\)".*$/\1/p' "$srcdir/pax.h"`
whatlong='MirCPIO (paxmirabilis)'
whatshort=paxmirabilis

e=echo
r=0
eq=0
pm=0
cm=normal
Cg=
optflags=-std-compile-opts
last=
mans=0

for i
do
	case $last:$i in
	c:dragonegg|c:llvm)
		cm=$i
		last=
		;;
	c:*)
		echo "$me: Unknown option -c '$i'!" >&2
		exit 1
		;;
	o:*)
		optflags=$i
		last=
		;;
	:-A)
		rm -f autoconf.h
		addtoach '/* work around NeXTstep bug */'
		use_ach=1
		add_cppflags -DMKSH_USE_AUTOCONF_H
		;;
	:-c)
		last=c
		;;
	:-g)
		# checker, debug, valgrind build
		add_cppflags -DDEBUG
		Cg=YES
		;;
	:-j)
		pm=1
		;;
	:-M)
		cm=makefile
		;;
	:-O)
		optflags=-std-compile-opts
		;;
	:-o)
		last=o
		;;
	:-Q)
		eq=1
		;;
	:-r)
		r=1
		;;
	:-tmir)
		mans=1
		;;
	:-tpax)
		mans=2
		;;
	:-v)
		echo "Build.sh $srcversion"
		echo "for $whatlong $dstversion"
		exit 0
		;;
	:*)
		echo "$me: Unknown option '$i'!" >&2
		exit 1
		;;
	*)
		echo "$me: Unknown option -'$last' '$i'!" >&2
		exit 1
		;;
	esac
done
if test_n "$last"; then
	echo "$me: Option -'$last' not followed by argument!" >&2
	exit 1
fi

tfn=paxpax
case $mans in
0)
	paxname=pax
	cpioname=cpio
	tarname=tar
	;;
1)
	paxname=mirpax
	cpioname=mircpio
	tarname=mirtar
	;;
2)
	paxname=pax
	cpioname=paxcpio
	tarname=paxtar
	;;
esac
if test -d $tfn || test -d $tfn.exe; then
	echo "$me: Error: ./$tfn is a directory!" >&2
	exit 1
fi
test x"$use_ach" = x"1" || use_ach=0
cpp_define MKSH_BUILDSH 1
rmf a.exe* a.out* conftest.* *core core.* ${tfn}* *.bc *.dbg *.ll *.o *.cat? \
    *.gen Rebuild.sh Makefrag.inc lft no x vv.out
rm -rf mans

SRCS="ar.c ar_io.c ar_subs.c buf_subs.c compat.c cpio.c"
SRCS="$SRCS file_subs.c ftree.c gen_subs.c getoldopt.c options.c"
SRCS="$SRCS pat_rep.c pax.c sel_subs.c tables.c tar.c tty_subs.c"
add_cppflags -DMBSDPORT_H=\\\"compat.h\\\"

if test_z "$srcdisp"; then
	CPPFLAGS="-I. $CPPFLAGS"
else
	CPPFLAGS="-I. -I'$srcdir' $CPPFLAGS"
fi
test_z "$LDSTATIC" || if test_z "$LDFLAGS"; then
	LDFLAGS=$LDSTATIC
else
	LDFLAGS="$LDFLAGS $LDSTATIC"
fi

if test_z "$TARGET_OS"; then
	x=`uname -s 2>/dev/null || uname`
	case $x in
	scosysv)
		# SVR4 Unix with uname -s = uname -n, whitelist
		TARGET_OS=$x
		;;
	syllable)
		# other OS with uname -s = uname = uname -n, whitelist
		TARGET_OS=$x
		;;
	*)
		test x"$x" = x"`uname -n 2>/dev/null`" || TARGET_OS=$x
		;;
	esac
fi
if test_z "$TARGET_OS"; then
	echo "$me: Set TARGET_OS, your uname is broken!" >&2
	exit 1
fi
osnote=
oswarn=
ccpc=-Wc,
ccpl=-Wl,
tsts=
ccpr='|| for _f in ${tcfn}*; do case $_f in cpio.[1ch]|pax.[1ch]|tar.[1ch]) ;; *) rm -f "$_f" ;; esac; done'

# Evil hack
if test x"$TARGET_OS" = x"Android"; then
	TARGET_OS=Linux
fi

# Evil OS
if test x"$TARGET_OS" = x"Minix"; then
	echo >&2 "
WARNING: additional checks before running Build.sh required!
You can avoid these by calling Build.sh correctly, see below.
"
	cat_h_blurb >conftest.c <<'EOF'
#include <sys/types.h>
const char *
#ifdef _NETBSD_SOURCE
ct="Ninix3"
#else
ct="Minix3"
#endif
;
EOF
	ct=unknown
	vv ']' "${CC-cc} -E $CFLAGS $Cg $CPPFLAGS $NOWARN conftest.c | grep ct= | tr -d \\\\015 >x"
	sed 's/^/[ /' x
	eval `cat x`
	rmf x vv.out
	case $ct in
	Minix3|Ninix3)
		echo >&2 "
Warning: you set TARGET_OS to $TARGET_OS but that is ambiguous.
Please set it to either Minix3 or Ninix3, whereas the latter is
all versions of Minix with even partial NetBSD(R) userland. The
value determined from your compiler for the current compilation
(which may be wrong) is: $ct
"
		TARGET_OS=$ct
		;;
	*)
		echo >&2 "
Warning: you set TARGET_OS to $TARGET_OS but that is ambiguous.
Please set it to either Minix3 or Ninix3, whereas the latter is
all versions of Minix with even partial NetBSD(R) userland. The
proper value couldn't be determined, continue at your own risk.
"
		;;
	esac
fi

# Configuration depending on OS revision, on OSes that need them
case $TARGET_OS in
NEXTSTEP)
	test_n "$TARGET_OSREV" || TARGET_OSREV=`hostinfo 2>&1 | \
	    grep 'NeXT Mach [0-9][0-9.]*:' | \
	    sed 's/^.*NeXT Mach \([0-9][0-9.]*\):.*$/\1/'`
	;;
BeOS|HP-UX|QNX|SCO_SV)
	test_n "$TARGET_OSREV" || TARGET_OSREV=`uname -r`
	;;
esac

# SVR4 (some) workaround
int_as_ssizet() {
	cpp_define SSIZE_MIN INT_MIN
	cpp_define SSIZE_MAX INT_MAX
	cpp_define ssize_t int
}

cmplrflgs=

# Configuration depending on OS name
case $TARGET_OS in
386BSD)
	osnote='; it is untested'
	: "${HAVE_CAN_OTWO=0}"
	;;
4.4BSD)
	osnote='; assuming BOW (BSD on Windows)'
	;;
A/UX)
	oswarn='; it is untested'
	add_cppflags -D_POSIX_SOURCE
	: "${CC=gcc}"
	: "${LIBS=-lposix}"
	# GCC defines AUX but cc nothing
	add_cppflags -D__A_UX__
	;;
AIX)
	oswarn='; it is untested'
	add_cppflags -D_ALL_SOURCE
	;;
BeOS)
	oswarn='; it is untested'
	: "${CC=gcc}"
	;;
BSD/OS)
	osnote='; it is untested'
	;;
Coherent)
	oswarn='; it is untested, possibly has major issues'
	cpp_define MKSH__NO_SYMLINK 1
	;;
CYGWIN*)
	# libc lacks dprintf but the headers declare it unless #define’d
	cpp_define dprintf rpl_dprintf
	;;
Darwin)
	osnote='; it is untested'
	add_cppflags -D_DARWIN_C_SOURCE
	;;
DragonFly)
	osnote='; it is untested'
	;;
FreeBSD)
	osnote='; it is untested'
	;;
FreeMiNT)
	oswarn='; it is untested'
	add_cppflags -D_GNU_SOURCE
	;;
GNU)
	osnote='; it is untested'
	case $CC in
	*tendracc*) ;;
	*) add_cppflags -D_GNU_SOURCE ;;
	esac
	;;
GNU/kFreeBSD)
	osnote='; it is untested'
	case $CC in
	*tendracc*) ;;
	*) add_cppflags -D_GNU_SOURCE ;;
	esac
	;;
Haiku)
	oswarn='; it is untested'
	;;
Harvey)
	oswarn='; it is not ported'
	add_cppflags -D_POSIX_SOURCE
	add_cppflags -D_LIMITS_EXTENSION
	add_cppflags -D_BSD_EXTENSION
	add_cppflags -D_SUSV2_SOURCE
	add_cppflags -D_GNU_SOURCE
	cpp_define MKSH__NO_SYMLINK 1
	;;
HP-UX)
	osnote='; it is untested'
	case $TARGET_OSREV in
	B.09.*)
		: "${CC=c89}"
		add_cppflags -D_HPUX_SOURCE
		cpp_define MBSDINT_H_SMALL_SYSTEM 1
		;;
	esac
	;;
Interix)
	oswarn='; it is untested'
	ccpc='-X '
	ccpl='-Y '
	add_cppflags -D_ALL_SOURCE
	;;
IRIX*)
	osnote='; it is untested'
	;;
Jehanne)
	oswarn='; it is not ported'
	add_cppflags -D_POSIX_SOURCE
	add_cppflags -D_LIMITS_EXTENSION
	add_cppflags -D_BSD_EXTENSION
	add_cppflags -D_SUSV2_SOURCE
	add_cppflags -D_GNU_SOURCE
	cpp_define MKSH__NO_SYMLINK 1
	;;
Linux)
	case $CC in
	*tendracc*) ;;
	*) add_cppflags -D_GNU_SOURCE ;;
	esac
	;;
LynxOS)
	osnote='; it is untested'
	;;
midipix)
	oswarn='; it is untested'
	add_cppflags -D_GNU_SOURCE
	;;
MidnightBSD)
	cpp_define _WITH_DPRINTF 1
	cpp_define UT_NAMESIZE 32
	;;
Minix-vmd)
	oswarn='; it is untested'
	add_cppflags -D_MINIX_SOURCE
	;;
Minix3)
	oswarn='; it is untested'
	add_cppflags -D_POSIX_SOURCE -D_POSIX_1_SOURCE=2 -D_MINIX
	;;
Minoca)
	oswarn='; it is untested'
	: "${CC=gcc}"
	;;
MirBSD)
	add_cppflags -D_ALL_SOURCE
	;;
MSYS_*)
	osnote='; it is untested'
	# broken on this OE (from ir0nh34d)
	: "${HAVE_STDINT_H=0}"
	;;
NetBSD)
	add_cppflags -D_NETBSD_SOURCE
	add_cppflags -D_OPENBSD_SOURCE
	;;
NEXTSTEP)
	oswarn='; it is untested'
	add_cppflags -D_NEXT_SOURCE
	add_cppflags -D_POSIX_SOURCE
	: "${CC=cc -posix -traditional-cpp}"
	;;
Ninix3)
	oswarn='; it is untested'
	;;
OpenBSD)
	osnote='; it is untested'
	;;
OS/2)
	oswarn='; it is not ported'
	# cf. https://github.com/komh/pdksh-os2/commit/590f2b19b0ff92a9a373295bce914654f9f5bf22
	HAVE_TERMIOS_H=0
	: "${CC=gcc}"
	: "${SIZE=: size}"
	;;
OS/390)
	oswarn='; it is not ported'
	osnote='; EBCDIC support missing'
	: "${CC=xlc}"
	: "${SIZE=: size}"
	add_cppflags -D_ALL_SOURCE
	;;
OSF1)
	oswarn='; it is untested'
	add_cppflags -D_OSF_SOURCE
	add_cppflags -D_POSIX_C_SOURCE=200112L
	add_cppflags -D_XOPEN_SOURCE=600
	add_cppflags -D_XOPEN_SOURCE_EXTENDED
	;;
Plan9)
	oswarn='; it is not ported'
	add_cppflags -D_POSIX_SOURCE
	add_cppflags -D_LIMITS_EXTENSION
	add_cppflags -D_BSD_EXTENSION
	add_cppflags -D_SUSV2_SOURCE
	cpp_define MKSH__NO_SYMLINK 1
	# this is for detecting kencc
	cmplrflgs=-DMKSH_MAYBE_KENCC
	;;
PW32*)
	oswarn='; it is untested'
	;;
QNX)
	oswarn='; it is untested'
	add_cppflags -D__NO_EXT_QNX
	add_cppflags -D__EXT_UNIX_MISC
	;;
scosysv)
	oswarn='; it is untested'
	cmplrflgs=-DMKSH_MAYBE_QUICK_C
	int_as_ssizet
	;;
SCO_SV)
	oswarn='; it is untested'
	case $TARGET_OSREV in
	3.2*)
		# SCO OpenServer 5
		;;
	5*)
		# SCO OpenServer 6
		;;
	*)
		oswarn='; this is an unknown version of'
		oswarn="$oswarn$nl$TARGET_OS ${TARGET_OSREV}, please tell me what to do"
		;;
	esac
	;;
SerenityOS)
	oswarn='; it is untested'
	;;
SINIX-Z)
	: "${CC=cc -Xa}"
	cmplrflgs=-DMKSH_MAYBE_SCDE
	;;
skyos)
	oswarn='; it is untested'
	;;
SunOS)
	oswarn='; it is untested'
	add_cppflags -D_BSD_SOURCE
	add_cppflags -D__EXTENSIONS__
	;;
syllable)
	oswarn='; it is untested'
	add_cppflags -D_GNU_SOURCE
	;;
ULTRIX)
	oswarn='; it is untested'
	: "${CC=cc -YPOSIX}"
	int_as_ssizet
	;;
UnixWare|UNIX_SV)
	# SCO UnixWare
	oswarn='; it is untested'
	;;
UWIN*)
	oswarn='; it is untested'
	ccpc='-Yc,'
	ccpl='-Yl,'
	tsts=" 3<>/dev/tty"
	;;
XENIX)
	oswarn='; it is untested'
	# mostly when crosscompiling from scosysv
	cmplrflgs=-DMKSH_MAYBE_QUICK_C
	# this can barely do anything
	int_as_ssizet
	cpp_define MKSH__NO_SYMLINK 1
	# these are broken
	HAVE_TERMIOS_H=0
	;;
_svr4)
	# generic target for SVR4 Unix with uname -s = uname -n
	oswarn='; it may or may not work'
	: "${CC=cc -Xa}"
	cmplrflgs=-DMKSH_MAYBE_SCDE
	int_as_ssizet #XXX maybe not for *all* _svr4? here for Dell UNIX
	;;
*)
	oswarn='; it may or may not work'
	;;
esac
test_n "$TARGET_OSREV" || TARGET_OSREV=`uname -r`

: "${AWK=awk}${CC=cc}${NROFF=nroff}${SIZE=size}"
test 0 = $r && echo | $NROFF -v 2>&1 | grep GNU >/dev/null 2>&1 && \
    echo | $NROFF -c >/dev/null 2>&1 && NROFF="$NROFF -c"

# this aids me in tracing FTBFSen without access to the buildd
$e "Hi from$ao $bi$srcversion$ao on:"
case $TARGET_OS in
AIX)
	vv '|' "oslevel >&2"
	vv '|' "uname -a >&2"
	;;
Darwin)
	vv '|' "hwprefs machine_type os_type os_class >&2"
	vv '|' "sw_vers >&2"
	vv '|' "system_profiler -detailLevel mini SPSoftwareDataType SPHardwareDataType >&2"
	vv '|' "/bin/sh --version >&2"
	vv '|' "xcodebuild -version >&2"
	vv '|' "uname -a >&2"
	vv '|' "sysctl kern.version hw.machine hw.model hw.memsize hw.availcpu hw.ncpu hw.cpufrequency hw.byteorder hw.cpu64bit_capable >&2"
	vv '|' "sysctl hw.cpufrequency hw.byteorder hw.cpu64bit_capable hw.ncpu >&2"
	;;
IRIX*)
	vv '|' "uname -a >&2"
	vv '|' "hinv -v >&2"
	;;
OSF1)
	vv '|' "uname -a >&2"
	vv '|' "/usr/sbin/sizer -v >&2"
	;;
scosysv|SCO_SV|UnixWare|UNIX_SV|XENIX)
	vv '|' "uname -a >&2"
	vv '|' "uname -X >&2"
	;;
*)
	vv '|' "uname -a >&2"
	;;
esac
test_z "$oswarn" || echo >&2 "
Warning: $whatshort has not yet been ported to or tested on your
operating system '$TARGET_OS'$oswarn."
test_z "$osnote" || echo >&2 "
Note: $whatshort is not fully ported to or tested yet on your
operating system '$TARGET_OS'$osnote."
test_z "$osnote$oswarn" || echo >&2 "
If you can provide a shell account to the developer, this
may improve; please drop us a success or failure notice or
even send patches for the remaining issues, or, at the very
least, complete logs (Build.sh + test?) will help.
"
$e "$bi$me: Building $whatlong$ao $ui$dstversion$ao on $TARGET_OS ${TARGET_OSREV}..."

#
# Start of mirtoconf checks
#
$e $bi$me: Scanning for functions... please ignore any errors.$ao

#
# Compiler: which one?
#
# notes:
# - ICC defines __GNUC__ too
# - GCC defines __hpux too
# - LLVM+clang defines __GNUC__ too
# - nwcc defines __GNUC__ too
CPP="$CC -E"
$e ... which compiler type seems to be used
cat_h_blurb >conftest.c <<'EOF'
const char *
#if defined(__ICC) || defined(__INTEL_COMPILER)
ct="icc"
#elif defined(__xlC__) || defined(__IBMC__)
ct="xlc"
#elif defined(__SUNPRO_C)
ct="sunpro"
#elif defined(__neatcc__)
ct="neatcc"
#elif defined(__lacc__)
ct="lacc"
#elif defined(__ACK__)
ct="ack"
#elif defined(__BORLANDC__)
ct="bcc"
#elif defined(__WATCOMC__)
ct="watcom"
#elif defined(__MWERKS__)
ct="metrowerks"
#elif defined(__HP_cc)
ct="hpcc"
#elif defined(__DECC) || (defined(__osf__) && !defined(__GNUC__))
ct="dec"
#elif defined(__PGI)
ct="pgi"
#elif defined(__DMC__)
ct="dmc"
#elif defined(_MSC_VER)
ct="msc"
#elif defined(__ADSPBLACKFIN__) || defined(__ADSPTS__) || defined(__ADSP21000__)
ct="adsp"
#elif defined(__IAR_SYSTEMS_ICC__)
ct="iar"
#elif defined(SDCC)
ct="sdcc"
#elif defined(__PCC__)
ct="pcc"
#elif defined(__TenDRA__)
ct="tendra"
#elif defined(__TINYC__)
ct="tcc"
#elif defined(__llvm__) && defined(__clang__)
ct="clang"
#elif defined(__NWCC__)
ct="nwcc"
#elif defined(__GNUC__) && (__GNUC__ < 2)
ct="gcc1"
#elif defined(__GNUC__)
ct="gcc"
#elif defined(_COMPILER_VERSION)
ct="mipspro"
#elif defined(__sgi)
ct="mipspro"
#elif defined(__hpux) || defined(__hpua)
ct="hpcc"
#elif defined(__ultrix)
ct="ucode"
#elif defined(__USLC__)
ct="uslc"
#elif defined(__LCC__)
ct="lcc"
#elif defined(MKSH_MAYBE_QUICK_C) && defined(_M_BITFIELDS)
ct="quickc"
#elif defined(MKSH_MAYBE_KENCC)
/* and none of the above matches */
ct="kencc"
#elif defined(MKSH_MAYBE_SCDE)
ct="tryscde"
#else
ct="unknown"
#endif
;
const char *
#if defined(__KLIBC__) && !defined(__OS2__)
et="klibc"
#elif defined(__dietlibc__)
et="dietlibc"
#else
et="unknown"
#endif
;
EOF
ct=untested
et=untested
vv ']' "$CPP $CFLAGS $CPPFLAGS $NOWARN $cmplrflgs conftest.c | \
    sed -n '/^ *[ce]t *= */s/^ *\([ce]t\) *= */\1=/p' | tr -d \\\\015 >x"
sed 's/^/[ /' x
eval `cat x`
rmf x vv.out
cat_h_blurb >conftest.c <<'EOF'
#include <unistd.h>
int main(void) { return (isatty(0)); }
EOF
test_z "$Cg" || Cg=-g  # generic
case $ct:$TARGET_OS in
tryscde:*)
	case `LC_ALL=C; export LC_ALL; $CC -V 2>&1` in
	*'Standard C Development Environment'*)
		ct=scde ;;
	*)
		ct=unknown ;;
	esac
	;;
esac
case $ct in
ack)
	# work around "the famous ACK const bug"
	CPPFLAGS="-Dconst= $CPPFLAGS"
	: "${HAVE_ATTRIBUTE_EXTENSION=0}"  # skip checking as we know it absent
	;;
adsp)
	echo >&2 'Warning: Analog Devices C++ compiler for Blackfin, TigerSHARC
    and SHARC (21000) DSPs detected. This compiler has not yet
    been tested for compatibility with this. Continue at your
    own risk, please report success/failure to the developers.'
	;;
bcc)
	echo >&2 "Warning: Borland C++ Builder detected. This compiler might
    produce broken executables. Continue at your own risk,
    please report success/failure to the developers."
	;;
clang)
	# does not work with current "ccc" compiler driver
	vv '|' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN $LIBS --version"
	# one of these two works, for now
	vv '|' "${CLANG-clang} -version"
	# ensure compiler and linker are in sync unless overridden
	case $CCC_CC:$CCC_LD in
	:*)	;;
	*:)	CCC_LD=$CCC_CC; export CCC_LD ;;
	esac
	;;
dec)
	vv '|' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN $LIBS -V"
	vv '|' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN -Wl,-V conftest.c $LIBS"
	: "${HAVE_ATTRIBUTE_EXTENSION=0}"  # skip checking as we know it absent
	;;
dmc)
	echo >&2 "Warning: Digital Mars Compiler detected. When running under"
	echo >&2 "    UWIN, mksh tends to be unstable due to the limitations"
	echo >&2 "    of this platform. Continue at your own risk,"
	echo >&2 "    please report success/failure to the developers."
	;;
gcc1)
	vv '|' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN -v conftest.c $LIBS"
	vv '|' 'eval echo "\`$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN $LIBS -dumpmachine\`" \
		 "gcc\`$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN $LIBS -dumpversion\`"'
	: "${HAVE_ATTRIBUTE_EXTENSION=0}" # false positive
	;;
gcc)
	test_z "$Cg" || Cg='-g3 -fno-builtin'
	vv '|' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN -v conftest.c $LIBS"
	vv '|' 'eval echo "\`$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN $LIBS -dumpmachine\`" \
		 "gcc\`$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN $LIBS -dumpversion\`"'
	;;
hpcc)
	vv '|' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN -V conftest.c $LIBS"
	case $TARGET_OS,$TARGET_OSREV in
	HP-UX,B.09.*)
		: "${HAVE_ATTRIBUTE_EXTENSION=0}"
		;;
	esac
	;;
iar)
	echo >&2 'Warning: IAR Systems (http://www.iar.com) compiler for embedded
    systems detected. This unsupported compiler has not yet
    been tested for compatibility with this. Continue at your
    own risk, please report success/failure to the developers.'
	;;
icc)
	vv '|' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN $LIBS -V"
	;;
kencc)
	vv '|' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN -v conftest.c $LIBS"
	: "${HAVE_ATTRIBUTE_EXTENSION=0}"  # skip checking as we know it absent
	;;
lacc)
	# no version information
	;;
lcc)
	vv '|' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN -v conftest.c $LIBS"
	cpp_define __inline__ __inline
	: "${HAVE_ATTRIBUTE_EXTENSION=0}"  # skip checking as we know it absent
	;;
metrowerks)
	echo >&2 'Warning: Metrowerks C compiler detected. This has not yet
    been tested for compatibility with this. Continue at your
    own risk, please report success/failure to the developers.'
	;;
mipspro)
	test_z "$Cg" || Cg='-g3'
	vv '|' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN $LIBS -version"
	: "${HAVE_STDINT_H=0}" # broken unless building with __c99
	: "${HAVE_ATTRIBUTE_EXTENSION=0}"  # skip checking as we know it absent
	;;
msc)
	ccpr=		# errorlevels are not reliable
	case $TARGET_OS in
	Interix)
		if test_z "$C89_COMPILER"; then
			C89_COMPILER=CL.EXE
		else
			C89_COMPILER=`ntpath2posix -c "$C89_COMPILER"`
		fi
		if test_z "$C89_LINKER"; then
			C89_LINKER=LINK.EXE
		else
			C89_LINKER=`ntpath2posix -c "$C89_LINKER"`
		fi
		vv '|' "$C89_COMPILER /HELP >&2"
		vv '|' "$C89_LINKER /LINK >&2"
		;;
	esac
	;;
neatcc)
	cpp_define MKSH_DONT_EMIT_IDSTRING 1
	vv '|' "$CC"
	;;
nwcc)
	vv '|' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN $LIBS -version"
	;;
pcc)
	vv '|' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN $LIBS -v"
	;;
pgi)
	echo >&2 'Warning: PGI detected. This unknown compiler has not yet
    been tested for compatibility with this. Continue at your
    own risk, please report success/failure to the developers.'
	;;
quickc)
	# no version information
	: "${HAVE_ATTRIBUTE_EXTENSION=0}"  # skip checking as we know it absent
	;;
scde)
	vv '|' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN -V conftest.c $LIBS"
	: "${HAVE_ATTRIBUTE_EXTENSION=0}"  # skip checking as we know it absent
	;;
sdcc)
	echo >&2 'Warning: sdcc (http://sdcc.sourceforge.net), the small devices
    C compiler for embedded systems detected. This has not yet
    been tested for compatibility with this. Continue at your
    own risk, please report success/failure to the developers.'
	;;
sunpro)
	vv '|' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN -V conftest.c $LIBS"
	;;
tcc)
	vv '|' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN $LIBS -v"
	;;
tendra)
	vv '|' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN $LIBS -V 2>&1 | \
	    grep -i -e version -e release"
	: "${HAVE_ATTRIBUTE_EXTENSION=0}" # false positive
	;;
ucode)
	vv '|' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN $LIBS -V"
	vv '|' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN -Wl,-V conftest.c $LIBS"
	: "${HAVE_ATTRIBUTE_EXTENSION=0}"  # skip checking as we know it absent
	;;
uslc)
	case $TARGET_OS:$TARGET_OSREV in
	SCO_SV:3.2*)
		# SCO OpenServer 5
		CFLAGS="$CFLAGS -g"
		: "${HAVE_CAN_OTWO=0}${HAVE_CAN_OPTIMISE=0}"
		;;
	esac
	vv '|' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN -V conftest.c $LIBS"
	: "${HAVE_ATTRIBUTE_EXTENSION=0}"  # skip checking as we know it absent
	;;
watcom)
	vv '|' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN -v conftest.c $LIBS"
	;;
xlc)
	vv '|' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN $LIBS -qversion"
	vv '|' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN $LIBS -qversion=verbose"
	vv '|' "ld -V"
	;;
*)
	test x"$ct" = x"untested" && $e "!!! detecting preprocessor failed"
	ct=unknown
	vv '|' "$CC --version"
	vv '|' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN -v conftest.c $LIBS"
	vv '|' "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $NOWARN -V conftest.c $LIBS"
	;;
esac
case $cm in
dragonegg|llvm)
	vv '|' "llc -version"
	;;
esac
etd=" on $et"
# still imake style but… can’t be helped
case $et in
dietlibc)
	# live, BSD, live❣
	#add_cppflags -D_BSD_SOURCE
	# dietlibc has u_long as uint32_t in many versions, ouch,
	# but thankfully ifdef _BSD_SOURCE, so… ouch²…
	add_cppflags -U_BSD_SOURCE
	: "${HAVE_CAN_ULONG=0}"
	;;
klibc)
	;;
unknown)
	# nothing special detected, don’t worry
	etd=
	;;
*)
	# huh?
	;;
esac
$e "$bi==> which compiler type seems to be used...$ao $ui$ct$etd$ao"
rmf conftest.c conftest.o conftest a.out* a.exe* conftest.exe* vv.out

#
# Compiler: works as-is, with -Wno-error and -Werror
#
save_NOWARN=$NOWARN
NOWARN=
DOWARN=
ac_flags 0 compiler_works '' 'if the compiler works'
test 1 = $HAVE_CAN_COMPILER_WORKS || exit 1
HAVE_COMPILER_KNOWN=0
test $ct = unknown || HAVE_COMPILER_KNOWN=1
if ac_ifcpp 'if 0' compiler_fails '' \
    'if the compiler does not fail correctly'; then
	save_CFLAGS=$CFLAGS
	: "${HAVE_CAN_DELEXE=x}"
	case $ct in
	dec)
		CFLAGS="$CFLAGS ${ccpl}-non_shared"
		ac_testn can_delexe compiler_fails 0 'for the -non_shared linker option' <<-'EOF'
			#include <unistd.h>
			int main(void) { return (isatty(0)); }
		EOF
		;;
	dmc)
		CFLAGS="$CFLAGS ${ccpl}/DELEXECUTABLE"
		ac_testn can_delexe compiler_fails 0 'for the /DELEXECUTABLE linker option' <<-'EOF'
			#include <unistd.h>
			int main(void) { return (isatty(0)); }
		EOF
		;;
	*)
		exit 1
		;;
	esac
	test 1 = $HAVE_CAN_DELEXE || CFLAGS=$save_CFLAGS
	ac_ifcpp 'if 0' compiler_still_fails \
	    'if the compiler still does not fail correctly' && exit 1
fi
if ac_ifcpp 'ifdef __TINYC__' couldbe_tcc '!' compiler_known 0 \
    'if this could be tcc'; then
	ct=tcc
	CPP='cpp -D__TINYC__'
	HAVE_COMPILER_KNOWN=1
fi

case $ct in
bcc)
	save_NOWARN="${ccpc}-w"
	DOWARN="${ccpc}-w!"
	;;
dec)
	# -msg_* flags not used yet, or is -w2 correct?
	;;
dmc)
	save_NOWARN="${ccpc}-w"
	DOWARN="${ccpc}-wx"
	;;
hpcc)
	save_NOWARN=
	DOWARN=+We
	;;
kencc)
	save_NOWARN=
	DOWARN=
	;;
mipspro)
	save_NOWARN=
	DOWARN="-diag_error 1-10000"
	;;
msc)
	save_NOWARN="${ccpc}/w"
	DOWARN="${ccpc}/WX"
	;;
quickc)
	;;
scde)
	;;
sunpro)
	test x"$save_NOWARN" = x"" && save_NOWARN='-errwarn=%none'
	ac_flags 0 errwarnnone "$save_NOWARN"
	test 1 = $HAVE_CAN_ERRWARNNONE || save_NOWARN=
	ac_flags 0 errwarnall "-errwarn=%all"
	test 1 = $HAVE_CAN_ERRWARNALL && DOWARN="-errwarn=%all"
	;;
tendra)
	save_NOWARN=-w
	;;
ucode)
	save_NOWARN=
	DOWARN=-w2
	;;
watcom)
	save_NOWARN=
	DOWARN=-Wc,-we
	;;
xlc)
	case $TARGET_OS in
	OS/390)
		save_NOWARN=-qflag=e
		DOWARN=-qflag=i
		;;
	*)
		save_NOWARN=-qflag=i:e
		DOWARN=-qflag=i:i
		;;
	esac
	;;
*)
	test x"$save_NOWARN" = x"" && save_NOWARN=-Wno-error
	ac_flags 0 wnoerror "$save_NOWARN"
	test 1 = $HAVE_CAN_WNOERROR || save_NOWARN=
	ac_flags 0 werror -Werror
	test 1 = $HAVE_CAN_WERROR && DOWARN=-Werror
	test $ct = icc && DOWARN="$DOWARN -wd1419"
	;;
esac
NOWARN=$save_NOWARN

#
# Compiler: extra flags (-O2 -f* -W* etc.)
#
i=`echo :"$orig_CFLAGS" | sed 's/^://' | tr -c -d $alll$allu$alln`
# optimisation: only if orig_CFLAGS is empty
test_n "$i" || case $ct in
hpcc)
	phase=u
	ac_flags 1 otwo +O2
	phase=x
	;;
kencc|quickc|scde|tcc|tendra)
	# no special optimisation
	;;
sunpro)
	cat >x <<-'EOF'
		#include <unistd.h>
		int main(void) { return (isatty(0)); }
		#define __IDSTRING_CONCAT(l,p)	__LINTED__ ## l ## _ ## p
		#define __IDSTRING_EXPAND(l,p)	__IDSTRING_CONCAT(l,p)
		#define pad			void __IDSTRING_EXPAND(__LINE__,x)(void) { }
	EOF
	yes pad | head -n 256 >>x
	ac_flags - 1 otwo -xO2 <x
	rmf x
	;;
xlc)
	ac_flags 1 othree "-O3 -qstrict"
	test 1 = $HAVE_CAN_OTHREE || ac_flags 1 otwo -O2
	;;
*)
	if test_n "$Cg"; then
		ac_flags 1 ogee -Og
		if test 1 = $HAVE_CAN_OGEE; then
			HAVE_CAN_OTWO=1 # for below
		else
			ac_flags 1 otwo -O2
		fi
	else
		ac_flags 1 otwo -O2
	fi
	test 1 = $HAVE_CAN_OTWO || ac_flags 1 optimise -O
	;;
esac
# other flags: just add them if they are supported
i=0
case $ct in
bcc)
	ac_flags 1 strpool "${ccpc}-d" 'if string pooling can be enabled'
	;;
clang)
	i=1
	;;
dec)
	ac_flags 0 verb -verbose
	ac_flags 1 rodata -readonly_strings
	;;
dmc)
	ac_flags 1 decl "${ccpc}-r" 'for strict prototype checks'
	ac_flags 1 schk "${ccpc}-s" 'for stack overflow checking'
	;;
gcc1)
	# The following tests run with -Werror (gcc only) if possible
	NOWARN=$DOWARN; phase=u
	ac_flags 1 wnodeprecateddecls -Wno-deprecated-declarations
	# we do not even use CFrustFrust in MirBSD so don’t code in it…
	ac_flags 1 no_eh_frame -fno-asynchronous-unwind-tables
	ac_flags 1 fnostrictaliasing -fno-strict-aliasing
	ac_flags 1 data_abi_align -malign-data=abi
	i=1
	;;
gcc)
	ac_flags 1 fnolto -fno-lto 'whether we can explicitly disable buggy GCC LTO' -fno-lto
	# The following tests run with -Werror (gcc only) if possible
	NOWARN=$DOWARN; phase=u
	ac_flags 1 wnodeprecateddecls -Wno-deprecated-declarations
	# we do not even use CFrustFrust in MirBSD so don’t code in it…
	ac_flags 1 no_eh_frame -fno-asynchronous-unwind-tables
	ac_flags 1 fnostrictaliasing -fno-strict-aliasing
	ac_flags 1 fstackprotectorstrong -fstack-protector-strong
	test 1 = $HAVE_CAN_FSTACKPROTECTORSTRONG || \
	    ac_flags 1 fstackprotectorall -fstack-protector-all
	test $cm = dragonegg && case " $CC $CFLAGS $Cg $LDFLAGS " in
	*\ -fplugin=*dragonegg*) ;;
	*) ac_flags 1 fplugin_dragonegg -fplugin=dragonegg ;;
	esac
	case $cm in
	combine)
		fv=0
		checks='7 8'
		;;
	lto)
		fv=0
		checks='1 2 3 4 5 6 7 8'
		;;
	*)
		fv=1
		;;
	esac
	test $fv = 1 || for what in $checks; do
		test $fv = 1 && break
		case $what in
		1)	t_cflags='-flto=jobserver'
			t_ldflags='-fuse-linker-plugin'
			t_use=1 t_name=fltojs_lp ;;
		2)	t_cflags='-flto=jobserver' t_ldflags=''
			t_use=1 t_name=fltojs_nn ;;
		3)	t_cflags='-flto=jobserver'
			t_ldflags='-fno-use-linker-plugin -fwhole-program'
			t_use=1 t_name=fltojs_np ;;
		4)	t_cflags='-flto'
			t_ldflags='-fuse-linker-plugin'
			t_use=1 t_name=fltons_lp ;;
		5)	t_cflags='-flto' t_ldflags=''
			t_use=1 t_name=fltons_nn ;;
		6)	t_cflags='-flto'
			t_ldflags='-fno-use-linker-plugin -fwhole-program'
			t_use=1 t_name=fltons_np ;;
		7)	t_cflags='-fwhole-program --combine' t_ldflags=''
			t_use=0 t_name=combine cm=combine ;;
		8)	fv=1 cm=normal ;;
		esac
		test $fv = 1 && break
		ac_flags $t_use $t_name "$t_cflags" \
		    "if gcc supports $t_cflags $t_ldflags" "$t_ldflags"
	done
	ac_flags 1 data_abi_align -malign-data=abi
	i=1
	;;
hpcc)
	phase=u
	# probably not needed
	#ac_flags 1 agcc -Agcc 'for support of GCC extensions'
	phase=x
	;;
icc)
	ac_flags 1 fnobuiltinsetmode -fno-builtin-setmode
	ac_flags 1 fnostrictaliasing -fno-strict-aliasing
	ac_flags 1 fstacksecuritycheck -fstack-security-check
	i=1
	;;
mipspro)
	ac_flags 1 fullwarn -fullwarn 'for remark output support'
	;;
msc)
	ac_flags 1 strpool "${ccpc}/GF" 'if string pooling can be enabled'
	echo 'int main(void) { char test[64] = ""; return (*test); }' >x
	ac_flags - 1 stackon "${ccpc}/GZ" 'if stack checks can be enabled' <x
	ac_flags - 1 stckall "${ccpc}/Ge" 'stack checks for all functions' <x
	ac_flags - 1 secuchk "${ccpc}/GS" 'for compiler security checks' <x
	rmf x
	ac_flags 1 wall "${ccpc}/Wall" 'to enable all warnings'
	ac_flags 1 wp64 "${ccpc}/Wp64" 'to enable 64-bit warnings'
	;;
nwcc)
	#broken# ac_flags 1 ssp -stackprotect
	i=1
	;;
pcc)
	ac_flags 1 fstackprotectorall -fstack-protector-all
	i=1
	;;
sunpro)
	phase=u
	ac_flags 1 v -v
	ac_flags 1 ipo -xipo 'for cross-module optimisation'
	phase=x
	;;
tcc)
	: #broken# ac_flags 1 boundschk -b
	;;
tendra)
	ac_flags 0 ysystem -Ysystem
	test 1 = $HAVE_CAN_YSYSTEM && CPPFLAGS="-Ysystem $CPPFLAGS"
	ac_flags 1 extansi -Xa
	;;
xlc)
	case $TARGET_OS in
	OS/390)
		# On IBM z/OS, the following are warnings by default:
		# CCN3296: #include file <foo.h> not found.
		# CCN3944: Attribute "__foo__" is not supported and is ignored.
		# CCN3963: The attribute "foo" is not a valid variable attribute and is ignored.
		ac_flags 1 halton '-qhaltonmsg=CCN3296 -qhaltonmsg=CCN3944 -qhaltonmsg=CCN3963'
		# CCN3290: Unknown macro name FOO on #undef directive.
		# CCN4108: The use of keyword '__attribute__' is non-portable.
		ac_flags 1 supprss '-qsuppress=CCN3290 -qsuppress=CCN4108'
		;;
	*)
		ac_flags 1 rodata '-qro -qroconst -qroptr'
		ac_flags 1 rtcheck -qcheck=all
		#ac_flags 1 rtchkc -qextchk	# reported broken
		ac_flags 1 wformat '-qformat=all -qformat=nozln'
		;;
	esac
	#ac_flags 1 wp64 -qwarn64	# too verbose for now
	;;
esac
# flags common to a subset of compilers (run with -Werror on gcc)
if test 1 = $i; then
	ac_flags 1 wall -Wall
	ac_flags 1 fwrapv -fwrapv
fi

phase=x
# The following tests run with -Werror or similar (all compilers) if possible
NOWARN=$DOWARN
test $ct = pcc && phase=u

#
# Compiler: check for stuff that only generates warnings
#
: "${HAVE_ATTRIBUTE_EXTENSION=1}" # not a separate test but a dependency
ac_test attribute_bounded attribute_extension 0 'for __attribute__((__bounded__))' <<-'EOF'
	#include <string.h>
	#undef __attribute__
	int xcopy(const void *, void *, size_t)
	    __attribute__((__bounded__(__buffer__, 1, 3)))
	    __attribute__((__bounded__(__buffer__, 2, 3)));
	int main(int ac, char *av[]) { return (xcopy(av[0], av[--ac], 1)); }
	int xcopy(const void *s, void *d, size_t n) {
		/*
		 * if memmove does not exist, we are not on a system
		 * with GCC with __bounded__ attribute either so poo
		 */
		memmove(d, s, n); return ((int)n);
	}
EOF
ac_test attribute_format attribute_extension 0 'for __attribute__((__format__))' <<-'EOF'
	#define fprintf printfoo
	#include <stdio.h>
	#undef __attribute__
	#undef fprintf
	extern int fprintf(FILE *, const char *format, ...)
	    __attribute__((__format__(__printf__, 2, 3)));
	int main(int ac, char *av[]) { return (fprintf(stderr, "%s%d", *av, ac)); }
EOF
ac_test attribute_nonnull attribute_extension 0 'for __attribute__((__nonnull__))' <<-'EOF'
	#include <stdio.h>
	#undef __attribute__
	int fnord(const char *) __attribute__((__nonnull__(1)));
	int main(void) { return (fnord("x")); }
	int fnord(const char *x) { return (fputc(*x, stderr)); }
EOF
ac_test attribute_noreturn attribute_extension 0 'for __attribute__((__noreturn__))' <<-'EOF'
	#include <stdlib.h>
	#undef __attribute__
	void fnord(void) __attribute__((__noreturn__));
	int main(void) { fnord(); }
	void fnord(void) { exit(0); }
EOF
ac_test attribute_pure attribute_extension 0 'for __attribute__((__pure__))' <<-'EOF'
	#include <unistd.h>
	#undef __attribute__
	int foo(const char *) __attribute__((__pure__));
	int main(int ac, char *av[]) { return (foo(av[ac - 1]) + isatty(0)); }
	int foo(const char *s) { return ((int)s[0]); }
EOF
ac_test attribute_unused attribute_extension 0 'for __attribute__((__unused__))' <<-'EOF'
	#include <unistd.h>
	#undef __attribute__
	int main(int ac __attribute__((__unused__)), char *av[]
	    __attribute__((__unused__))) { return (isatty(0)); }
EOF
ac_test attribute_used attribute_extension 0 'for __attribute__((__used__))' <<-'EOF'
	#include <unistd.h>
	#undef __attribute__
	static const char fnord[] __attribute__((__used__)) = "42";
	int main(void) { return (isatty(0)); }
EOF

# End of tests run with -Werror
NOWARN=$save_NOWARN
phase=x

#
# Environment: headers
#
ac_header sys/time.h sys/types.h
ac_header time.h sys/types.h
test "11" = "$HAVE_SYS_TIME_H$HAVE_TIME_H" || HAVE_BOTH_TIME_H=0
ac_test both_time_h '' 'whether <sys/time.h> and <time.h> can both be included' <<-'EOF'
	#include <sys/types.h>
	#include <sys/time.h>
	#include <time.h>
	#include <unistd.h>
	int main(void) { struct tm tm; return ((int)sizeof(tm) + isatty(0)); }
EOF
ac_header sys/mkdev.h sys/types.h
ac_header sys/mtio.h sys/types.h
ac_header sys/resource.h sys/types.h _time
ac_header sys/sysmacros.h
ac_header grp.h sys/types.h
ac_header paths.h
ac_header stdint.h stdarg.h
# include strings.h only if compatible with string.h
ac_header strings.h sys/types.h string.h
ac_header utime.h _time
ac_header utmp.h _time
ac_header utmpx.h _time
ac_header vis.h stdlib.h

#
# Environment: definitions
#
echo '#include <sys/types.h>
#include <fts.h>
#include <unistd.h>
struct ctassert_offt {
	off_t min63bits:63;
};
int main(void) { return ((int)sizeof(struct ctassert_offt)); }' >lft.c
ac_testn can_lfs '' "for large file support" <lft.c
save_CPPFLAGS=$CPPFLAGS
add_cppflags -D_FILE_OFFSET_BITS=64
ac_testn can_lfs_sus '!' can_lfs 0 "... with -D_FILE_OFFSET_BITS=64" <lft.c
if test 0 = $HAVE_CAN_LFS_SUS; then
	CPPFLAGS=$save_CPPFLAGS
	add_cppflags -D_LARGE_FILES=1
	ac_testn can_lfs_aix '!' can_lfs 0 "... with -D_LARGE_FILES=1" <lft.c
	test 1 = $HAVE_CAN_LFS_AIX || CPPFLAGS=$save_CPPFLAGS
fi
rm -f lft.c
rmf lft*	# end of large file support test

#
# Environment: types
#
ac_test can_inttypes '!' stdint_h 1 "for standard 32-bit integer types" <<-'EOF'
	#include <sys/types.h>
	#include <stddef.h>
	int main(int ac, char *av[]) { return ((uint32_t)(size_t)*av + (int32_t)ac); }
EOF
ac_test can_ucbints '!' can_inttypes 1 "for UCB 32-bit integer types" <<-'EOF'
	#include <sys/types.h>
	#include <stddef.h>
	int main(int ac, char *av[]) { return ((u_int32_t)(size_t)*av + (int32_t)ac); }
EOF
ac_test can_ulong '' "for u_long" <<-'EOF'
	#include <sys/types.h>
	#include <stddef.h>
	int main(int ac, char *av[]) { return ((u_long)(size_t)av[ac]); }
EOF

#
# check whether whatever we use for the final link will succeed
#
if test $cm = makefile; then
	: nothing to check
else
	HAVE_LINK_WORKS=x
	ac_testinit link_works '' 'if the final link command may succeed'
	fv=1
	cat >conftest.c <<-EOF
		#include <sys/types.h>
		#if HAVE_BOTH_TIME_H
		#include <sys/time.h>
		#include <time.h>
		#elif HAVE_SYS_TIME_H
		#include <sys/time.h>
		#elif HAVE_TIME_H
		#include <time.h>
		#endif
		#include <sys/ioctl.h>
		#if HAVE_SYS_MTIO_H
		#include <sys/mtio.h>
		#endif
		#if HAVE_SYS_RESOURCE_H
		#include <sys/resource.h>
		#endif
		#include <sys/stat.h>
		#include <sys/wait.h>
		#include <ctype.h>
		#include <err.h>
		#include <errno.h>
		#include <fcntl.h>
		#include <fts.h>
		#if HAVE_GRP_H
		#include <grp.h>
		#endif
		#include <limits.h>
		#if HAVE_PATHS_H
		#include <paths.h>
		#endif
		#include <pwd.h>
		#include <regex.h>
		#include <signal.h>
		#include <stdarg.h>
		#include <stdio.h>
		#include <stdlib.h>
		#include <string.h>
		#if HAVE_STRINGS_H
		#include <strings.h>
		#endif
		#include <unistd.h>
		#if HAVE_UTMP_H
		#include <utmp.h>
		#elif HAVE_UTMPX_H
		#include <utmpx.h>
		#endif
		#if HAVE_VIS_H
		#include <vis.h>
		#endif
		#define EXTERN
		#define MIRTOCONF_EARLY
		#include "pax.h"
		#include "ftimes.h"
		#include "ar.h"
		#include "cpio.h"
		#include "tar.h"
		#include "extern.h"
		__RCSID("$srcversion");
		int main(void) { printf("Hello, World!\\n"); return (isatty(0)); }
EOF
	case $cm in
	llvm)
		v "$CC $CFLAGS $Cg $CPPFLAGS $NOWARN -emit-llvm -c conftest.c" || fv=0
		rmf $tfn.s
		test $fv = 0 || v "llvm-link -o - conftest.o | opt $optflags | llc -o $tfn.s" || fv=0
		test $fv = 0 || v "$CC $CFLAGS $Cg $LDFLAGS -o $tcfn $tfn.s $LIBS $ccpr"
		;;
	dragonegg)
		v "$CC $CFLAGS $Cg $CPPFLAGS $NOWARN -S -flto conftest.c" || fv=0
		test $fv = 0 || v "mv conftest.s conftest.ll"
		test $fv = 0 || v "llvm-as conftest.ll" || fv=0
		rmf $tfn.s
		test $fv = 0 || v "llvm-link -o - conftest.bc | opt $optflags | llc -o $tfn.s" || fv=0
		test $fv = 0 || v "$CC $CFLAGS $Cg $LDFLAGS -o $tcfn $tfn.s $LIBS $ccpr"
		;;
	combine)
		v "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS -fwhole-program --combine $NOWARN -o $tcfn conftest.c $LIBS $ccpr"
		;;
	lto|normal)
		cm=normal
		v "$CC $CFLAGS $Cg $CPPFLAGS $NOWARN -c conftest.c" || fv=0
		test $fv = 0 || v "$CC $CFLAGS $Cg $LDFLAGS -o $tcfn conftest.o $LIBS $ccpr"
		;;
	esac
	test -f $tcfn || fv=0
	ac_testdone
	test $fv = 1 || exit 1
fi

#
# Environment: library functions
#
ac_test dprintf <<-'EOF'
	#include <stdio.h>
	int main(void) { return (dprintf(1, "hi\n")); }
EOF

ac_test fchmodat <<-'EOF'
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	#include <unistd.h>
	int main(void) { return (fchmodat(AT_FDCWD, ".",
	    0, AT_SYMLINK_NOFOLLOW)); }
EOF

ac_test fchownat <<-'EOF'
	#include <fcntl.h>
	#include <unistd.h>
	int main(void) { return (fchownat(AT_FDCWD, ".",
	    0, 0, AT_SYMLINK_NOFOLLOW)); }
EOF

ac_test futimens <<-'EOF'
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	struct timespec ts[2] = {{0L, 0L}, {0L, UTIME_OMIT}};
	int main(void) { return (futimens(0, ts)); }
EOF

ac_test lchmod '!' fchmodat 0 <<-'EOF'
	#include <sys/types.h>
	#include <sys/stat.h>
	int main(void) { return (lchmod(".", 0)); }
EOF

ac_test lchown '!' fchownat 0 <<-'EOF'
	#include <sys/types.h>
	#include <unistd.h>
	int main(void) { return (lchown(".", 0, 0)); }
EOF

ac_test linkat <<-'EOF'
	#include <fcntl.h>
	#include <unistd.h>
	int main(int ac, char *av[]) { return (linkat(AT_FDCWD, av[1],
	    AT_FDCWD, av[2], ac)); }
EOF

ac_test pledge <<-'EOF'
	#include <unistd.h>
	int main(void) { return (pledge("", "")); }
EOF

ac_test reallocarray <<-'EOF'
	#include <stdlib.h>
	int main(void) { return ((void *)reallocarray(NULL, 3, 3) == (void *)0UL); }
EOF

ac_test setpgent grp_h 0 'for setpassent and setgroupent' <<-'EOF'
	#include <sys/types.h>
	#include <grp.h>
	#include <pwd.h>
	int main(void) { return (setpassent(1) + setgroupent(1)); }
EOF

ac_test strlcpy <<-'EOF'
	#include <string.h>
	int main(int ac, char *av[]) { return (strlcpy(*av, av[1], (size_t)ac)); }
EOF

ac_test strlcat strlcpy 0 <<-'EOF'
	#include <string.h>
	int main(int ac, char *av[]) { return (strlcat(*av, av[1], (size_t)ac)); }
EOF

ac_test strmode <<-'EOF'
	#include <string.h>
	#include <unistd.h>
	int main(int ac, char *av[]) { strmode(ac, av[0]); return (*av[0]); }
EOF

ac_test strtonum <<-'EOF'
	#include <limits.h>
	#include <stdlib.h>
	int main(int ac, char *av[]) {
		return (ac == (int)strtonum(av[1], 0, 100, NULL));
	}
EOF

ac_test ug_from_ugid grp_h 0 'for user_from_uid and group_from_gid' <<-'EOF'
	#include <sys/types.h>
	#include <grp.h>
	#include <pwd.h>
	int main(void) { return (*user_from_uid(0, 0) ^ *group_from_gid(0, 0)); }
EOF

ac_test ugid_from_ug ug_from_ugid 0 'for uid_from_user and gid_from_group' <<-'EOF'
	#include <sys/types.h>
	#include <grp.h>
	#include <pwd.h>
	int main(void) {
		uid_t uid;
		gid_t gid;
		uid_from_user("nobody", &uid);
		gid_from_group("nobody", &gid);
		return (uid ^ gid);
	}
EOF

ac_test utimensat <<-'EOF'
	#include <sys/types.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	struct timespec ts[2] = {{0L, 0L}, {0L, UTIME_OMIT}};
	int main(void) { return (utimensat(AT_FDCWD, ".", ts,
	    AT_SYMLINK_NOFOLLOW)); }
EOF

ac_test utimes '!' utimensat 0 <<-'EOF'
	#include <sys/time.h>
	struct timeval tv[2] = {{0L, 0L}, {0L, 0L}};
	int main(void) { return (utimes(".", tv)); }
EOF

ac_test lutimes '!' utimensat 0 <<-'EOF'
	#include <sys/time.h>
	struct timeval tv[2] = {{0L, 0L}, {0L, 0L}};
	int main(void) { return (lutimes(".", tv)); }
EOF

ac_test futimes '!' futimens 0 <<-'EOF'
	#include <sys/time.h>
	struct timeval tv[2] = {{0L, 0L}, {0L, 0L}};
	int main(void) { return (futimes(0, tv)); }
EOF

#
# check headers for declarations
#

#
# other checks
#
ac_test offt_long '' 'whether off_t is as wide as long' <<-'EOF'
	#include <sys/types.h>
	#include <limits.h>
	#include <unistd.h>
	#ifndef CHAR_BIT
	#define CHAR_BIT 0
	#endif
	struct ctasserts {
	#define cta(name,assertion) char name[(assertion) ? 1 : -1]
		cta(char_is_8_bits, (CHAR_BIT) == 8);
		cta(off_t_is_long, sizeof(off_t) == sizeof(long));
	};
	int main(void) { return (sizeof(struct ctasserts)); }
EOF

ac_testn offt_llong '!' offt_long 0 'whether off_t is as wide as long long' <<-'EOF'
	#include <sys/types.h>
	#include <limits.h>
	#include <unistd.h>
	#ifndef CHAR_BIT
	#define CHAR_BIT 0
	#endif
	struct ctasserts {
	#define cta(name,assertion) char name[(assertion) ? 1 : -1]
		cta(char_is_8_bits, (CHAR_BIT) == 8);
		cta(off_t_is_llong, sizeof(off_t) == sizeof(long long));
	};
	int main(void) { return (sizeof(struct ctasserts)); }
EOF

case $HAVE_OFFT_LLONG$HAVE_OFFT_LONG in
10|01)	;;
*)	echo Cannot determine width of off_t
	exit 1 ;;
esac

ac_test timet_long '' 'whether time_t is as wide as long' <<-'EOF'
	#include <sys/types.h>
	#if HAVE_BOTH_TIME_H
	#include <sys/time.h>
	#include <time.h>
	#elif HAVE_SYS_TIME_H
	#include <sys/time.h>
	#elif HAVE_TIME_H
	#include <time.h>
	#endif
	#include <limits.h>
	#ifndef CHAR_BIT
	#define CHAR_BIT 0
	#endif
	struct ctasserts {
	#define cta(name,assertion) char name[(assertion) ? 1 : -1]
		cta(char_is_8_bits, (CHAR_BIT) == 8);
		cta(time_t_is_long, sizeof(time_t) == sizeof(long));
	};
	int main(void) { return (sizeof(struct ctasserts)); }
EOF

ac_testn timet_llong '!' timet_long 0 'whether time_t is as wide as long long' <<-'EOF'
	#include <sys/types.h>
	#if HAVE_BOTH_TIME_H
	#include <sys/time.h>
	#include <time.h>
	#elif HAVE_SYS_TIME_H
	#include <sys/time.h>
	#elif HAVE_TIME_H
	#include <time.h>
	#endif
	#include <limits.h>
	#ifndef CHAR_BIT
	#define CHAR_BIT 0
	#endif
	struct ctasserts {
	#define cta(name,assertion) char name[(assertion) ? 1 : -1]
		cta(char_is_8_bits, (CHAR_BIT) == 8);
		cta(time_t_is_llong, sizeof(time_t) == sizeof(long long));
	};
	int main(void) { return (sizeof(struct ctasserts)); }
EOF

case $HAVE_TIMET_LLONG$HAVE_TIMET_LONG in
10|01)	;;
*)	echo Cannot determine width of time_t
	exit 1 ;;
esac

ac_test timet_large '' 'whether time_t is wider than 32 bit' <<-'EOF'
	#include <sys/types.h>
	#if HAVE_BOTH_TIME_H
	#include <sys/time.h>
	#include <time.h>
	#elif HAVE_SYS_TIME_H
	#include <sys/time.h>
	#elif HAVE_TIME_H
	#include <time.h>
	#endif
	#include <limits.h>
	#ifndef CHAR_BIT
	#define CHAR_BIT 0
	#endif
	struct ctasserts {
	#define cta(name,assertion) char name[(assertion) ? 1 : -1]
		cta(char_is_8_bits, (CHAR_BIT) == 8);
		cta(time_t_is_large, sizeof(time_t) > 4);
	};
	int main(void) { return (sizeof(struct ctasserts)); }
EOF

ac_testn st_mtimensec '' 'for struct stat.st_mtimensec' <<-'EOF'
	#include <sys/types.h>
	#if HAVE_BOTH_TIME_H
	#include <sys/time.h>
	#include <time.h>
	#elif HAVE_SYS_TIME_H
	#include <sys/time.h>
	#elif HAVE_TIME_H
	#include <time.h>
	#endif
	#include <sys/stat.h>
	int main(void) { struct stat sb; return (sizeof(sb.st_mtimensec)); }
EOF
ac_testn st_mtimespec '!' st_mtimensec 0 'for struct stat.st_mtimespec.tv_nsec' <<-'EOF'
	#include <sys/types.h>
	#if HAVE_BOTH_TIME_H
	#include <sys/time.h>
	#include <time.h>
	#elif HAVE_SYS_TIME_H
	#include <sys/time.h>
	#elif HAVE_TIME_H
	#include <time.h>
	#endif
	#include <sys/stat.h>
	int main(void) { struct stat sb; return (sizeof(sb.st_mtimespec.tv_nsec)); }
EOF
if test 1 = "$HAVE_ST_MTIMESPEC"; then
	cpp_define st_atimensec st_atimespec.tv_nsec
	cpp_define st_ctimensec st_ctimespec.tv_nsec
	cpp_define st_mtimensec st_mtimespec.tv_nsec
	HAVE_ST_MTIMENSEC=1
fi
ac_testn st_mtim '!' st_mtimensec 0 'for struct stat.st_mtim.tv_nsec' <<-'EOF'
	#include <sys/types.h>
	#if HAVE_BOTH_TIME_H
	#include <sys/time.h>
	#include <time.h>
	#elif HAVE_SYS_TIME_H
	#include <sys/time.h>
	#elif HAVE_TIME_H
	#include <time.h>
	#endif
	#include <sys/stat.h>
	int main(void) { struct stat sb; return (sizeof(sb.st_mtim.tv_nsec)); }
EOF
if test 1 = "$HAVE_ST_MTIM"; then
	cpp_define st_atimensec st_atim.tv_nsec
	cpp_define st_ctimensec st_ctim.tv_nsec
	cpp_define st_mtimensec st_mtim.tv_nsec
	HAVE_ST_MTIMENSEC=1
fi
ac_testn st_mtime_nsec '!' st_mtimensec 0 'for struct stat.st_mtime_nsec' <<-'EOF'
	#include <sys/types.h>
	#if HAVE_BOTH_TIME_H
	#include <sys/time.h>
	#include <time.h>
	#elif HAVE_SYS_TIME_H
	#include <sys/time.h>
	#elif HAVE_TIME_H
	#include <time.h>
	#endif
	#include <sys/stat.h>
	int main(void) { struct stat sb; return (sizeof(sb.st_mtime_nsec)); }
EOF
if test 1 = "$HAVE_ST_MTIME_NSEC"; then
	cpp_define st_atimensec st_atime_nsec
	cpp_define st_ctimensec st_ctime_nsec
	cpp_define st_mtimensec st_mtime_nsec
	HAVE_ST_MTIMENSEC=1
fi
ac_cppflags ST_MTIMENSEC


#
# Compiler: Praeprocessor (only if needed)
#

#
# End of mirtoconf checks
#
$e ... done.
rmf vv.out

addsrcs '!' HAVE_UGID_FROM_UG cache.c
addsrcs '!' HAVE_REALLOCARRAY reallocarray.c
addsrcs '!' HAVE_STRMODE strmode.c
addsrcs '!' HAVE_STRTONUM strtonum.c

test 1 = "$HAVE_CAN_VERB" && CFLAGS="$CFLAGS -verbose"

$e $bi$me: Finished configuration testing, now producing output.$ao

files=
objs=
fsp=
case $tcfn in
a.exe|conftest.exe)
	buildoutput=$tfn.exe
	paxexe=$paxname.exe
	cpioexe=$cpioname.exe
	tarexe=$tarname.exe
	cpp_define MKSH_EXE_EXT 1
	;;
*)
	buildoutput=$tfn
	paxexe=$paxname
	cpioexe=$cpioname
	tarexe=$tarname
	;;
esac
case $cm in
dragonegg)
	emitbc="-S -flto"
	;;
llvm)
	emitbc="-emit-llvm -c"
	;;
*)
	emitbc=-c
	;;
esac
echo ": # work around NeXTstep bug" >Rebuild.sh
echo set -x >>Rebuild.sh
for file in $SRCS; do
	op=`echo x"$file" | sed 's/^x\(.*\)\.c$/\1./'`
	test -f $file || file=$srcdir/$file
	files="$files$fsp$file"
	echo "$CC $CFLAGS $Cg $CPPFLAGS $emitbc $file || exit 1" >>Rebuild.sh
	if test $cm = dragonegg; then
		echo "mv ${op}s ${op}ll" >>Rebuild.sh
		echo "llvm-as ${op}ll || exit 1" >>Rebuild.sh
		objs="$objs$fsp${op}bc"
	else
		objs="$objs$fsp${op}o"
	fi
	fsp=$sp
done
case $cm in
dragonegg|llvm)
	echo "rm -f $tfn.s" >>Rebuild.sh
	echo "llvm-link -o - $objs | opt $optflags | llc -o $tfn.s" >>Rebuild.sh
	lobjs=$tfn.s
	;;
*)
	lobjs=$objs
	;;
esac
echo tcfn=$buildoutput >>Rebuild.sh
echo "$CC $CFLAGS $Cg $LDFLAGS -o \$tcfn $lobjs $LIBS $ccpr" >>Rebuild.sh
echo "test -f \$tcfn || exit 1; $SIZE \$tcfn" >>Rebuild.sh
echo "rm -f $paxexe $cpioexe $tarexe" >>Rebuild.sh
echo "for x in $paxexe $cpioexe $tarexe; do" >>Rebuild.sh
echo "  ln \$tcfn \$x || cp -p \$tcfn \$x || exit 1" >>Rebuild.sh
echo "done" >>Rebuild.sh
if test $cm = makefile; then
	extras='.linked/reallocarray.inc .linked/strlfun.inc .linked/strmode.inc .linked/strtonum.inc ar.h compat.h cpio.h extern.h ftimes.h pax.h tar.h'
	cat >Makefrag.inc <<EOF
# Makefile fragment for building $whatlong $dstversion

PROG=		$buildoutput
# install as $paxexe and $cpioexe and $tarexe though
MAN=		cpio.1 pax.1 tar.1
SRCDIR=		$srcdir
MF_DIR=		$curdisp
SRCS=		$SRCS
SRCS_FP=	$files
OBJS_BP=	$objs
INDSRCS=	$extras
NONSRCS_INST=	\$(MAN)
NONSRCS_NOINST=	Build.sh Makefile Rebuild.sh
CC=		$CC
CPPFLAGS=	$CPPFLAGS -I'\$(MF_DIR)'
CFLAGS=		$CFLAGS $Cg
LDFLAGS=	$LDFLAGS
LIBS=		$LIBS

# not BSD make only:
#VPATH=		\$(SRCDIR)
#all: \$(PROG)
#\$(PROG): \$(OBJS_BP)
#	\$(CC) \$(CFLAGS) \$(LDFLAGS) -o \$@ \$(OBJS_BP) \$(LIBS)
#\$(OBJS_BP): \$(SRCS_FP) \$(NONSRCS)
#.c.o:
#	\$(CC) \$(CFLAGS) \$(CPPFLAGS) -c \$<

# for BSD make only:
#.PATH: \$(SRCDIR)
#.include <bsd.prog.mk>
EOF
	$e
	$e Generated Makefrag.inc successfully.
	exit 0
fi
if test $cm = combine; then
	objs="-o $buildoutput"
	for file in $SRCS; do
		test -f $file || file=$srcdir/$file
		objs="$objs $file"
	done
	emitbc="-fwhole-program --combine"
	v "$CC $CFLAGS $Cg $CPPFLAGS $LDFLAGS $emitbc $objs $LIBS $ccpr"
elif test 1 = $pm; then
	for file in $SRCS; do
		test -f $file || file=$srcdir/$file
		v "$CC $CFLAGS $Cg $CPPFLAGS $emitbc $file" &
	done
	wait
else
	for file in $SRCS; do
		test $cm = dragonegg && \
		    op=`echo x"$file" | sed 's/^x\(.*\)\.c$/\1./'`
		test -f $file || file=$srcdir/$file
		v "$CC $CFLAGS $Cg $CPPFLAGS $emitbc $file" || exit 1
		if test $cm = dragonegg; then
			v "mv ${op}s ${op}ll"
			v "llvm-as ${op}ll" || exit 1
		fi
	done
fi
case $cm in
dragonegg|llvm)
	rmf $tfn.s
	v "llvm-link -o - $objs | opt $optflags | llc -o $tfn.s"
	;;
esac
tcfn=$buildoutput
case $cm in
combine)
	;;
*)
	v "$CC $CFLAGS $Cg $LDFLAGS -o $tcfn $lobjs $LIBS $ccpr"
	;;
esac
test -f $tcfn || exit 1
rm -f $paxexe $cpioexe $tarexe
for x in $paxexe $cpioexe $tarexe; do
	ln $tcfn $x || cp -p $tcfn $x || exit 1
done
rm -rf mans
mkdir mans
echo .nr g $mans | cat - "$srcdir/cpio.1" >mans/$cpioname.1
echo .nr g $mans | cat - "$srcdir/pax.1" >mans/$paxname.1
echo .nr g $mans | cat - "$srcdir/tar.1" >mans/$tarname.1
test 1 = $r || v "$NROFF -mdoc <mans/$cpioname.1 >mans/$cpioname.cat1" || rmf mans/$cpioname.cat1
test 1 = $r || v "$NROFF -mdoc <mans/$paxname.1 >mans/$paxname.cat1" || rmf mans/$paxname.cat1
test 1 = $r || v "$NROFF -mdoc <mans/$tarname.1 >mans/$tarname.cat1" || rmf mans/$tarname.cat1
test 0 = $eq && v $SIZE $tcfn
i=install
test -f /usr/ucb/$i && i=/usr/ucb/$i
test 1 = $eq && e=:
$e
$e Installing the executable:
$e "# $i -c -s -o root -g bin -m 555 $paxexe /bin/$paxexe"
for x in $cpioexe $tarexe; do
	$e "# ln -f /bin/$paxexe /bin/$x || cp -fp /bin/$paxexe /bin/$x"
done
$e
$e Installing the manual:
if test -f mans/$paxname.cat1; then
	$e "# $i -c -o root -g bin -m 444 mans/$cpioname.cat1" \
	    "/usr/share/man/cat1/$cpioname.0"
	$e "# $i -c -o root -g bin -m 444 mans/$paxname.cat1" \
	    "/usr/share/man/cat1/$paxname.0"
	$e "# $i -c -o root -g bin -m 444 mans/$tarname.cat1" \
	    "/usr/share/man/cat1/$tarname.0"
	$e or
fi
$e "# $i -c -o root -g bin -m 444 mans/$cpioname.1 mans/$paxname.1 mans/$tarname.1 /usr/share/man/man1/"
$e
$e Please also read the fine manual.
exit 0

: <<'EOD'

=== Environment used ===

==== build environment ====
CC				default: cc
CFLAGS				if empty, defaults to -xO2 or +O2
				or -O3 -qstrict or -O2, per compiler
CPPFLAGS			default empty
LDFLAGS				default empty; added before sources
LDSTATIC			set this to '-static'; default unset
LIBS				default empty; added after sources
NOWARN				-Wno-error or similar
NROFF				default: nroff
TARGET_OS			default: `uname -s || uname`
TARGET_OSREV			default: `uname -r` [only needed on some OS]

===== general format =====
HAVE_STRLEN			ac_test
HAVE_STRING_H			ac_header
HAVE_CAN_FSTACKPROTECTORALL	ac_flags

==== cpp definitions ====
DEBUG				don’t use in production, wants gcc
MKSH_DONT_EMIT_IDSTRING		omit RCS IDs from binary
PAX_SAFE_PATH			subprocess PATH, default "/bin:/usr/bin"
SMALL				for the MirBSD installer/rescue system

=== generic installation instructions ===

Set CC and possibly CFLAGS, CPPFLAGS, LDFLAGS, LIBS. If cross-compiling,
also set TARGET_OS. To disable tests, set e.g. HAVE_STRLCPY=0; to enable
them, set to a value other than 0 or 1 (e.g. to x).

Normally, the following command is what you want to run, then:
$ sh Build.sh -r 2>&1 | tee log

Install as /bin/pax and hardlink to /bin/cpio and /bin/tar or install as
$prefix/bin/mirpax and hardlink to $prefix/bin/mir{cpio,tar}; install the
manpages, if omitting the -r flag catmanpages are made using $NROFF.

Add -tmir to install as mir{pax,cpio,tar} or -tpax for pax{,cpio,tar}.

EOD

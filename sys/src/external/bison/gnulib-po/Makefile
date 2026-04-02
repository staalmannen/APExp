# Makefile for PO directory in any package using GNU gettext.
# Copyright (C) 1995-1997, 2000-2007, 2009-2010 by Ulrich Drepper <drepper@gnu.ai.mit.edu>
#
# This file can be copied and used freely without restrictions.  It can
# be used in projects which are not available under the GNU General Public
# License but which still want to provide support for the GNU gettext
# functionality.
# Please note that the actual code of GNU gettext is covered by the GNU
# General Public License and is *not* in the public domain.
#
# Origin: gettext-0.19
GETTEXT_MACRO_VERSION = 0.19

PACKAGE = bison
VERSION = 3.8
PACKAGE_BUGREPORT = bug-bison@gnu.org

SED = /bin/sed
SHELL = /bin/sh


srcdir = .
top_srcdir = ..


prefix = /usr/local
exec_prefix = ${prefix}
datarootdir = ${prefix}/share
datadir = ${datarootdir}
localedir = ${datarootdir}/locale
gettextsrcdir = $(datadir)/gettext/po

INSTALL = /bin/install -c
INSTALL_DATA = ${INSTALL} -m 644

# We use $(mkdir_p).
# In automake <= 1.9.x, $(mkdir_p) is defined either as "mkdir -p --" or as
# "$(mkinstalldirs)" or as "$(install_sh) -d". For these automake versions,
# ${SHELL} /usr/glenda/APExp/sys/src/external/bison/build-aux/install-sh does not start with $(SHELL), so we add it.
# In automake >= 1.10, $(MKDIR_P) is derived from ${MKDIR_P}, which is defined
# either as "/path/to/mkdir -p" or ".../install-sh -c -d". For these automake
# versions, $(mkinstalldirs) and $(install_sh) are unused.
mkinstalldirs = $(SHELL) ${SHELL} /usr/glenda/APExp/sys/src/external/bison/build-aux/install-sh -d
install_sh = $(SHELL) ${SHELL} /usr/glenda/APExp/sys/src/external/bison/build-aux/install-sh
MKDIR_P = .././build-aux/install-sh -c -d
mkdir_p = $(MKDIR_P)

GMSGFMT_ = :
GMSGFMT_no = :
GMSGFMT_yes = :
GMSGFMT = $(GMSGFMT_$(USE_MSGCTXT))
MSGFMT_ = :
MSGFMT_no = :
MSGFMT_yes = :
MSGFMT = $(MSGFMT_$(USE_MSGCTXT))
XGETTEXT_ = :
XGETTEXT_no = :
XGETTEXT_yes = :
XGETTEXT = $(XGETTEXT_$(USE_MSGCTXT))
MSGMERGE = msgmerge
MSGMERGE_UPDATE = /bin/msgmerge --update
MSGINIT = msginit
MSGCONV = msgconv
MSGFILTER = msgfilter

POFILES =  af.po be.po bg.po ca.po cs.po da.po de.po el.po eo.po es.po et.po eu.po fi.po fr.po ga.po gl.po hu.po it.po ja.po ko.po ms.po nb.po nl.po pl.po pt.po pt_BR.po ro.po ru.po rw.po sk.po sl.po sr.po sv.po tr.po uk.po vi.po zh_CN.po zh_TW.po
GMOFILES =  af.gmo be.gmo bg.gmo ca.gmo cs.gmo da.gmo de.gmo el.gmo eo.gmo es.gmo et.gmo eu.gmo fi.gmo fr.gmo ga.gmo gl.gmo hu.gmo it.gmo ja.gmo ko.gmo ms.gmo nb.gmo nl.gmo pl.gmo pt.gmo pt_BR.gmo ro.gmo ru.gmo rw.gmo sk.gmo sl.gmo sr.gmo sv.gmo tr.gmo uk.gmo vi.gmo zh_CN.gmo zh_TW.gmo
UPDATEPOFILES =  af.po-update be.po-update bg.po-update ca.po-update cs.po-update da.po-update de.po-update el.po-update eo.po-update es.po-update et.po-update eu.po-update fi.po-update fr.po-update ga.po-update gl.po-update hu.po-update it.po-update ja.po-update ko.po-update ms.po-update nb.po-update nl.po-update pl.po-update pt.po-update pt_BR.po-update ro.po-update ru.po-update rw.po-update sk.po-update sl.po-update sr.po-update sv.po-update tr.po-update uk.po-update vi.po-update zh_CN.po-update zh_TW.po-update
DUMMYPOFILES =  af.nop be.nop bg.nop ca.nop cs.nop da.nop de.nop el.nop eo.nop es.nop et.nop eu.nop fi.nop fr.nop ga.nop gl.nop hu.nop it.nop ja.nop ko.nop ms.nop nb.nop nl.nop pl.nop pt.nop pt_BR.nop ro.nop ru.nop rw.nop sk.nop sl.nop sr.nop sv.nop tr.nop uk.nop vi.nop zh_CN.nop zh_TW.nop
DISTFILES.common = Makefile.in.in remove-potcdate.sin \
$(DISTFILES.common.extra1) $(DISTFILES.common.extra2) $(DISTFILES.common.extra3)
DISTFILES = $(DISTFILES.common) Makevars POTFILES.in \
$(POFILES) $(GMOFILES) \
$(DISTFILES.extra1) $(DISTFILES.extra2) $(DISTFILES.extra3)

POTFILES = \
     ../lib/_Noreturn.h \
     ../lib/access.c \
     ../lib/alignof.h \
     ../lib/alloca.in.h \
     ../lib/allocator.c \
     ../lib/allocator.h \
     ../lib/areadlink.c \
     ../lib/areadlink.h \
     ../lib/arg-nonnull.h \
     ../lib/argmatch.c \
     ../lib/argmatch.h \
     ../lib/asnprintf.c \
     ../lib/asprintf.c \
     ../lib/assure.h \
     ../lib/at-func.c \
     ../lib/attribute.h \
     ../lib/basename-lgpl.c \
     ../lib/basename-lgpl.h \
     ../lib/basename.c \
     ../lib/binary-io.c \
     ../lib/binary-io.h \
     ../lib/bitrotate.c \
     ../lib/bitrotate.h \
     ../lib/bitset.c \
     ../lib/bitset.h \
     ../lib/bitset/array.c \
     ../lib/bitset/array.h \
     ../lib/bitset/base.h \
     ../lib/bitset/list.c \
     ../lib/bitset/list.h \
     ../lib/bitset/stats.c \
     ../lib/bitset/stats.h \
     ../lib/bitset/table.c \
     ../lib/bitset/table.h \
     ../lib/bitset/vector.c \
     ../lib/bitset/vector.h \
     ../lib/bitsetv.c \
     ../lib/bitsetv.h \
     ../lib/c++defs.h \
     ../lib/c-ctype.c \
     ../lib/c-ctype.h \
     ../lib/c-strcase.h \
     ../lib/c-strcasecmp.c \
     ../lib/c-strcaseeq.h \
     ../lib/c-strncasecmp.c \
     ../lib/calloc.c \
     ../lib/canonicalize-lgpl.c \
     ../lib/canonicalize.c \
     ../lib/canonicalize.h \
     ../lib/careadlinkat.c \
     ../lib/careadlinkat.h \
     ../lib/cdefs.h \
     ../lib/chdir-long.c \
     ../lib/chdir-long.h \
     ../lib/cloexec.c \
     ../lib/cloexec.h \
     ../lib/close-stream.c \
     ../lib/close-stream.h \
     ../lib/close.c \
     ../lib/closedir.c \
     ../lib/closeout.c \
     ../lib/closeout.h \
     ../lib/concat-filename.c \
     ../lib/concat-filename.h \
     ../lib/diffseq.h \
     ../lib/dirent-private.h \
     ../lib/dirent.in.h \
     ../lib/dirfd.c \
     ../lib/dirname-lgpl.c \
     ../lib/dirname.c \
     ../lib/dirname.h \
     ../lib/dup-safer-flag.c \
     ../lib/dup-safer.c \
     ../lib/dup.c \
     ../lib/dup2.c \
     ../lib/eloop-threshold.h \
     ../lib/errno.in.h \
     ../lib/error.c \
     ../lib/error.h \
     ../lib/execute.c \
     ../lib/execute.h \
     ../lib/exitfail.c \
     ../lib/exitfail.h \
     ../lib/fatal-signal.c \
     ../lib/fatal-signal.h \
     ../lib/fchdir.c \
     ../lib/fcntl.c \
     ../lib/fcntl.in.h \
     ../lib/fd-hook.c \
     ../lib/fd-hook.h \
     ../lib/fd-safer-flag.c \
     ../lib/fd-safer.c \
     ../lib/fdopendir.c \
     ../lib/ffs.c \
     ../lib/ffsl.c \
     ../lib/ffsl.h \
     ../lib/file-set.c \
     ../lib/file-set.h \
     ../lib/filename.h \
     ../lib/filenamecat-lgpl.c \
     ../lib/filenamecat.h \
     ../lib/findprog-in.c \
     ../lib/findprog.h \
     ../lib/float+.h \
     ../lib/float.c \
     ../lib/float.in.h \
     ../lib/fopen-safer.c \
     ../lib/fopen.c \
     ../lib/fpending.c \
     ../lib/fpending.h \
     ../lib/fprintf.c \
     ../lib/fpucw.h \
     ../lib/free.c \
     ../lib/frexp.c \
     ../lib/frexpl.c \
     ../lib/fseterr.c \
     ../lib/fseterr.h \
     ../lib/fstat.c \
     ../lib/fstatat.c \
     ../lib/fstrcmp.c \
     ../lib/fstrcmp.h \
     ../lib/fsync.c \
     ../lib/getcwd-lgpl.c \
     ../lib/getcwd.c \
     ../lib/getdelim.c \
     ../lib/getdtablesize.c \
     ../lib/gethrxtime.c \
     ../lib/gethrxtime.h \
     ../lib/getline.c \
     ../lib/getopt-cdefs.in.h \
     ../lib/getopt-core.h \
     ../lib/getopt-ext.h \
     ../lib/getopt-pfx-core.h \
     ../lib/getopt-pfx-ext.h \
     ../lib/getopt.c \
     ../lib/getopt.in.h \
     ../lib/getopt1.c \
     ../lib/getopt_int.h \
     ../lib/getprogname.c \
     ../lib/getprogname.h \
     ../lib/getrusage.c \
     ../lib/gettext.h \
     ../lib/gettime.c \
     ../lib/gettimeofday.c \
     ../lib/gl_anyhash1.h \
     ../lib/gl_anyhash2.h \
     ../lib/gl_anyhash_primes.h \
     ../lib/gl_anylinked_list1.h \
     ../lib/gl_anylinked_list2.h \
     ../lib/gl_anyrbtree_list1.h \
     ../lib/gl_anyrbtree_list2.h \
     ../lib/gl_anytree_list1.h \
     ../lib/gl_anytree_list2.h \
     ../lib/gl_anytree_oset.h \
     ../lib/gl_anytreehash_list1.h \
     ../lib/gl_anytreehash_list2.h \
     ../lib/gl_array_list.c \
     ../lib/gl_array_list.h \
     ../lib/gl_hash_map.c \
     ../lib/gl_hash_map.h \
     ../lib/gl_linked_list.c \
     ../lib/gl_linked_list.h \
     ../lib/gl_list.c \
     ../lib/gl_list.h \
     ../lib/gl_map.c \
     ../lib/gl_map.h \
     ../lib/gl_oset.c \
     ../lib/gl_oset.h \
     ../lib/gl_rbtree_ordered.h \
     ../lib/gl_rbtree_oset.c \
     ../lib/gl_rbtree_oset.h \
     ../lib/gl_rbtreehash_list.c \
     ../lib/gl_rbtreehash_list.h \
     ../lib/gl_xlist.c \
     ../lib/gl_xlist.h \
     ../lib/gl_xmap.c \
     ../lib/gl_xmap.h \
     ../lib/glthread/lock.c \
     ../lib/glthread/lock.h \
     ../lib/glthread/threadlib.c \
     ../lib/glthread/tls.c \
     ../lib/glthread/tls.h \
     ../lib/hard-locale.c \
     ../lib/hard-locale.h \
     ../lib/hash-pjw.c \
     ../lib/hash-pjw.h \
     ../lib/hash-triple-simple.c \
     ../lib/hash-triple.h \
     ../lib/hash.c \
     ../lib/hash.h \
     ../lib/ialloc.c \
     ../lib/ialloc.h \
     ../lib/iconv.c \
     ../lib/iconv.in.h \
     ../lib/iconv_close.c \
     ../lib/iconv_open-aix.gperf \
     ../lib/iconv_open-hpux.gperf \
     ../lib/iconv_open-irix.gperf \
     ../lib/iconv_open-osf.gperf \
     ../lib/iconv_open-solaris.gperf \
     ../lib/iconv_open-zos.gperf \
     ../lib/iconv_open.c \
     ../lib/idx.h \
     ../lib/integer_length.c \
     ../lib/integer_length.h \
     ../lib/integer_length_l.c \
     ../lib/intprops.h \
     ../lib/inttypes.in.h \
     ../lib/isnan.c \
     ../lib/isnand-nolibm.h \
     ../lib/isnand.c \
     ../lib/isnanf-nolibm.h \
     ../lib/isnanf.c \
     ../lib/isnanl-nolibm.h \
     ../lib/isnanl.c \
     ../lib/iswblank.c \
     ../lib/iswdigit.c \
     ../lib/iswxdigit.c \
     ../lib/itold.c \
     ../lib/lc-charset-dispatch.c \
     ../lib/lc-charset-dispatch.h \
     ../lib/ldexpl.c \
     ../lib/libc-config.h \
     ../lib/limits.in.h \
     ../lib/localcharset.c \
     ../lib/localcharset.h \
     ../lib/locale.in.h \
     ../lib/lstat.c \
     ../lib/malloc.c \
     ../lib/malloc/scratch_buffer.h \
     ../lib/malloc/scratch_buffer_dupfree.c \
     ../lib/malloc/scratch_buffer_grow.c \
     ../lib/malloc/scratch_buffer_grow_preserve.c \
     ../lib/malloc/scratch_buffer_set_array_size.c \
     ../lib/malloca.c \
     ../lib/malloca.h \
     ../lib/math.c \
     ../lib/math.in.h \
     ../lib/mbchar.c \
     ../lib/mbchar.h \
     ../lib/mbfile.c \
     ../lib/mbfile.h \
     ../lib/mbrtowc-impl-utf8.h \
     ../lib/mbrtowc-impl.h \
     ../lib/mbrtowc.c \
     ../lib/mbsinit.c \
     ../lib/mbswidth.c \
     ../lib/mbswidth.h \
     ../lib/mbtowc-lock.c \
     ../lib/mbtowc-lock.h \
     ../lib/memchr.c \
     ../lib/memchr.valgrind \
     ../lib/mempcpy.c \
     ../lib/memrchr.c \
     ../lib/minmax.h \
     ../lib/msvc-inval.c \
     ../lib/msvc-inval.h \
     ../lib/msvc-nothrow.c \
     ../lib/msvc-nothrow.h \
     ../lib/obstack.c \
     ../lib/obstack.h \
     ../lib/obstack_printf.c \
     ../lib/open.c \
     ../lib/openat-die.c \
     ../lib/openat-priv.h \
     ../lib/openat-proc.c \
     ../lib/openat.c \
     ../lib/openat.h \
     ../lib/opendir.c \
     ../lib/os2-spawn.c \
     ../lib/os2-spawn.h \
     ../lib/pathmax.h \
     ../lib/perror.c \
     ../lib/pipe-safer.c \
     ../lib/pipe.c \
     ../lib/pipe2-safer.c \
     ../lib/pipe2.c \
     ../lib/printf-args.c \
     ../lib/printf-args.h \
     ../lib/printf-frexp.c \
     ../lib/printf-frexp.h \
     ../lib/printf-frexpl.c \
     ../lib/printf-frexpl.h \
     ../lib/printf-parse.c \
     ../lib/printf-parse.h \
     ../lib/printf.c \
     ../lib/progname.c \
     ../lib/progname.h \
     ../lib/progreloc.c \
     ../lib/quote.h \
     ../lib/quotearg.c \
     ../lib/quotearg.h \
     ../lib/raise.c \
     ../lib/rawmemchr.c \
     ../lib/rawmemchr.valgrind \
     ../lib/readdir.c \
     ../lib/readline.c \
     ../lib/readline.h \
     ../lib/readlink.c \
     ../lib/realloc.c \
     ../lib/reallocarray.c \
     ../lib/relocatable.c \
     ../lib/relocatable.h \
     ../lib/relocwrapper.c \
     ../lib/rename.c \
     ../lib/rewinddir.c \
     ../lib/rmdir.c \
     ../lib/same-inode.h \
     ../lib/save-cwd.c \
     ../lib/save-cwd.h \
     ../lib/sched.in.h \
     ../lib/scratch_buffer.h \
     ../lib/setenv.c \
     ../lib/setlocale-lock.c \
     ../lib/setlocale_null.c \
     ../lib/setlocale_null.h \
     ../lib/sig-handler.c \
     ../lib/sig-handler.h \
     ../lib/sigaction.c \
     ../lib/signal.in.h \
     ../lib/signbitd.c \
     ../lib/signbitf.c \
     ../lib/signbitl.c \
     ../lib/sigprocmask.c \
     ../lib/size_max.h \
     ../lib/snprintf.c \
     ../lib/spawn-pipe.c \
     ../lib/spawn-pipe.h \
     ../lib/spawn.c \
     ../lib/spawn.in.h \
     ../lib/spawn_faction_addchdir.c \
     ../lib/spawn_faction_addclose.c \
     ../lib/spawn_faction_adddup2.c \
     ../lib/spawn_faction_addopen.c \
     ../lib/spawn_faction_destroy.c \
     ../lib/spawn_faction_init.c \
     ../lib/spawn_int.h \
     ../lib/spawnattr_destroy.c \
     ../lib/spawnattr_init.c \
     ../lib/spawnattr_setflags.c \
     ../lib/spawnattr_setpgroup.c \
     ../lib/spawnattr_setsigmask.c \
     ../lib/spawni.c \
     ../lib/spawnp.c \
     ../lib/sprintf.c \
     ../lib/stat-time.c \
     ../lib/stat-time.h \
     ../lib/stat-w32.c \
     ../lib/stat-w32.h \
     ../lib/stat.c \
     ../lib/stdbool.in.h \
     ../lib/stddef.in.h \
     ../lib/stdint.in.h \
     ../lib/stdio--.h \
     ../lib/stdio-impl.h \
     ../lib/stdio-safer.h \
     ../lib/stdio.in.h \
     ../lib/stdlib.in.h \
     ../lib/stpcpy.c \
     ../lib/stpncpy.c \
     ../lib/strchrnul.c \
     ../lib/strchrnul.valgrind \
     ../lib/strdup.c \
     ../lib/streq.h \
     ../lib/strerror-override.c \
     ../lib/strerror-override.h \
     ../lib/strerror.c \
     ../lib/strerror_r.c \
     ../lib/string.in.h \
     ../lib/strings.in.h \
     ../lib/stripslash.c \
     ../lib/strndup.c \
     ../lib/strnlen.c \
     ../lib/strverscmp.c \
     ../lib/sys_ioctl.in.h \
     ../lib/sys_resource.in.h \
     ../lib/sys_stat.in.h \
     ../lib/sys_time.in.h \
     ../lib/sys_times.in.h \
     ../lib/sys_types.in.h \
     ../lib/sys_wait.in.h \
     ../lib/termios.in.h \
     ../lib/textstyle.in.h \
     ../lib/thread-optim.h \
     ../lib/time.in.h \
     ../lib/timespec.c \
     ../lib/timespec.h \
     ../lib/timevar.c \
     ../lib/timevar.h \
     ../lib/unicodeio.c \
     ../lib/unicodeio.h \
     ../lib/unistd--.h \
     ../lib/unistd-safer.h \
     ../lib/unistd.c \
     ../lib/unistd.in.h \
     ../lib/unistr.in.h \
     ../lib/unistr/u8-mbtoucr.c \
     ../lib/unistr/u8-uctomb-aux.c \
     ../lib/unistr/u8-uctomb.c \
     ../lib/unitypes.in.h \
     ../lib/uniwidth.in.h \
     ../lib/uniwidth/cjk.h \
     ../lib/uniwidth/width.c \
     ../lib/unlink.c \
     ../lib/unlocked-io.h \
     ../lib/unsetenv.c \
     ../lib/vasnprintf.c \
     ../lib/vasnprintf.h \
     ../lib/vasprintf.c \
     ../lib/verify.h \
     ../lib/vfprintf.c \
     ../lib/vsnprintf.c \
     ../lib/vsprintf.c \
     ../lib/wait-process.c \
     ../lib/wait-process.h \
     ../lib/waitpid.c \
     ../lib/warn-on-use.h \
     ../lib/wchar.in.h \
     ../lib/wctype-h.c \
     ../lib/wctype.in.h \
     ../lib/wcwidth.c \
     ../lib/windows-initguard.h \
     ../lib/windows-mutex.c \
     ../lib/windows-mutex.h \
     ../lib/windows-once.c \
     ../lib/windows-once.h \
     ../lib/windows-recmutex.c \
     ../lib/windows-recmutex.h \
     ../lib/windows-rwlock.c \
     ../lib/windows-rwlock.h \
     ../lib/windows-spawn.c \
     ../lib/windows-spawn.h \
     ../lib/windows-tls.c \
     ../lib/windows-tls.h \
     ../lib/xalloc-die.c \
     ../lib/xalloc-oversized.h \
     ../lib/xalloc.h \
     ../lib/xconcat-filename.c \
     ../lib/xhash.c \
     ../lib/xmalloc.c \
     ../lib/xmemdup0.c \
     ../lib/xmemdup0.h \
     ../lib/xreadlink.c \
     ../lib/xreadlink.h \
     ../lib/xsize.c \
     ../lib/xsize.h \
     ../lib/xstrndup.c \
     ../lib/xstrndup.h \
     ../lib/xtime.c \
     ../lib/xtime.h

CATALOGS =  af.gmo be.gmo bg.gmo ca.gmo cs.gmo da.gmo de.gmo el.gmo eo.gmo es.gmo et.gmo eu.gmo fi.gmo fr.gmo ga.gmo gl.gmo hu.gmo it.gmo ja.gmo ko.gmo ms.gmo nb.gmo nl.gmo pl.gmo pt.gmo pt_BR.gmo ro.gmo ru.gmo rw.gmo sk.gmo sl.gmo sr.gmo sv.gmo tr.gmo uk.gmo vi.gmo zh_CN.gmo zh_TW.gmo

POFILESDEPS_ = $(srcdir)/$(DOMAIN).pot
POFILESDEPS_yes = $(POFILESDEPS_)
POFILESDEPS_no =
POFILESDEPS = $(POFILESDEPS_$(PO_DEPENDS_ON_POT))

DISTFILESDEPS_ = update-po
DISTFILESDEPS_yes = $(DISTFILESDEPS_)
DISTFILESDEPS_no =
DISTFILESDEPS = $(DISTFILESDEPS_$(DIST_DEPENDS_ON_UPDATE_PO))

# Makevars gets inserted here. (Don't remove this line!)
## DO NOT EDIT! GENERATED AUTOMATICALLY!
# Copyright (C) 2002-2021 Free Software Foundation, Inc.
#
# This file is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This file is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this file.  If not, see <https://www.gnu.org/licenses/>.
#
# As a special exception to the GNU General Public License,
# this file may be distributed as part of a program that
# contains a configuration script generated by Autoconf, under
# the same distribution terms as the rest of that program.
#
# Generated by gnulib-tool.

# Usually the message domain is the same as the package name.
# But here it has a '-gnulib' suffix.
DOMAIN = bison-gnulib

# These two variables depend on the location of this directory.
subdir = gnulib-po
top_builddir = ..

# These options get passed to xgettext.
XGETTEXT_OPTIONS = \
  --keyword=_ --flag=_:1:pass-c-format \
  --keyword=N_ --flag=N_:1:pass-c-format \
  --keyword='proper_name:1,"This is a proper name. See the gettext manual, section Names."' \
  --keyword='proper_name_utf8:1,"This is a proper name. See the gettext manual, section Names."' \
  --flag=error:3:c-format --flag=error_at_line:5:c-format

# This is the copyright holder that gets inserted into the header of the
# $(DOMAIN).pot file.  gnulib is copyrighted by the FSF.
COPYRIGHT_HOLDER = Free Software Foundation, Inc.

# This is the email address or URL to which the translators shall report
# bugs in the untranslated strings:
# - Strings which are not entire sentences, see the maintainer guidelines
#   in the GNU gettext documentation, section 'Preparing Strings'.
# - Strings which use unclear terms or require additional context to be
#   understood.
# - Strings which make invalid assumptions about notation of date, time or
#   money.
# - Pluralisation problems.
# - Incorrect English spelling.
# - Incorrect formatting.
# It can be your email address, or a mailing list address where translators
# can write to without being subscribed, or the URL of a web page through
# which the translators can contact you.
MSGID_BUGS_ADDRESS = bug-gnulib@gnu.org

# This is the list of locale categories, beyond LC_MESSAGES, for which the
# message catalogs shall be used.  It is usually empty.
EXTRA_LOCALE_CATEGORIES =

# This tells whether the $(DOMAIN).pot file contains messages with an 'msgctxt'
# context.  Possible values are "yes" and "no".  Set this to yes if the
# package uses functions taking also a message context, like pgettext(), or
# if in $(XGETTEXT_OPTIONS) you define keywords with a context argument.
USE_MSGCTXT = no

.SUFFIXES:
.SUFFIXES: .po .gmo .mo .sed .sin .nop .po-create .po-update

.po.mo:
	@echo "$(MSGFMT) -c -o $@ $<"; \
	$(MSGFMT) -c -o t-$@ $< && mv t-$@ $@

.po.gmo:
	@lang=`echo $* | sed -e 's,.*/,,'`; \
	test "$(srcdir)" = . && cdcmd="" || cdcmd="cd $(srcdir) && "; \
	echo "$${cdcmd}rm -f $${lang}.gmo && $(GMSGFMT) -c --statistics --verbose -o $${lang}.gmo $${lang}.po"; \
	cd $(srcdir) && rm -f $${lang}.gmo && $(GMSGFMT) -c --statistics --verbose -o t-$${lang}.gmo $${lang}.po && mv t-$${lang}.gmo $${lang}.gmo

.sin.sed:
	sed -e '/^#/d' $< > t-$@
	mv t-$@ $@


all: all-no

all-yes: stamp-po
all-no:

# Ensure that the gettext macros and this Makefile.in.in are in sync.
CHECK_MACRO_VERSION = \
	test "$(GETTEXT_MACRO_VERSION)" = "0.19" \
	  || { echo "*** error: gettext infrastructure mismatch: using a Makefile.in.in from gettext version $(GETTEXT_MACRO_VERSION) but the autoconf macros are from gettext version 0.19" 1>&2; \
	       exit 1; \
	     }

# $(srcdir)/$(DOMAIN).pot is only created when needed. When xgettext finds no
# internationalized messages, no $(srcdir)/$(DOMAIN).pot is created (because
# we don't want to bother translators with empty POT files). We assume that
# LINGUAS is empty in this case, i.e. $(POFILES) and $(GMOFILES) are empty.
# In this case, stamp-po is a nop (i.e. a phony target).

# stamp-po is a timestamp denoting the last time at which the CATALOGS have
# been loosely updated. Its purpose is that when a developer or translator
# checks out the package via CVS, and the $(DOMAIN).pot file is not in CVS,
# "make" will update the $(DOMAIN).pot and the $(CATALOGS), but subsequent
# invocations of "make" will do nothing. This timestamp would not be necessary
# if updating the $(CATALOGS) would always touch them; however, the rule for
# $(POFILES) has been designed to not touch files that don't need to be
# changed.
stamp-po: $(srcdir)/$(DOMAIN).pot
	@$(CHECK_MACRO_VERSION)
	test ! -f $(srcdir)/$(DOMAIN).pot || \
	  test -z "$(GMOFILES)" || $(MAKE) $(GMOFILES)
	@test ! -f $(srcdir)/$(DOMAIN).pot || { \
	  echo "touch stamp-po" && \
	  echo timestamp > stamp-poT && \
	  mv stamp-poT stamp-po; \
	}

# Note: Target 'all' must not depend on target '$(DOMAIN).pot-update',
# otherwise packages like GCC can not be built if only parts of the source
# have been downloaded.

# This target rebuilds $(DOMAIN).pot; it is an expensive operation.
# Note that $(DOMAIN).pot is not touched if it doesn't need to be changed.
# The determination of whether the package xyz is a GNU one is based on the
# heuristic whether some file in the top level directory mentions "GNU xyz".
# If GNU 'find' is available, we avoid grepping through monster files.
$(DOMAIN).pot-update: $(POTFILES) $(srcdir)/POTFILES.in remove-potcdate.sed
	package_gnu="$(PACKAGE_GNU)"; \
	test -n "$$package_gnu" || { \
	  if { if (LC_ALL=C find --version) 2>/dev/null | grep GNU >/dev/null; then \
		 LC_ALL=C find -L $(top_srcdir) -maxdepth 1 -type f \
			       -size -10000000c -exec grep 'GNU bison' \
			       /dev/null '{}' ';' 2>/dev/null; \
	       else \
		 LC_ALL=C grep 'GNU bison' $(top_srcdir)/* 2>/dev/null; \
	       fi; \
	     } | grep -v 'libtool:' >/dev/null; then \
	     package_gnu=yes; \
	   else \
	     package_gnu=no; \
	   fi; \
	}; \
	if test "$$package_gnu" = "yes"; then \
	  package_prefix='GNU '; \
	else \
	  package_prefix=''; \
	fi; \
	if test -n '$(MSGID_BUGS_ADDRESS)' || test '$(PACKAGE_BUGREPORT)' = '@'PACKAGE_BUGREPORT'@'; then \
	  msgid_bugs_address='$(MSGID_BUGS_ADDRESS)'; \
	else \
	  msgid_bugs_address='$(PACKAGE_BUGREPORT)'; \
	fi; \
	case `$(XGETTEXT) --version | sed 1q | sed -e 's,^[^0-9]*,,'` in \
	  '' | 0.[0-9] | 0.[0-9].* | 0.1[0-5] | 0.1[0-5].* | 0.16 | 0.16.[0-1]*) \
	    $(XGETTEXT) --default-domain=$(DOMAIN) --directory=$(top_srcdir) \
	      --add-comments=TRANSLATORS: $(XGETTEXT_OPTIONS)  --flag=error:3:c-format --flag=error_at_line:5:c-format --flag=asprintf:2:c-format --flag=vasprintf:2:c-format \
	      --files-from=$(srcdir)/POTFILES.in \
	      --copyright-holder='$(COPYRIGHT_HOLDER)' \
	      --msgid-bugs-address="$$msgid_bugs_address" \
	    ;; \
	  *) \
	    $(XGETTEXT) --default-domain=$(DOMAIN) --directory=$(top_srcdir) \
	      --add-comments=TRANSLATORS: $(XGETTEXT_OPTIONS)  --flag=error:3:c-format --flag=error_at_line:5:c-format --flag=asprintf:2:c-format --flag=vasprintf:2:c-format \
	      --files-from=$(srcdir)/POTFILES.in \
	      --copyright-holder='$(COPYRIGHT_HOLDER)' \
	      --package-name="$${package_prefix}bison" \
	      --package-version='3.8' \
	      --msgid-bugs-address="$$msgid_bugs_address" \
	    ;; \
	esac
	test ! -f $(DOMAIN).po || { \
	  if test -f $(srcdir)/$(DOMAIN).pot; then \
	    sed -f remove-potcdate.sed < $(srcdir)/$(DOMAIN).pot > $(DOMAIN).1po && \
	    sed -f remove-potcdate.sed < $(DOMAIN).po > $(DOMAIN).2po && \
	    if cmp $(DOMAIN).1po $(DOMAIN).2po >/dev/null 2>&1; then \
	      rm -f $(DOMAIN).1po $(DOMAIN).2po $(DOMAIN).po; \
	    else \
	      rm -f $(DOMAIN).1po $(DOMAIN).2po $(srcdir)/$(DOMAIN).pot && \
	      mv $(DOMAIN).po $(srcdir)/$(DOMAIN).pot; \
	    fi; \
	  else \
	    mv $(DOMAIN).po $(srcdir)/$(DOMAIN).pot; \
	  fi; \
	}

# This rule has no dependencies: we don't need to update $(DOMAIN).pot at
# every "make" invocation, only create it when it is missing.
# Only "make $(DOMAIN).pot-update" or "make dist" will force an update.
$(srcdir)/$(DOMAIN).pot:
	$(MAKE) $(DOMAIN).pot-update

# This target rebuilds a PO file if $(DOMAIN).pot has changed.
# Note that a PO file is not touched if it doesn't need to be changed.
$(POFILES): $(POFILESDEPS)
	@lang=`echo $@ | sed -e 's,.*/,,' -e 's/\.po$$//'`; \
	if test -f "$(srcdir)/$${lang}.po"; then \
	  test -f $(srcdir)/$(DOMAIN).pot || $(MAKE) $(srcdir)/$(DOMAIN).pot; \
	  test "$(srcdir)" = . && cdcmd="" || cdcmd="cd $(srcdir) && "; \
	  echo "$${cdcmd}$(MSGMERGE_UPDATE) $(MSGMERGE_OPTIONS) --lang=$${lang} $${lang}.po $(DOMAIN).pot"; \
	  cd $(srcdir) \
	    && { case `$(MSGMERGE_UPDATE) --version | sed 1q | sed -e 's,^[^0-9]*,,'` in \
	           '' | 0.[0-9] | 0.[0-9].* | 0.1[0-7] | 0.1[0-7].*) \
	             $(MSGMERGE_UPDATE) $(MSGMERGE_OPTIONS) $${lang}.po $(DOMAIN).pot;; \
	           *) \
	             $(MSGMERGE_UPDATE) $(MSGMERGE_OPTIONS) --lang=$${lang} $${lang}.po $(DOMAIN).pot;; \
	         esac; \
	       }; \
	else \
	  $(MAKE) $${lang}.po-create; \
	fi


install: install-exec install-data
install-exec:
install-data: install-data-no
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  $(mkdir_p) $(DESTDIR)$(gettextsrcdir); \
	  for file in $(DISTFILES.common) Makevars.template; do \
	    $(INSTALL_DATA) $(srcdir)/$$file \
			    $(DESTDIR)$(gettextsrcdir)/$$file; \
	  done; \
	  for file in Makevars; do \
	    rm -f $(DESTDIR)$(gettextsrcdir)/$$file; \
	  done; \
	else \
	  : ; \
	fi
install-data-no: all
install-data-yes: all
	@catalogs='$(CATALOGS)'; \
	for cat in $$catalogs; do \
	  cat=`basename $$cat`; \
	  lang=`echo $$cat | sed -e 's/\.gmo$$//'`; \
	  dir=$(localedir)/$$lang/LC_MESSAGES; \
	  $(mkdir_p) $(DESTDIR)$$dir; \
	  if test -r $$cat; then realcat=$$cat; else realcat=$(srcdir)/$$cat; fi; \
	  $(INSTALL_DATA) $$realcat $(DESTDIR)$$dir/$(DOMAIN).mo; \
	  echo "installing $$realcat as $(DESTDIR)$$dir/$(DOMAIN).mo"; \
	  for lc in '' $(EXTRA_LOCALE_CATEGORIES); do \
	    if test -n "$$lc"; then \
	      if (cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc 2>/dev/null) | grep ' -> ' >/dev/null; then \
	        link=`cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc | sed -e 's/^.* -> //'`; \
	        mv $(DESTDIR)$(localedir)/$$lang/$$lc $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	        mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        (cd $(DESTDIR)$(localedir)/$$lang/$$lc.old && \
	         for file in *; do \
	           if test -f $$file; then \
	             ln -s ../$$link/$$file $(DESTDIR)$(localedir)/$$lang/$$lc/$$file; \
	           fi; \
	         done); \
	        rm -f $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	      else \
	        if test -d $(DESTDIR)$(localedir)/$$lang/$$lc; then \
	          :; \
	        else \
	          rm -f $(DESTDIR)$(localedir)/$$lang/$$lc; \
	          mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        fi; \
	      fi; \
	      rm -f $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo; \
	      ln -s ../LC_MESSAGES/$(DOMAIN).mo $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo 2>/dev/null || \
	      ln $(DESTDIR)$(localedir)/$$lang/LC_MESSAGES/$(DOMAIN).mo $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo 2>/dev/null || \
	      cp -p $(DESTDIR)$(localedir)/$$lang/LC_MESSAGES/$(DOMAIN).mo $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo; \
	      echo "installing $$realcat link as $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo"; \
	    fi; \
	  done; \
	done

install-strip: install

installdirs: installdirs-exec installdirs-data
installdirs-exec:
installdirs-data: installdirs-data-no
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  $(mkdir_p) $(DESTDIR)$(gettextsrcdir); \
	else \
	  : ; \
	fi
installdirs-data-no:
installdirs-data-yes:
	@catalogs='$(CATALOGS)'; \
	for cat in $$catalogs; do \
	  cat=`basename $$cat`; \
	  lang=`echo $$cat | sed -e 's/\.gmo$$//'`; \
	  dir=$(localedir)/$$lang/LC_MESSAGES; \
	  $(mkdir_p) $(DESTDIR)$$dir; \
	  for lc in '' $(EXTRA_LOCALE_CATEGORIES); do \
	    if test -n "$$lc"; then \
	      if (cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc 2>/dev/null) | grep ' -> ' >/dev/null; then \
	        link=`cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc | sed -e 's/^.* -> //'`; \
	        mv $(DESTDIR)$(localedir)/$$lang/$$lc $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	        mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        (cd $(DESTDIR)$(localedir)/$$lang/$$lc.old && \
	         for file in *; do \
	           if test -f $$file; then \
	             ln -s ../$$link/$$file $(DESTDIR)$(localedir)/$$lang/$$lc/$$file; \
	           fi; \
	         done); \
	        rm -f $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	      else \
	        if test -d $(DESTDIR)$(localedir)/$$lang/$$lc; then \
	          :; \
	        else \
	          rm -f $(DESTDIR)$(localedir)/$$lang/$$lc; \
	          mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        fi; \
	      fi; \
	    fi; \
	  done; \
	done

# Define this as empty until I found a useful application.
installcheck:

uninstall: uninstall-exec uninstall-data
uninstall-exec:
uninstall-data: uninstall-data-no
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  for file in $(DISTFILES.common) Makevars.template; do \
	    rm -f $(DESTDIR)$(gettextsrcdir)/$$file; \
	  done; \
	else \
	  : ; \
	fi
uninstall-data-no:
uninstall-data-yes:
	catalogs='$(CATALOGS)'; \
	for cat in $$catalogs; do \
	  cat=`basename $$cat`; \
	  lang=`echo $$cat | sed -e 's/\.gmo$$//'`; \
	  for lc in LC_MESSAGES $(EXTRA_LOCALE_CATEGORIES); do \
	    rm -f $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo; \
	  done; \
	done

check: all

info dvi ps pdf html tags TAGS ctags CTAGS ID:

mostlyclean:
	rm -f remove-potcdate.sed
	rm -f stamp-poT
	rm -f core core.* $(DOMAIN).po $(DOMAIN).1po $(DOMAIN).2po *.new.po
	rm -fr *.o

clean: mostlyclean

distclean: clean
	rm -f Makefile Makefile.in POTFILES *.mo

maintainer-clean: distclean
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."
	rm -f stamp-po $(GMOFILES)

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
dist distdir:
	test -z "$(DISTFILESDEPS)" || $(MAKE) $(DISTFILESDEPS)
	@$(MAKE) dist2
# This is a separate target because 'update-po' must be executed before.
dist2: stamp-po $(DISTFILES)
	dists="$(DISTFILES)"; \
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  dists="$$dists Makevars.template"; \
	fi; \
	if test -f $(srcdir)/$(DOMAIN).pot; then \
	  dists="$$dists $(DOMAIN).pot stamp-po"; \
	fi; \
	if test -f $(srcdir)/ChangeLog; then \
	  dists="$$dists ChangeLog"; \
	fi; \
	for i in 0 1 2 3 4 5 6 7 8 9; do \
	  if test -f $(srcdir)/ChangeLog.$$i; then \
	    dists="$$dists ChangeLog.$$i"; \
	  fi; \
	done; \
	if test -f $(srcdir)/LINGUAS; then dists="$$dists LINGUAS"; fi; \
	for file in $$dists; do \
	  if test -f $$file; then \
	    cp -p $$file $(distdir) || exit 1; \
	  else \
	    cp -p $(srcdir)/$$file $(distdir) || exit 1; \
	  fi; \
	done

update-po: Makefile
	$(MAKE) $(DOMAIN).pot-update
	test -z "$(UPDATEPOFILES)" || $(MAKE) $(UPDATEPOFILES)
	$(MAKE) update-gmo

# General rule for creating PO files.

.nop.po-create:
	@lang=`echo $@ | sed -e 's/\.po-create$$//'`; \
	echo "File $$lang.po does not exist. If you are a translator, you can create it through 'msginit'." 1>&2; \
	exit 1

# General rule for updating PO files.

.nop.po-update:
	@lang=`echo $@ | sed -e 's/\.po-update$$//'`; \
	if test "$(PACKAGE)" = "gettext-tools"; then PATH=`pwd`/../src:$$PATH; fi; \
	tmpdir=`pwd`; \
	echo "$$lang:"; \
	test "$(srcdir)" = . && cdcmd="" || cdcmd="cd $(srcdir) && "; \
	echo "$${cdcmd}$(MSGMERGE) $(MSGMERGE_OPTIONS) --lang=$$lang $$lang.po $(DOMAIN).pot -o $$lang.new.po"; \
	cd $(srcdir); \
	if { case `$(MSGMERGE) --version | sed 1q | sed -e 's,^[^0-9]*,,'` in \
	       '' | 0.[0-9] | 0.[0-9].* | 0.1[0-7] | 0.1[0-7].*) \
	         $(MSGMERGE) $(MSGMERGE_OPTIONS) -o $$tmpdir/$$lang.new.po $$lang.po $(DOMAIN).pot;; \
	       *) \
	         $(MSGMERGE) $(MSGMERGE_OPTIONS) --lang=$$lang -o $$tmpdir/$$lang.new.po $$lang.po $(DOMAIN).pot;; \
	     esac; \
	   }; then \
	  if cmp $$lang.po $$tmpdir/$$lang.new.po >/dev/null 2>&1; then \
	    rm -f $$tmpdir/$$lang.new.po; \
	  else \
	    if mv -f $$tmpdir/$$lang.new.po $$lang.po; then \
	      :; \
	    else \
	      echo "msgmerge for $$lang.po failed: cannot move $$tmpdir/$$lang.new.po to $$lang.po" 1>&2; \
	      exit 1; \
	    fi; \
	  fi; \
	else \
	  echo "msgmerge for $$lang.po failed!" 1>&2; \
	  rm -f $$tmpdir/$$lang.new.po; \
	fi

$(DUMMYPOFILES):

update-gmo: Makefile $(GMOFILES)
	@:

# Recreate Makefile by invoking config.status. Explicitly invoke the shell,
# because execution permission bits may not work on the current file system.
# Use /bin/sh, which is the shell determined by autoconf for the use by its
# scripts, not $(SHELL) which is hardwired to /bin/sh and may be deficient.
Makefile: Makefile.in.in Makevars $(top_builddir)/config.status POTFILES.in LINGUAS
	cd $(top_builddir) \
	  && /bin/sh ./config.status $(subdir)/$@.in po-directories

force:

# Tell versions [3.59,3.63) of GNU make not to export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
# This file, Rules-quot, can be copied and used freely without restrictions.
# Special Makefile rules for English message catalogs with quotation marks.

DISTFILES.common.extra1 = quot.sed boldquot.sed en@quot.header en@boldquot.header insert-header.sin Rules-quot

.SUFFIXES: .insert-header .po-update-en

en@quot.po-create:
	$(MAKE) en@quot.po-update
en@boldquot.po-create:
	$(MAKE) en@boldquot.po-update

en@quot.po-update: en@quot.po-update-en
en@boldquot.po-update: en@boldquot.po-update-en

.insert-header.po-update-en:
	@lang=`echo $@ | sed -e 's/\.po-update-en$$//'`; \
	if test "$(PACKAGE)" = "gettext-tools"; then PATH=`pwd`/../src:$$PATH; GETTEXTLIBDIR=`cd $(top_srcdir)/src && pwd`; export GETTEXTLIBDIR; fi; \
	tmpdir=`pwd`; \
	echo "$$lang:"; \
	ll=`echo $$lang | sed -e 's/@.*//'`; \
	LC_ALL=C; export LC_ALL; \
	cd $(srcdir); \
	if $(MSGINIT) -i $(DOMAIN).pot --no-translator -l $$lang -o - 2>/dev/null \
	   | $(SED) -f $$tmpdir/$$lang.insert-header | $(MSGCONV) -t UTF-8 | \
	   { case `$(MSGFILTER) --version | sed 1q | sed -e 's,^[^0-9]*,,'` in \
	     '' | 0.[0-9] | 0.[0-9].* | 0.1[0-8] | 0.1[0-8].*) \
	       $(MSGFILTER) $(SED) -f `echo $$lang | sed -e 's/.*@//'`.sed \
	       ;; \
	     *) \
	       $(MSGFILTER) `echo $$lang | sed -e 's/.*@//'` \
	       ;; \
	     esac } 2>/dev/null > $$tmpdir/$$lang.new.po \
	     ; then \
	  if cmp $$lang.po $$tmpdir/$$lang.new.po >/dev/null 2>&1; then \
	    rm -f $$tmpdir/$$lang.new.po; \
	  else \
	    if mv -f $$tmpdir/$$lang.new.po $$lang.po; then \
	      :; \
	    else \
	      echo "creation of $$lang.po failed: cannot move $$tmpdir/$$lang.new.po to $$lang.po" 1>&2; \
	      exit 1; \
	    fi; \
	  fi; \
	else \
	  echo "creation of $$lang.po failed!" 1>&2; \
	  rm -f $$tmpdir/$$lang.new.po; \
	fi

en@quot.insert-header: insert-header.sin
	sed -e '/^#/d' -e 's/HEADER/en@quot.header/g' $(srcdir)/insert-header.sin > en@quot.insert-header

en@boldquot.insert-header: insert-header.sin
	sed -e '/^#/d' -e 's/HEADER/en@boldquot.header/g' $(srcdir)/insert-header.sin > en@boldquot.insert-header

mostlyclean: mostlyclean-quot
mostlyclean-quot:
	rm -f *.insert-header

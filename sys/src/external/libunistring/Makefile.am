## Makefile for the toplevel directory of GNU libunistring.
## Copyright (C) 2009-2025 Free Software Foundation, Inc.
##
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <https://www.gnu.org/licenses/>.

## Process this file with automake to produce Makefile.in.

AUTOMAKE_OPTIONS = 1.5 gnu no-dependencies
ACLOCAL_AMFLAGS = -I m4 -I gnulib-m4

SUBDIRS = doc gnulib-local lib tests install-tests

EXTRA_DIST = \
  version.sh BUGS DEPENDENCIES INSTALL.generic HACKING JOIN-GNU \
  autogen.sh \
  build-aux/join-v-1 build-aux/texi2html build-aux/run-test \
  build-aux/git-log-fix


# Allow users to use "gnulib-tool --update".
EXTRA_DIST += gnulib-m4/gnulib-cache.m4


# Cygwin support.

EXTRA_DIST += woe32dll/export.h


# Windows support.

EXTRA_DIST += INSTALL.windows build-aux/windres-options


# Generate ChangeLog during "make dist".

dist-hook: gen-ChangeLog

gen_start_date = 2023-09-10
.PHONY: gen-ChangeLog
gen-ChangeLog:
	$(AM_V_GEN)if test -d $(srcdir)/.git; then                      \
	  log_fix="$(srcdir)/build-aux/git-log-fix";                    \
	  test -e "$$log_fix"                                           \
	    && amend_git_log="--amend=$$log_fix"                        \
	    || amend_git_log=;                                          \
	  $(top_srcdir)/build-aux/gitlog-to-changelog                   \
	    --srcdir=$(srcdir)                                          \
	    $$amend_git_log --no-cluster --since=$(gen_start_date) -- . \
	    > "$(distdir)/ChangeLog-t"                                  \
	    && rm -f "$(distdir)/ChangeLog"                             \
	    && mv "$(distdir)/ChangeLog-t" "$(distdir)/ChangeLog";      \
	fi

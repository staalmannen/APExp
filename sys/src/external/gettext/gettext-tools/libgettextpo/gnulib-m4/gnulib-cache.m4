# Copyright (C) 2002-2024 Free Software Foundation, Inc.
#
# This file is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
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
#
# This file represents the specification of how gnulib-tool is used.
# It acts as a cache: It is written and read by gnulib-tool.
# In projects that use version control, this file is meant to be put under
# version control, like the configure.ac and various Makefile.am files.


# Specification in the form of a command-line invocation:
# gnulib-tool --import --local-dir=gnulib-local \
#  --lib=libgnu \
#  --source-base=libgettextpo \
#  --m4-base=libgettextpo/gnulib-m4 \
#  --doc-base=doc \
#  --tests-base=tests \
#  --aux-dir=../build-aux \
#  --makefile-name=Makefile.gnulib \
#  --no-conditional-dependencies \
#  --libtool \
#  --macro-prefix=gtpo \
#  --avoid=progname \
#  attribute \
#  basename-lgpl \
#  c-ctype \
#  c-strcase \
#  c-strstr \
#  close \
#  error \
#  error-progname \
#  fdopen \
#  filename \
#  fopen \
#  free-posix \
#  fstrcmp \
#  fwriteerror \
#  gcd \
#  getline \
#  gettext-h \
#  iconv \
#  libtextstyle-dummy \
#  libunistring-optional \
#  markup \
#  mem-hash-map \
#  minmax \
#  open \
#  realloc-posix \
#  relocatable-lib \
#  sigpipe \
#  stdbool \
#  stdio \
#  stdlib \
#  stpcpy \
#  stpncpy \
#  strchrnul \
#  strerror \
#  string-desc \
#  unictype/ctype-space \
#  unilbrk/ulc-width-linebreaks \
#  unistr/u16-mbtouc \
#  unistr/u8-mbtouc \
#  unistr/u8-mbtoucr \
#  unistr/u8-uctomb \
#  uniwidth/width \
#  unlocked-io \
#  vasprintf \
#  xalloc \
#  xconcat-filename \
#  xerror \
#  xmalloca \
#  xstriconv \
#  xvasprintf

# Specification in the form of a few gnulib-tool.m4 macro invocations:
gl_LOCAL_DIR([../gnulib-local])
gl_MODULES([
  attribute
  basename-lgpl
  c-ctype
  c-strcase
  c-strstr
  close
  error
  error-progname
  fdopen
  filename
  fopen
  free-posix
  fstrcmp
  fwriteerror
  gcd
  getline
  gettext-h
  iconv
  libtextstyle-dummy
  libunistring-optional
  markup
  mem-hash-map
  minmax
  open
  realloc-posix
  relocatable-lib
  sigpipe
  stdbool
  stdio
  stdlib
  stpcpy
  stpncpy
  strchrnul
  strerror
  string-desc
  unictype/ctype-space
  unilbrk/ulc-width-linebreaks
  unistr/u16-mbtouc
  unistr/u8-mbtouc
  unistr/u8-mbtoucr
  unistr/u8-uctomb
  uniwidth/width
  unlocked-io
  vasprintf
  xalloc
  xconcat-filename
  xerror
  xmalloca
  xstriconv
  xvasprintf
])
gl_AVOID([ progname])
gl_SOURCE_BASE([libgettextpo])
gl_M4_BASE([libgettextpo/gnulib-m4])
gl_PO_BASE([])
gl_DOC_BASE([doc])
gl_TESTS_BASE([tests])
gl_LIB([libgnu])
gl_MAKEFILE_NAME([Makefile.gnulib])
gl_LIBTOOL
gl_MACRO_PREFIX([gtpo])
gl_PO_DOMAIN([])
gl_WITNESS_C_MACRO([])

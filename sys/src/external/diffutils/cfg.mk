# Customize maint.mk                           -*- makefile -*-
# Copyright (C) 2003-2013, 2015-2025 Free Software Foundation, Inc.

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Use the direct link.  This is guaranteed to work immediately, while
# it can take a while for the faster mirror links to become usable.
url_dir_list = https://ftp.gnu.org/gnu/$(PACKAGE)

# Used in maint.mk's web-manual rule
manual_title = Comparing and Merging Files

# Tests not to run as part of "make distcheck".
local-checks-to-skip =		\
  sc_error_message_period	\
  sc_error_message_uppercase	\
  sc_indent

# Tools used to bootstrap this package, used for "announcement".
bootstrap-tools = autoconf,automake,gnulib

# Override the default Cc: used in generating an announcement.
announcement_Cc_ = $(translation_project_), $(PACKAGE)-devel@gnu.org

# Now that we have better tests, make this the default.
export VERBOSE = yes

old_NEWS_hash = eefa9b0b34af4272f659040508d9acd0

# Tell maint.mk's syntax-check rules that diff gets config.h directly or
# via diff.h or system.h.
config_h_header = (<config\.h>|"(diff|system)\.h")

# Write base64-encoded (not hex) checksums into the announcement.
announce_gen_args = --cksum-checksums

# Add an exemption for sc_makefile_at_at_check.
_makefile_at_at_check_exceptions = ' && !/MAKEINFO/'

update-copyright-env = \
  UPDATE_COPYRIGHT_USE_INTERVALS=1 \
  UPDATE_COPYRIGHT_MAX_LINE_LENGTH=79

-include $(srcdir)/dist-check.mk

_cf_state_dir ?= .config-state
_date_time := $(shell date +%F.%T)
config-compare:
	diff -u					\
	  -I'define VERSION '			\
	  -I'define PACKAGE_VERSION '		\
	  -I'define PACKAGE_STRING '		\
	  $(_cf_state_dir)/latest lib/config.h
	diff -u					\
	  -I'$(PACKAGE_NAME)'			\
	  -I'[SD]\["VERSION"\]'			\
	  -I'[SD]\["PACKAGE_VERSION"\]'		\
	  -I'D\["PACKAGE_STRING"\]'		\
	  $(_cf_state_dir)/latest config.status

config-save:
	$(MAKE) --quiet config-compare > /dev/null 2>&1 \
	  && { echo no change; exit 1; } || :
	mkdir -p $(_cf_state_dir)/$(_date_time)
	ln -nsf $(_date_time) $(_cf_state_dir)/latest
	cp lib/config.h config.status $(_cf_state_dir)/latest

exclude_file_name_regexp--sc_GPL_version = ^gl/lib/
exclude_file_name_regexp--sc_bindtextdomain = ^gl/tests/
exclude_file_name_regexp--sc_doubled_words = ^gl/lib/mcel\.h$$
exclude_file_name_regexp--sc_prohibit_doubled_word = ^(gl/lib/mcel\.h|tests/y2038-vs-32bit)$$
exclude_file_name_regexp--sc_prohibit_strcmp = ^gl/lib/

# Tell gnulib's tight_scope rule that we mark extern inlines with
# DIFF_INLINE and SYSTEM_INLINE.
export _gl_TS_extern = extern|DIFF_INLINE|SYSTEM_INLINE

codespell_ignore_words_list = FO,ND,debbugs

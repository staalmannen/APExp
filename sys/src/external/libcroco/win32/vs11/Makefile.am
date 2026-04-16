# This file is part of The Croco Library
# This program is free software; you can redistribute it and/or
# modify it under the terms of version 2.1 of the GNU Lesser General Public
# License as published by the Free Software Foundation.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU Lesser General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
# USA

# Author: Fan, Chun-wei
# See COPYRIGHTS file for copyright information.

EXTRA_DIST = \
	libcroco.sln		\
	croco.vcxproj		\
	croco.vcxproj.filters		\
	csslint.vcxproj		\
	csslint.vcxproj.filters	\
	croco-install.vcxproj	\
	croco-install.vcxproj.filters	\
	croco-build-defines.props	\
	croco-gen-srcs.props	\
	croco-install.props	\
	croco-version-paths.props

DISTCLEANFILES = $(EXTRA_DIST)

MSVC_BASE_VER = 10
MSVC_BASE_VER_LONG = 2010
MSVC_VER = 11
MSVC_VER_LONG = 2012

include $(top_srcdir)/win32/Makefile-newvs.am

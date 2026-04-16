#This file is part of The Croco Library
#This program is free software; you can redistribute it and/or
#modify it under the terms of version 2.1 of the GNU Lesser General Public
#License as published by the Free Software Foundation.

#This program is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#GNU General Public License for more details.

#You should have received a copy of the GNU Lesser General Public License
#along with this program; if not, write to the Free Software
#Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
#USA

#Author: Fan, Chun-wei
#See COPYRIGHTS file for copyright information.

GENERATED_ITEMS =	\
	croco.vcproj		\
	croco-install.vsprops	\
	croco-version-paths.vsprops

EXTRA_DIST = \
	croco.vcprojin			\
	csslint.vcproj			\
	croco-install.vcproj	\
	libcroco.sln			\
	croco-build-defines.vsprops	\
	croco-gen-srcs.vsprops		\
	croco-install.vspropsin		\
	croco-version-paths.vsprops.in	\
	$(GENERATED_ITEMS)

croco-install.vsprops: $(top_srcdir)/win32/vs9/croco-install.vspropsin croco.headers
	$(CPP) -P - <$(top_srcdir)/win32/vs9/croco-install.vspropsin >$@
	rm croco.headers

DISTCLEANFILES = $(GENERATED_ITEMS)

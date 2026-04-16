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
	croco.vcxproj		\
	croco.vcxproj.filters	\
	croco-install.props	\
	croco-version-paths.props

EXTRA_DIST = \
	croco.vcxprojin			\
	croco.vcxproj.filtersin	\
	csslint.vcxproj			\
	csslint.vcxproj.filters	\
	croco-install.vcxproj	\
	croco-install.vcxproj.filters	\
	libcroco.sln			\
	croco-build-defines.props	\
	croco-gen-srcs.props	\
	croco-install.propsin	\
	croco-version-paths.props.in	\
	$(GENERATED_ITEMS)

croco-install.props: $(top_srcdir)/win32/vs10/croco-install.propsin croco.vs10.headers
	-$(RM) $(top_builddir)/win32/vs11/croco-install.props
	-$(RM) $(top_builddir)/win32/vs12/croco-install.props
	-$(RM) $(top_builddir)/win32/vs14/croco-install.props
	-$(RM) $(top_builddir)/win32/vs15/croco-install.props
	$(CPP) -P - <$(top_srcdir)/win32/vs10/croco-install.propsin > $@
	rm croco.vs10.headers

DISTCLEANFILES = $(GENERATED_ITEMS)


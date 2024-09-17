#
# doc/Makefile.am --- automake input file for gawk
#
# Copyright (C) 2000, 2001, 2002, 2004, 2005, 2007, 2010, 2011, 2016, 2017,
# 2021, 2022, 2023,
# the Free Software Foundation, Inc.
#
# This file is part of GAWK, the GNU implementation of the
# AWK Programming Language.
#
# GAWK is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# GAWK is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
#

## process this file with automake to produce Makefile.in

info_TEXINFOS = gawk.texi gawkinet.texi gawkworkflow.texi pm-gawk.texi

man_MANS = gawk.1 gawkbug.1 pm-gawk.1

png_images = gawk_api-figure1.png gawk_api-figure2.png gawk_api-figure3.png \
	gawk_array-elements.png gawk_general-program.png gawk_process-flow.png
html_images = $(png_images) gawk_statist.jpg

fig_images = $(png_images:%.png=%.fig)
txt_images = $(png_images:%.png=%.txt) gawk_statist.txt
eps_images = $(txt_images:%.txt=%.eps) gawk_statist.eps
pdf_images = $(txt_images:%.txt=%.pdf) gawk_statist.pdf

EXTRA_DIST = ChangeLog ChangeLog.0 ChangeLog.1 \
	README.card ad.block setter.outline \
	awkcard.in awkforai.txt texinfo.tex cardfonts \
	$(fig_images) $(txt_images) $(eps_images) $(pdf_images) \
	$(html_images) \
	it \
	macros colors no.colors $(man_MANS) \
	lflashlight-small.xpic lflashlight.eps lflashlight.pdf \
	rflashlight-small.xpic rflashlight.eps rflashlight.pdf \
	wordlist wordlist2 wordlist3 wordlist4 wordlist5 wordlist6 \
	bc_notes

# Get rid of generated files when cleaning
CLEANFILES = *.ps *.html *.dvi *~ awkcard.nc awkcard.tr gawk.pdf gawkinet.pdf gawkworkflow.pdf awkcard.pdf gawk.1.pdf gawkbug.1.pdf pm-gawk.1.pdf pm-gawk.pdf

MAKEINFO = @MAKEINFO@ -c CHECK_NORMAL_MENU_STRUCTURE=1 --no-split --force

TROFF = groff -t -Tps -U
SEDME = sed -e "s/^level0 restore/level0 restore flashme 100 72 moveto (Copyright `date '+%m-%d-%y %T'`, FSF, Inc. (all)) show/" \
		-e "s/^\/level0 save def/\/level0 save def 30 -48 translate/"
SEDME2 = sed '/%%Page: 10 10/,/0 Cg EP/d'

CARDSRC = $(srcdir)/macros $(srcdir)/cardfonts $(srcdir)/colors awkcard.tr
CARDSRC_N = $(srcdir)/macros $(srcdir)/cardfonts $(srcdir)/no.colors awkcard.tr
CARDFILES= $(CARDSRC) ad.block awkcard.in setter.outline
PAPEROPTS= -dpaper=letter -P-pletter

# Use this if your troff can correctly handle macros from 'colors' file
AWKCARD = awkcard.ps

# Uncomment the following definition of AWKCARD if your troff can produce
# Postscript but still has troubles with macros from 'colors'.  As this
# is not groff you will have to change TROFF macro as well.  Do not forget
# to ensure that awkcard.tr is processed by tbl.
#AWKCARD = awkcard.nc

postscript: gawk.ps gawkinet.ps gawkworkflow.ps pm-gawk.ps gawk.1.ps gawkbug.1.ps pm-gawk.1.ps $(AWKCARD)

pdf-local: postscript gawk.pdf gawkinet.pdf awkcard.pdf gawk.1.pdf gawkbug.1.pdf pm-gawk.1.pdf pm-gawk.pdf

gawk.ps: gawk.dvi
	TEXINPUTS=$(srcdir): dvips -o gawk.ps gawk.dvi

gawkinet.ps: gawkinet.dvi
	TEXINPUTS=$(srcdir): dvips -o gawkinet.ps gawkinet.dvi

gawkworkflow.ps: gawkworkflow.dvi
	TEXINPUTS=$(srcdir): dvips -o gawkworkflow.ps gawkworkflow.dvi

pm-gawk.ps: pm-gawk.dvi
	TEXINPUTS=$(srcdir): dvips -o pm-gawk.ps pm-gawk.dvi

gawk.1.ps: gawk.1
	-groff -man $(srcdir)/gawk.1 > gawk.1.ps

gawk.1.pdf: gawk.1.ps
	ps2pdf gawk.1.ps gawk.1.pdf

gawkbug.1.ps: gawkbug.1
	-groff -man $(srcdir)/gawkbug.1 > gawkbug.1.ps

gawkbug.1.pdf: gawkbug.1.ps
	ps2pdf gawkbug.1.ps gawkbug.1.pdf

pm-gawk.1.ps: pm-gawk.1
	-groff -man $(srcdir)/pm-gawk.1 > pm-gawk.1.ps

pm-gawk.1.pdf: pm-gawk.1.ps
	ps2pdf pm-gawk.1.ps pm-gawk.1.pdf

awkcard.tr: awkcard.in
	sed 's:SRCDIR:$(srcdir):' < $(srcdir)/awkcard.in > awkcard.tr

awkcard.ps: $(CARDFILES)
	$(TROFF) $(PAPEROPTS) $(CARDSRC) | $(SEDME) | cat $(srcdir)/setter.outline - | $(SEDME2) > awkcard.ps

awkcard.nc: $(CARDFILES)
	$(TROFF) $(PAPEROPTS) $(CARDSRC_N) | $(SEDME) | cat $(srcdir)/setter.outline - | $(SEDME2) > awkcard.ps && touch awkcard.nc

awkcard.pdf: awkcard.ps
	ps2pdf awkcard.ps awkcard.pdf

spell: spellmanual spellworkflow spellmanpage spellinet

spellmanual:
	@echo ==== gawk.texi ====;
	export LC_ALL=C ; spell "$(srcdir)"/gawk.texi | \
	sort -u | comm -23 - "$(srcdir)"/wordlist

spellworkflow:
	@echo ==== gawkworkflow.texi ====
	export LC_ALL=C ; spell "$(srcdir)"/gawkworkflow.texi | \
	sort -u | comm -23 - "$(srcdir)"/wordlist2

spellmanpage: spellgawkmanpage spellgawkbugmanpage spellpmgawkmanpage

spellgawkmanpage:
	@echo ==== gawk.1 ====
	export LC_ALL=C ; spell "$(srcdir)"/gawk.1 | \
	sort -u | comm -23 - "$(srcdir)"/wordlist3

spellgawkbugmanpage:
	@echo ==== gawkbug.1 ====
	export LC_ALL=C ; spell "$(srcdir)"/gawkbug.1 | \
	sort -u | comm -23 - "$(srcdir)"/wordlist5

spellpmgawkmanpage:
	@echo ==== pm-gawk.1 ====
	export LC_ALL=C ; spell "$(srcdir)"/pm-gawk.1 | \
	sort -u | comm -23 - "$(srcdir)"/wordlist6

spellinet:
	@echo ==== gawkinet.texi ====
	export LC_ALL=C ; spell "$(srcdir)"/gawkinet.texi | \
	sort -u | comm -23 - "$(srcdir)"/wordlist4

# Install/unistall graphic image files in the info/ dir

imagedir = $(infodir)
image_DATA = $(html_images)

# Install/unistall graphic image files in the html doc dir

install-html-local:
	@$(NORMAL_INSTALL)
	@list='$(html_images)'; test -n "$(htmldir)" || list=; \
	if test -n "$$list"; then \
	  echo " $(MKDIR_P) '$(DESTDIR)$(htmldir)'"; \
	  $(MKDIR_P) "$(DESTDIR)$(htmldir)" || exit 1; \
	fi; \
	for p in $$list; do \
		$(INSTALL_DATA) $$p "$(DESTDIR)$(htmldir)" || exit $$?; \
	done;

uninstall-local:
	@$(NORMAL_UNINSTALL)
	@list='$(html_images)'; test -n "$(htmldir)" || list=; \
	for p in $$list; do \
	  echo " rm -rf '$(DESTDIR)$(htmldir)/$$p'"; \
	  rm -rf "$(DESTDIR)$(htmldir)/$$p"; \
	done


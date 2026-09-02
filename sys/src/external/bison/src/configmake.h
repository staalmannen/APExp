/*
 * APExp: hand-written, where a normal build has configure generate it.
 * Only bison/src reads this file; the gnulib tree has its own
 * configmake.h with no PKGDATADIR at all, which is why the include
 * order in sys/src/ape/cmd/bison/mkfile puts -I$BISONSRC/src ahead of
 * -I$GNUSRC.
 *
 * PKGDATADIR is where bison looks for the files it cannot run without:
 * output.c:885 wants pkgdatadir()/skeletons -- yacc.c and the twenty
 * m4 files beside it -- and output.c:725 wants pkgdatadir()/m4sugar.
 * Without them bison reads its grammar and then dies with no message
 * at all:
 *
 *	bison -y -d yacc.ym
 *	mk: ... : exit status=rc 23058: bison 23059: abort
 *
 * It was "/sys/lib/ape", which would have scattered skeletons/,
 * m4sugar/ and xslt/ directly into the directory that also holds awk,
 * locale, m4 and termcap. Upstream installs to $(datadir)/bison, so
 * this does too; sys/src/ape/cmd/bison/mkfile's install populates it.
 */
#define PKGDATADIR "/sys/lib/ape/bison"

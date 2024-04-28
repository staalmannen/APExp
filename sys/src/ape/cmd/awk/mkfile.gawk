</$objtype/mkfile
TARG=awk
BIN=/$objtype/bin/ape

OFILES=	array.$O\
		builtin.$O\
		dfa.$O\
		eval.$O\
		ext.$O\
		field.$O\
		floatcomp.$O\
		gawkmisc.$O\
		getopt.$O\
		getopt1.$O\
		io.$O\
		msg.$O\
		node.$O\
		profile.$O\
		re.$O\
		regex.$O\
		replace.$O\
		version.$O\
		awkgram.$O\
		main.$O\
		random.$O

</sys/src/cmd/mkone

GAWKSRC=../../../external/gawk

CC=pcc
LD=pcc
CFLAGS=-c -I. -I$GAWKSRC -I$GAWKSRC/missing_d -DPLAN9 -DGAWK \
	-D_POSIX_SOURCE -D_SUSV2_SOURCE -D_C99_SNPRINTF_EXTENSION -D_BSD_EXTENSION \
	-D_REENTRANT_SOURCE -D_EXPERIMENTAL_SOURCE -DHAVE_SOCK_OPTS -DHAVE_CONFIG_H \
	-DGETGROUPS_NOT_STANDARD -DHAVE_STDINT_H -DHAVE_MKTIME -DHAVE_WCHAR_H -DHAVE_WCTYPE_H \
	-DHAVE_STDBOOL_H 

%.$O: $GAWKSRC/%.c
	$CC $CFLAGS $GAWKSRC/$stem.c




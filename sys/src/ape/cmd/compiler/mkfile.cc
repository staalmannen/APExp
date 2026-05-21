</$objtype/mkfile

APEXPROOT=../../../../..
CCSRC=$APEXPROOT/sys/src/cmd/cc

LIB=cc.a$O
OFILES=\
	y.tab.$O\
	lex.$O\
	mac.$O\
	dcl.$O\
	acid.$O\
	pickle.$O\
	bits.$O\
	com.$O\
	cmplx.$O\
	scon.$O\
	funct.$O\
	sub.$O\
	com64.$O\
	compat.$O\
	dpchk.$O\
	omachcap.$O\
	vla.$O\

CFLAGS=-FTVw -c -I$CCSRC

$LIB: $OFILES
	ar vu $LIB $OFILES

y.tab.$O: $CCSRC/y.tab.c

mac.$O: $CCSRC/macbody

compat.$O: $CCSRC/compat

%.$O: $CCSRC/%.c
	$CC $CFLAGS $prereq





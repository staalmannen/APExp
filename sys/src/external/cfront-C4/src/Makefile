#CC  ?=  gcc
CC  =  gcc
#CC  =  gcc -fsanitize=address
#CC  =  clang-11-env clang
#CCFLAGS	= -fpermissive -D__HAVE_SIZE_T -g
#CCFLAGS	= -Wall -D__HAVE_SIZE_T -g
CCFLAGS	= -D__HAVE_SIZE_T -g $(MSIZE)

CCOMP = gcc

#MPMACRO = PATCH
MPMACRO = MUNCH

OFILES	=	Bits.o alloc.o block.o dcl.o dcl2.o dcl3.o dcl4.o \
		del.o discrim.o error.o expand.o expr.o expr2.o \
		expr3.o find.o hash.o lalex.o lex.o main.o norm.o \
		norm2.o print.o print2.o repr.o simpl.o simpl2.o \
		size.o table.o template.o tree_copy.o tree_walk.o \
		typ.o typ2.o y.tab.o cfront_stubs.o _stdio.o


COMDEP0	= 	Makefile \
		Bits.h Block.h cfront.h hash.h node_classes.h overload.h \
		sdelicense.h sdetoolnum.h size.h template.h token.h \
		tqueue.h tree_copy.h tree_walk.h typedef.h cfront_translated.h

COMDEP	=	$(COMDEP0) yystype.h

cfront$(EXEEXT):	$(OFILES)
	$(CCOMP) $(MSIZE)	-o cfront$(EXEEXT) $(OFILES)
	cp cfront$(EXEEXT) ..

szal.result: ../tools/szal/szal.c
	$(CCOMP) $(MSIZE) -o ../tools/szal/szal$(EXEEXT) ../tools/szal/szal.c
	$(EXEWRAPPER) ../tools/szal/szal$(EXEEXT) > szal.result

# Parser: use pre-generated C translation (pregen-y.tab.c)
# gram.y / byacc are only needed to regenerate pregen-y.tab.c
y.tab.o: pregen-y.tab.c $(COMDEP)
	$(CCOMP) $(MSIZE) $(CCFLAGS) -c -o y.tab.o pregen-y.tab.c

alloc.o: alloc.c $(COMDEP)
	$(CC) $(CCFLAGS) -c alloc.c

Bits.o:	Bits.c $(COMDEP)
	$(CC) $(CCFLAGS) -c Bits.c

block.o: block.c $(COMDEP)
	$(CC) $(CCFLAGS) -c block.c

dcl.o:	dcl.c $(COMDEP)
	$(CC) $(CCFLAGS) -c dcl.c

dcl2.o:	dcl2.c $(COMDEP)
	$(CC) $(CCFLAGS) -c dcl2.c

dcl3.o:	dcl3.c $(COMDEP)
	$(CC) $(CCFLAGS) -c dcl3.c

dcl4.o:	dcl4.c $(COMDEP)
	$(CC) $(CCFLAGS) -c dcl4.c

del.o:	del.c $(COMDEP)
	$(CC) $(CCFLAGS) -c del.c

discrim.o: discrim.c $(COMDEP)
	$(CC) $(CCFLAGS) -c discrim.c

error.o: error.c $(COMDEP)
	$(CC) $(CCFLAGS) -c error.c

expand.o: expand.c $(COMDEP)
	$(CC) $(CCFLAGS) -c expand.c

expr.o:	expr.c $(COMDEP)
	$(CC) $(CCFLAGS) -c expr.c

expr2.o: expr2.c $(COMDEP)
	$(CC) $(CCFLAGS) -c expr2.c

expr3.o: expr3.c $(COMDEP)
	$(CC) $(CCFLAGS) -c expr3.c

find.o:	find.c $(COMDEP)
	$(CC) $(CCFLAGS) -c find.c

hash.o: hash.c $(COMDEP)
	$(CC) $(CCFLAGS) -c hash.c

lalex.o:lalex.c $(COMDEP)
	$(CC) $(CCFLAGS) -c lalex.c

lex.o:	lex.c $(COMDEP)
	$(CC) $(CCFLAGS) -c lex.c

main.o:	main.c $(COMDEP)
	$(CC) -D$(MPMACRO) $(DENSE) $(CCFLAGS) -c main.c

norm.o:	norm.c $(COMDEP)
	$(CC) $(CCFLAGS) -c norm.c

norm2.o: norm2.c $(COMDEP)
	$(CC) $(CCFLAGS) -c norm2.c

print.o: print.c $(COMDEP)
	$(CC) $(CCFLAGS) -c print.c

print2.o: print2.c $(COMDEP)
	$(CC) $(DENSE) $(CCFLAGS) -c print2.c

repr.o:	repr.c $(COMDEP)
	$(CC) $(CCFLAGS) -c repr.c

simpl.o: simpl.c $(COMDEP)
	$(CC) $(CCFLAGS) -c simpl.c

simpl2.o: simpl2.c $(COMDEP)
	$(CC) $(CCFLAGS) -c simpl2.c

size.o:	size.c $(COMDEP)
	$(CC) $(CCFLAGS) -c size.c

table.o: table.c $(COMDEP)
	$(CC) $(CCFLAGS) -c table.c

template.o: template.c $(COMDEP)
	$(CC) $(CCFLAGS) -c template.c

tree_copy.o: tree_copy.c $(COMDEP)
	$(CC) $(CCFLAGS) -c tree_copy.c

tree_walk.o: tree_walk.c $(COMDEP)
	$(CC) $(CCFLAGS) -c tree_walk.c

typ.o: typ.c $(COMDEP)
	$(CC) $(CCFLAGS) -c typ.c

typ2.o:	typ2.c $(COMDEP)
	$(CC) $(CCFLAGS) -c typ2.c

cfront_stubs.o: cfront_stubs.c
	$(CCOMP) $(MSIZE) -c cfront_stubs.c

_stdio.o: _stdio.c
	$(CCOMP)  $(MSIZE) -c _stdio.c

ns_strip: ns_strip.c
	$(CCOMP) $(MSIZE) -o ns_strip ns_strip.c
	cp ns_strip ..

clean:
	-rm -f szal.result ../tools/szal/szal$(EXEEXT)
	-rm -f *.o *..c cfront$(EXEEXT) ns_strip #../cfront

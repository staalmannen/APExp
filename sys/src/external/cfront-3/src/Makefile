#CC  ?=  gcc
CC  =  gcc
#CC  =  gcc -fsanitize=address
#CC  =  clang-11-env clang
#CXX	?=	g++ -fno-rtti -fno-exceptions
CXX	=	g++ -fno-rtti -fno-exceptions
#CXX	=	g++ -fno-rtti -fno-exceptions -fsanitize=address
#CXX	=	clang-11-env clang++ -fno-rtti -fno-exceptions
#CCFLAGS	= -fpermissive -I../incl -D__HAVE_SIZE_T -g
#CCFLAGS	= -Wall -I../incl -D__HAVE_SIZE_T -g
CCFLAGS	= -I../incl -D__HAVE_SIZE_T -g $(MSIZE)

CCOMP = gcc

#MPMACRO = PATCH
MPMACRO = MUNCH

OFILES	=	Bits.o alloc.o block.o dcl.o dcl2.o dcl3.o dcl4.o \
		del.o discrim.o error.o expand.o expr.o expr2.o \
		expr3.o find.o hash.o lalex.o lex.o main.o norm.o \
		norm2.o print.o print2.o repr.o simpl.o simpl2.o \
		size.o table.o template.o tree_copy.o tree_walk.o \
		typ.o typ2.o y.tab.o _stdio.o


COMDEP0	= 	szal.result Makefile \
		Bits.h Block.h cfront.h hash.h node_classes.h overload.h \
		sdelicense.h sdetoolnum.h size.h template.h token.h \
		tqueue.h tree_copy.h tree_walk.h typedef.h

COMDEP	=	$(COMDEP0) yystype.h

cfront$(EXEEXT):	$(OFILES)
	#$(CXX)	-o cfront$(EXEEXT) $(OFILES)
	$(CCOMP) $(MSIZE)	-o cfront$(EXEEXT) $(OFILES)
	cp cfront$(EXEEXT) ..

cfront_c$(EXEEXT): $(OFILES)
	$(CCOMP) $(MSIZE) -g -o cfront_c$(EXEEXT) $(OFILES) ../libC.a
	nm cfront_c$(EXEEXT) | $(EXEWRAPPER) ../munch$(EXEEXT) > cfront_c.cdts..c
	$(CCOMP) $(MSIZE) -g -o cfront_c$(EXEEXT) $(OFILES) cfront_c.cdts..c ../libC.a

cfront_cc$(EXEEXT): $(OFILES)
	$(CCOMP) $(MSIZE) -g -o cfront_cc$(EXEEXT) $(OFILES) ../libC.a
	nm cfront_cc$(EXEEXT) | $(EXEWRAPPER) ../munch$(EXEEXT) > cfront_cc.cdts..c
	$(CCOMP) $(MSIZE) -g -o cfront_cc$(EXEEXT) $(OFILES) cfront_cc.cdts..c ../libC.a

cfront_ccc$(EXEEXT): $(OFILES)
	$(CCOMP) $(MSIZE) -g -o cfront_ccc$(EXEEXT) $(OFILES) ../libC.a
	nm cfront_ccc$(EXEEXT) | $(EXEWRAPPER) ../munch$(EXEEXT) > cfront_ccc.cdts..c
	$(CCOMP) $(MSIZE) -g -o cfront_ccc$(EXEEXT) $(OFILES) cfront_ccc.cdts..c ../libC.a

szal.result: szal/szal.c
	$(CCOMP) $(MSIZE) -o szal/szal$(EXEEXT) szal/szal.c
	$(EXEWRAPPER) ./szal/szal$(EXEEXT) > szal.result

y.tab.cpp yystype.h: gram.y $(COMDEP0)
	#byacc -d gram.y
	#mv y.tab.c y.tab.cpp
	#mv y.tab.h yystype.h
	#mybison -y --defines=yystype.h -o y.tab.cpp gram.y
	#mv gram.tab.c y.tab.cpp
	#mv gram.tab.h yystype.h
	#sed -i -e 's/^#ifdef __cplusplus/#if 0/' y.tab.cpp
	#sed -i -e 's/^#ifndef YYTOKENTYPE/#if 0/' yystype.h

alloc.o: alloc.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c alloc.cpp

Bits.o:	Bits.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c Bits.cpp

block.o: block.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c block.cpp

dcl.o:	dcl.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c dcl.cpp

dcl2.o:	dcl2.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c dcl2.cpp

dcl3.o:	dcl3.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c dcl3.cpp

dcl4.o:	dcl4.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c dcl4.cpp

del.o:	del.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c del.cpp

discrim.o: discrim.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c discrim.cpp

error.o: error.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c error.cpp

expand.o: expand.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c expand.cpp

expr.o:	expr.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c expr.cpp

expr2.o: expr2.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c expr2.cpp

expr3.o: expr3.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c expr3.cpp

find.o:	find.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c find.cpp

hash.o: hash.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c hash.cpp

lalex.o:lalex.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c lalex.cpp

lex.o:	lex.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c lex.cpp

main.o:	main.cpp $(COMDEP)
	$(CXX) -D$(MPMACRO) $(DENSE) $(CCFLAGS) -c main.cpp

norm.o:	norm.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c norm.cpp

norm2.o: norm2.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c norm2.cpp

print.o: print.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c print.cpp

print2.o: print2.cpp $(COMDEP)
	$(CXX) $(DENSE) $(CCFLAGS) -c print2.cpp

repr.o:	repr.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c repr.cpp

simpl.o: simpl.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c simpl.cpp

simpl2.o: simpl2.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c simpl2.cpp

size.o:	size.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c size.cpp

table.o: table.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c table.cpp

template.o: template.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c template.cpp

tree_copy.o: tree_copy.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c tree_copy.cpp

tree_walk.o: tree_walk.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c tree_walk.cpp

typ.o: typ.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c typ.cpp

typ2.o:	typ2.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c typ2.cpp

y.tab.o: y.tab.cpp $(COMDEP)
	$(CXX) $(CCFLAGS) -c y.tab.cpp

_stdio.o: _stdio.c
	$(CCOMP)  $(MSIZE) -c _stdio.c

clean:
	-rm -f szal.result szal/szal$(EXEEXT)
	#-rm -f y.tab.cpp yystype.h
	-rm -f *.o *..c cfront$(EXEEXT) #../cfront

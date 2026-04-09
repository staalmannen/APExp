
#
# Portable Object Compiler
#

RM=rm -f

esql.o : esql.em
	objc -c esql.em

esql : esql.o
	objc -o esql esql.o

poseAs.o : poseAs.m
	objc -c poseAs.m

Foo.o : Foo.m
	objc -c Foo.m

Bar.o : Bar.m
	objc -c Bar.m

Zot.o : Zot.m
	objc -c Zot.m

perfect.o : perfect.m
	objc -c perfect.m

perfect : perfect.o
	objc -o perfect perfect.o

poseAs : poseAs.o Zot.o Foo.o Bar.o
	objc -o poseAs poseAs.o Zot.o Foo.o Bar.o

dynclass.o : dynclass.m
	objc -c -fpic dynclass.m

dynclass.so : dynclass.o
	objc -dl dynclass.o -o dynclass.so

dlopen : dynclass.so
	objc -dynamic dlopen.m -o dlopen

cleantmp :
	-$(RM) *.P
	-$(RM) *.c
	-$(RM) *.i

clean : cleantmp
	-$(RM) *.o
	-$(RM) $(PROGRAM) a.out
	-$(RM) perfect dlopen dynclass.so

distclean : clean
	-$(RM) Makefile 


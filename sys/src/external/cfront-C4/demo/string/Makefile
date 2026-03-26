CC=../../CC
LIBS=
CCFLAGS=-Wall -g -DNO_EXCEPTION -I../../incl  $(MSIZE)
CCOMP = gcc
#ISTL=--stl -I../../stl
G=
LDFLAGS=$(G)
SHELL=sh

.SUFFIXES: .E
 
.cpp.E:
	$(CC) $(CCFLAGS) $(ISTL) $(LDFLAGS) -o $*.E $< $(LIBS)

.cpp.o:
	$(CC) $(CCFLAGS) $(ISTL) -c $<

all:
	$(SHELL) ./regress

clean:
	-@rm -f *.o *.E *.r *.ii core *.c
	-@rm -rf ptrepository

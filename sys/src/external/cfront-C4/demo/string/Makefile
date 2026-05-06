# CC: C++ compiler. Default: g++ for Linux/macOS.
# For cfront testing: make CC="path/to/cfront-wrapper"
CC=g++
LIBS=
CCFLAGS=-Wall -g -DNO_EXCEPTION $(MSIZE)
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

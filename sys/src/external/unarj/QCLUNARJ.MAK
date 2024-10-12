# Makefile for unarj.exe for QuickC QCL

CC=qcl -AS -W4

all:	      unarj.exe

unarj.obj:    unarj.c	unarj.h

environ.obj:  environ.c unarj.h

decode.obj:   decode.c	unarj.h

unarj.exe:    unarj.obj decode.obj environ.obj
       qcl    unarj.obj decode.obj environ.obj

# end of makefile

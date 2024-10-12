# Makefile for unarj.exe for Borland C++

unarj.exe:    unarj.obj decode.obj environ.obj

       bcc -M unarj.obj decode.obj environ.obj

unarj.obj:    unarj.c	unarj.h

environ.obj:  environ.c unarj.h

decode.obj:   decode.c	unarj.h

.c.obj:
    bcc -c -N -k -w -ms $<

# end of makefile

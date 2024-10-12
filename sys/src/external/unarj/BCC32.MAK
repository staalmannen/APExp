# Makefile for unarj.exe for Borland C++ 5.0

unarj32.exe:    unarj.obj decode.obj environ.obj

       bcc32 -M -eunarj32 unarj.obj decode.obj environ.obj

unarj.obj:    unarj.c	unarj.h

environ.obj:  environ.c unarj.h

decode.obj:   decode.c	unarj.h

.c.obj:
       bcc32 -c -N -k -w $<

# end of makefile

#
# unRAR Makefile for Plan9/APE and GNU make
#


BINDIR = /$(objtype)/bin
CC = cc
CFLAGS = -D_UNIX -D_POSIX_SOURCE -D_SUSV2_SOURCE -D_BSD_EXTENSION

unrar:
	$(CC) -s $(CFLAGS) -o $@ unrar.c


install: unrar
	install -m 755 -o root -g root $^ $(BINDIR)/

clean:
	-rm -f *.o unrar

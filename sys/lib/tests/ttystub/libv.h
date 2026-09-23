/*
 * Stub for tty-xcheck.c on the BUILD HOST only.
 *
 * ap/plan9/tty.c includes <libv.h>. The real one is
 * sys/include/ape/libv.h, which carries `#pragma lib' and pulls APE
 * headers that do not exist on a unix; this gives the two
 * declarations tty.c actually needs and nothing else.
 */
#ifndef __LIBV_H
#define __LIBV_H
extern int tty_echoon(int);
extern int tty_echooff(int);
#endif

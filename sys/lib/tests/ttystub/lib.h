/*
 * Stub for tty-xcheck.c on the BUILD HOST only.
 *
 * ap/plan9/tty.c includes "lib.h". The real one is
 * sys/src/ape/lib/ap/include/lib.h, which has no include guard and
 * pulls <ureg.h> and <sys/limits.h> -- neither of which exists on a
 * unix. These are the three declarations tty.c defines, copied from
 * the real header; if they drift apart the harness stops compiling,
 * which is the point of having them here rather than inside the .c.
 */
extern int _tty_raw(int);
extern int _tty_israw(void);
extern int _ttymark(void);

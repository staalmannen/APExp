#ifndef __ERROR_H
#define __ERROR_H

#pragma lib "/$M/lib/ape/libap.a"

#ifdef __cplusplus
extern "C" {
#endif

extern char *_progname;		/* program name */
extern void _perror(char *);	/* perror but with _progname */

/* GNU error reporting (from glibc / gnulib) */
extern const char *program_invocation_name;
extern const char *program_invocation_short_name;
extern unsigned int error_message_count;
extern int error_one_per_line;
extern void (*error_print_progname)(void);

extern void error(int, int, const char *, ...);
extern void error_at_line(int, int, const char *, unsigned int, const char *, ...);

#ifdef __cplusplus
}
#endif

#endif /* _ERROR_H */

#ifndef __SYSLOG_H
#define __SYSLOG_H
#pragma lib "/$M/lib/ape/libap.a"

/*
 * ***THE FACILITIES THAT WERE MISSING WERE EXACTLY THE ONES WITH NO
 * MODERN USE, AND FOUR OF THEM ARE POSIX.***  2, 6, 7, 8 and 11 were
 * absent -- LOG_MAIL, LOG_LPR, LOG_NEWS, LOG_UUCP and LOG_FTP -- and
 * POSIX requires the first four by name.  php's
 * `basic_functions_arginfo.h:3677' registers the whole set as PHP
 * constants and answered
 *
 *	name not declared: LOG_MAIL
 *	name not declared: LOG_LPR
 *
 * The numbering is universal (it is the wire protocol's, RFC 5424
 * Table 1), so these are not a choice; the one external definition in
 * the tree, `perl/os2/os2ish.h', agrees to the digit.
 *
 * *They are enum constants here and not `#define's*, as the rest of
 * this header is, which means a package that `#define's its own would
 * not merely redefine it but break -- the same exposure the list
 * already had for LOG_KERN, and the reason the grep before adding a
 * name is for the BARE WORD.
 */
enum {
	/* facility */
	LOG_KERN	= 0<<3,
	LOG_USER	= 1<<3,
	LOG_MAIL	= 2<<3,
	LOG_DAEMON	= 3<<3,
	LOG_AUTH	= 4<<3,
	LOG_SYSLOG	= 5<<3,
	LOG_LPR		= 6<<3,
	LOG_NEWS	= 7<<3,
	LOG_UUCP	= 8<<3,
	LOG_CRON	= 9<<3,
	LOG_FTP		= 11<<3,
	LOG_AUTHPRIV= 10<<3,
	LOG_LOCAL0	= 16<<3,
	LOG_LOCAL1	= 17<<3,
	LOG_LOCAL2	= 18<<3,
	LOG_LOCAL3	= 19<<3,
	LOG_LOCAL4	= 20<<3,
	LOG_LOCAL5	= 21<<3,
	LOG_LOCAL6	= 22<<3,
	LOG_LOCAL7	= 23<<3,
};

enum {
	/* priority */
	LOG_EMERG,
	LOG_ALERT,
	LOG_CRIT,
	LOG_ERR,
	LOG_WARNING,
	LOG_NOTICE,
	LOG_INFO,
	LOG_DEBUG,
};

enum {
	/* option */
	LOG_PID		= 0x01,
	LOG_CONS	= 0x02,
	LOG_ODELAY	= 0x04,
	LOG_NDELAY	= 0x08,
	LOG_NOWAIT	= 0x10,
};

#ifdef __cplusplus
extern "C" {
#endif

extern void openlog(const char *, int, int);
extern void syslog(int, const char *, ...);
extern void closelog(void);

#ifdef __cplusplus
}
#endif

#endif

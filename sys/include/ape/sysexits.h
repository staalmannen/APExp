/*
 * sysexits.h -- preferable exit codes for programs, from 4.3BSD.
 *
 *   tar.c:48 Could not find include file <sysexits.h>
 *
 * GNU tar includes it unguarded and uses EX_USAGE; chicken's runtime
 * refers to it too. The values are the historical BSD ones and are
 * fixed by convention -- sendmail and everything after it rely on the
 * exact numbers -- so they are reproduced rather than invented.
 *
 * Codes below EX__BASE (64) are left to the program: 0 for success and
 * 1 for the usual sort of failure. The range 64..78 is what this header
 * is for, and EX__BASE/EX__MAX let a caller test whether a wait status
 * carries one of them.
 */

#ifndef __SYSEXITS_H
#define __SYSEXITS_H

#define EX_OK		0	/* successful termination */

#define EX__BASE	64	/* base value for error messages */

#define EX_USAGE	64	/* command line usage error */
#define EX_DATAERR	65	/* data format error */
#define EX_NOINPUT	66	/* cannot open input */
#define EX_NOUSER	67	/* addressee unknown */
#define EX_NOHOST	68	/* host name unknown */
#define EX_UNAVAILABLE	69	/* service unavailable */
#define EX_SOFTWARE	70	/* internal software error */
#define EX_OSERR	71	/* system error, e.g. cannot fork */
#define EX_OSFILE	72	/* critical OS file missing */
#define EX_CANTCREAT	73	/* cannot create (user) output file */
#define EX_IOERR	74	/* input/output error */
#define EX_TEMPFAIL	75	/* temporary failure; the user is invited
				   to retry */
#define EX_PROTOCOL	76	/* remote error in protocol */
#define EX_NOPERM	77	/* permission denied */
#define EX_CONFIG	78	/* configuration error */

#define EX__MAX		78	/* maximum listed value */

#endif /* __SYSEXITS_H */

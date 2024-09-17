/*
 * redirect.h --- definitions for functions that are OS specific.
 */

/*
 * Copyright (C) 1986, 1988, 1989, 1991-1993, 1996, 1997, 2007, 2010, 2011,
 * 2023 the Free Software Foundation, Inc.
 *
 * This file is part of GAWK, the GNU implementation of the
 * AWK Programming Language.
 *
 * GAWK is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * GAWK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

/* This file is included by custom.h for VMS-POSIX, or first
   by config.h (vms-conf.h) then again by awk.h for normal VMS.  */

#if defined(VMS_POSIX) || defined(IN_CONFIG_H)

#define DEFAULT_FILETYPE ".awk"

/* some macros to redirect some non-VMS-specific code */
#define getopt		gnu_getopt
#define opterr		gnu_opterr
#define optarg		gnu_optarg
#define optind		gnu_optind
#define optopt		gnu_optopt
#define regcomp		gnu_regcomp
#define regexec		gnu_regexec
#define regfree		gnu_regfree
#define regerror	gnu_regerror
#define setenv		gawk_setenv
#define unsetenv	gawk_unsetenv
#ifndef VMS_POSIX
#define strftime	gnu_strftime	/* always use missing/strftime.c */
#define strcasecmp	gnu_strcasecmp
#define strncasecmp	gnu_strncasecmp
#ifndef VMS_V7
#define tzset		fake_tzset
#define tzname		fake_tzname
#define daylight	fake_daylight
#define timezone	fake_timezone
#define altzone		fake_altzone
#endif
#if !defined(__DECC) && !defined(VAXC2DECC) && !defined(__alpha)
#define strcoll(s,t) strcmp((s),(t))	/* VAXCRTL lacks locale support */
#endif
#endif

#ifdef STDC_HEADERS
/* This is for getopt.c and alloca.c (compiled with HAVE_CONFIG_H defined),
   to prevent diagnostics about various implicitly declared functions.  */
#include <stdlib.h>
#include <string.h>
#endif
#ifndef VMS_POSIX
/* This if for random.c. */
#define gettimeofday	vms_gettimeofday
#ifndef __TIMEVAL
#define __TIMEVAL 1
struct timeval	{ long tv_sec, tv_usec; };
#endif
extern int   gettimeofday(struct timeval *,void *);
#endif

#else	/* awk.h, not POSIX */

/* some macros to redirect to code in vms/vms_misc.c */
#ifndef bcopy
#define bcopy		vms_bcopy
#endif
#define open		vms_open
#define popen		vms_popen
#define pclose		vms_pclose
#ifndef HAVE_SNPRINTF
#define snprintf gawk_snprintf	/* avoid %CC-I-INTRINSICDECL diagnostic */
#define vsnprintf gawk_vsnprintf
#endif
/* supply missing or suppressed (due to defines in config.h) declarations */
extern int snprintf(char *,size_t,const char *,...);
extern int vsnprintf(char *restrict,size_t,const char *,va_list);
extern int setenv(const char *,const char *,int);
extern int unsetenv(const char *);
#define strerror	vms_strerror
#define strdup		vms_strdup
#define unlink		vms_unlink
#if defined(VAXC) || (defined(__GNUC__) && !defined(__alpha))
#define fstat(fd,sb)	VMS_fstat(fd,sb)
#endif
extern void  exit(int);
extern int   open(const char *,int,...);
extern char *strerror(int);
extern char *strdup(const char *str);
extern int   vms_devopen(const char *,int);
# ifndef NO_TTY_FWRITE
#define fwrite		tty_fwrite
#define fclose		tty_fclose
extern size_t fwrite(const void *,size_t,size_t,FILE *);
extern int    fclose(FILE *);
# endif
extern FILE *popen(const char *,const char *);
extern int   pclose(FILE *);
extern void vms_arg_fixup(int *,char ***);
/* some things not in STDC_HEADERS */
extern size_t gnu_strftime(char *,size_t,const char *,const struct tm *);
extern int unlink(const char *);
extern int getopt(int,char **,char *);
extern int isatty(int);
#ifndef fileno
extern int fileno(FILE *);
#endif
extern int close(int);
extern int dup(int);
extern int dup2(int, int);
extern ssize_t read(int, void *, size_t);
extern int getpgrp(void);
extern void tzset(void);

#endif	/* not VMS_POSIX and not IN_CONFIG_H */

/*vms/redirect.h*/

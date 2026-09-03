#ifndef __STRING_H_
#define __STRING_H_
#pragma lib "/$M/lib/ape/libap.a"

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void *memcpy(void *, const void *, size_t);
extern void *memccpy(void*, void*, int, size_t);
extern void *memmove(void *, const void *, size_t);
extern char *strcpy(char *, const char *);
extern char *strncpy(char *, const char *, size_t);
extern char *strcat(char *, const char *);
extern char *strncat(char *, const char *, size_t);
extern int memcmp(const void *, const void *, size_t);
extern int strcmp(const char *, const char *);
extern int strcoll(const char *, const char *);
extern int strverscmp(const char *, const char *);
extern char *strdup(const char*);
extern char *strndup(const char*, size_t);
extern int strncmp(const char *, const char *, size_t);
extern size_t strxfrm(char *, const char *, size_t);
extern void *memchr(const void *, int, size_t);
extern char *strchr(const char *, int);
extern size_t strcspn(const char *, const char *);
extern char *strpbrk(const char *, const char *);
extern char *strrchr(const char *, int);
extern size_t strspn(const char *, const char *);
extern char *strstr(const char *, const char *);
extern char *strtok(char *, const char *);
extern void *memset(void *, int, size_t);
extern char *strerror(int);
extern size_t strlen(const char *);
extern size_t strnlen(const char *, size_t);

extern char *strtok_r(char *, const char *, char **);

#include <bsd.h>

/* from musl */
extern char *strchrnul(const char*, int);
extern int strerror_r(int, char *, size_t);

/* GNU extensions */
extern int ffsl(long);
extern int ffsll(long long);
extern void *rawmemchr(const void *, int);


void *memmem(const void *, size_t, const void *, size_t);
void *memrchr(const void *, int, size_t);
char *stpcpy(char *, const char *);
char *stpncpy(char *, const char *, size_t);
size_t strlcpy(char *dst, const char *src, size_t n);
char *strsignal(int);
char *strsep(char **, const char *);
char *strcasestr(const char *, const char *);
char *strfry(char *);
void *mempcpy(void *, const void *, size_t);
size_t strlcat(char *, const char *, size_t);
#define estrlcat strlcat
#define xstrlcat strlcat

char *index(const char *s, int c);
void swab(const void *src, void *dst, ssize_t n);

/*
 * These three are APExp additions, and they need wchar_t and nothing
 * else -- which <stddef.h>, included at the top, already provides.
 *
 * This used to say "#include <wchar.h>", which made <string.h> the head
 * of a chain reaching all the way into Plan 9's own headers:
 *
 *	string.h -> wchar.h -> time.h -> signal.h -> pthread.h
 *	  -> lock.h -> u.h
 *
 * and u.h defines nil, uchar, ushort, ulong and uint. So every
 * translation unit that asked for strlen got those too. The Portable
 * Object Compiler is where it surfaced -- Object.h defines nil as
 * ((id)0), as any Objective-C runtime does, and u.h then redefined it:
 *
 *	Object.m:28 ... Object.h:32 ... string.h:70 ... u.h:4
 *	  Macro redefinition of nil
 *
 * It was also circular: <wchar.h> includes <string.h> back. Each of the
 * four links has been cut where it was needed only for a pointer
 * parameter; see the forward declarations in wchar.h, time.h and
 * signal.h.
 */
extern size_t wcsnlen(const wchar_t *, size_t);
extern int wcscasecmp(const wchar_t *, const wchar_t *);
extern int wcsncasecmp(const wchar_t *, const wchar_t *, size_t);


#ifdef __cplusplus
}
#endif

#endif

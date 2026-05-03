/* info about wchar.h:
 * https://pubs.opengroup.org/onlinepubs/009695399/basedefs/wchar.h.html
 * wide UTF --> WTF */

#ifndef _WCHAR_H
#define _WCHAR_H 1

#pragma lib "/$M/lib/ape/libap.a"

#define _REENTRANT_SOURCE 1

/* we want to map wchars to Runes and rune functions if possible */
#include <utf.h>

/* Headers that need to be included according to the definition */
#include <ctype.h>
#include <stdarg.h>
#include <stddef.h> /* provides: wchar_t size_t */
#include <stdint.h>
#include <stdio.h>  /* provides FILE */
#include <stdlib.h> /* provides: mbtowc wctomb mbstowcs wcstombs */
#include <string.h>
#include <time.h>
#include <langinfo.h>

/*
 * #############################################
 *              typedefs
 * #############################################
 */

#define wint_t Rune
#define wctype_t unsigned long

typedef struct {
	unsigned int count;
	unsigned int value;
} mbstate_t;

#ifndef WCHAR_MIN
#define WCHAR_MIN ((wchar_t) 0)
#endif
#ifndef WCHAR_MAX
#define WCHAR_MAX Runemax
#endif
#ifndef WEOF
#define WEOF ((Rune) EOF)
#endif


/* ##############################################
 * Missing functions from standard APE libraries.
 * Redefined or remapped to APE library functions
 * ##############################################
 */

/* hack */
extern Rune btowc(int);
#define btowc(c) ((Rune)(c))
extern int wctob(Rune);
#define wctob(c) ((int)(c))

/* stdio.h */
extern Rune fgetwc(struct _IO_FILE *);
#define fgetwc(f) fgetc(f)
extern Rune fputwc(wchar_t, struct _IO_FILE *);
#define fputwc(c, f) fputc((int)(c), (f))
extern wchar_t *fgetws(wchar_t *, int, struct _IO_FILE *);
#define fgetws(c, i, f) fgets((char *)(c), (i), (f))
extern int fputws(const wchar_t *, struct _IO_FILE *);
#define fputws(c, f) fputs((const char *)(c), (f))

/* Variadic wide stdio: delegate to narrow counterparts via __VA_ARGS__ */
extern int fwprintf(struct _IO_FILE *, const wchar_t *, ...);
#define fwprintf(f, c, ...) fprintf((f), (const char *)(c), __VA_ARGS__)
extern int fwscanf(struct _IO_FILE *, const wchar_t *, ...);
#define fwscanf(f, c, ...) fscanf((f), (const char *)(c), __VA_ARGS__)
extern Rune getwchar(void);
#define getwchar() getchar()
extern Rune getwc(struct _IO_FILE *);
#define getwc(f) getc(f)
extern Rune putwchar(Rune);
#define putwchar(c) putchar((int)(c))
extern Rune putwc(Rune, struct _IO_FILE *);
#define putwc(r, f) putc((int)(r), (f))
extern int swprintf(wchar_t *, size_t, const wchar_t *, ...);
#define swprintf(c, st, wc, ...) snprintf((char *)(c), (st), (const char *)(wc), __VA_ARGS__)
extern int swscanf(const wchar_t *, const wchar_t *, ...);
#define swscanf(c1, c2, ...) sscanf((const char *)(c1), (const char *)(c2), __VA_ARGS__)
extern Rune ungetwc(Rune, struct _IO_FILE *);
#define ungetwc(c, f) ungetc((int)(c), (f))
extern int vfwprintf(struct _IO_FILE *, const wchar_t *, va_list);
#define vfwprintf(f, c, a) vfprintf((f), (const char *)(c), (a))
extern int vfwscanf(struct _IO_FILE *, const wchar_t *, va_list);
#define vfwscanf(f, c, a) vfscanf((f), (const char *)(c), (a))
extern int vwprintf(const wchar_t *, va_list);
#define vwprintf(c, a) vprintf((const char *)(c), (a))
extern int vwscanf(const wchar_t *, va_list);
#define vwscanf(c, a) vscanf((const char *)(c), (a))
extern int vswprintf(wchar_t *, size_t, const wchar_t *, va_list);
#define vswprintf(c1, st, c2, a) vsnprintf((char *)(c1), (st), (const char *)(c2), (a))
extern int vswscanf(const wchar_t *, const wchar_t *, va_list);
#define vswscanf(c1, c2, a) vsscanf((const char *)(c1), (const char *)(c2), (a))
extern int wprintf(const wchar_t *, ...);
#define wprintf(c, ...) printf((const char *)(c), __VA_ARGS__)
extern int wscanf(const wchar_t *, ...);
#define wscanf(c, ...) scanf((const char *)(c), __VA_ARGS__)

/* stdlib.h
 * All wcs numeric conversions cast to char * and delegate to str* equivalents.
 * This is sound because numeric input is always ASCII, regardless of encoding.
 * wcstof/wcstold use strtof/strtold (not strtod) to preserve precision. */
extern double wcstod(const wchar_t *, wchar_t **);
#define wcstod(c1, c2) strtod((const char *)(c1), (char **)(c2))
extern float wcstof(const wchar_t *, wchar_t **);
#define wcstof(c1, c2) strtof((const char *)(c1), (char **)(c2))
extern long double wcstold(const wchar_t *, wchar_t **);
#define wcstold(c1, c2) strtold((const char *)(c1), (char **)(c2))
extern long wcstol(const wchar_t *, wchar_t **, int);
#define wcstol(c1, c2, i) strtol((const char *)(c1), (char **)(c2), (i))
extern long long wcstoll(const wchar_t *, wchar_t **, int);
#define wcstoll(c1, c2, i) strtoll((const char *)(c1), (char **)(c2), (i))
extern unsigned long wcstoul(const wchar_t *, wchar_t **, int);
#define wcstoul(c1, c2, i) strtoul((const char *)(c1), (char **)(c2), (i))
extern unsigned long long wcstoull(const wchar_t *, wchar_t **, int);
#define wcstoull(c1, c2, i) strtoull((const char *)(c1), (char **)(c2), (i))

/* string.h
 * Note: wchar_t * strings are UTF-8 Rune sequences in this implementation,
 * so byte-level str* operations are correct for most cases. Operations that
 * are character-count sensitive (wcslen, wcsncat, wcsncmp, wcsncpy) may
 * return byte counts rather than Rune counts; this is a known limitation. */
extern wchar_t *wcscat(wchar_t *, const wchar_t *);
#define wcscat(c1, c2) strcat((char *)(c1), (const char *)(c2))
extern wchar_t *wcschr(const wchar_t *, wchar_t);
#define wcschr(c1, c2) ((wchar_t *)strchr((const char *)(c1), (int)(c2)))
extern int wcscmp(const wchar_t *, const wchar_t *);
#define wcscmp(c1, c2) strcmp((const char *)(c1), (const char *)(c2))
extern int wcscoll(const wchar_t *, const wchar_t *);
#define wcscoll(c1, c2) strcoll((const char *)(c1), (const char *)(c2))
extern wchar_t *wcscpy(wchar_t *, const wchar_t *);
#define wcscpy(dest, src) ((wchar_t *)strcpy((char *)(dest), (const char *)(src)))
extern size_t wcscspn(const wchar_t *, const wchar_t *);
#define wcscspn(c1, c2) strcspn((const char *)(c1), (const char *)(c2))
extern size_t wcslen(const wchar_t *);
#define wcslen(s) strlen((const char *)(s))
extern wchar_t *wcsncat(wchar_t *, const wchar_t *, size_t);
#define wcsncat(c1, c2, st) ((wchar_t *)strncat((char *)(c1), (const char *)(c2), (st)))
extern int wcsncmp(const wchar_t *, const wchar_t *, size_t);
#define wcsncmp(c1, c2, st) strncmp((const char *)(c1), (const char *)(c2), (st))
extern wchar_t *wcsncpy(wchar_t *, const wchar_t *, size_t);
#define wcsncpy(c1, c2, st) ((wchar_t *)strncpy((char *)(c1), (const char *)(c2), (st)))
extern wchar_t *wcspbrk(const wchar_t *, const wchar_t *);
#define wcspbrk(c1, c2) ((wchar_t *)strpbrk((const char *)(c1), (const char *)(c2)))
extern wchar_t *wcsrchr(const wchar_t *, wchar_t);
#define wcsrchr(c1, c2) ((wchar_t *)strrchr((const char *)(c1), (int)(c2)))
extern size_t wcsspn(const wchar_t *, const wchar_t *);
#define wcsspn(c1, c2) strspn((const char *)(c1), (const char *)(c2))
extern wchar_t *wcsstr(const wchar_t *, const wchar_t *);
#define wcsstr(c1, c2) ((wchar_t *)strstr((const char *)(c1), (const char *)(c2)))
extern wchar_t *wcstok(wchar_t *, const wchar_t *, wchar_t **);
#define wcstok(c1, c2, c3) ((wchar_t *)strtok_r((char *)(c1), (const char *)(c2), (char **)(c3)))
extern wchar_t *wcswcs(const wchar_t *, const wchar_t *);
#define wcswcs(c1, c2) ((wchar_t *)strstr((const char *)(c1), (const char *)(c2)))
extern size_t wcsxfrm(wchar_t *, const wchar_t *, size_t);
#define wcsxfrm(c1, c2, st) strxfrm((char *)(c1), (const char *)(c2), (st))
extern wchar_t *wmemchr(const wchar_t *, wchar_t, size_t);
#define wmemchr(c1, c2, st) ((wchar_t *)memchr((const void *)(c1), (int)(c2), (st)))
extern int wmemcmp(const wchar_t *, const wchar_t *, size_t);
#define wmemcmp(c1, c2, st) memcmp((const void *)(c1), (const void *)(c2), (st))
extern wchar_t *wmemcpy(wchar_t *, const wchar_t *, size_t);
#define wmemcpy(c1, c2, st) ((wchar_t *)memcpy((void *)(c1), (const void *)(c2), (st)))
extern wchar_t *wmemmove(wchar_t *, const wchar_t *, size_t);
#define wmemmove(c1, c2, st) ((wchar_t *)memmove((void *)(c1), (const void *)(c2), (st)))
extern wchar_t *wmemset(wchar_t *, wchar_t, size_t);
#define wmemset(c1, c2, st) ((wchar_t *)memset((void *)(c1), (int)(c2), (st)))

/* time.h */
extern size_t wcsftime(wchar_t *, size_t, const wchar_t *, const struct tm *);
#define wcsftime(c1, st, c2, stm) strftime((char *)(c1), (st), (const char *)(c2), (stm))

/* ##############################################
 * Missing functions from standard APE libraries.
 * Functions that need actual implementation.
 * ##############################################
 */

int fwide(struct _IO_FILE *, int);
size_t mbrlen(const char *, size_t, mbstate_t *);
size_t mbrtowc(wchar_t *, const char *, size_t, mbstate_t *);
int mbsinit(const mbstate_t *);
size_t mbsrtowcs(wchar_t *, const char **, size_t, mbstate_t *);
size_t wcrtomb(char *, wchar_t, mbstate_t *);
size_t wcsrtombs(char *, const wchar_t **, size_t, mbstate_t *);
int wcwidth(wchar_t);
int wcswidth(const wchar_t *, size_t);

/* from musl */

wchar_t *wcsdup(const wchar_t *s);
size_t mbsnrtowcs(wchar_t *wcs, const char **src,
	size_t n, size_t wn, mbstate_t *st);
size_t wcsnrtombs(char *dst, const wchar_t **wcs,
	size_t wn, size_t n, mbstate_t *st);
wchar_t *wcpcpy(wchar_t *d, const wchar_t *s);
wchar_t *wcpncpy(wchar_t *d, const wchar_t *s, size_t n);



#endif /* _WCHAR_H */

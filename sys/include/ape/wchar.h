/* info about whcar.h:
 * https://pubs.opengroup.org/onlinepubs/009695399/basedefs/wchar.h.html
 wide UTF --> WTF */

#ifndef _WCHAR_H
#define _WCHAR_H 1

#pragma lib "/$M/lib/ape/libutf.a"
#pragma src "/sys/src/ape/lib/utf"

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

#define WCHAR_MIN ((wchar_t) 0)
#define WCHAR_MAX Runemax
#define WEOF ((Rune) EOF)


/* ##############################################
 * Missing functions from standard APE libraries. 
 * Redefined or remapped to APE library functions 
 * ##############################################
 */

/* hack */
extern Rune btowc(int);
#define btowc(c) ((Rune) c)
extern int wctob(Rune);
#define wctob(c) ((int) c)

/* utf.h */
/* some function redefintions below might
 * benefit from the rune variant? */

/* stdio.h */
extern Rune fgetwc(FILE *);
#define fgetwc(f) fgetc(f)
extern Rune fputwc(wchar_t, FILE *);
#define fputwc(c, f) fputc((int) c, f) 
extern wchar_t *fgetws(wchar_t *, int, FILE *);
#define fgetws(c, i, f) fgets((char *) c, i, f)
extern int fputws(const wchar_t *, FILE *);
#define fputws(c, f) fputs((const char *) c, f)
extern int fwprintf(FILE *, const wchar_t *, ...);
#define fwprintf(f, c, ...) fprintf(f, (const char *) c, ...)
extern int fwscanf(FILE *, const wchar_t *, ...);
#define fwscanf(f, c, ...) fscanf(f, (const char *) c, ...)
extern Rune getwchar(void);
#define getwchar() getchar()
extern Rune getwc(FILE *);
#define getwc(f) getc(f)
extern Rune putwchar(Rune);
#define putwchar(c) putchar((int) c)
extern Rune putwc(Rune, FILE*);
#define putwc(r, f) putc((int) r, f)
extern int swprintf(wchar_t *, size_t, const wchar_t *, ...);
#define swprintf(c, st, cw, ...) sprintf((char *) c, (const char *) wc, ...)
extern int swscanf(const wchar_t *, const wchar_t *, ...);
#define swscanf(c1, c2, ...) sscanf((const char *) c1, (const char *) c2, ...)
extern Rune ungetwc(Rune, FILE *);
#define ungetwc(c, f) ungetc((int) c, f)
extern int vfwprintf(FILE *, const wchar_t *, va_list);
#define vfwprintf(f, c, a) vfprintf(f, (const char *) c, a)
extern int vfwscanf(FILE *, const wchar_t *, va_list);
#define vfwscanf(f, c, a) vfscanf(f, (const char *) c, a)
extern int vwprintf(const wchar_t *, va_list);
#define vwprintf(c, a) vprintf((const char *) c, a)
extern int vwscanf(const wchar_t *, va_list);
#define vwscanf(c, a) scanf((const char *) c, ...)
extern int vswprintf(wchar_t *, size_t, const wchar_t *, va_list);
#define vswprintf(c1, st, c2, a) vsprintf((char *) c1, (const char *) c2, a)
extern int vswscanf(const wchar_t *, const wchar_t *, va_list);
#define vswscanf(c1, c2, a) sscanf((const char *) c1, (const char *) c2, ...)
extern int wprintf(const wchar_t *, ...);
#define wprintf(c, ...) printf((const char *) c, ...)
extern int wscanf(const wchar_t *, ...);
#define wscanf(c, ...) scanf((const char *) c, ...)

/* stdlib.h */
extern double wcstod(const wchar_t *, wchar_t **);
#define wcstod(c1, c2) strtod((const char *) c1, (char **) c2)
extern double wcstof(const wchar_t *, wchar_t **);
#define wcstof(c1, c2) strtod((const char *) c1, (char **) c2)
extern long wcstol(const wchar_t *, wchar_t **, int);
#define wcstol(c1, c2, i) strtol((const char *) c1, (char **) c2, i)
extern long double wcstold(const wchar_t *, wchar_t **);
#define wcstold(c1, c2) strtod((const char *) c1, (char **) c2)
extern long long wcstoll(const wchar_t *, wchar_t **, int);
#define wcstoll(c1, c2, i) strtoll((const char *) c1, (char **) c2, i)
extern unsigned long wcstoul(const wchar_t *, wchar_t **, int);
#define wcstoul(c1, c2, i) strtoul((const char *) c1, (char **) c2, i)
extern unsigned long long wcstoull(const wchar_t *, wchar_t **, int);
#define wcstoull(c1, c2, i) strtoull((const char *) c1, (char **) c2, i)

/* string.h */
extern wchar_t wcscat(wchar_t *, const wchar_t *);
#define wcscat(c1, c2) strcat((char *) c1, (const char *) c2)
extern wchar_t *wcschr(const wchar_t *, wchar_t);
#define wcschr(c1, c2) strchr((const char *) c1, (int) c2)
extern int wcscmp(const wchar_t *, const wchar_t *);
#define wcscmp(c1, c2) strcmp((const char *) c1, (const char *) c2)
extern int wcscoll(const wchar_t *, const wchar_t *);
#define wcscoll(c1, c2) strcoll((const char *) c1, (const char *) c2)
extern size_t wcscspn(const wchar_t *, const wchar_t *);
#define wcscspn(c1, c2) strcspn((const char *) c1, (const char *) c2)
extern wchar_t wcscpy(wchar_t *, const wchar_t *);
#define wcscpy(dest,src) strcpy((char *) dest, (const char *) src)
extern size_t wcslen(const wchar_t *);
#define wcslen(s) strlen((const char *) s)
extern wchar_t *wcsncat(wchar_t *, const wchar_t *, size_t);
#define wcsncat(c1, c2, st) strncat((char *) c1, (const char *) c2, st)
extern int wcsncmp(const wchar_t *, const wchar_t *, size_t);
#define wcsncmp(c1, c2, st) strncmp((const char *) c1, (const char *) c2, st)
extern wchar_t *wcsncpy(wchar_t *, const wchar_t *, size_t);
#define wcsncpy(c1, c2, st) strncpy((char *) c1, (const char *) c2, st)
extern wchar_t *wcspbrk(const wchar_t *, const wchar_t *);
#define wcspbrk(c1, c2) strpbrk((const char *) c1, (const char *) c2)
extern wchar_t *wcsrchr(const wchar_t *, wchar_t);
#define wcsrchr(c1, c2) strrchr((const char *) c1, (int) c2)
extern size_t wcsspn(const wchar_t *, const wchar_t *);
#define wcsspn(c1,c2) strspn((const char *) c1, (const char *) c2)
extern wchar_t *wcsstr(const wchar_t *, const wchar_t *);
#define wcsstr(c1, c2) strstr((const char *) c1, (const char *) c2)
extern wchar_t *wcstok(wchar_t *, const wchar_t *, wchar_t **);
#define wcstok(c1, c2, c3) strtok_r((char *) c1, (const char *) c2, (char **) c3)
extern wchar_t *wcswcs(const wchar_t *, const wchar_t *);
#define wcswcs(c1, c2) strstr((const char *) c1, (const char *) c2)
extern size_t wcsxfrm(wchar_t *, const wchar_t *, size_t);
#define wcsxfrm(c1, c2, st) strxfrm((char *) c1, (const char *) c2, st)
extern wchar_t *wmemchr(const wchar_t *, wchar_t, size_t);
#define wmemchr(c1, c2, st) memchr((const void*) c1, (int) c2, st)
extern int wmemcmp(const wchar_t *, const wchar_t *, size_t);
#define wmemcmp(c1, c2, st) memcmp((const void *) c1, (const void *) c2, st)
extern wchar_t *wmemcpy(wchar_t *, const wchar_t *, size_t);
#define wmemcpy(c1, c2, st) memcpy((void *) c1, (const void *) c2, st)
extern wchar_t *wmemmove(wchar_t *, const wchar_t *, size_t);
#define wmemmove(c1, c2, st) memmove((void *) c1, (const void *) c2, st)
extern wchar_t *wmemset(wchar_t *, wchar_t, size_t);
#define wmemset(c1, c2, st) memset((void *) c1, (int) c2, st)

/* time.h */
extern size_t wcsftime(wchar_t *, size_t, const wchar_t *, const struct tm *);
#define wcsftime(c1, st, c2, stm) strftime((char *) c1, st, (const char *) c2, stm)

/* ##############################################
 * Missing functions from standard APE libraries. 
 * Functions that need libwtf.a 
 * ##############################################
 */

int fwide(FILE *, int);
size_t mbrlen(const char *, size_t, mbstate_t *);
size_t mbrtowc(wchar_t *, const char *, size_t, mbstate_t *);
int mbsinit(const mbstate_t *);
size_t mbsrtowcs(wchar_t *, const char **, size_t, mbstate_t *);
size_t wcrtomb(char *, wchar_t, mbstate_t *);
size_t wcsrtombs(char *, const wchar_t **, size_t, mbstate_t *);
int wcwidth(wchar_t);
int wcswidth(const wchar_t *, size_t);

#endif /* WCHAR_H */


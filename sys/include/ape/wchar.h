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
struct tm;	/* for wcsftime; avoid pulling in time.h */
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
 *
 * These were once remapping macros: each wide function was declared and
 * then #define'd onto its NARROW counterpart by casting wchar_t * to
 * char *, which is only correct if wchar_t is a byte. It is not, so
 * wcslen(s) was strlen((const char *)(s)) and returned 1 for a string of
 * any length, the first element's low byte being zero for any ASCII
 * character. They also broke any translation unit DEFINING one of these
 * names, since the definition itself got expanded -- which is how
 * gnulib's btowc.c came to report
 *     btowc.c:29 external redeclaration of: Rune
 *
 * All 53 are gone. libap implements every one of them now: the wcs* and
 * wmem* string and memory functions in string/, btowc and wctob in
 * multibyte/, the wide stdio and the wide printf and scanf families in
 * stdio/, and the wide conversions in string/wcstol.c and
 * string/wcsftime.c.
 */
/* hack */
/*
 * btowc and wctob are declared but deliberately NOT macro'd.
 *
 * They used to be "#define btowc(c) ((Rune)(c))" and
 * "#define wctob(c) ((int)(c))", which are wrong above ASCII: in a UTF-8
 * locale a lone byte 128..255 is not a character and btowc must return
 * WEOF, and btowc(EOF) must be WEOF rather than a huge Rune. libap
 * implements both correctly in multibyte/, and both files open with
 * "#undef btowc" / "#undef wctob" to escape these macros -- which is
 * what made them recognisable as a hack rather than an optimisation.
 *
 * The macros also broke anything that DEFINES either name: gnulib's
 * btowc.c expanded to "wint_t ((Rune)(int c))", reported as
 *   btowc.c:29 external redeclaration of: Rune
 */
extern Rune btowc(int);
extern int wctob(Rune);

/* stdio.h */
extern Rune fgetwc(struct _IO_FILE *);
extern Rune fputwc(wchar_t, struct _IO_FILE *);
extern wchar_t *fgetws(wchar_t *, int, struct _IO_FILE *);
extern int fputws(const wchar_t *, struct _IO_FILE *);

/* Variadic wide stdio: delegate to narrow counterparts via __VA_ARGS__ */
extern int fwprintf(struct _IO_FILE *, const wchar_t *, ...);
extern int fwscanf(struct _IO_FILE *, const wchar_t *, ...);
extern Rune getwchar(void);
extern Rune getwc(struct _IO_FILE *);
extern Rune putwchar(Rune);
extern Rune putwc(Rune, struct _IO_FILE *);
extern int swprintf(wchar_t *, size_t, const wchar_t *, ...);
extern int swscanf(const wchar_t *, const wchar_t *, ...);
extern Rune ungetwc(Rune, struct _IO_FILE *);
extern int vfwprintf(struct _IO_FILE *, const wchar_t *, va_list);
extern int vfwscanf(struct _IO_FILE *, const wchar_t *, va_list);
extern int vwprintf(const wchar_t *, va_list);
extern int vwscanf(const wchar_t *, va_list);
extern int vswprintf(wchar_t *, size_t, const wchar_t *, va_list);
extern int vswscanf(const wchar_t *, const wchar_t *, va_list);
extern int wprintf(const wchar_t *, ...);
extern int wscanf(const wchar_t *, ...);

/* stdlib.h
 * All wcs numeric conversions cast to char * and delegate to str* equivalents.
 * This is sound because numeric input is always ASCII, regardless of encoding.
 * wcstof/wcstold use strtof/strtold (not strtod) to preserve precision. */
extern double wcstod(const wchar_t *, wchar_t **);
extern float wcstof(const wchar_t *, wchar_t **);
extern long double wcstold(const wchar_t *, wchar_t **);
extern long wcstol(const wchar_t *, wchar_t **, int);
extern long long wcstoll(const wchar_t *, wchar_t **, int);
extern unsigned long wcstoul(const wchar_t *, wchar_t **, int);
extern unsigned long long wcstoull(const wchar_t *, wchar_t **, int);

/* string.h
 * Note: wchar_t * strings are UTF-8 Rune sequences in this implementation,
 * so byte-level str* operations are correct for most cases. Operations that
 * are character-count sensitive (wcslen, wcsncat, wcsncmp, wcsncpy) may
 * return byte counts rather than Rune counts; this is a known limitation. */
extern wchar_t *wcscat(wchar_t *, const wchar_t *);
extern wchar_t *wcschr(const wchar_t *, wchar_t);
extern int wcscmp(const wchar_t *, const wchar_t *);
extern int wcscoll(const wchar_t *, const wchar_t *);
extern wchar_t *wcscpy(wchar_t *, const wchar_t *);
extern size_t wcscspn(const wchar_t *, const wchar_t *);
extern size_t wcslen(const wchar_t *);
extern wchar_t *wcsncat(wchar_t *, const wchar_t *, size_t);
extern int wcsncmp(const wchar_t *, const wchar_t *, size_t);
extern wchar_t *wcsncpy(wchar_t *, const wchar_t *, size_t);
extern wchar_t *wcspbrk(const wchar_t *, const wchar_t *);
extern wchar_t *wcsrchr(const wchar_t *, wchar_t);
extern size_t wcsspn(const wchar_t *, const wchar_t *);
extern wchar_t *wcsstr(const wchar_t *, const wchar_t *);
extern wchar_t *wcstok(wchar_t *, const wchar_t *, wchar_t **);
extern wchar_t *wcswcs(const wchar_t *, const wchar_t *);
extern size_t wcsxfrm(wchar_t *, const wchar_t *, size_t);
extern wchar_t *wmemchr(const wchar_t *, wchar_t, size_t);
extern int wmemcmp(const wchar_t *, const wchar_t *, size_t);
extern wchar_t *wmemcpy(wchar_t *, const wchar_t *, size_t);
extern wchar_t *wmemmove(wchar_t *, const wchar_t *, size_t);
extern wchar_t *wmemset(wchar_t *, wchar_t, size_t);

/* time.h */
extern size_t wcsftime(wchar_t *, size_t, const wchar_t *, const struct tm *);

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

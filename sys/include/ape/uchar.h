#ifndef _UCHAR_H
#define _UCHAR_H

#include <unitypes.h>
#include <wchar.h>

typedef uint32_t char32_t;

int c32isalnum(char32_t r);
int c32isalpha(char32_t r);
int c32isblank(char32_t r);
int c32iscntrl(char32_t r);
int c32isdigit(char32_t r);
int c32isgraph(char32_t r);
int c32islower(char32_t r);
int c32isprint(char32_t r);
int c32ispunct(char32_t r);
int c32isspace(char32_t r);
int c32isupper(char32_t r);
int c32isxdigit(char32_t r);

ucs4_t c32tolower(ucs4_t r);
ucs4_t c32toupper(ucs4_t r);
size_t c32rtomb(char *s, ucs4_t wc, mbstate_t *ps);
size_t mbrtoc32(ucs4_t *pwc, const char *s, size_t n, mbstate_t *ps);

#endif

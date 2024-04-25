/* info about wctype.h:
 * https://pubs.opengroup.org/onlinepubs/009695399/basedefs/wctype.h.html
 */

#ifndef _WCTYPE_H
#define _WCTYPE_H 1

#pragma lib "/$M/lib/ape/libutf.a"
#pragma src "/sys/src/ape/lib/utf"

#include <wchar.h> /* provides wint_t --> Rune and wctype_t */

typedef const short* const* wctrans_t;


/* ##############################################
 * Missing functions from standard APE libraries. 
 * Redefined or remapped to APE library functions 
 * ##############################################
 */

extern int iswalnum(Rune);
extern int iswalpha(Rune);
extern int iswblank(Rune);
extern int iswcntrl(Rune);
extern int iswdigit(Rune);
extern int iswgraph(Rune);
extern int iswlower(Rune);
extern int iswprint(Rune);
extern int iswpunct(Rune);
extern int iswspace(Rune);
extern int iswupper(Rune);
extern int iswxdigit(Rune);
extern int towlower(Rune);
extern int towupper(Rune);

#define iswalnum(c) isalnum((int) c)
#define iswalpha(c) isalpharune(c)
#define iswblank(c) isblank((int) c)
#define iswcntrl(c) iscntrl((int) c)
#define iswdigit(c) isdigit((int) c)
#define iswgraph(c) isgraph((int) c)
#define iswlower(c) islowerrune(c)
#define iswprint(c) isprint((int) c)
#define iswpunct(c) ispunct((int) c)
#define iswspace(c) isspacerune(c)
#define iswupper(c) isupperrune(c)
#define iswxdigit(c) isxdigit((int) c)
#define towlower(c) tolowerrune(c)
#define towupper(c) toupperrune(c)


/* ##############################################
 * Missing functions from standard APE libraries. 
 * Functions that need libwtf.a 
 * ##############################################
 */

Rune towctrans(Rune, wctrans_t);
wctrans_t wctrans(const char*);
wctype_t wctype(const char*);
int iswctype(Rune, unsigned long);

#endif /* _WCTYPE_H */

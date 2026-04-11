/* info about wctype.h:
 * https://pubs.opengroup.org/onlinepubs/009695399/basedefs/wctype.h.html
 */

#ifndef _WCTYPE_H
#define _WCTYPE_H 1

#pragma lib "/$M/lib/ape/libap.a"

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
extern int iswtitle(Rune);
extern int towlower(Rune);
extern int towupper(Rune);

#define iswalnum(c) isalnumrune(c)
#define iswalpha(c) isalpharune(c)
#define iswblank(c) isblankrune(c)
#define iswcntrl(c) iscntrlrune(c)
#define iswdigit(c) isdigitrune(c)
#define iswgraph(c) isgraphrune(c)
#define iswlower(c) islowerrune(c)
#define iswprint(c) isprintrune(c)
#define iswpunct(c) ispunctrune(c)
#define iswspace(c) isspacerune(c)
#define iswupper(c) isupperrune(c)
#define iswxdigit(c) isxdigitrune(c)
#define iswtitle(c) istitlerune(c)
#define towlower(c) tolowerrune(c)
#define towupper(c) toupperrune(c)


/* ##############################################
 * Missing functions from standard APE libraries. 
 * Functions that need libwtf.a 
 * ##############################################
 */

extern Rune towctrans(Rune, wctrans_t);
extern wctrans_t wctrans(const char*);
extern wctype_t wctype(const char*);
extern int iswctype(Rune, unsigned long);

#endif /* _WCTYPE_H */

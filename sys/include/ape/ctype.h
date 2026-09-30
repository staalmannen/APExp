#ifndef __CTYPE
#define __CTYPE
#pragma lib "/$M/lib/ape/libap.a"

#ifdef __cplusplus
extern "C" {
#endif

extern int isalnum(int);
extern int isalpha(int);
extern int isblank(int);
extern int iscntrl(int);
extern int isdigit(int);
extern int isgraph(int);
extern int islower(int);
extern int isprint(int);
extern int ispunct(int);
extern int isspace(int);
extern int isupper(int);
extern int isxdigit(int);
extern int tolower(int);
extern int toupper(int);

#ifdef __cplusplus
}
#endif
enum
{
  _ISupper = 01,	/* UPPERCASE.  */
  _ISlower = 02,	/* lowercase.  */
  _ISdigit = 04,	/* Numeric.  */
  _ISspace = 010,	/* Whitespace.  */
  _ISpunct = 020,	/* Punctuation.  */
  _IScntrl = 040,	/* Control character.  */
  _ISblank = 0100,	/* Blank (usually SPC and TAB).  */
  _ISxdigit = 0200,	/* Hexadecimal numeric.  */
};

extern unsigned char _ctype[];
#define	isalnum(c)	(_ctype[(unsigned char)(c)]&(_ISupper|_ISlower|_ISdigit))
#define	isalpha(c)	(_ctype[(unsigned char)(c)]&(_ISupper|_ISlower))
#define	isblank(c)	(_ctype[(unsigned char)(c)]&_ISblank)
#define	iscntrl(c)	(_ctype[(unsigned char)(c)]&_IScntrl)
#undef isdigit
#define	isdigit(c)	(_ctype[(unsigned char)(c)]&_ISdigit)
#define	isgraph(c)	(_ctype[(unsigned char)(c)]&(_ISpunct|_ISupper|_ISlower|_ISdigit))
#define	islower(c)	(_ctype[(unsigned char)(c)]&_ISlower)
/*
 * isprint has NO MACRO, deliberately: it is the one classification
 * that cannot be a single mask.
 *
 * It used to be (graph bits | _ISblank), which was correct only
 * because SPACE was the sole character carrying _ISblank -- the mask
 * was using "blank" as a stand-in for "space". Giving TAB its
 * standard _ISblank (C99 7.4.1.3) would then have made isprint('\t')
 * true, so the two could not both be right while isprint was a mask.
 * A macro cannot say `isgraph(c) || c == ' '' without evaluating c
 * twice, which breaks isprint(*p++), so the FUNCTION in
 * ap/ctype/isprint.c is the definition. One call instead of one
 * lookup; isprint is not on a hot path here.
 */
#define	ispunct(c)	(_ctype[(unsigned char)(c)]&_ISpunct)
#undef isspace
#define	isspace(c)	(_ctype[(unsigned char)(c)]&_ISspace)
#define	isupper(c)	(_ctype[(unsigned char)(c)]&_ISupper)
#define	isxdigit(c)	(_ctype[(unsigned char)(c)]&_ISxdigit)

#define	isascii(c) (((unsigned int)(c))<0x80)
#define	toascii( c ) ((unsigned)(c) & 0x007f)

#endif /* __CTYPE */

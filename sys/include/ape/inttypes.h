#ifndef _INTTYPES_H_
#define _INTTYPES_H_ 1

#pragma lib "/$M/lib/ape/libap.a"

#include <stdint.h>

#define PRId8 "d"
#define PRId16 "d"
#define PRId32 "d"
#define PRId64 "lld"
#define PRIdPTR "lld"
#define PRIdMAX "lld"

#define PRIo8 "o"
#define PRIo16 "o"
#define PRIo32 "o"
#define PRIo64 "llo"
#define PRIoPTR "llo"
#define PRIoMAX "llo"

#define PRIx8 "x"
#define PRIx16 "x"
#define PRIx32 "x"
#define PRIx64 "llx"
#define PRIxPTR "llx"
#define PRIxMAX "llx"

#define PRIu8 "u"
#define PRIu16 "u"
#define PRIu32 "u"
#define PRIu64 "llu"
#define PRIuPTR "llu"
#define PRIuMAX "llu"

/*from musl*/
typedef struct { intmax_t quot, rem; } imaxdiv_t;
extern intmax_t strtoimax(const char *, char **, int);
extern uintmax_t strtoumax(const char *, char **, int);
extern intmax_t imaxabs(intmax_t);
extern imaxdiv_t imaxdiv(intmax_t, intmax_t);


#endif

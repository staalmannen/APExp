#ifndef _INTTYPES_H_
#define _INTTYPES_H_ 1

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

extern intmax_t strtoimax(const char *, char **, int);

#endif

#ifndef _npe_inttypes_h_
#define _npe_inttypes_h_

#include <stdint.h>

#ifndef CHAR_BIT
#define CHAR_BIT 8
#endif

#define PRId32 "d"
#define PRIu32 "u"
#define PRIi32 PRId32
#define PRIx32 "x"
#define PRId64 "lld"
#define PRIu64 "llu"
#define PRIi64 PRId64
#define PRIx64 "llx"
#define PRIdPTR "p"
#define PRIuPTR "p"

#endif

#ifndef _BASE_ALL_H_INCLUDED
#define _BASE_ALL_H_INCLUDED

#include <config.h>

#define BASE_VERSION_VERSIONSTR VERSION "  "

#ifdef _WIN32
# define WIN32_LEAN_AND_MEAN
# include <windows.h>
#else
/* assume __unix__ for everything else */
# if defined(__APPLE__) && defined(__MACH__)
#   define __MACOSX__ 1
# endif
# include <sys/types.h>
# include <unistd.h>
#endif

#include "wintypes.h"
#include "base/lfn.h"

#define in(v1,v2,v3) ((((INT) v1) >= ((INT) v2)) && (((INT) v1)<=((INT) v3)))

//=====================================================================

#ifdef __EMULATE_UNALIGNED__
#include <string.h>

#define get_unaligned(ptr) \
({ __typeof__(*(ptr)) __tmp; memmove(&__tmp, (ptr), sizeof(*(ptr))); __tmp; })
#define put_unaligned(ptr, val) \
({ __typeof__(*(ptr)) __tmp = (val); \
memmove((ptr), &__tmp, sizeof(*(ptr))); \
(void)0; })
#else
#define get_unaligned(ptr) (*(ptr))
#define put_unaligned(ptr, val) ((void)( *(ptr) = (val) ))
#endif /* __EMULATE_UNALIGNED__ */


#include "w_endian.h"

#ifdef WORDS_BIGENDIAN
#define ADJUST_ENDIANNESS16(Ptr) {\
  USHORT x = get_unaligned((USHORT*) (Ptr));\
  put_unaligned((USHORT*) (Ptr), x >> 8 | x << 8);\
}
#define ADJUST_ENDIANNESS32(Ptr) {\
  ULONG x = get_unaligned((ULONG*) (Ptr));\
  x = x >> 16 | x << 16;\
  put_unaligned((ULONG*) (Ptr), (x&0xff00ff00) >> 8 | (x&0x00ff00ff) << 8);\
}
#define ADJUST_ENDIANNESS64(Ptr) {\
  ULONG x1 = get_unaligned((ULONG*) (Ptr)), x2 = get_unaligned(((ULONG*) (Ptr))+1);\
  x1 = x1 >> 16 | x1 << 16;\
  put_unaligned(((ULONG*) (Ptr))+1, (x1&0xff00ff00) >> 8 | (x1&0x00ff00ff) << 8);\
  x2 = x2 >> 16 | x2 << 16;\
  put_unaligned(((ULONG*) (Ptr)), (x2&0xff00ff00) >> 8 | (x2&0x00ff00ff) << 8);\
}
#else // little endian
#define ADJUST_ENDIANNESS16(Ptr) 
#define ADJUST_ENDIANNESS32(Ptr) 
#define ADJUST_ENDIANNESS64(Ptr) 
#endif

#endif

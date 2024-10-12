// Public Domain
// 2022-12-29

/*
 Assume little endian by default, detect big endian (W_BIG_ENDIAN)

 Define WORDS_BIGENDIAN if a big endian system is detected
        (compatibility with autoconf)

 https://gist.github.com/PkmX/63dd23f28ba885be53a5
 https://man7.org/linux/man-pages/man3/endian.3.html
 https://man7.org/linux/man-pages/man3/bswap.3.html
 https://man.openbsd.org/OpenBSD-5.6/byteorder.3
*/
 
#ifndef __W_ENDIAN_H__
#define __W_ENDIAN_H__

#ifdef __cplusplus
extern "C" {
#endif

//#define DEBUG_W_ENDIAN

#include <inttypes.h>

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

// ========================================================
// known systems

#if defined(__linux__) || defined(__HAIKU__) || defined(__CYGWIN__) || defined(__GNU__) \
                       || defined(__OpenBSD__) /* OpenBSD >= 5.6 */
#   include <endian.h>

#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
#   include <sys/endian.h>

#elif defined(sun) || defined(__sun)
#   include <sys/byteorder.h>
#   define bswap16(x) BSWAP_16(x)
#   define bswap32(x) BSWAP_32(x)
#   define bswap64(x) BSWAP_64(x)

#elif defined(__APPLE__)
#   include <libkern/OSByteOrder.h>
#   define bswap16(x) OSSwapInt16(x)
#   define bswap32(x) OSSwapInt32(x)
#   define bswap64(x) OSSwapInt64(x)

#elif defined(_WIN32) && defined(_MSC_VER) // MSVC
#   include <stdlib.h>
#   define bswap16(x) _byteswap_ushort(x)
#   define bswap32(x) _byteswap_ulong(x)
#   define bswap64(x) _byteswap_uint64(x)
#endif


// ========================================================
// make sure bswapXX is defined

#if !defined(bswap16)
#   if defined(__linux__)
#       include <byteswap.h>
#   endif
#   if defined(bswap_16)
#       define bswap16(x) bswap_16(x)
#       define bswap32(x) bswap_32(x)
#       define bswap64(x) bswap_64(x)
#   elif defined(__GNUC__) || defined(__clang__)
#       define bswap16(x) __builtin_bswap16(x)
#       define bswap32(x) __builtin_bswap32(x)
#       define bswap64(x) __builtin_bswap64(x)
#   else //--
#       define bswap16(x) ((uint16_t)(x) << 8) | ((uint16_t)(x) >> 8)
#       define bswap32(x) \
         ((((uint32_t)(x) & 0xff000000) >> 24) | (((uint32_t)(x) & 0x00ff0000) >>  8) | \
          (((uint32_t)(x) & 0x0000ff00) <<  8) | (((uint32_t)(x) & 0x000000ff) << 24))
#       define bswap64(x) \
         ((((uint64_t)(x) & 0xff00000000000000ull) >> 56) \
        | (((uint64_t)(x) & 0x00ff000000000000ull) >> 40) \
        | (((uint64_t)(x) & 0x0000ff0000000000ull) >> 24) \
        | (((uint64_t)(x) & 0x000000ff00000000ull) >> 8) \
        | (((uint64_t)(x) & 0x00000000ff000000ull) << 8) \
        | (((uint64_t)(x) & 0x0000000000ff0000ull) << 24) \
        | (((uint64_t)(x) & 0x000000000000ff00ull) << 40) \
        | (((uint64_t)(x) & 0x00000000000000ffull) << 56))
#   endif
#endif

// ========================================================
// define W_LITTLE_ENDIAN or W_BIG_ENDIAN

#if defined(__BYTE_ORDER__) && defined(__ORDER_BIG_ENDIAN__) && defined(__ORDER_LITTLE_ENDIAN__)
#   if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#       define W_BIG_ENDIAN 1
#   endif

#elif defined(__BYTE_ORDER) && defined(__ORDER_BIG_ENDIAN) && defined(__ORDER_LITTLE_ENDIAN)
#   if __BYTE_ORDER == __ORDER_BIG_ENDIAN
#       define W_BIG_ENDIAN 1
#   endif

#elif defined(__BYTE_ORDER) && defined(__BIG_ENDIAN) && defined(__LITTLE_ENDIAN)
#   if __BYTE_ORDER == __BIG_ENDIAN
#       define W_BIG_ENDIAN 1
#   endif

#elif defined(_BYTE_ORDER) && defined(_BIG_ENDIAN) && defined(_LITTLE_ENDIAN)
    //solaris is known to use this
#   if _BYTE_ORDER == _BIG_ENDIAN
#       define W_BIG_ENDIAN 1
#   endif

#elif defined(BYTE_ORDER) && defined(BIG_ENDIAN) && defined(LITTLE_ENDIAN)
    //FreeBSD and similar os'es
#   if BYTE_ORDER == BIG_ENDIAN
#       define W_BIG_ENDIAN 1
#   endif

#elif defined (__BIG_ENDIAN__) ||                                              \
      defined(__ARMEB__) || defined(THUMBEB__)   || defined (__AARCH64EB__) || \
      defined(_MIPSEB)   || defined(__MIPSEB)    || defined(__MIPSEB__)     || \
      defined(__sparc)   || defined(__sparc__)   ||                            \
      defined(_POWER)    || defined(__powerpc__) || defined(__ppc__)        || \
      defined(__hpux)    || defined(__hppa)      ||                            \
      defined(__s390__)  || defined(__s390x__)   || defined(__zarch__)
#   define W_BIG_ENDIAN 1
#endif

#ifdef W_BIG_ENDIAN
#   ifdef DEBUG_W_ENDIAN
#       warning [DEBUG] BIG ENDIAN detected
#   endif
#   define WORDS_BIGENDIAN 1
#else // little endian, default
#   define W_LITTLE_ENDIAN 1
#endif


// ========================================================
// the system may not define the BSD endianness conversion macross

#if !defined(be16toh) && !defined(betoh16)

#   ifdef DEBUG_W_ENDIAN
#       warning [DEBUG] USING CUSTOM ENDIANNESS CONVERSION DEFINES
#   endif

#   ifdef W_LITTLE_ENDIAN
#       define htobe16(x) bswap16(x)
#       define htole16(x) (uint16_t)(x)
#       define be16toh(x) bswap16(x)
#       define le16toh(x) (uint16_t)(x)

#       define htobe32(x) bswap32(x)
#       define htole32(x) (uint32_t)(x)
#       define be32toh(x) bswap32(x)
#       define le32toh(x) (uint32_t)(x)

#       define htobe64(x) bswap64(x)
#       define htole64(x) (uint64_t)(x)
#       define be64toh(x) bswap64(x)
#       define le64toh(x) (uint64_t)(x)

#   else /* BIG ENDIAN */
#       define htobe16(x) (uint16_t)(x)
#       define htole16(x) bswap16(x)
#       define be16toh(x) (uint16_t)(x)
#       define le16toh(x) bswap16(x)

#       define htobe32(x) (uint32_t)(x)
#       define htole32(x) bswap32(x)
#       define be32toh(x) (uint32_t)(x)
#       define le32toh(x) bswap32(x)

#       define htobe64(x) (uint64_t)(x)
#       define htole64(x) bswap64(x)
#       define be64toh(x) (uint64_t)(x)
#       define le64toh(x) bswap64(x)
#   endif

#endif

// OpenBSD introduced betoh16 but it's not used by other
//   UNIX-like systems (they use be16toh instead)
#if defined(betoh16) && !defined(be16toh)
#   define be16toh(x) betoh16(x)
#   define le16toh(x) letoh16(x)
#   define be32toh(x) betoh32(x)
#   define le32toh(x) letoh32(x)
#   define be64toh(x) betoh64(x)
#   define le64toh(x) letoh64(x)
#elif !defined(betoh16) && defined(be16toh)
#   define betoh16(x) be16toh(x)
#   define letoh16(x) le16toh(x)
#   define betoh32(x) be32toh(x)
#   define letoh32(x) le32toh(x)
#   define betoh64(x) be64toh(x)
#   define letoh64(x) le64toh(x)
#endif

// ========================================================

#ifdef __cplusplus
}
#endif

#endif /* __W_ENDIAN_H__ */


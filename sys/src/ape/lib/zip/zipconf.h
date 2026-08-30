#ifndef _HAD_ZIPCONF_H
#define _HAD_ZIPCONF_H

/*
   zipconf.h -- platform specific include file

   Upstream generates this from zipconf.h.in with CMake. There is no
   CMake here, so it is written out once and kept beside the mkfile,
   the same way curl_config.h is.

   This is a PUBLIC header: <zip.h> includes it, so it is installed
   into sys/include/ape alongside zip.h and anything linking against
   libzip.a reads it. Keep it in step with libzip's version if the
   import is ever updated -- the three LIBZIP_VERSION_* numbers below
   are what zip_libzip_version() reports.

   ZIP_STATIC is defined because APExp builds only static libraries
   (CMakeLists.txt:92 sets it in exactly that case). It is not
   decoration: without it, lib/zip.h gives every ZIP_EXTERN function
   __declspec(dllimport) on Windows or default-visibility on gcc, and
   the point here is that neither applies.
 */

#define LIBZIP_VERSION "1.11.4"
#define LIBZIP_VERSION_MAJOR 1
#define LIBZIP_VERSION_MINOR 11
#define LIBZIP_VERSION_MICRO 4

#define ZIP_STATIC

#include <inttypes.h>

typedef int8_t zip_int8_t;
typedef uint8_t zip_uint8_t;
typedef int16_t zip_int16_t;
typedef uint16_t zip_uint16_t;
typedef int32_t zip_int32_t;
typedef uint32_t zip_uint32_t;
typedef int64_t zip_int64_t;
typedef uint64_t zip_uint64_t;

#define ZIP_INT8_MIN	 (-ZIP_INT8_MAX-1)
#define ZIP_INT8_MAX	 0x7f
#define ZIP_UINT8_MAX	 0xff

#define ZIP_INT16_MIN	 (-ZIP_INT16_MAX-1)
#define ZIP_INT16_MAX	 0x7fff
#define ZIP_UINT16_MAX	 0xffff

#define ZIP_INT32_MIN	 (-ZIP_INT32_MAX-1L)
#define ZIP_INT32_MAX	 0x7fffffffL
#define ZIP_UINT32_MAX	 0xffffffffLU

#define ZIP_INT64_MIN	 (-ZIP_INT64_MAX-1LL)
#define ZIP_INT64_MAX	 0x7fffffffffffffffLL
#define ZIP_UINT64_MAX	 0xffffffffffffffffULL

#endif /* zipconf.h */

#ifndef _BITS64
#define _BITS64
#endif

#if !defined(__BYTE_ORDER) && defined(__LITTLE_ENDIAN)
#define	__BYTE_ORDER	__LITTLE_ENDIAN
#endif

#if !defined(BYTE_ORDER) && defined(LITTLE_ENDIAN)
#define	BYTE_ORDER	LITTLE_ENDIAN
#endif

#ifndef __x86_64__
#define __x86_64__ 1
#endif


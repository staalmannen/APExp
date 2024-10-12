// Public Domain
// 2023-01-04

#include <stdint.h>

#ifndef __WINTYPES_H__
#define __WINTYPES_H__ 1

#ifndef _WIN32
typedef int  BOOL;
typedef int *PBOOL;

typedef char  CHAR;
typedef char *PCHAR;
typedef char *PSZ;
typedef char *LPSTR;

typedef unsigned char  UCHAR;
typedef unsigned char *PUCHAR;
typedef signed char    SCHAR;

typedef int  INT;
typedef int *PINT;
typedef unsigned int  UINT;
typedef unsigned int *PUINT;

typedef uint8_t  BYTE;
typedef uint16_t WORD;
typedef uint32_t DWORD;

typedef int16_t   SHORT;
typedef int16_t  *PSHORT;
typedef uint16_t  USHORT;
typedef uint16_t *PUSHORT;

typedef int32_t   LONG;
typedef int32_t  *PLONG;
typedef uint32_t  ULONG;
typedef uint32_t *PULONG;

typedef int64_t   LONGLONG;
typedef int64_t  *PLONGLONG;
typedef uint64_t  ULONGLONG;
typedef uint64_t *PULONGLONG;

#ifndef VOID
#define VOID void
#endif
typedef void *PVOID;
typedef void *LPVOID;
typedef void *HANDLE;
typedef HANDLE *PHANDLE, *LPHANDLE;
#endif

#endif /* __WINTYPES_H__ */

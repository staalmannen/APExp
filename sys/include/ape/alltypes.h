#ifndef ALLTYPES_H
#define ALLTYPES_H

#include <machine/endian.h>

#include <unistd.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>
#include <bsd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <regex.h>
#include <wchar.h>
#include <pthread.h>
#include <langinfo.h>

typedef long register_t;
typedef long long suseconds_t;
typedef uint64_t u_int64_t;

typedef long blksize_t;
typedef int64_t blkcnt_t;
typedef uint64_t fsblkcnt_t;
typedef uint64_t fsfilcnt_t;

typedef unsigned id_t;
typedef int key_t;
typedef unsigned useconds_t;

typedef va_list __isoc_va_list;

struct iovec { void *iov_base; size_t iov_len; };

struct winsize { unsigned short ws_row, ws_col, ws_xpixel, ws_ypixel; };

typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[12*sizeof(int)/sizeof(void*)]; } __u; } cnd_t;

typedef struct { union { int __i[sizeof(long)==8?10:6]; volatile int __vi[sizeof(long)==8?10:6]; volatile void *volatile __p[sizeof(long)==8?5:6]; } __u; } mtx_t;

#endif /* ALLTYPES_H */




#ifndef _P9SHIM_U_H
#define _P9SHIM_U_H
#include <stddef.h>
#include <stdarg.h>
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef long long vlong;
typedef unsigned long long uvlong;
typedef unsigned int Rune;
#define nil ((void*)0)
#define nelem(x) (sizeof(x)/sizeof((x)[0]))
#define USED(x) if(x){}else{}
#endif

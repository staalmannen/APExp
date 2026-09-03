#ifndef __U_H
#define __U_H

/*
 * Guarded because nil is not a reserved name, and this header arrives
 * through <lock.h> under <pthread.h> where a caller has no reason to
 * expect it. Every Objective-C runtime defines nil as ((id)0) -- the
 * Portable Object Compiler's objcrt.h:83 does, and guards it, so an
 * unguarded definition here simply lost to whichever came second.
 */
#ifndef nil
#define nil		((void*)0)
#endif
typedef	unsigned short	ushort;
typedef	unsigned char	uchar;
typedef unsigned long	ulong;
typedef unsigned int	uint;
typedef signed char	schar;
typedef	long long	vlong;
typedef	unsigned long long uvlong;
typedef	uint		Rune;
typedef 	union FPdbleword FPdbleword;
typedef	char*	p9va_list;

typedef uchar	u8int;
typedef ushort	u16int;
typedef ulong	u32int;
typedef uvlong	u64int;
typedef signed char	s8int;
typedef signed short	s16int;
typedef signed int	s32int;
typedef signed long long	s64int;

#endif

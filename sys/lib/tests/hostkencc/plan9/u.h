/*
 * u.h -- a MINIMAL stand-in for 9front's own /sys/include/u.h, for
 * feeding NATIVE probes to a host-built kencc.
 *
 * ***NOT A COPY OF 9front's HEADER AND NOT A SUBSTITUTE FOR IT.*** This
 * tree does not vendor the native Plan 9 headers -- `sys/include' holds
 * only `ape/' -- so a probe that `#include <u.h>' cannot be compiled
 * here at all without something standing in. This is sized for the
 * probes whose RESULT IS WHETHER THEY COMPILE (`regpair-min.c',
 * `regpair-probe.c'), which between them use `vlong', `nil', `USED',
 * `print' and `exits' and nothing else -- measured, not assumed.
 *
 * **So a pass here means the construct compiles; it does NOT mean the
 * probe would compile against the real header**, which declares far
 * more and could collide. For that, the VM. Anything needing more than
 * this should say so by failing to compile, which is why nothing
 * speculative has been added.
 *
 * The widths are kencc's, not the host's: `long' 32, `vlong' 64,
 * pointers 64. These are what the TARGET compiler sees, so they are
 * right regardless of what gcc built the compiler with.
 */
typedef	unsigned char	uchar;
typedef	unsigned short	ushort;
typedef	unsigned int	uint;
typedef	unsigned long	ulong;
typedef	long long	vlong;
typedef	unsigned long long uvlong;
typedef	unsigned long long uintptr;
typedef	unsigned char	u8int;
typedef	unsigned short	u16int;
typedef	unsigned int	u32int;
typedef	unsigned long long u64int;
typedef	int		s32int;
typedef	long long	s64int;
typedef	unsigned int	Rune;
typedef	union FPdbleword FPdbleword;
typedef	char*		va_list;

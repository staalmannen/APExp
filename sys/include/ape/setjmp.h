#ifndef __SETJMP_H
#define __SETJMP_H
#pragma lib "/$M/lib/ape/libap.a"

/* 
 * Buffers must be large enough to hold all callee-saved registers (64-bit).
 * We save 8 registers: SP, PC, BP, BX, R12, R13, R14, R15.
 * 8 * 8 = 64 bytes.
 * int[24] = 96 bytes, provides safe headroom.
 */
typedef int jmp_buf[24];
typedef int sigjmp_buf[32];

#ifdef __cplusplus
extern "C" {
#endif

extern int setjmp(jmp_buf);
extern void longjmp(jmp_buf, int);

extern int sigsetjmp(sigjmp_buf, int);
extern void siglongjmp(sigjmp_buf, int);

#ifdef __cplusplus
}
#endif

#endif /* __SETJMP_H */

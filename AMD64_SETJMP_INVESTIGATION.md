# Investigation Summary: amd64 sigsetjmp/siglongjmp Instability

This document summarizes the findings and fixes for the "mysterious crashes" (suicide traps) observed in the Plan 9 APE environment on amd64, specifically affecting libraries like `readline` and `curses`.

## Symptoms
1.  **Suicide Traps**: `suicide: sys: trap: fault write addr=0x7ffffffff000`
    *   **Final Root Cause Identified**: The process startup code (`main9.s`) was attempting to relocate a fixed-size environment block from the kernel stack to a new location. When the kernel placed `argc` near the absolute top of memory (`USTKTOP`), the relocation loop would read or write past the boundary, triggering the trap immediately during startup or when a large environment was passed.
2.  **General Protection Violations**: `trap: general protection violation pc=...`
    *   Triggered by stack misalignment or incomplete callee-save register restoration (BX, BP, R12-R15).
    *   Also occurred when `siglongjmp` attempted to resume via `NRSTR` using a `Ureg` that was itself located at the memory boundary.

## Root Cause: REGEXT Register Pollution in main9.s

### The R13 = 0x7ffffffff000 Bug (Final Diagnosis)

The boundary-safe relocation loop used R13 as a scratch register to hold the
guard-page address:

```asm
MOVQ  $0x7ffffffff000, R13   /* ← poisons R13 */
copy_loop:
    MOVQ  SI, R11
    CMPQ  R11, R13            /* boundary check */
    JAE   copy_done
    MOVSQ
    LOOP  copy_loop
```

R13 is a **callee-saved REGEXT register** in Plan 9 6c (used to cache the
address of a global variable within a function).  The call chain from _main to
`sigsetjmp` may not reinitialise R13 (if no function in the chain uses R13 as
REGEXT), so `sigsetjmp` saves `R13 = 0x7ffffffff000` into `jmpbuf[5]`.

When `longjmp` restores the registers:
```asm
MOVQ  40(R11), R13    /* restores R13 = 0x7ffffffff000 */
```

Any subsequent function that uses R13 as REGEXT for a global generates:
```asm
MOVL  newval, 0(R13)  /* FAULT: write to 0x7ffffffff000 (guard page) */
```

This produces exactly the observed crash:
`suicide: sys: trap: fault write addr=0x7ffffffff000 pc=<instr>`

### Fix

Use R11 (caller-saved scratch register, NOT in setjmp's save list) instead of
R12 to hold the kernel SP.  R12–R15 are callee-saved REGEXT registers; using
any of them to hold a value near USTKTOP contaminates the jmpbuf when
sigsetjmp is called later.

Replace the explicit boundary-check loop with `CLD; REP; MOVSQ`.  No boundary
check is needed: the last source read is at `kernel_SP + (argc+1)*8 =
USTKTOP - ssize + argc*8 < USTKTOP - 8`, always within mapped memory.
Using only AX/CX/SI/DI/R11 (all caller-saved) for the copy keeps all
callee-saved REGEXT registers (R12–R15, BP, BX) clean.

## The Architectural Fix (Final Patch)
1.  **Safe Startup (`main9.s`)**: Shifts stack 128KB below USTKTOP; copies
    `argc`/`argv` with `REP; MOVSQ` using only caller-saved registers.
2.  **Standard Signal Path (`notetramp.c`)**: Uses `longjmp()` path when
    `nstack==0` (single-level signal); uses `NRSTR` only for nested signals.
3.  **8-Register setjmp (`setjmp.s`)**: Saves/restores all callee-saved REGEXT
    registers (R12–R15, BP, BX) so the setjmp site sees correct global-cache values.

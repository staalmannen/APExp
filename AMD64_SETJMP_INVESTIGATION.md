# Investigation Summary: amd64 sigsetjmp/siglongjmp Instability

This document summarizes the findings and fixes for the "mysterious crashes" (suicide traps) observed in the Plan 9 APE environment on amd64, specifically affecting libraries like `readline` and `curses`.

## Symptoms
1.  **Suicide Traps**: `suicide: sys: trap: fault write addr=0x7ffffffff000 pc=...`
    *   Occurs when the process is executing at the very top of the user stack (`USTKTOP`).
2.  **General Protection Violations**: `trap: general protection violation`
    *   Triggered by the kernel's `NRSTR` (`noted(3)`) path when the restored register state is inconsistent or incomplete.
3.  **Shell Freezes/Exit Failures**: The `pdksh` shell would freeze or fail to exit cleanly.
    *   Caused by corruption of callee-saved registers (especially `R15`/`RARG`) during signal transitions.

## Discovered Root Causes

### 1. Incomplete Register Synchronization in `NRSTR`
The Plan 9 `noted(3)` (NRSTR) system call reloads **all** General Purpose Registers (GPRs) from the `Ureg` structure. Previous implementations only updated `AX`, `PC`, and `SP`. When the process resumed, registers like `BP`, `BX`, and `R12-R15` contained stale or garbage values from the signal handler context, leading to immediate General Protection Violations.

### 2. Stack Boundary Faults at `USTKTOP`
Plan 9 amd64 processes start their main stack at `0x7ffffffff000`. The auto-generated system call wrappers in APE are C functions that push arguments onto the stack. If the current `SP` is already near the top (common in signal delivery), these writes cross the boundary and trigger a "suicide" trap before the system call ever reaches the kernel.

### 3. Calling Convention Mismatch
*   **APE (6c)**: Expects the first argument in `R15` (`RARG`).
*   **Plan 9 Kernel**: Delivers signals with arguments on the stack (`0(SP)=dummy`, `8(SP)=u`, `16(SP)=msg`).
*   **noted() Signature**: The kernel expects `noted(Ureg *u, int v)`, requiring both the context pointer and the restoration code.

### 4. Register Corruption in Trampolines
Previous trampolines used callee-saved registers as scratch space without preserving them, or relied on scratch registers (`R11`) that are destroyed by the `SYSCALL` instruction itself.

## The Architectural Fix

### 1. Full Register-to-Ureg Sync
Updated `siglongjmp` in `notetramp.c` to explicitly copy the entire 64-bit context from the `sigjmp_buf` into the `Ureg` structure before restoration:
```c
u->ax = (ret == 0) ? 1 : ret;
u->pc = jb->jmpbuf[1];
u->sp = jb->jmpbuf[0] + 8;
u->bp = jb->jmpbuf[2];
u->bx = jb->jmpbuf[3];
u->r12 = jb->jmpbuf[4];
u->r13 = jb->jmpbuf[5];
u->r14 = jb->jmpbuf[6];
u->r15 = jb->jmpbuf[7];
```

### 2. Stack-Safe Syscall Bridge (`_signoted`)
Implemented a raw assembly routine that:
1.  Saves the stack pointer in `R12` (preserved by `SYSCALL`).
2.  **Moves the stack pointer down** by 128 bytes to create a "safe zone" away from `USTKTOP`.
3.  Places both arguments (`u` and `v`) on this new, safe stack.
4.  Invokes the system call via `R15=33` and `SYSCALL`.

### 3. Robust Assembly Trampolines
*   **`_notehandler`**: Correctly extracts `u` and `msg`, ensures 16-byte stack alignment, and preserves `R12`.
*   **`_main` Headroom**: Moved the initial stack pointer down by 64KB to provide a permanent safety buffer for kernel signal delivery.

### 4. Expanded Buffer Sizes
Updated `sys/include/ape/setjmp.h` to `int[48]` (192 bytes) to provide ample room for the full 64-bit register state and prevent buffer overflows.

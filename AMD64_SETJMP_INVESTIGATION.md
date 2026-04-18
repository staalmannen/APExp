# Investigation Summary: amd64 sigsetjmp/siglongjmp Instability

This document summarizes the findings and fixes for the "mysterious crashes" observed in the Plan 9 APE environment on amd64, specifically affecting libraries like `readline` and `curses`.

## Symptoms
1.  **General Protection Violations**: `trap: general protection violation pc=...`
    *   Triggered by the kernel's `NRSTR` (`noted(3)`) path when the restored register state is incomplete.
2.  **Suicide Traps at Boundary**: `suicide: sys: trap: fault write addr=0x7ffffffff000`
    *   Occurs when the process executes at the absolute top of the user stack (`USTKTOP`).
3.  **Shell Freezes/Stability Issues**: `pdksh` would freeze or fail to exit.
    *   Caused by corruption of callee-saved registers (BP, BX, R12-R15) during jump transitions.

## Discovered Root Causes

### 1. Incomplete Register Synchronization in `NRSTR`
The Plan 9 `noted(3)` (NRSTR) system call reloads **all** General Purpose Registers (GPRs) from the `Ureg` structure. Previous APE implementations only updated `AX`, `PC`, and `SP`. When the process resumed from a signal, registers like `BP`, `BX`, and `R12-R15` still contained values from the signal handler's context rather than the `sigsetjmp` site, leading to immediate GPVs.

### 2. Undersized Jump Buffers
The original `jmp_buf` was `int[10]` (40 bytes). On 64-bit amd64, saving the 8 essential registers (`SP`, `PC`, `BP`, `BX`, `R12`, `R13`, `R14`, `R15`) requires 64 bytes. `setjmp` was consistently overwriting 24 bytes of memory adjacent to the buffer.

### 3. Calling Convention and Register Conflict
*   **C arguments (6c)**: Expects the first argument in `R15` (`RARG`).
*   **Kernel delivery**: Delivers signals with arguments on the stack, but uses `BP` as the context pointer in some paths.
*   **Assembly Bridges**: Previous bridges were inconsistent in how they moved these values, leading to "bad address" errors when the kernel received a garbage pointer.

### 4. Stack Boundary Faults at `USTKTOP`
Auto-generated syscall wrappers in APE are C functions that push arguments onto the stack. If the `SP` is already at the limit (`0x7ffffffff000`), these writes trigger a suicide trap before the syscall is executed.

## The Architectural Fix

### 1. Full Register Context Preservation
Updated `setjmp` and `sigsetjmp` to save the complete 64-bit context (8 registers) into an expanded 160-byte buffer (`int[40]`).

### 2. Explicit `Ureg` Synchronization
Updated `siglongjmp` in `notetramp.c` to explicitly copy the entire preserved context from the `sigjmp_buf` into the `Ureg` structure before restoration:
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

### 3. Robust Assembly Trampolines
*   **`_notehandler`**: Correctly bridges the kernel's stack-based arguments to the `6c` register convention using only scratch registers.
*   **`main9.s`**: Restored to the proven 9front startup sequence to ensure a stable environment for the C runtime.

### 4. Binary Compatibility
Maintained the standard Plan 9 `main` entry point while providing the stability required for complex amd64 APE applications.

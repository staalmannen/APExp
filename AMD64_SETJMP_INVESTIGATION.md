# Investigation Summary: amd64 sigsetjmp/siglongjmp Instability

This document summarizes the findings and fixes for the "mysterious crashes" (suicide traps) observed in the Plan 9 APE environment on amd64, specifically affecting libraries like `readline` and `curses`.

## Symptoms
1.  **Suicide Traps**: `suicide: sys: trap: fault write addr=0x7ffffffff000`
    *   Occurred when `longjmp` attempted to write a return address to the very top of the stack (`USTKTOP`).
2.  **General Protection Violations**: `trap: general protection violation pc=...`
    *   Triggered by the kernel's `NRSTR` (`noted(3)`) path when the restored register state was inconsistent or when the stack was misaligned.
3.  **Shell Freezes/Stability Issues**:
    *   Caused by corruption of callee-saved registers and misaligned startup arguments in `_main`.

## Discovered Root Causes

### 1. The Stack Boundary Conflict
Plan 9 amd64 processes often start with a stack pointer at the absolute limit of user memory (`0x7ffffffff000`).
*   **Original Bug**: `longjmp` used the `RET` instruction, which requires pushing the target PC onto the stack. If the stack was already at the boundary, this write triggered a suicide trap.
*   **Fix**: Re-implemented `longjmp` to use a direct `JMP` after restoring `SP`, ensuring it **never writes to the stack** during context restoration.

### 2. Register/Calling Convention Mismatches
There was a critical three-way mismatch in register usage:
*   **APE Compiler (6c)**: Uses `R15` as the first argument register (`RARG`) for C functions.
*   **Plan 9 Kernel**: Delivers signals with arguments on the stack but uses `BP` as the argument register for system calls.
*   **APE Syscall Wrappers**: C functions that attempted to use the stack, causing faults at the boundary.

### 3. Incomplete Context Restoration in `NRSTR`
The kernel's `noted(NRSTR)` path reloads **all** General Purpose Registers from the `Ureg` structure.
*   **Original Bug**: APE only updated `AX`, `PC`, and `SP` in the `Ureg`. Registers like `BP`, `BX`, and `R12-R15` were restored with stale values from the signal handler context, causing immediate GPVs.
*   **Fix**: `siglongjmp` now explicitly synchronizes all 8 general-purpose registers from the jump buffer into the `Ureg` before restoration.

### 4. Linker Frame Requirements
The Plan 9 linker (`6l`) requires strictly balanced stack operations.
*   **Original Bug**: Manual `PUSH`/`POP` in functions without a declared frame size caused the linker to generate invalid branch targets.
*   **Fix**: All assembly entry points now use standard declared frames (e.g., `TEXT name(SB), 1, $frame_size`).

## The Architectural Fix

### 1. Stack-Safe Context Switching
Updated `setjmp.s` to perform "read-only" restoration:
```assembly
MOVQ    0(RARG), SP   /* Restore stack */
ADDQ    $8, SP        /* Simulate the pop of the return address */
MOVQ    8(RARG), DI   /* Load target PC into register */
JMP     DI            /* Jump directly; no stack write required */
```

### 2. Full Register-to-Ureg Sync
Updated `siglongjmp` in `notetramp.c` to perform a complete state hand-off to the kernel.
Also expanded `sigjmp_buf_amd64.jmpbuf` from `[2]` to `[8]` entries to match the 8-register
layout that `sigsetjmp` in `setjmp.s` actually saves (SP, PC, BP, BX, R12–R15):
```c
u->ax  = (ret == 0) ? 1 : ret;
u->pc  = jb->jmpbuf[1];
u->sp  = jb->jmpbuf[0] + 8;
u->bp  = jb->jmpbuf[2];
u->bx  = jb->jmpbuf[3];
u->r12 = jb->jmpbuf[4];
u->r13 = jb->jmpbuf[5];
u->r14 = jb->jmpbuf[6];
u->r15 = jb->jmpbuf[7];
```

### 3. Corrected Startup Sequence
Updated `main9.s` to use a non-stack-modifying `JMP` to enter the C runtime, ensuring `argc` and `argv` are perfectly aligned with the compiler's frame pointer expectations.

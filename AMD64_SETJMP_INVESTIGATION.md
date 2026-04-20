# Investigation Summary: amd64 sigsetjmp/siglongjmp Instability

This document summarizes the findings and fixes for the "mysterious crashes" (suicide traps) observed in the Plan 9 APE environment on amd64, specifically affecting libraries like `readline` and `curses`.

## Symptoms
1.  **Suicide Traps**: `suicide: sys: trap: fault write addr=0x7ffffffff000`
    *   Occurred when instructions (like `PUSH` or `CALL`) attempted to write to the absolute top of user memory (`USTKTOP`).
    *   Persistent even after shifting the stack pointer in `_main`, suggesting subtle interactions with signal delivery or context restoration.
2.  **General Protection Violations**: `trap: general protection violation pc=...`
    *   Triggered by the kernel's `NRSTR` (`noted(3)`) path when the restored register state was inconsistent or when the stack was misaligned.
    *   Also occurred when `_notehandler` signature mismatches caused the signal message to be misread as a pointer.
3.  **Shell Freezes/Stability Issues**:
    *   Caused by corruption of callee-saved registers (R12-R15) during signal recovery.

## Discovered Root Causes

### 1. The Stack Boundary Conflict
Plan 9 amd64 processes start with `SP` at the absolute limit of user memory (`0x7ffffffff000`).
*   **Original Bug**: `longjmp` used `RET`, which pushes to the stack. If `SP` was at the boundary, this write faulted.
*   **Fix**: Re-implemented `longjmp` to use a direct `JMP` after restoring `SP`, ensuring it **never writes to the stack** during context restoration.
*   **Evolution**: We discovered that moving the stack 1MB+ below `USTKTOP` in `_main` is necessary to provide headroom for kernel-delivered signal contexts and to prevent the application from ever touching the faulting boundary.

### 2. Register/Calling Convention for Note Handlers
The Plan 9 kernel delivers signals by pushing a `Ureg` and a note message pointer onto the user stack.
*   **Bug**: The `6c` compiler's calling convention (first arg in `RARG=BP`, second at `8(FP)`) means a standard 2-argument C handler receives the `Ureg` in `BP` and the note message at `8(FP)`. This correctly maps to the kernel's layout if `0(FP)` is at `SP+8`.
*   **Fix**: Verified that `_notehandler(Ureg *u, char *msg)` is the correct signature for `6c` amd64. Previous attempts to use 3 arguments caused General Protection Violations.

### 3. Signal Handler State Preservation
*   **Bug**: `_notetramp` (the resumption stub) was previously receiving arguments on its stack which were then lost or corrupted when the kernel resumed the process.
*   **Fix**: Updated `_notetramp` to capture the signal message into a global `Pcstack` before returning `NSAVE` to the kernel. `notecont` then retrieves this preserved state during resumption, ensuring the user signal handler sees the correct message.

### 4. Linker Frame and Prologue Issues
The Plan 9 linker (`6l`) may insert register-save prologues into `_main` if it contains standard jumps or calls.
*   **Bug**: Linker-inserted prologues shift `SP` by 8 bytes, corrupting the location of `argc` and `argv` for `_callmain`.
*   **Fix**: Used `JMPF` and `TEXT _main(SB), 1, $0` (NOPROF) to suppress prologues and maintain absolute control over the stack layout.

## The Architectural Fix

### 1. Stack-Safe Startup (`main9.s`)
We now relocate the entire process environment to a safe stack location far below `USTKTOP`:
```assembly
SUBQ    $1048576, SP      /* 1MB Headroom */
ANDQ    $~15, SP          /* 16-byte alignment */
REP; MOVSQ                /* Relocate argc/argv block */
JMPF    _callmain(SB)     /* Dispatch to C runtime */
```

### 2. Context Restoration (`setjmp.s` & `notetramp.c`)
*   `longjmp` and `siglongjmp` now restore all 8 callee-saved registers (including `R15=REGEXT`).
*   `siglongjmp` in `notetramp.c` explicitly unwinds the `nstack` depth if a jump bypasses nested handlers, preventing signal stack overflow.

### 3. Signal Message Capture
`_notetramp` signature was updated to `_notetramp(int sig, handler f, Ureg *u, char *msg)` to explicitly receive and store the signal message, ensuring it survives the kernel's `NSAVE`/`NRSTR` cycle.

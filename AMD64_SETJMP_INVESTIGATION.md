# Investigation Summary: amd64 sigsetjmp/siglongjmp Instability

This document summarizes the findings and fixes for the "mysterious crashes" (suicide traps) observed in the Plan 9 APE environment on amd64, specifically affecting libraries like `readline` and `curses`.

## Symptoms
1.  **Suicide Traps**: `suicide: sys: trap: fault write addr=0x7ffffffff000 pc=...`
    *   Occurs when the process is executing at the very top of the user stack.
2.  **General Protection Violations**: `trap: general protection violation`
    *   Triggered by the kernel's `NRSTR` (`noted(3)`) path when the restored register state or stack alignment is invalid.
3.  **Shell Freezes/Exit Failures**: The `pdksh` shell would freeze or fail to exit cleanly.
    *   Caused by corruption of callee-saved registers (especially `R15`/`RARG`) during `sigsetjmp`.

## Discovered Root Causes

### 1. Undersized Jump Buffers
The original `jmp_buf` was defined as `int[10]` (40 bytes). On 64-bit amd64, saving the 8 essential registers (`SP`, `PC`, `BP`, `BX`, `R12`, `R13`, `R14`, `R15`) requires at least 64 bytes. `setjmp` was consistently overwriting 24 bytes of memory adjacent to the buffer.

### 2. Calling Convention Mismatch
*   **APE (6c)**: Expects the first argument in `R15` (`RARG`).
*   **Plan 9 Kernel**: Delivers signals with arguments on the stack (`0(SP)=dummy`, `8(SP)=u`, `16(SP)=msg`).
*   **Result**: The signal handler (`_notehandler`) was receiving a garbage pointer for the `Ureg` structure.

### 3. Stack Boundary Faults at `USTKTOP`
Plan 9 amd64 processes often start their main stack at `0x7ffffffff000`. The auto-generated system call wrappers in APE are C functions that push arguments onto the stack. If the current `SP` is already near the top, these writes cross the boundary and trigger a "suicide" trap before the system call ever reaches the kernel.

### 4. Register Corruption
Previous implementations used callee-saved registers (like `BX`) as scratch space during signal transitions without saving them. This corrupted the execution state of the caller, breaking the shell's logic.

## The Architectural Fix

### 1. Expanded Buffer Sizes
Updated `sys/include/ape/setjmp.h`:
*   `jmp_buf`: `int[24]` (96 bytes)
*   `sigjmp_buf`: `int[32]` (128 bytes)

### 2. Stack-Safe Signal Restoration (`_signoted`)
Implemented a raw assembly routine that:
1.  Calculates the target register state.
2.  **Moves the stack pointer down** by 128 bytes to create a "safe zone" away from `USTKTOP`.
3.  Places the `noted(3)` (NRSTR) argument on this new, safe stack.
4.  Invokes the system call via `R15=33` and `SYSCALL`.

### 3. Robust Assembly Trampolines
*   **`_notehandler`**: Corrected to extract `u` from `8(SP)` and `msg` from `16(SP)`, moving `u` into `R15` for the C runtime.
*   **`_notecont_trampoline`**: Ensures 16-byte stack alignment before calling the restoration logic.
*   **Scratch Registers**: Used only `R11` for intermediate stack management to avoid corrupting callee-saved state.

### 4. Full Context Preservation
`sigsetjmp` and `longjmp` now save and restore the complete 64-bit execution context: `SP`, `PC`, `BP`, `BX`, `R12`, `R13`, `R14`, and `R15`.

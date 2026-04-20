# Investigation Summary: amd64 sigsetjmp/siglongjmp Instability

This document summarizes the findings and fixes for the "mysterious crashes" (suicide traps) observed in the Plan 9 APE environment on amd64, specifically affecting libraries like `readline` and `curses`.

## Symptoms
1.  **Suicide Traps**: `suicide: sys: trap: fault write addr=0x7ffffffff000`
    *   Occurred when instructions attempted to write to the absolute top of user memory (`USTKTOP`).
    *   **Crucial Observation**: Shifting the stack pointer (`SP`) by 2MB in `_main` did **not** prevent the crash at `0x7ffffffff000`. This strongly suggests that the problematic write is either:
        *   Restoring an `SP` value that was captured *before* the shift (unlikely in this environment).
        *   Using a corrupted pointer that happens to point to the boundary.
        *   Occurring in a context where the stack shift was not applied (e.g., a different thread or kernel-level delivery).
2.  **General Protection Violations**: `trap: general protection violation pc=...`
    *   Triggered when restored register state was inconsistent or when the stack was misaligned.
    *   Resolved by ensuring 16-byte alignment and correct callee-saved register restoration (R12-R15).
3.  **Constant PC Values**:
    *   The crash `pc` has remained remarkably consistent (`0x20ca43`, `0x20ca44`, `0x20ca47`, `0x20ca59`) across different stack-shift builds. This suggests the faulting instruction is in a fixed location in `libc` (likely `setjmp.s` or `notetramp.c`) and that our changes to `_main` (which vary in instruction count) are shifting the binary layout in ways that haven't yet isolated the bug.

## Current Investigation State

### 1. The Stack Shift Mystery
We moved `SP` 2MB below the top, yet we still see writes to `0x7ffffffff000`. This address is the first invalid address above the stack. A write here usually means a `PUSH` or `CALL` occurred when `SP` was exactly `0x7ffffffff008`.
*   **Hypothesis**: Something is restoring `SP` to the very top of the memory space, bypassing our `_main` shift.

### 2. Signal Handler Signature
Verified `_notehandler(Ureg *u, char *msg)` as the correct 2-argument signature for APE on amd64. A 3-argument version caused GPVs.

### 3. State Capture in `notetramp.c`
We have implemented a 4-argument `_notetramp` that captures the signal message into a global `Pcstack`. This ensures the message survives the `NSAVE`/`NRSTR` cycle, addressing potential corruption during resumption.

## Planned Diagnostic Steps
1.  **NOP Injection**: We are injecting 16 NOPs into `setjmp.s` to force a shift in the binary layout of `libc`. If the crash `pc` shifts by 16 bytes, we have positively identified `setjmp`/`longjmp` as the faulting site.
2.  **Simplified Startup**: Reverting to a simpler `main9.s` to eliminate any side effects from complex relocation loops while maintaining a safe 64KB headroom.
3.  **Strict siglongjmp Review**: Ensuring that `siglongjmp` never restores an `SP` value that could lead to a boundary fault.

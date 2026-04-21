# Investigation Summary: amd64 sigsetjmp/siglongjmp Instability

This document summarizes the findings and fixes for the "mysterious crashes" (suicide traps) observed in the Plan 9 APE environment on amd64, specifically affecting libraries like `readline` and `curses`.

## Symptoms
1.  **Suicide Traps**: `suicide: sys: trap: fault write addr=0x7ffffffff000`
    *   Occurred when instructions attempted to write to the absolute top of user memory (`USTKTOP`).
    *   **Persistent Failure**: Shifting the stack by up to 2MB in `_main` did **not** resolve the crash. This indicates that the problematic write is likely targeting a pointer or structure (like the `Ureg`) that is derived from the kernel's initial stack placement, bypassing our relocation.
2.  **General Protection Violations**: `trap: general protection violation pc=...`
    *   Triggered by inconsistent register state or stack misalignment.
    *   Resolved by 16-byte alignment and full callee-save (R12-R15) restoration.
3.  **Constant PC Values**:
    *   The crash `pc` has remained remarkably stable (most recently `0x20ca44`), suggesting the faulting instruction is likely in the signal resumption path (`siglongjmp` or `_NOTED` stub).

## Current Investigation State

### 1. The NRSTR Vulnerability
The `NRSTR` path in `siglongjmp` writes to the `Ureg` struct provided by the kernel. If the signal arrived when the process was at a very high stack address (common in early startup or deep recursion), the `Ureg` itself may be located at the very edge of the address space. Writing to high-offset members (like `r15` or `ss`) in this struct can trigger the suicide trap.

### 2. Startup Stack Relocation
We have relocated the user stack and arguments in `_main`. While this protects normal function calls, it does not prevent the kernel from delivering new signals on the "current" stack, which might still be near the top if a previous `longjmp` restored an old `SP`.

## The "Nuclear Option" Fix (Current Patch)
To definitively stop the suicide traps, we are transitioning to a **stack-neutral signal recovery** model:
1.  **Bypass NRSTR**: `siglongjmp` no longer modifies the kernel's `Ureg` or calls `noted(NRSTR)`.
2.  **Manual Unwind**: We manually adjust the global `nstack` state to "pop" all handlers being jumped over.
3.  **Direct Context Restore**: We use `longjmp` (which we've already verified to be stack-safe) to restore the CPU state and resume execution. This avoids the need to touch the kernel's signal context at the memory boundary.
4.  **Robust Relocation**: `main9.s` now uses a simplified 128KB shift with a safe manual copy loop for the environment block.

# Investigation Summary: amd64 sigsetjmp/siglongjmp Instability

This document summarizes the findings and fixes for the "mysterious crashes" (suicide traps) observed in the Plan 9 APE environment on amd64, specifically affecting libraries like `readline` and `curses`.

## Symptoms
1.  **Suicide Traps**: `suicide: sys: trap: fault write addr=0x7ffffffff000`
    *   **Final Root Cause Identified**: The process startup code (`main9.s`) was attempting to relocate a fixed-size environment block from the kernel stack to a new location. When the kernel placed `argc` near the absolute top of memory (`USTKTOP`), the relocation loop would read or write past the boundary, triggering the trap immediately during startup or when a large environment was passed.
2.  **General Protection Violations**: `trap: general protection violation pc=...`
    *   Triggered by stack misalignment or incomplete callee-save register restoration (BX, BP, R12-R15).
    *   Also occurred when `siglongjmp` attempted to resume via `NRSTR` using a `Ureg` that was itself located at the memory boundary.

## Current Investigation State

### 1. Boundary-Safe Relocation
We have implemented a quad-by-quad relocation loop in `main9.s` that explicitly checks every source address against `0x7ffffffff000`. This ensures that we relocate as much of the kernel environment as possible (at least `argc` and the `argv` pointer array) without ever crossing the faulting boundary.

### 2. Signal Context Safety
By moving the primary user stack 128KB+ away from `USTKTOP` at the first instruction of `_main`, we ensure that any subsequently delivered signals have their `Ureg` and note strings placed in safe memory. This allows `siglongjmp` to use the standard `NRSTR` resumption path safely.

### 3. Register Integrity
`longjmp` and `siglongjmp` have been verified to restore all 8 callee-saved registers required by the `6c` compiler, particularly `R15` (REGEXT), which is critical for global variable access in many APE libraries.

## The Architectural Fix (Current Patch)
1.  **Safe Startup (`main9.s`)**: Relocates `argc`/`argv` using a boundary-aware copy loop.
2.  **Standard Signal Path (`notetramp.c`)**: Uses `NRSTR` for reliable kernel-level signal resumption, but includes manual `nstack` unwinding to prevent signal stack corruption.
3.  **Preserved Notes**: `_notetramp` captures the signal message into a global stack to ensure it survives the kernel's state-holding cycle.

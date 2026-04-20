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

### 2. Register/Calling Convention for Note Handlers
APExp's 6c uses `BP` as `RARG` (first argument register). The Plan 9 kernel sets `ureg->bp = nureg`
(the Ureg pointer) when delivering notes, matching this convention exactly — so note handlers
compiled with 6c receive the correct Ureg pointer in RARG=BP. The second argument (note string)
is placed at 0(FP)=[SP+8], but the kernel puts it at [SP+16] (one slot higher due to the first-arg
shadow slot). This means the `char *msg` parameter in `_notehandler` gets the Ureg pointer rather
than the string, causing signal table lookup to always fail; the process falls through to
`_NOTED(1)` (default action). This is the same behaviour as upstream 9front APE and is harmless
for most signals (the signal number in RARG is still correct).

### 3. `nstack--` Ordering in `notecont` + Callee-Save Register Corruption
The call flow through `_notetramp` → NSAVE → `notecont` → signal handler → `siglongjmp` involves
two independent issues:

**Bug A — nstack ordering (primary crash cause):**
Upstream APE decrements `nstack` BEFORE calling `(*f)()`, so when the signal handler calls
`siglongjmp`, `nstack==0` and siglongjmp takes the `longjmp()` path.  A previous "fix" moved
`nstack--` AFTER `(*f)()` to force the NRSTR path (since the old longjmp wrote to the stack and
crashed at USTKTOP).  But once `longjmp` was rewritten to use `ADDQ $8,SP + JMP` (no stack write),
the longjmp() path became safe again.  With `nstack--` AFTER `(*f)()`, siglongjmp took the NRSTR
path which has subtler interactions with the NSAVE/NRSTR note stack, causing a GPV at a slightly
different address.
*   **Fix**: Restored upstream ordering — `nstack--` BEFORE `(*f)()`. siglongjmp always sees
    `nstack==0` for a single-level signal and takes the safe `longjmp()` path.

**Bug B — incomplete jmpbuf / callee-save register corruption in NRSTR path:**
`sigjmp_buf_amd64.jmpbuf` was declared `[2]` (SP and PC only), but `sigsetjmp` in `setjmp.s`
saves 8 registers (SP, PC, BP, BX, R12–R15).  The NRSTR path (reached for nested signals) only
restored AX, PC, and SP into the Ureg, leaving BP/BX/R12–R15 stale.  The kernel's
`noted(NRSTR)` → `setregisters()` copies the Ureg verbatim, so stale callee-saved values
(especially R15=REGEXT) were restored at the sigsetjmp site → GPV.
*   **Fix**: Expanded `jmpbuf[2]` → `jmpbuf[8]` in the struct; added full register sync in the
    NRSTR path (kept for the nested-signal case).

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
Updated `main9.s` to use `JMPF` (not `JMP`) to enter the C runtime, and moved `GLOBL _tos(SB), $8` before the `TEXT` directive to match the upstream layout.

**Why `JMPF` matters:** The 6l linker treats `TEXT f(SB)` containing `JMP g(SB)` as a normal function and may insert a REGEXT (R15) save/restore prologue. For `_main`, this prologue emits `SUBQ $8, SP; MOVQ R15, 0(SP)` before our two `PUSHQ` instructions. This shifts the stack by 8 bytes, so `_callmain` reads R15's saved value as `argc` instead of the kernel's real `argc`. The corrupted `argc` and `argv` cascade into all downstream startup code — including the first `setjmp`/`sigsetjmp` call sites, which then save a wrong SP value that later causes the suicide trap (or GPV).

`JMPF` signals to the linker that `_main` is a dispatch stub, suppressing the REGEXT prologue and preserving the correct stack layout for `_callmain`.

/*
 * amd64 setjmp/longjmp for APExp.
 *
 * jmp_buf layout (8-byte slots):
 *  [0]: SP   [1]: PC
 *
 * sigjmp_buf layout:
 *  [0]: set (savemask flag, low 4 bytes)
 *  [8]: blocked (_psigblocked value)
 * [16]: jmpbuf[0] = SP
 * [24]: jmpbuf[1] = PC (return address of sigsetjmp)
 *
 * Plan 9 amd64 calling convention (APExp / 6c):
 *   RARG (= BP register) carries the first argument.
 *   Subsequent args are on the stack at 0(FP)=8(SP), 8(FP)=16(SP), ...
 *   The first arg is NOT also pushed to the stack (unlike upstream 9front).
 *
 * _notehandler assembly:
 *   The kernel delivers notes with RARG=nureg, [sp+0]=0 (retPC), [sp+8]=nureg,
 *   [sp+16]=msg.  The stub overwrites the retPC placeholder at [sp+0] with msg,
 *   then CALLs _ape_notehandler.  After the CALL pushes a return address,
 *   msg lands at [sp+8]=0(FP) in the callee — matching APExp's convention.
 *   _ape_notehandler never returns (it always calls _NOTED before returning).
 */

TEXT	setjmp(SB), $0
	MOVQ	SP, 0(RARG)
	MOVQ	0(SP), BX		/* return PC */
	MOVQ	BX, 8(RARG)
	MOVL	$0, AX
	RET

TEXT	longjmp(SB), $0
	MOVL	val+0(FP), AX		/* second arg at 0(FP) in APExp convention */
	CMPL	AX, $0
	JNE	ok
	MOVL	$1, AX
ok:
	MOVQ	0(RARG), SP
	ADDQ	$8, SP			/* skip return-address slot; no stack write */
	MOVQ	8(RARG), BX		/* target PC into scratch register */
	JMP	BX			/* stack-safe: no write near USTKTOP */

TEXT	sigsetjmp(SB), $0
	MOVL	savemask+0(FP), BX	/* second arg at 0(FP) */
	MOVL	$0, 0(RARG)
	MOVL	BX, 0(RARG)		/* store savemask flag (low 32 bits) */
	MOVQ	_psigblocked(SB), BX	/* VALUE of _psigblocked (not address) */
	MOVQ	BX, 8(RARG)
	MOVQ	SP, 16(RARG)
	MOVQ	0(SP), BX		/* return PC */
	MOVQ	BX, 24(RARG)
	MOVL	$0, AX
	RET

/*
 * Entry point for Plan 9 notes (registered via _NOTIFY).
 *
 * Kernel delivery layout:
 *   RARG (BP) = nureg*
 *   [sp+0]  = 0        (return PC placeholder, never used)
 *   [sp+8]  = nureg*   (first arg, also in RARG)
 *   [sp+16] = msg*     (second arg in upstream convention, third in APExp)
 *
 * APExp second-arg convention: 0(FP) = [sp+8] after CALL.
 * We overwrite the kernel's placeholder at [sp+0] with msg, then CALL.
 * After CALL pushes the return address, msg sits at [sp+8]=0(FP). ✓
 *
 * _ape_notehandler never returns — it always calls _NOTED.
 */
TEXT	_notehandler(SB), $0
	MOVQ	16(SP), AX		/* msg */
	MOVQ	AX, 0(SP)		/* overwrite retPC placeholder with msg */
	CALL	_ape_notehandler(SB)	/* RARG=nureg, 0(FP)=msg */
	/* _ape_notehandler always calls _NOTED; should not return here */
	RET

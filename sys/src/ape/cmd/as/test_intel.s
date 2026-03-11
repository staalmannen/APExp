; test_intel.s — Intel syntax test input for the 'as' front-end
; Uses NASM/MASM-style Intel syntax

	.intel_syntax noprefix

	.text

myfunc_intel:
	push	rbp
	mov	rbp, rsp
	sub	rsp, 32

	; immediate to register
	mov	eax, 42
	mov	rbx, 0xdeadbeef

	; register to register
	mov	ecx, eax
	mov	rdx, rbx

	; memory addressing
	mov	eax, DWORD PTR [rsp]
	mov	eax, DWORD PTR [rsp+8]
	mov	eax, DWORD PTR [rbp-4]

	; indexed addressing
	mov	ecx, DWORD PTR [rax+rbx*4]
	mov	ecx, DWORD PTR [rax+rbx*8+16]

	; arithmetic
	add	eax, 1
	sub	eax, ecx
	imul	eax, 3
	and	eax, 0xff
	or	eax, ecx
	xor	eax, eax

	; shifts
	shl	eax, 2
	shr	eax, 1
	sar	rax, cl

	; comparisons and conditional jumps
	cmp	eax, 0
	je	.Lzero_intel
	jne	.Lnonzero_intel
	jl	.Lless_intel
	jmp	.Lend_intel

.Lzero_intel:
	mov	eax, 0
	jmp	.Lend_intel

.Lnonzero_intel:
	mov	eax, 1
	jmp	.Lend_intel

.Lless_intel:
	mov	eax, -1

.Lend_intel:
	mov	rsp, rbp
	pop	rbp
	ret

	; 8-bit ops
byte_ops_intel:
	mov	al, 0xff
	mov	cl, al
	add	al, 1
	cmp	al, 0
	ret

	; SSE ops
sse_intel:
	movaps	xmm0, [rax]
	movaps	[rbx], xmm0
	addps	xmm0, xmm1
	ret

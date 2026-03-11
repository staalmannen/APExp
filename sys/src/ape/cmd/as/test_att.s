/* test_att.s — AT&T syntax test input for the 'as' front-end
 * Covers: registers, addressing modes, directives, labels, jumps
 */

	.text

/* simple function */
myfunc:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$32, %rsp

	/* immediate to register */
	movl	$42, %eax
	movq	$0xdeadbeef, %rbx

	/* register to register */
	movl	%eax, %ecx
	movq	%rbx, %rdx

	/* memory addressing */
	movl	(%rsp), %eax
	movl	8(%rsp), %eax
	movl	-4(%rbp), %eax

	/* indexed addressing */
	movl	(%rax,%rbx,4), %ecx
	movl	16(%rax,%rbx,8), %ecx

	/* arithmetic */
	addl	$1, %eax
	subl	%ecx, %eax
	imull	$3, %eax
	andl	$0xff, %eax
	orl	%ecx, %eax
	xorl	%eax, %eax		/* zero eax */

	/* shifts */
	shll	$2, %eax
	shrl	$1, %eax
	sarq	%cl, %rax

	/* comparisons and jumps */
	cmpl	$0, %eax
	je	.Lzero
	jne	.Lnonzero
	jl	.Lless
	jge	.Lgreater_eq
	jmp	.Lend

.Lzero:
	movl	$0, %eax
	jmp	.Lend

.Lnonzero:
	movl	$1, %eax
	jmp	.Lend

.Lless:
	movl	$-1, %eax
	jmp	.Lend

.Lgreater_eq:
	movl	$2, %eax

.Lend:
	/* stack frame teardown */
	movq	%rbp, %rsp
	popq	%rbp
	ret

	/* string ops with rep prefix */
string_ops:
	movq	%rdi, %rsi
	rep movsb
	repne scasb
	ret

	/* 8-bit operations */
byte_ops:
	movb	$0xff, %al
	movb	%al, %cl
	addb	$1, %al
	cmpb	$0, %al
	ret

	/* SSE operations */
sse_func:
	movaps	(%rax), %xmm0
	movaps	%xmm0, (%rbx)
	addps	%xmm1, %xmm0
	mulsd	%xmm2, %xmm0
	ret

	/* RIP-relative (position-independent) */
pic_func:
	movq	myvar(%rip), %rax
	leaq	myvar(%rip), %rbx
	ret

	.data
myvar:
	.quad	0x1234567890abcdef

	.byte	0x01, 0x02, 0x03
	.word	0xabcd
	.long	0xdeadbeef

	.globl	myfunc

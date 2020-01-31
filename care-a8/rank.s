	.file	"rank.c"
	.text
	.p2align 4,,15
	.globl	compute_ranks
	.type	compute_ranks, @function
compute_ranks:
.LFB0:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	cmpl	$4, %esi
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rdx, -8(%rsp)
	movq	%rcx, -32(%rsp)
	movq	%r8, -24(%rsp)
	movq	%r9, -16(%rsp)
	jle	.L65
	leal	-5(%rsi), %eax
	movq	%rdx, %rbp
	movq	%rdi, %rbx
	pxor	%xmm8, %xmm8
	xorl	%r14d, %r14d
	shrl	$2, %eax
	pxor	%xmm9, %xmm9
	leal	4(,%rax,4), %r13d
	movl	%eax, %edx
	salq	$4, %rdx
	leaq	16(%rdi,%rdx), %r12
	movslq	%r13d, %rdx
	leaq	(%rdi,%rdx,4), %rax
	movq	%rax, -40(%rsp)
	leal	-1(%rsi), %eax
	subl	%r13d, %eax
	addq	%rdx, %rax
	leaq	4(%rdi,%rax,4), %r15
	.p2align 4,,10
	.p2align 3
.L54:
	movss	(%rbx), %xmm3
	movq	%rdi, %r9
	movl	$1, %eax
	movss	4(%rbx), %xmm2
	movl	$1, %edx
	movss	8(%rbx), %xmm1
	movl	$1, %ecx
	movss	12(%rbx), %xmm0
	movl	$1, %r8d
	.p2align 4,,10
	.p2align 3
.L35:
	movss	(%r9), %xmm7
	xorl	%r10d, %r10d
	ucomiss	%xmm3, %xmm7
	movss	4(%r9), %xmm6
	movss	8(%r9), %xmm5
	movss	12(%r9), %xmm4
	seta	%r10b
	addl	%r10d, %r8d
	xorl	%r10d, %r10d
	ucomiss	%xmm3, %xmm6
	seta	%r10b
	addl	%r10d, %r8d
	xorl	%r10d, %r10d
	ucomiss	%xmm3, %xmm5
	seta	%r10b
	addl	%r10d, %r8d
	xorl	%r10d, %r10d
	ucomiss	%xmm3, %xmm4
	seta	%r10b
	addl	%r10d, %r8d
	xorl	%r10d, %r10d
	ucomiss	%xmm2, %xmm7
	seta	%r10b
	addl	%r10d, %ecx
	xorl	%r10d, %r10d
	ucomiss	%xmm2, %xmm6
	seta	%r10b
	addl	%r10d, %ecx
	xorl	%r10d, %r10d
	ucomiss	%xmm2, %xmm5
	seta	%r10b
	addl	%r10d, %ecx
	xorl	%r10d, %r10d
	ucomiss	%xmm2, %xmm4
	seta	%r10b
	addl	%r10d, %ecx
	xorl	%r10d, %r10d
	ucomiss	%xmm1, %xmm7
	seta	%r10b
	addl	%r10d, %edx
	xorl	%r10d, %r10d
	ucomiss	%xmm1, %xmm6
	seta	%r10b
	addl	%r10d, %edx
	xorl	%r10d, %r10d
	ucomiss	%xmm1, %xmm5
	seta	%r10b
	addl	%r10d, %edx
	xorl	%r10d, %r10d
	ucomiss	%xmm1, %xmm4
	seta	%r10b
	addl	%r10d, %edx
	xorl	%r10d, %r10d
	ucomiss	%xmm0, %xmm7
	seta	%r10b
	addl	%r10d, %eax
	xorl	%r10d, %r10d
	ucomiss	%xmm0, %xmm6
	seta	%r10b
	addl	%r10d, %eax
	xorl	%r10d, %r10d
	ucomiss	%xmm0, %xmm5
	seta	%r10b
	addl	%r10d, %eax
	xorl	%r10d, %r10d
	ucomiss	%xmm0, %xmm4
	seta	%r10b
	addq	$16, %r9
	addl	%r10d, %eax
	cmpq	%r12, %r9
	jne	.L35
	cmpl	%r13d, %esi
	jle	.L36
	movq	-40(%rsp), %r10
.L45:
	movss	(%r10), %xmm4
	xorl	%r11d, %r11d
	ucomiss	%xmm3, %xmm4
	seta	%r11b
	addl	%r11d, %r8d
	xorl	%r11d, %r11d
	ucomiss	%xmm2, %xmm4
	seta	%r11b
	addl	%r11d, %ecx
	xorl	%r11d, %r11d
	ucomiss	%xmm1, %xmm4
	seta	%r11b
	addl	%r11d, %edx
	xorl	%r11d, %r11d
	ucomiss	%xmm0, %xmm4
	seta	%r11b
	addq	$4, %r10
	addl	%r11d, %eax
	cmpq	%r15, %r10
	jne	.L45
.L36:
	movaps	%xmm3, %xmm4
	movl	%r8d, 0(%rbp)
	movl	%ecx, 4(%rbp)
	ucomiss	.LC1(%rip), %xmm3
	addss	%xmm2, %xmm4
	movl	%edx, 8(%rbp)
	movl	%eax, 12(%rbp)
	addss	%xmm1, %xmm4
	addss	%xmm0, %xmm4
	addss	%xmm4, %xmm9
	jb	.L46
	addss	%xmm3, %xmm8
	addl	$1, %r14d
.L46:
	ucomiss	.LC1(%rip), %xmm2
	jb	.L48
	addss	%xmm2, %xmm8
	addl	$1, %r14d
.L48:
	ucomiss	.LC1(%rip), %xmm1
	jb	.L50
	addss	%xmm1, %xmm8
	addl	$1, %r14d
.L50:
	ucomiss	.LC1(%rip), %xmm0
	jb	.L52
	addss	%xmm0, %xmm8
	addl	$1, %r14d
.L52:
	addq	$16, %rbx
	addq	$16, %rbp
	cmpq	%r9, %rbx
	jne	.L54
.L2:
	cmpl	%r13d, %esi
	jle	.L55
	leal	-1(%rsi), %eax
	movq	-8(%rsp), %r9
	movslq	%r13d, %r13
	leaq	4(%rdi,%rax,4), %r8
.L61:
	movss	(%rdi,%r13,4), %xmm1
	ucomiss	.LC1(%rip), %xmm1
	addss	%xmm1, %xmm9
	jb	.L56
	addss	%xmm1, %xmm8
	addl	$1, %r14d
.L56:
	movq	%rdi, %rax
	movl	$1, %edx
	.p2align 4,,10
	.p2align 3
.L60:
	movss	(%rax), %xmm0
	xorl	%ecx, %ecx
	ucomiss	%xmm1, %xmm0
	seta	%cl
	addq	$4, %rax
	addl	%ecx, %edx
	cmpq	%rax, %r8
	jne	.L60
	movl	%edx, (%r9,%r13,4)
	addq	$1, %r13
	cmpl	%r13d, %esi
	jg	.L61
.L62:
	pxor	%xmm0, %xmm0
	cvtsi2ss	%esi, %xmm0
	divss	%xmm0, %xmm9
.L63:
	testl	%r14d, %r14d
	je	.L64
	pxor	%xmm0, %xmm0
	cvtsi2ss	%r14d, %xmm0
	divss	%xmm0, %xmm8
.L64:
	movq	-16(%rsp), %rax
	movl	%r14d, (%rax)
	movq	-32(%rsp), %rax
	movss	%xmm9, (%rax)
	movq	-24(%rsp), %rax
	movss	%xmm8, (%rax)
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L55:
	.cfi_restore_state
	testl	%esi, %esi
	jle	.L63
	jmp	.L62
	.p2align 4,,10
	.p2align 3
.L65:
	pxor	%xmm8, %xmm8
	xorl	%r14d, %r14d
	pxor	%xmm9, %xmm9
	xorl	%r13d, %r13d
	jmp	.L2
	.cfi_endproc
.LFE0:
	.size	compute_ranks, .-compute_ranks
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC1:
	.long	1112014848
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~16.04~ppa1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits

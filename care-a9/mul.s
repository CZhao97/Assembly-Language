	.file	"mul.c"
	.text
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"Incompatible multiplication: %d x %d times a %d x %d\n"
	.text
	.p2align 4,,15
	.globl	mul
	.type	mul, @function
mul:
.LFB38:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movl	%r9d, %r13d
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movl	%esi, %ebp
	movl	%edx, %r12d
	movl	%r8d, %ebx
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	cmpl	%r8d, %edx
	movq	%rdi, 8(%rsp)
	jne	.L28
	movl	%r9d, %esi
	movl	%ebp, %edi
	movq	%rcx, %r15
	call	newMatrix
	testq	%rax, %rax
	movq	%rax, %r14
	je	.L1
	movl	%r12d, %esi
	movl	%r13d, %edi
	call	newMatrix
	testq	%rax, %rax
	je	.L1
	testl	%r13d, %r13d
	jle	.L6
	leal	-1(%r13), %edx
	leal	-1(%r12), %r9d
	xorl	%ecx, %ecx
	leaq	4(,%rdx,4), %r10
	addq	$1, %r9
	.p2align 4,,10
	.p2align 3
.L7:
	testl	%ebx, %ebx
	jle	.L10
	movq	(%rax,%rcx,2), %rdi
	xorl	%edx, %edx
	.p2align 4,,10
	.p2align 3
.L8:
	movq	(%r15,%rdx,8), %rsi
	movl	(%rsi,%rcx), %esi
	movl	%esi, (%rdi,%rdx,4)
	addq	$1, %rdx
	cmpq	%rdx, %r9
	jne	.L8
.L10:
	addq	$4, %rcx
	cmpq	%rcx, %r10
	jne	.L7
.L6:
	testl	%ebp, %ebp
	jle	.L11
	movq	8(%rsp), %rdi
	leal	-1(%rbp), %ecx
	leal	-1(%r13), %r15d
	movq	%r14, %rdx
	movq	%r14, 8(%rsp)
	addq	$1, %r15
	leaq	8(%rdi,%rcx,8), %rsi
	leal	-1(%r12), %ecx
	leaq	4(,%rcx,4), %rbx
	movq	%rsi, %r14
	.p2align 4,,10
	.p2align 3
.L12:
	testl	%r13d, %r13d
	jle	.L14
	movq	(%rdx), %rbp
	xorl	%r11d, %r11d
	.p2align 4,,10
	.p2align 3
.L17:
	xorl	%r8d, %r8d
	testl	%r12d, %r12d
	jle	.L16
	movq	(%rdi), %r10
	movq	(%rax,%r11,8), %r9
	xorl	%ecx, %ecx
	xorl	%r8d, %r8d
	.p2align 4,,10
	.p2align 3
.L13:
	movl	(%r10,%rcx), %esi
	imull	(%r9,%rcx), %esi
	addq	$4, %rcx
	addl	%esi, %r8d
	cmpq	%rcx, %rbx
	jne	.L13
.L16:
	movl	%r8d, 0(%rbp,%r11,4)
	addq	$1, %r11
	cmpq	%r11, %r15
	jne	.L17
.L14:
	addq	$8, %rdi
	addq	$8, %rdx
	cmpq	%r14, %rdi
	jne	.L12
	movq	8(%rsp), %r14
.L11:
	movq	%rax, %rdi
	call	free
.L1:
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	movq	%r14, %rax
	popq	%rbx
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
.L28:
	.cfi_restore_state
	movl	%edx, %ecx
	movl	$1, %edi
	movl	%esi, %edx
	xorl	%eax, %eax
	movl	$.LC0, %esi
	call	__printf_chk
	orl	$-1, %edi
	call	exit
	.cfi_endproc
.LFE38:
	.size	mul, .-mul
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~16.04~ppa1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits

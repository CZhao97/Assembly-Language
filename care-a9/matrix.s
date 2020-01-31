	.file	"matrix.c"
	.text
	.p2align 4,,15
	.globl	newMatrix
	.type	newMatrix, @function
newMatrix:
.LFB38:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	movslq	%edi, %rdi
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	%rdi, %rbp
	salq	$3, %rdi
	movl	%esi, %ebx
	call	malloc
	testq	%rax, %rax
	movq	%rax, %r12
	je	.L1
	movl	%ebp, %edi
	imull	%ebx, %edi
	movslq	%edi, %rdi
	salq	$2, %rdi
	call	malloc
	testq	%rax, %rax
	je	.L3
	testl	%ebp, %ebp
	jle	.L1
	leal	-1(%rbp), %ecx
	movslq	%ebx, %rsi
	movq	%r12, %rdx
	salq	$2, %rsi
	leaq	8(%r12,%rcx,8), %rcx
	.p2align 4,,10
	.p2align 3
.L5:
	movq	%rax, (%rdx)
	addq	$8, %rdx
	addq	%rsi, %rax
	cmpq	%rcx, %rdx
	jne	.L5
.L1:
	movq	%r12, %rax
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L3:
	.cfi_restore_state
	movq	%r12, %rdi
	xorl	%r12d, %r12d
	call	free
	jmp	.L1
	.cfi_endproc
.LFE38:
	.size	newMatrix, .-newMatrix
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	" %3d"
	.text
	.p2align 4,,15
	.globl	printMatrix
	.type	printMatrix, @function
printMatrix:
.LFB39:
	.cfi_startproc
	testl	%esi, %esi
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	jle	.L13
	leal	-1(%rsi), %eax
	movl	%edx, %r12d
	movq	%rdi, %r14
	leaq	8(%rdi,%rax,8), %r13
	leal	-1(%rdx), %eax
	leaq	4(,%rax,4), %rbp
	.p2align 4,,10
	.p2align 3
.L14:
	xorl	%ebx, %ebx
	testl	%r12d, %r12d
	jle	.L16
	.p2align 4,,10
	.p2align 3
.L15:
	movq	(%r14), %rax
	movl	$.LC0, %esi
	movl	$1, %edi
	movl	(%rax,%rbx), %edx
	xorl	%eax, %eax
	addq	$4, %rbx
	call	__printf_chk
	cmpq	%rbx, %rbp
	jne	.L15
.L16:
	movq	stdout(%rip), %rsi
	movl	$10, %edi
	addq	$8, %r14
	call	_IO_putc
	cmpq	%r13, %r14
	jne	.L14
.L13:
	popq	%rbx
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	movq	stdout(%rip), %rsi
	movl	$10, %edi
	jmp	_IO_putc
	.cfi_endproc
.LFE39:
	.size	printMatrix, .-printMatrix
	.p2align 4,,15
	.globl	freeMatrix
	.type	freeMatrix, @function
freeMatrix:
.LFB40:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdi, %rbx
	movq	(%rdi), %rdi
	call	free
	movq	%rbx, %rdi
	popq	%rbx
	.cfi_def_cfa_offset 8
	jmp	free
	.cfi_endproc
.LFE40:
	.size	freeMatrix, .-freeMatrix
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~16.04~ppa1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits

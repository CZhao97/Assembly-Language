	.file	"main.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"The trace is %ld.\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB38:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	xorl	%edi, %edi
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	xorl	%eax, %eax
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movl	$1717986919, %r12d
	xorl	%ebx, %ebx
	subq	$8, %rsp
	.cfi_def_cfa_offset 64
	call	time
	movl	%eax, %edi
	call	srand
	movl	$512, %esi
	movl	$512, %edi
	call	newMatrix
	movl	$512, %esi
	movq	%rax, %r13
	movl	$512, %edi
	call	newMatrix
	movq	%r13, %r15
	movq	%rax, %rbp
	.p2align 4,,10
	.p2align 3
.L2:
	xorl	%r14d, %r14d
	.p2align 4,,10
	.p2align 3
.L3:
	call	rand
	movl	%eax, %ecx
	imull	%r12d
	movl	%ecx, %eax
	sarl	$31, %eax
	sarl	$2, %edx
	subl	%eax, %edx
	leal	(%rdx,%rdx,4), %eax
	addl	%eax, %eax
	subl	%eax, %ecx
	movq	(%r15), %rax
	subl	$5, %ecx
	movl	%ecx, (%rax,%r14)
	movq	0(%rbp,%r14,2), %rax
	addq	$4, %r14
	cmpq	$2048, %r14
	movl	%ecx, (%rax,%rbx)
	jne	.L3
	addq	$4, %rbx
	addq	$8, %r15
	cmpq	$2048, %rbx
	jne	.L2
	movl	$10, %r12d
	xorl	%ebx, %ebx
.L4:
	movl	$512, %edx
	movl	$512, %r9d
	movl	$512, %r8d
	movq	%rbp, %rcx
	movl	$512, %esi
	movq	%r13, %rdi
	call	mul
	xorl	%edx, %edx
	.p2align 4,,10
	.p2align 3
.L5:
	movq	(%rax,%rdx,2), %rcx
	movslq	(%rcx,%rdx), %rcx
	addq	$4, %rdx
	addq	%rcx, %rbx
	cmpq	$2048, %rdx
	jne	.L5
	movq	%rax, %rdi
	call	freeMatrix
	subl	$1, %r12d
	jne	.L4
	movq	%rbx, %rdx
	movl	$.LC0, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	movq	%r13, %rdi
	call	freeMatrix
	addq	$8, %rsp
	.cfi_def_cfa_offset 56
	movq	%rbp, %rdi
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
	jmp	freeMatrix
	.cfi_endproc
.LFE38:
	.size	main, .-main
	.comm	total,8,8
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~16.04~ppa1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits

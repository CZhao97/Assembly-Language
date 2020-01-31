	.file	"main.c"
	.text
	.p2align 4,,15
	.globl	lsearch_1
	.type	lsearch_1, @function
lsearch_1:
.LFB39:
	.cfi_startproc
	testl	%esi, %esi
	movl	$-1, %eax
	jle	.L1
	cmpl	(%rdi), %edx
	je	.L6
	subl	$1, %esi
	movl	$1, %ecx
	addq	$1, %rsi
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L4:
	addq	$1, %rcx
	cmpl	%edx, -4(%rdi,%rcx,4)
	je	.L1
.L3:
	cmpq	%rsi, %rcx
	movl	%ecx, %eax
	jne	.L4
	movl	$-1, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L6:
	xorl	%eax, %eax
.L1:
	rep ret
	.cfi_endproc
.LFE39:
	.size	lsearch_1, .-lsearch_1
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Initializing array . . ."
.LC1:
	.string	"Array initialized. . ."
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"Starting test of function %d . . .\n"
	.section	.rodata.str1.1
.LC3:
	.string	"Error: A[N] not consistent.\n"
	.section	.rodata.str1.8
	.align 8
.LC4:
	.string	"Error: A[N-1] not consistent.\n"
	.align 8
.LC5:
	.string	"It took %ld microseconds to run function %d.\n"
	.section	.rodata.str1.1
.LC6:
	.string	"Totalling work %d . . .\n"
	.section	.rodata.str1.8
	.align 8
.LC7:
	.string	"Error: Results of searches disagree.\n"
	.section	.rodata.str1.1
.LC8:
	.string	"Total misses = %ld, %ld\n"
	.section	.rodata.str1.8
	.align 8
.LC9:
	.string	"Total of positions searched = %ld, %ld\n"
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
	movl	$.LC0, %edi
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movl	$A+4, %r13d
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movl	$1, %r12d
	movl	$A, %ebx
	movl	$-1431655765, %ebp
	subq	$3544, %rsp
	.cfi_def_cfa_offset 3600
	movq	%fs:40, %rax
	movq	%rax, 3528(%rsp)
	xorl	%eax, %eax
	movq	$lsearch_1, 304(%rsp)
	movq	$lsearch_2, 312(%rsp)
	call	puts
	xorl	%edi, %edi
	movl	$0, A(%rip)
	call	times
	movl	%eax, %edi
	call	srand
	.p2align 4,,10
	.p2align 3
.L9:
	movl	%r12d, %eax
	mull	%ebp
	shrl	%edx
	leal	(%rdx,%rdx,2), %eax
	leal	(%r12,%r12,2), %edx
	cmpl	%eax, %r12d
	sete	%al
	addl	$1, %r12d
	addq	$4, %r13
	movzbl	%al, %eax
	addl	%edx, %eax
	movl	%eax, -4(%r13)
	call	rand
	movl	%eax, %r14d
	call	rand
	movslq	%r14d, %rcx
	movl	%r14d, %edx
	imulq	$-2147418109, %rcx, %rcx
	sarl	$31, %edx
	shrq	$32, %rcx
	addl	%r14d, %ecx
	sarl	$14, %ecx
	subl	%edx, %ecx
	movl	%ecx, %edx
	sall	$15, %edx
	subl	%ecx, %edx
	movslq	%eax, %rcx
	imulq	$-2147450879, %rcx, %rcx
	subl	%edx, %r14d
	cltd
	sall	$16, %r14d
	shrq	$32, %rcx
	addl	%eax, %ecx
	sarl	$15, %ecx
	subl	%edx, %ecx
	movl	%ecx, %edx
	sall	$16, %edx
	subl	%ecx, %edx
	subl	%edx, %eax
	orl	%r14d, %eax
	cltd
	idivl	%r12d
	movl	-4(%r13), %eax
	movslq	%edx, %rdx
	movl	A(,%rdx,4), %ecx
	movl	%ecx, -4(%r13)
	cmpl	$20000000, %r12d
	movl	%eax, A(,%rdx,4)
	jne	.L9
	movl	$A+80000000, %eax
	movl	(%rax), %r13d
	movabsl	A+79999996, %eax
	leaq	320(%rsp), %r15
	movl	$.LC1, %edi
	movl	$lsearch_1, %r12d
	movl	%eax, 8(%rsp)
	movq	%r15, %rbp
	call	puts
	movq	$1, (%rsp)
.L15:
	movq	(%rsp), %rax
	movl	$.LC2, %esi
	movl	$1, %edi
	xorl	%r14d, %r14d
	movl	%eax, %edx
	movl	%eax, 12(%rsp)
	xorl	%eax, %eax
	call	__printf_chk
	leaq	16(%rsp), %rsi
	xorl	%edi, %edi
	call	getrusage
	jmp	.L13
	.p2align 4,,10
	.p2align 3
.L10:
	movl	8(%rsp), %eax
	cmpl	%eax, 79999996(%rbx)
	jne	.L35
	addq	$1, %r14
	cmpq	$400, %r14
	je	.L36
.L13:
	movl	%r14d, %edx
	movl	$20000000, %esi
	movl	$A, %edi
	call	*%r12
	movl	%eax, 0(%rbp,%r14,4)
	cmpl	%r13d, 80000000(%rbx)
	je	.L10
	movl	$.LC3, %edi
	call	perror
.L8:
	movq	3528(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L37
	addq	$3544, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
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
.L35:
	.cfi_restore_state
	movl	$.LC4, %edi
	call	perror
	jmp	.L8
.L36:
	leaq	160(%rsp), %rsi
	xorl	%edi, %edi
	addq	$1600, %rbp
	call	getrusage
	movq	160(%rsp), %rdx
	subq	16(%rsp), %rdx
	xorl	%eax, %eax
	movl	12(%rsp), %ecx
	movl	$.LC5, %esi
	movl	$1, %edi
	imulq	$1000000, %rdx, %rdx
	addq	168(%rsp), %rdx
	subq	24(%rsp), %rdx
	call	__printf_chk
	cmpq	$2, (%rsp)
	jne	.L38
	movl	$3, %edx
	movl	$.LC6, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	xorl	%r12d, %r12d
	xorl	%ebx, %ebx
	call	__printf_chk
	xorl	%ebp, %ebp
	xorl	%edx, %edx
	xorl	%ecx, %ecx
	leaq	1600(%r15), %r9
	xorl	%r10d, %r10d
	xorl	%r13d, %r13d
	xorl	%r11d, %r11d
	jmp	.L16
	.p2align 4,,10
	.p2align 3
.L41:
	movslq	%esi, %rax
	addq	%rax, %rbx
	movl	1600(%r15), %eax
	cmpl	$-1, %eax
	je	.L39
.L33:
	movslq	%eax, %rdi
	addq	%rdi, %rbp
	cmpl	%esi, %eax
	jne	.L40
.L18:
	addq	$4, %r15
	cmpq	%r9, %r15
	je	.L19
.L16:
	movl	(%r15), %esi
	cmpl	$-1, %esi
	jne	.L41
	movl	1600(%r15), %eax
	addq	$1, %r10
	addq	$20000000, %rbx
	movl	$1, %r12d
	cmpl	$-1, %eax
	jne	.L33
.L39:
	addq	$1, %r11
	addq	$20000000, %rbp
	cmpl	%esi, %eax
	movl	$1, %r13d
	je	.L18
.L40:
	movl	$.LC7, %edi
	call	perror
	jmp	.L8
.L19:
	testb	%r13b, %r13b
	movl	$.LC8, %esi
	movl	$1, %edi
	cmovne	%r11, %rcx
	testb	%r12b, %r12b
	cmovne	%r10, %rdx
	xorl	%eax, %eax
	call	__printf_chk
	movq	%rbp, %rcx
	movq	%rbx, %rdx
	movl	$.LC9, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	jmp	.L8
.L38:
	movq	312(%rsp), %r12
	movq	$2, (%rsp)
	jmp	.L15
.L37:
	call	__stack_chk_fail
	.cfi_endproc
.LFE38:
	.size	main, .-main
	.comm	A,80000000,32
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~16.04~ppa1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits

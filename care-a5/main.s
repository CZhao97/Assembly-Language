	.file	"main.c"
	.text
	.p2align 4,,15
	.globl	cmp
	.type	cmp, @function
cmp:
.LFB39:
	.cfi_startproc
	movss	(%rdi), %xmm1
	movl	$-1, %eax
	movss	(%rsi), %xmm0
	ucomiss	%xmm1, %xmm0
	ja	.L1
	ucomiss	%xmm0, %xmm1
	jp	.L1
	movl	$0, %eax
	je	.L1
	movl	$1, %eax
.L1:
	rep ret
	.cfi_endproc
.LFE39:
	.size	cmp, .-cmp
	.p2align 4,,15
	.globl	u2f
	.type	u2f, @function
u2f:
.LFB38:
	.cfi_startproc
	movl	%edi, -4(%rsp)
	movss	-4(%rsp), %xmm0
	ret
	.cfi_endproc
.LFE38:
	.size	u2f, .-u2f
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC2:
	.string	"Test Case 1:\n"
.LC4:
	.string	"The total before sorting: "
.LC5:
	.string	" The total after sorting: "
.LC6:
	.string	"\nTest Case 2:\n"
.LC8:
	.string	""
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB40:
	.cfi_startproc
	subq	$328, %rsp
	.cfi_def_cfa_offset 336
	movl	$.LC2, %edi
	movq	%fs:40, %rax
	movq	%rax, 312(%rsp)
	xorl	%eax, %eax
	call	puts
	movss	.LC0(%rip), %xmm0
	leaq	20(%rsp), %rax
	movss	%xmm0, 16(%rsp)
	leaq	112(%rsp), %rdx
	movss	.LC3(%rip), %xmm1
	.p2align 4,,10
	.p2align 3
.L12:
	movss	%xmm1, (%rax)
	addq	$4, %rax
	addss	%xmm1, %xmm0
	cmpq	%rax, %rdx
	jne	.L12
	movl	$.LC4, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	movss	%xmm0, 12(%rsp)
	call	__printf_chk
	movss	12(%rsp), %xmm0
	call	f_printbits
	movq	stdout(%rip), %rsi
	movl	$10, %edi
	call	_IO_putc
	movl	$.LC5, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	leaq	16(%rsp), %rdi
	movl	$cmp, %ecx
	movl	$4, %edx
	movl	$24, %esi
	call	qsort
	leaq	16(%rsp), %rdi
	movl	$24, %esi
	call	sum_float
	call	f_printbits
	movq	stdout(%rip), %rsi
	movl	$10, %edi
	call	_IO_putc
	movl	$.LC6, %edi
	call	puts
	leaq	112(%rsp), %rsi
	xorl	%ecx, %ecx
	movl	$2, %r9d
	pxor	%xmm0, %xmm0
	movl	$613566757, %edi
	movsd	.LC7(%rip), %xmm2
	movl	$-1431655765, %r8d
	jmp	.L13
	.p2align 4,,10
	.p2align 3
.L15:
	movl	%ecx, %eax
	xorl	%r9d, %r9d
	mull	%r8d
	shrl	%edx
	leal	(%rdx,%rdx,2), %eax
	cmpl	%eax, %ecx
	sete	%r9b
	addq	$4, %rsi
	addl	$1, %r9d
.L13:
	movl	%ecx, %eax
	pxor	%xmm1, %xmm1
	mull	%edi
	movl	%ecx, %eax
	subl	%edx, %eax
	shrl	%eax
	addl	%eax, %edx
	shrl	$2, %edx
	leal	0(,%rdx,8), %eax
	subl	%edx, %eax
	cmpl	%eax, %ecx
	sete	%al
	addl	$1, %ecx
	movzbl	%al, %eax
	addl	%r9d, %eax
	cmpl	$50, %ecx
	cvtsi2sd	%eax, %xmm1
	mulsd	%xmm2, %xmm1
	cvtsd2ss	%xmm1, %xmm1
	movss	%xmm1, (%rsi)
	addss	%xmm1, %xmm0
	jne	.L15
	movl	$.LC4, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	movss	%xmm0, 12(%rsp)
	call	__printf_chk
	movss	12(%rsp), %xmm0
	call	f_printbits
	movq	stdout(%rip), %rsi
	movl	$10, %edi
	call	_IO_putc
	movl	$.LC5, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	leaq	112(%rsp), %rdi
	movl	$cmp, %ecx
	movl	$4, %edx
	movl	$50, %esi
	call	qsort
	leaq	112(%rsp), %rdi
	movl	$50, %esi
	call	sum_float
	call	f_printbits
	movq	stdout(%rip), %rsi
	movl	$10, %edi
	call	_IO_putc
	movl	$.LC8, %edi
	call	puts
	movq	312(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L20
	addq	$328, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L20:
	.cfi_restore_state
	call	__stack_chk_fail
	.cfi_endproc
.LFE40:
	.size	main, .-main
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC0:
	.long	1348468751
	.align 4
.LC3:
	.long	1140850690
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC7:
	.long	2576980378
	.long	1069128089
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~16.04~ppa1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits

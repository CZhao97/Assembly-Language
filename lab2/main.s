	.file	"main.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subq	$32, %rsp
	.cfi_def_cfa_offset 48
	movq	%fs:40, %rax
	movq	%rax, 24(%rsp)
	xorl	%eax, %eax
	movabsq	$7020664739288410196, %rax
	movabsq	$64267359385970, %rdx
	movq	%rax, (%rsp)
	movq	%rdx, 8(%rsp)
	movq	%rsp, %rdi
	call	puts
	movl	$0, %ebx
	movq	%rbx, %rsi
	movl	$4660, %edi
	call	cvt2bitstr
	movq	%rbx, %rdi
	call	puts
	movq	24(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L4
	addq	$32, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L4:
	.cfi_restore_state
	call	__stack_chk_fail
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~16.04~ppa1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits

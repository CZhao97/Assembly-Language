	.file	"main.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Original signal:  "
.LC1:
	.string	"%4d"
.LC2:
	.string	"Convolved signal: "
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB23:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	subq	$48, %rsp
	.cfi_def_cfa_offset 80
	movq	%fs:40, %rax
	movq	%rax, 40(%rsp)
	xorl	%eax, %eax
	leaq	25(%rsp), %rax
	movq	%rsp, %rbp
	movq	%rsp, %rbx
	.p2align 4,,10
	.p2align 3
.L2:
	movb	$-128, (%rbx)
	addq	$1, %rbx
	cmpq	%rax, %rbx
	jne	.L2
	movl	$.LC0, %edi
	movl	$signal, %r12d
	call	puts
	.p2align 4,,10
	.p2align 3
.L3:
	movsbl	(%r12), %edx
	xorl	%eax, %eax
	movl	$.LC1, %esi
	movl	$1, %edi
	addq	$1, %r12
	call	__printf_chk
	cmpq	$signal+15, %r12
	jne	.L3
	movq	stdout(%rip), %rsi
	movl	$10, %edi
	call	_IO_putc
	movq	stdout(%rip), %rsi
	movl	$10, %edi
	call	_IO_putc
	leaq	4(%rsp), %r8
	movl	$signal, %edi
	movl	$3, %ecx
	movl	$h, %edx
	movl	$15, %esi
	call	conv_arr
	movl	$.LC2, %edi
	call	puts
	.p2align 4,,10
	.p2align 3
.L4:
	movsbl	0(%rbp), %edx
	xorl	%eax, %eax
	movl	$.LC1, %esi
	movl	$1, %edi
	addq	$1, %rbp
	call	__printf_chk
	cmpq	%rbx, %rbp
	jne	.L4
	movq	stdout(%rip), %rsi
	movl	$10, %edi
	call	_IO_putc
	movq	stdout(%rip), %rsi
	movl	$10, %edi
	call	_IO_putc
	movq	40(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L11
	addq	$48, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L11:
	.cfi_restore_state
	call	__stack_chk_fail
	.cfi_endproc
.LFE23:
	.size	main, .-main
	.globl	h
	.data
	.type	h, @object
	.size	h, 3
h:
	.byte	1
	.byte	2
	.byte	3
	.globl	signal
	.align 8
	.type	signal, @object
	.size	signal, 15
signal:
	.byte	0
	.byte	4
	.byte	8
	.byte	6
	.byte	5
	.byte	6
	.byte	7
	.byte	4
	.byte	1
	.byte	-2
	.byte	-5
	.byte	-7
	.byte	-4
	.byte	-2
	.byte	0
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~16.04~ppa1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits

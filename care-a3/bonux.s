	.file	"bonux.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Original signal:  "
.LC1:
	.string	"%4d"
.LC2:
	.string	"Convolved signal: "
.LC3:
	.string	"   OF"
.LC4:
	.string	" %4d"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB23:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movl	$.LC0, %edi
	movl	$signal, %ebx
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	call	puts
	.p2align 4,,10
	.p2align 3
.L2:
	movsbl	(%rbx), %edx
	xorl	%eax, %eax
	movl	$.LC1, %esi
	movl	$1, %edi
	addq	$1, %rbx
	call	__printf_chk
	cmpq	$signal+20, %rbx
	jne	.L2
	movq	stdout(%rip), %rsi
	movl	$10, %edi
	xorl	%ebx, %ebx
	movl	$4, %ebp
	call	_IO_putc
	movl	$.LC2, %edi
	call	puts
	jmp	.L5
	.p2align 4,,10
	.p2align 3
.L11:
	xorl	%eax, %eax
	movl	$.LC3, %esi
	movl	$1, %edi
	addl	$1, %ebx
	call	__printf_chk
	cmpl	$20, %ebx
	je	.L10
.L5:
	cmpl	$4, %ebx
	movl	%ebp, %edx
	movl	%ebx, %edi
	cmovle	%ebx, %edx
	movl	$h, %esi
	addl	$1, %edx
	subl	%edx, %edi
	movslq	%edi, %rdi
	addq	$signal+1, %rdi
	call	conv
#APP
# 29 "bonux.c" 1
	movl %edx, %ecx
	
# 0 "" 2
#NO_APP
	testl	%ecx, %ecx
	jne	.L11
	movsbl	%al, %edx
	movl	$.LC4, %esi
	xorl	%eax, %eax
	movl	$1, %edi
	addl	$1, %ebx
	call	__printf_chk
	cmpl	$20, %ebx
	jne	.L5
.L10:
	movq	stdout(%rip), %rsi
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	movl	$10, %edi
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	jmp	_IO_putc
	.cfi_endproc
.LFE23:
	.size	main, .-main
	.globl	h
	.data
	.type	h, @object
	.size	h, 5
h:
	.byte	-5
	.byte	2
	.byte	6
	.byte	2
	.byte	-5
	.globl	signal
	.align 16
	.type	signal, @object
	.size	signal, 20
signal:
	.byte	0
	.byte	0
	.byte	0
	.byte	40
	.byte	80
	.byte	60
	.byte	50
	.byte	60
	.byte	70
	.byte	40
	.byte	10
	.byte	-20
	.byte	-50
	.byte	-70
	.byte	-40
	.byte	-20
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~16.04~ppa1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits

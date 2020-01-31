	.file	"main.c"
	.text
	.p2align 4,,15
	.globl	get_byte_by_order
	.type	get_byte_by_order, @function
get_byte_by_order:
.LFB23:
	.cfi_startproc
	leal	0(,%rsi,8), %ecx
	sarl	%cl, %edi
	movzbl	%dil, %eax
	ret
	.cfi_endproc
.LFE23:
	.size	get_byte_by_order, .-get_byte_by_order
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"x = %#.08x\n"
.LC1:
	.string	"x = %d\n"
.LC2:
	.string	"y = %#.08x\n"
.LC3:
	.string	"y = %u\n"
.LC4:
	.string	"x = "
.LC5:
	.string	"%02x"
.LC6:
	.string	"y = "
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	movl	x(%rip), %edx
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$.LC0, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	xorl	%ebx, %ebx
	call	__printf_chk
	movl	x(%rip), %edx
	movl	$.LC1, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	movl	y(%rip), %edx
	movl	$.LC2, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	movl	y(%rip), %edx
	movl	$.LC3, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	movl	$.LC4, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
.L4:
	movl	x(%rip), %edx
	movl	%ebx, %ecx
	xorl	%eax, %eax
	movl	$.LC5, %esi
	movl	$1, %edi
	addl	$8, %ebx
	sarl	%cl, %edx
	movzbl	%dl, %edx
	call	__printf_chk
	cmpl	$32, %ebx
	jne	.L4
	movq	stdout(%rip), %rsi
	movl	$10, %edi
	xorl	%ebx, %ebx
	call	_IO_putc
	movl	$.LC4, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
.L5:
	movl	%ebx, %esi
	movl	$x, %edi
	addl	$1, %ebx
	call	get_byte_by_addr
	movl	$.LC5, %esi
	movl	%eax, %edx
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	cmpl	$4, %ebx
	jne	.L5
	movq	stdout(%rip), %rsi
	movl	$10, %edi
	xorl	%ebx, %ebx
	call	_IO_putc
	movl	$.LC6, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
.L6:
	movl	y(%rip), %edx
	movl	%ebx, %ecx
	xorl	%eax, %eax
	movl	$.LC5, %esi
	movl	$1, %edi
	addl	$8, %ebx
	sarl	%cl, %edx
	movzbl	%dl, %edx
	call	__printf_chk
	cmpl	$32, %ebx
	jne	.L6
	movq	stdout(%rip), %rsi
	movl	$10, %edi
	xorl	%ebx, %ebx
	call	_IO_putc
	movl	$.LC6, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
.L7:
	movl	%ebx, %esi
	movl	$y, %edi
	addl	$1, %ebx
	call	get_byte_by_addr
	movl	$.LC5, %esi
	movl	%eax, %edx
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	cmpl	$4, %ebx
	jne	.L7
	popq	%rbx
	.cfi_def_cfa_offset 8
	movq	stdout(%rip), %rsi
	movl	$10, %edi
	jmp	_IO_putc
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.globl	y
	.data
	.align 4
	.type	y, @object
	.size	y, 4
y:
	.long	-42
	.globl	x
	.align 4
	.type	x, @object
	.size	x, 4
x:
	.long	19088743
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~16.04~ppa1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits

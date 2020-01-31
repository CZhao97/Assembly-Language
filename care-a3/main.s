	.file	"main.c"
	.text
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"The integer square root of %f and %d is %f.\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB23:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$10, %edi
	movss	.LC0(%rip), %xmm0
	call	sqrt
	pxor	%xmm1, %xmm1
	movl	$10, %edx
	movl	$.LC2, %esi
	movl	$1, %edi
	movl	$2, %eax
	cvtss2sd	%xmm0, %xmm1
	movsd	.LC1(%rip), %xmm0
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	jmp	__printf_chk
	.cfi_endproc
.LFE23:
	.size	main, .-main
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC0:
	.long	1092731535
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	3758096384
	.long	1076115537
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~16.04~ppa1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits

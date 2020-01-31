	.file	"subprog.c"
	.text
	.globl	cvt2bitstr
	.type	cvt2bitstr, @function
cvt2bitstr:
.LFB0:
	.cfi_startproc
	movl	$0, %eax
	jmp	.L2
.L3:
	movl	%edi, %edx
	shrw	$15, %dx
	movslq	%eax, %rcx
	orl	$48, %edx
	movb	%dl, (%rsi,%rcx)
	addl	%edi, %edi
	addl	$1, %eax
.L2:
	cmpl	$15, %eax
	jle	.L3
	movb	$0, 16(%rsi)
	ret
	.cfi_endproc
.LFE0:
	.size	cvt2bitstr, .-cvt2bitstr
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~16.04~ppa1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits

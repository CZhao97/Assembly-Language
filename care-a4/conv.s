	.file	"conv.c"
	.text
	.p2align 4,,15
	.globl	conv
	.type	conv, @function
conv:
.LFB0:
	.cfi_startproc
	testl	%edx, %edx
	jle	.L4
	movslq	%edx, %rax
	leaq	-1(%rsi,%rax), %rcx
	leaq	-2(%rsi,%rax), %rsi
	leal	-1(%rdx), %eax
	xorl	%edx, %edx
	subq	%rax, %rsi
	.p2align 4,,10
	.p2align 3
.L3:
	movzbl	(%rdi), %eax
	subq	$1, %rcx
	addq	$1, %rdi
	mulb	1(%rcx)
	addl	%eax, %edx
	cmpq	%rcx, %rsi
	jne	.L3
	movl	%edx, %eax
	ret
	.p2align 4,,10
	.p2align 3
.L4:
	xorl	%edx, %edx
	movl	%edx, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	conv, .-conv
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~16.04~ppa1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits

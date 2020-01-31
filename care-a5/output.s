	.file	"output.c"
	.text
	.p2align 4,,15
	.globl	bitstr
	.type	bitstr, @function
bitstr:
.LFB23:
	.cfi_startproc
	movslq	%edx, %rcx
	testl	%edx, %edx
	movq	%rsi, %rax
	movb	$0, (%rsi,%rcx)
	leal	-1(%rdx), %ecx
	je	.L2
	movslq	%ecx, %rsi
	movl	%ecx, %ecx
	leaq	-1(%rax,%rsi), %r8
	leaq	(%rax,%rsi), %rdx
	subq	%rcx, %r8
	.p2align 4,,10
	.p2align 3
.L3:
	movl	%edi, %ecx
	subq	$1, %rdx
	shrq	%rdi
	andl	$1, %ecx
	addl	$48, %ecx
	movb	%cl, 1(%rdx)
	cmpq	%r8, %rdx
	jne	.L3
.L2:
	rep ret
	.cfi_endproc
.LFE23:
	.size	bitstr, .-bitstr
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%8x"
	.text
	.p2align 4,,15
	.globl	f_printbits
	.type	f_printbits, @function
f_printbits:
.LFB24:
	.cfi_startproc
	movd	%xmm0, %edx
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	jmp	__printf_chk@PLT
	.cfi_endproc
.LFE24:
	.size	f_printbits, .-f_printbits
	.section	.rodata.str1.1
.LC1:
	.string	"%e\n"
.LC2:
	.string	"%e = %c 0.%s x 2^-126\n"
.LC3:
	.string	"%e = %c 1.%s x 2^%d\n"
	.text
	.p2align 4,,15
	.globl	f_print
	.type	f_print, @function
f_print:
.LFB25:
	.cfi_startproc
	movd	%xmm0, %edx
	subq	$40, %rsp
	.cfi_def_cfa_offset 48
	movd	%xmm0, %r8d
	movq	%fs:40, %rax
	movq	%rax, 24(%rsp)
	xorl	%eax, %eax
	shrl	$31, %edx
	movd	%xmm0, %eax
	cvtss2sd	%xmm0, %xmm0
	cmpl	$1, %edx
	sbbl	%edx, %edx
	shrl	$23, %r8d
	andl	$8388607, %eax
	andl	$-2, %edx
	movzbl	%r8b, %r8d
	addl	$45, %edx
	cmpl	$255, %r8d
	je	.L22
	testl	%r8d, %r8d
	jne	.L14
	movq	%rsp, %rcx
	leaq	-1(%rsp), %r8
	movb	$0, 23(%rsp)
	leaq	22(%rcx), %rsi
	.p2align 4,,10
	.p2align 3
.L15:
	movl	%eax, %edi
	subq	$1, %rsi
	shrq	%rax
	andl	$1, %edi
	addl	$48, %edi
	movb	%dil, 1(%rsi)
	cmpq	%rsi, %r8
	jne	.L15
	leaq	.LC2(%rip), %rsi
	movsbl	%dl, %edx
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk@PLT
.L10:
	movq	24(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L23
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L14:
	.cfi_restore_state
	movq	%rsp, %rcx
	leaq	-1(%rsp), %r9
	subl	$127, %r8d
	leaq	22(%rcx), %rsi
	movb	$0, 23(%rsp)
	.p2align 4,,10
	.p2align 3
.L16:
	movl	%eax, %edi
	subq	$1, %rsi
	shrq	%rax
	andl	$1, %edi
	addl	$48, %edi
	movb	%dil, 1(%rsi)
	cmpq	%rsi, %r9
	jne	.L16
	leaq	.LC3(%rip), %rsi
	movsbl	%dl, %edx
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk@PLT
	jmp	.L10
	.p2align 4,,10
	.p2align 3
.L22:
	leaq	.LC1(%rip), %rsi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk@PLT
	jmp	.L10
.L23:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE25:
	.size	f_print, .-f_print
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits

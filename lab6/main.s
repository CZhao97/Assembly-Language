	.file	"main.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Error:  sum mismatch"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC1:
	.string	"Sample %d completed in %d cycles.\n"
	.section	.rodata.str1.1
.LC2:
	.string	"Average of %ld cycles.\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB38:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	xorl	%edi, %edi
	movl	$A, %ebx
	subq	$296, %rsp
	.cfi_def_cfa_offset 320
	call	times
	movl	%eax, %edi
	call	srand
	movl	$0, Q(%rip)
	.p2align 4,,10
	.p2align 3
.L3:
	call	rand
	cltd
	shrl	$22, %edx
	addl	%edx, %eax
	andl	$1023, %eax
	subl	%edx, %eax
	subl	$512, %eax
	testl	%eax, %eax
	movl	%eax, (%rbx)
	jle	.L2
	addl	%eax, Q(%rip)
.L2:
	addq	$4, %rbx
	cmpq	$A+400, %rbx
	jne	.L3
	movq	144(%rsp), %rbp
	subq	(%rsp), %rbp
	movl	$cycles, %ebx
	imull	$10000000, %ebp, %ebp
	subl	8(%rsp), %ebp
	addl	152(%rsp), %ebp
	jmp	.L5
	.p2align 4,,10
	.p2align 3
.L4:
	movl	end_time(%rip), %eax
	subl	start_time(%rip), %eax
	addq	$4, %rbx
	movl	%eax, -4(%rbx)
	cmpq	$cycles+80, %rbx
	je	.L12
.L5:
	movl	$100, %esi
	movl	$A, %edi

	pushq   %rax
	pushq   %rbx
	pushq   %rcx
	pushq   %rdx
	cpuid
	rdtscp
	movl    %eax, start_time(%rip)
	popq    %rdx
	popq    %rcx
	popq    %rbx
	popq    %rax

	call	sum_plus

	pushq   %rax
	pushq   %rbx
	pushq   %rcx
	pushq   %rdx
	cpuid
	rdtscp
	movl    %eax, end_time(%rip)
	popq    %rdx
	popq    %rcx
	popq    %rbx
	popq    %rax

	cmpl	Q(%rip), %eax
	movl	%eax, P(%rip)
	movl	%ebp, (%rbx)
	je	.L4
	addq	$296, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	movl	$.LC0, %edi
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	jmp	perror
.L12:
	.cfi_restore_state
	movq	$0, total(%rip)
	movl	$1, %ebx
	.p2align 4,,10
	.p2align 3
.L6:
	movl	cycles-4(,%rbx,4), %ecx
	movl	%ebx, %edx
	xorl	%eax, %eax
	movl	$.LC1, %esi
	movl	$1, %edi
	call	__printf_chk
	movslq	cycles-4(,%rbx,4), %rax
	addq	$1, %rbx
	addq	total(%rip), %rax
	cmpq	$21, %rbx
	movq	%rax, total(%rip)
	jne	.L6
	movl	$20, %ecx
	cqto
	addq	$296, %rsp
	.cfi_def_cfa_offset 24
	idivq	%rcx
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	movl	$.LC2, %esi
	movl	$1, %edi
	movq	%rax, %rdx
	xorl	%eax, %eax
	jmp	__printf_chk
	.cfi_endproc
.LFE38:
	.size	main, .-main
	.globl	end_time
	.data
	.align 4
	.type	end_time, @object
	.size	end_time, 4
end_time:
	.long	125
	.globl	start_time
	.align 4
	.type	start_time, @object
	.size	start_time, 4
start_time:
	.long	150
	.comm	total,8,8
	.comm	cycles,80,32
	.comm	Q,4,4
	.comm	P,4,4
	.comm	A,400,32
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~16.04~ppa1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits

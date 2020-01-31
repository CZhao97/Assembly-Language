	.file	"p2.c"
	.text
	.p2align 4,,15
	.globl	proc2
	.type	proc2, @function
proc2:
.LFB0:
	.cfi_startproc
	imull	%esi, %edi
	leal	-12(%rdi), %eax
	ret
	.cfi_endproc
.LFE0:
	.size	proc2, .-proc2
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~16.04~ppa1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits

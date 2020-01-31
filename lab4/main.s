	.file	"main.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	rep ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	b
	.data
	.align 8
	.type	b, @object
	.size	b, 8
b:
	.quad	19
	.globl	a
	.type	a, @object
	.size	a, 1
a:
	.byte	10
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~16.04~ppa1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits

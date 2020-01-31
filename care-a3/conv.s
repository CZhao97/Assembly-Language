	.globl conv
conv:
	movb $0,%al
	leaq -1(%rdi,%rdx),%rdi
	movq $0,%r10
loop:
	cmp $0,%rdx
	je endloop
	movsx (%rsi),%r8w
	movsx (%rdi),%r9w
	imulw %r9w,%r8w
	movb %r8b,%r9b
	movsx %r9b,%r9w
	cmpw %r9w,%r8w
	je inc
	movq $1,%r10
	inc:
	addb %r8b,%al
	jno inc2
	movq $1,%r10
	inc2:
	decq %rdi
	incq %rsi
	decq %rdx
	jmp loop
endloop:
	movq %r10,%rdx
	ret


#discuss the idea of bonus question (the use of movcx) with classmate

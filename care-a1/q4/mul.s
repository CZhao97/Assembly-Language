	.globl times
times:
	mov $0,%rax
	mov %rdi,%rdx

loop:   
	cmp $0,%rdx
	jle endloop
	add %rsi,%rax
	decq %rdx
	jmp loop
endloop:
	ret


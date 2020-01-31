	.globl times
times:
	mov $0,%rax
	mov %rdi,%r8
	mov %rsi,%r9
	cmp $0,%rsi
	je endloop
	cmp $0,%rdi
	je endloop
	mov $1,%r10
	mov $1,%r11
	cmp $0,%rdi
	jge loop
	mov %rsi,%rdx
	mov %rdi,%rsi
	mov %rdx,%rdi
loop:
	cmp %r10,%r8
	jg ifcondition
	je equal
	jl elsecondition
	ifcondition:
		mov %r10,%r11
		mov %r9,%rdx
		add %r9,%r9
		add %r10,%r10
		jmp loop
	equal:
		add %r9,%rax
		jmp endloop
	elsecondition:
		add %rdx,%rax
		sub %r11,%r8
		mov $1,%r10
		mov %rsi,%r9
		jmp loop
endloop:
	ret

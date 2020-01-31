	.globl sqrt
sqrt:
	movl $0, %eax   # place your code for Q3 here
	movl $16,%ecx
	leal 0x8000,%edx
	loop:
		cmp $0,%ecx
		je endloop
		sub $1, %ecx
		movl %eax,%esi
		add %edx,%eax
		imul %eax,%eax
		cmp %eax,%edi
		jl case
		movl %esi,%eax
		add %edx,%eax
		shrl $1,%edx
		jmp loop
		case:
			movl %esi,%eax
			shrl $1,%edx
			jmp loop

	endloop:
	ret

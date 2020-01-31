	.globl sqrt
sqrt:
	movl $0, %eax   # place your code for Q3 here
	movl $16,%ecx
	movl $32768,%edx
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
		movl %eax,%esi
		movl %eax,%edx
		add $1,%esi
		imul %esi,%esi
		subl %edi,%esi
		imul %edx,%edx
		subl %edx,%edi
		cmp %edi,%esi
		jle case2
		ret
		case2:
			add $1, %eax
			ret






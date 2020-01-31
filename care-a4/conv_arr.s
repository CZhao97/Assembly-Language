	.globl conv_arr
conv_arr:

	pushq %r12			# push caller register to memory
	pushq %r13
	pushq %r14

	pushq %rsi			# push %rsi to memory
	addq %rcx,%rsi		# %rsi = %rsi + %rcx
	movq %rsi,%r12		# give value of %rsi to %r12
	popq %rsi 			# pop the top value in the stack to %rsi
	subq $2,%r12		# %r12 = %r12 - 2 which eqauls to m + n -2
	addq %r12,%r8		# move %r8 to the last element of the array
	loop:				# start of the loop
		cmpq $0,%r12	# compare %r12 with zero
		jl endloop		# if %r12 < 0 jump to endloop
		pushq %r12		# push %r12 to memory
		pushq %rdi		# push %rdi to memory
		pushq %rsi 		# push %rsi to memory
		pushq %rdx		# push %rdx to memory
		pushq %rcx		# push %rcx to memory
		pushq %r8		# push %r8 to memory
		addq $1,%r12	# change the value of %r12 to i + 1
		movq %r12,%rdi	# move the value of %r12 to %rdi
		movq %rcx,%rsi 	# set value of %rsi to m
		call min		# call the function min
		popq %r8		# pop the top of memory from memory to %r8
		popq %rcx		# pop the top of memory from memory to %rcx
		popq %rdx		# pop the top of memory from memory to %rdx
		popq %rsi 		# pop the top of memory from memory to %rsi
		popq %rdi		# pop the top of memory from memory to %rdi
		movq %rax,%r13	# save the value of ;adj to %r13

		pushq %rdi		# push %rdi to memory
		pushq %rsi 		# push %rsi to memory
		pushq %rdx		# push %rdx to memory
		pushq %rcx		# push %rcx to memory
		pushq %r8		# push %r8 to memory
		movq %rcx,%rdi	# set the value of %rdi to m
		addq %rsi,%rdi	# set %rdi to m + n
		subq %r12,%rdi	# set %rdi to m + n - (i + 1)
		movq %rcx,%rsi 	# set %rsi to m
		call min		# the function min
		popq %r8		# pop the top of memory from memory to %r8
		popq %rcx		# pop the top of memory from memory to %rcx
		popq %rdx		# pop the top of memory from memory to %rdx
		popq %rsi 		# pop the top of memory from memory to %rsi
		popq %rdi		# pop the top of memory from memory to %rdi
		pushq %rcx		# push %rcx to memory
		subq %rax,%rcx	# m - the return value of min
		movq %rcx,%r14	# give the value radj to %r14
		popq %rcx		# pop the top of memory from memory to %rcx

		subq %r13,%r12	# set %r12 to (i + 1 - ladj)
		pushq %rdi		# push %rdi to memory
		addq %r12,%rdi	# set %rdi as (x + (i+1-ladj)
		pushq %rsi 		# push %rsi to memory
		pushq %rdx		# push %rdx to memory
		pushq %rcx		# push %rcx to memory
		pushq %r8		# push %r8 to memory	
		addq %r14,%rdx	# %rdx = h + radj
		movq %rdx,%rsi 	# give the value of %rdx to %rsi
		movq %r13,%rdx	# set the value of %rdx to ladj
		subq %r14,%rdx	# %rdx = ladj - radj
		call conv 		# call the function conv
		popq %r8		# pop the top of memory from memory to %r8
		popq %rcx		# pop the top of memory from memory to %rcx
		popq %rdx		# pop the top of memory from memory to %rdx
		popq %rsi 		# pop the top of memory from memory to %rsi
		popq %rdi		# pop the top of memory from memory to %rdi
		movb %al,(%r8)	# give the final answer to %al
		decq %r8		# decrement %r8 by 1
		popq %r12		# pop the top of memory from memory to %r12
		decq %r12		# decrement %r12 by 1
		jmp loop		# jump back to loop

	endloop:			# the label of endloop
	popq %r14			# pop the callee register from memory
	popq %r13
	popq %r12
	ret 				# return 

	.globl sum_float

	# var map:
	#   %xmm0:  total
	#   %rdi:   F[n] (base pointer)
	#   %rsi:   n
	#   %rbp:   endptr

sum_float:					
	lea	(%rdi,%rsi,4),%r9		#set r9 as the test address to the last element
	push	%rbp				#push the reserved value to stack
	push	%r15
	mov	%rsp,%r8
	xorps	%xmm0,%xmm0			#set the value of xmm0 and xmm1 to zero
	xorps	%xmm1,%xmm1
	mov	%rdi,%rdx			#before the loop, add the sum of first two elements into Q
	add	$4,%rdi
	mov	%rdi,%rcx
	add	$4,%rdi
	addss	(%rdx),%xmm1
	addss	(%rcx),%xmm1
	sub	$4,%rsp
	movss	%xmm1,(%rsp)
	dec	%rsi
	lea	(%rsp),%rbp
loop:						#label to start the loop
	cmp	$1,%rsi				#test if neccessay to jump out the loop
	jle	endloop				#jump to endloop if failed
	dec	%rsi				#n=n-1
	xorps	%xmm1,%xmm1			#set xmm1 to zero
	xorps	%xmm2,%xmm2			#set xmm2 to zero
	xorps	%xmm3,%xmm3			#set xmm3 to zero

	cmp	%rdi,%r9			#test the F is empty or not
	jne	next				#if not empty jump to next
	addss	(%rbp),%xmm1			#give the result based on the two elements from F to Q
	sub	$4,%rbp
	addss	(%rbp),%xmm1
	sub	$4,%rbp
	sub	$4,%rsp
	movss	%xmm1,(%rsp)
	jmp	loop				#jump back to loop

	next:					#F not empty

	movss	(%rdi),%xmm2
	movss	(%rbp),%xmm3
	ucomiss	%xmm3,%xmm2			#find the smallest from F[0] and Q[0]
	jae	dequeueq			#dequeue q
	addss	(%rdi),%xmm1			#dequeue f
	add	$4,%rdi
	jmp	endcase				#jmp to test f empty?
	dequeueq:				#dequeue
		addss	(%rbp),%xmm1
		sub	$4,%rbp
		jmp	endcase2


	endcase:				
		cmp	%rdi,%r9		#test if F is empty
		jne	unequal			#jump to unequal not empty
		addss	(%rbp),%xmm1		#F not empty, then sum the first element from F to xmm1
		sub	$4,%rbp
		sub	$4,%rsp
		movss	%xmm1,(%rsp)
		jmp	loop
		
	unequal:				#F is empty
		movss	(%rdi),%xmm2		#find the smallest element between Q and F
		movss	(%rbp),%xmm3
		ucomiss	%xmm3,%xmm2
		jae	removeq
		addss	(%rdi),%xmm1		#dequeue from F
		add	$4,%rdi
		jmp	back
		removeq:			#dequeue from Q
			addss	(%rbp),%xmm1
			sub	$4,%rbp
		back:
			sub	$4,%rsp
			movss	%xmm1,(%rsp)
		jmp loop

	endcase2:				
		mov	%rbp,%r15		#test if Q empty
		add	$4,%r15
		cmp	%r15,%rsp
		jne	qbukong

		mov	%rdi,%rdx		#if Q is empty
		add	$4,%rdi
		addss	(%rdx),%xmm1
		sub	$4,%rsp
		movss	%xmm1,(%rsp)
		jmp	loop

	qbukong:				#if Q is empty
		movss	(%rdi),%xmm2		
		movss	(%rbp),%xmm3		
		ucomiss	%xmm3,%xmm2		#find the smallesrt element from F and Q
		jae	removeq2
		addss	(%rdi),%xmm1
		add	$4,%rdi
		jmp	back2
		removeq2:			#dequeue from Q
			addss	(%rbp),%xmm1
			sub	$4,%rbp
		back2:
			sub	$4,%rsp
			movss	%xmm1,(%rsp)
		jmp loop



endloop:					#end from the algorithm
	movss	%xmm1,%xmm0			#move the final result to the return value	
	mov	%r8,%rsp			#give the value of the original value back to %rsp
	pop	%r15				#pop the reserved value back
	pop	%rbp
	ret



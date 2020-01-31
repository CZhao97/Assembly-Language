	.globl	lsearch_2
#var map:
#int* A = %rdi
#int  n = %rsi
#int  target = %rdx
#return value = %rax


lsearch_2:
	testl	%esi, %esi			#if n < = 0, jump to end	C:if(n<=0)
	jle	end				
	movslq	%esi, %rax			#give value n to %rax
	leaq	-4(%rdi,%rax,4), %rax		#set %rax equal to the address of A[n-1]	C:tmp=A[n-1]
	movl	(%rax), %r9d			#save the value of A[n-1] in %r9d (32-bit)
	movl	%edx, (%rax)			#change the value of A[n-1] to target		C:A[n-1]=target
	cmpl	(%rdi), %edx			#compare the value of %edx with A[0]		C:compare A[0] and target
	je	first_is_result			#if equal then jump to first_is_result		C:if(A[0]==target)
	movl	$1, %ecx			#else move 1 to %ecx				C:i=1
loop:						#						C:while
	movl	%ecx, %r8d			#give the number of while loop compiled to %r8d	
	addq	$1, %rcx			#increment %rcx					C:i++
	cmpl	%edx, -4(%rdi,%rcx,4)		#compare A[n+%rcx-1] with target		C:if(A[i]!=target)
	jne	loop				#if not equal, then jump to loop again
restore_and_check:
	movl	%r9d, (%rax)			#set the value of A[n-1] back to its original value	C:A[n-1]=tmp
	leal	-1(%rsi), %eax			#set the value of %eax to n-1				C:i=n-1
	cmpl	%r8d, %eax			#compare the number that while loop compiled with n-1	C:if(A{n-1]==target)
	jg	find_result			#if the running time of while loop smaller than n-1, jump to find_result	C:if(i<n-1)
	cmpl	%edx, %r9d			#else compare A[n-1] with target(%edx)		C:if(A[n-1==target])
	jne	result_not_exist		#jump to result_not_exist 			C:if A[n-1] != target		
	rep ret					#return						C:retutn n-1
find_result:
	movl	%r8d, %eax			#move the result to return value
	ret					#return						C:return i
first_is_result:
	xorl	%r8d, %r8d			#set %r8d to 0					C:i=0
	jmp	restore_and_check			#jump to restore_and_check
result_not_exist:
	movl	$-1, %eax			#set the return value to -1			C:i=-1
	ret					#return						C:return i

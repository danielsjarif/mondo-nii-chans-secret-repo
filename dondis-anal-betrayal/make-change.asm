	
	global main
	extern printf
	extern atoi
	extern puts
	section .text

main:
	push rbx
	mov rdi, [rsi + 8]				;this should allow user input
	call atoi

	mov rsi, 25
	xor rdx, rdx
	div rsi
	mov rsi, rax
	mov r14, rdx
	mov rdi, display
	xor rax, rax
	call print

	mov rax, r14
	mov rsi, 10
	xor rdx, rdx
	div rsi
	mov rsi, rax
	mov rdi, display2
	xor rax, rax
	mov r14, rdx
	call printf

	mov rax, r14
	mov rsi, 5
	xor rdx, rdx
	div rsi
	mov rsi, rax
	mov rdi, display3
	xor rax, rax
	mov r14, rdx
	call printf

	mov rax, r14
	mov rsi, 1
	xor rdx, rdx
	div rsi
	mov rsi, rax
	div rsi
	mov rsi, rax
	mov rdi, display4
	xor rax, rax
	call printf

	;cmp rdx, 0
	;je complete


	; mov rdi, complete
	; mov rsi, rax
	; xor rax, rax
	; call printf
	; ;prinf("%d\n",rdi) 

	pop rbx
	ret

	display:
	db "you need %d quarters", 10, 0
	display2:
	db "you need %d dimes", 10, 0
	display3;
	db "you need %d nickels", 10, 0
	display4:
	db "you need %d pennies", 10, 0

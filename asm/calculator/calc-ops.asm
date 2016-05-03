        global  gcd
        global  add
        global	subtract

        section .text
gcd:   
		mov     rax, rdi    ; Move x into rax
        cmp     rax, rsi    ; x < y?
        cmovl   rdi, rsi    ; Switch places
        cmovl	rsi, rax 	;
		mov		rax, rsi	; Move y into rax
		cmp		rax, 0		; y == 0?
		jz 		zero		; If yes, jump
		mov 	rax, rdi 	; Move x into rax
		mov 	rcx, rsi 	; Move y into rcx
		xor 	rdx, rdx	; Clear rdx
		div		rcx 		; Divide, remainder goes in rdx
		mov 	rdi, rsi	; Put y where x was
		mov 	rsi, rdx 	; Put the x % y as second arg
		jmp 	gcd			; Recurse until rsi holds 0

zero:
		mov 	rax, rdi	; Move x into rax
		ret

add:
		mov 	rax, rdi	; Move arg 1 into rax
		add 	rax, rsi	; Add arg 2
		ret

subtract:
		mov 	rax, rdi	; Move arg 1 into rax
		sub 	rax, rsi	; Subtract arg 2
		ret
    global main
    extern strlen
    extern atoi

    section .text
    
main:
        push rbx
        mov rax, 82
        mov rdi, [rsi + 8]
        mov rsi, [rsi + 16]

        syscall
        
        pop rbx
        ret

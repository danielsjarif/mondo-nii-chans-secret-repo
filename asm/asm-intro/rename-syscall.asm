    global main
    extern strlen
    extern atoi
    extern printf

    section .text
    
main:
        push rbx
        mov rax, rdi
        cmp rax, 1
        je noArgs


        mov rax, 82
        mov rdi, [rsi + 8]
        mov rsi, [rsi + 16]

        syscall

        pop rbx
        ret

        noArgs:
        mov rdi, display
        call printf
        pop rbx
        ret

        display:
        db "there are no arguments", 10, 0

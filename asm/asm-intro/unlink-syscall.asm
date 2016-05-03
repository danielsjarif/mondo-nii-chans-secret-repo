    global main
    extern printf
    section .text
    
main:
        push rbx
        cmp rax, 1
        je noArgs
        mov rax, 87
        mov rdi, [rsi + 8]
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


 
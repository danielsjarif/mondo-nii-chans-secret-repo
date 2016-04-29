    global main
    section .text
    
main:
        push rbx
        mov rax, 87
        mov rdi, [rsi + 8]
        syscall

        ; mov eax, 60
        ; xor rdi, rdi
        ; syscall



        pop rbx
        ret


 
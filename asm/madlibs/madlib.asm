        global  main
        extern  strlen
        extern  printf
        extern  puts
        extern  madlib_by_numbers
        section .text

main: 
        push rbx

        mov r14, [rsi + 8]
        sub rdi, 2
        mov r13, rdi
        mov rdx, rsi
        add rdx, 16
        mov rdi, r14
        mov rsi, r13
        call madlib_by_numbers
        mov rdi, rax
        xor rax, rax
        call puts
        xor rax, rax

        pop rbx

        ret
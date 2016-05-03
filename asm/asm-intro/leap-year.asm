    global main
    extern printf
    extern atoi
    section .text

main:
    push rbx
    mov rdi, [rsi + 8]
    call atoi

    mov r14, rax
    xor rdx, rdx
    mov rcx, 400
    div rcx
    cmp rax, 0
    je yes

    mov rax, r14
    xor rdx, rdx
    mov rcx, 100
    div rcx
    cmp rdx, 0
    je no

    mov rax, r14
    xor rdx, rdx
    mov rcx, 4
    div rcx
    cmp rdx, 0
    je yes

    no:
    mov rdi, isntLeap
    call printf
    pop rbx
    ret

    yes:
    mov rdi, isLeap
    call printf
    pop rbx
    ret

    

    ; mov rsi, 4
    ; xor rdx, rdx
    ; div rsi
    ; mov rsi, rdx
    ; mov rdi, isLeap
    ; xor rax, rax
    ; call printf

   


    ;pop rbx
    ;ret

    isntLeap:
    db "The year is not a leap year", 10, 0
    isLeap:
    db "The year is a leap year", 10, 0




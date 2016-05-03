        global  main
        extern  puts
        extern strlen
        extern reverse_range_in_place
        section .text
main:
        push    rdi                     ; save registers that puts uses
        push    rsi
        sub     rsp, 8                  ; must align stack before call

        mov     rdi, [rsi]              ; the argument string to display
        call    strlen
        mov     rsi, 0
        sub     rax, 1
        mov     rdx, rax
        push    rdi
        call    reverse_range_in_place
        pop     rdi
        call    puts

        add     rsp, 8                  ; restore %rsp to pre-aligned value
        pop     rsi                     ; restore registers puts used
        pop     rdi

        add     rsi, 8                  ; point to next argument
        dec     rdi                     ; count down
        jnz     main                    ; if not done counting keep going

        ret

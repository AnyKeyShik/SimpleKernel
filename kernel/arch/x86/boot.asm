; Copyright (c) 2022. AnyKeyShik Rarity
;
; nikitav59@gmail.com
;
; https://t.me/AnyKeyShik

; Boot code for kernel

bits 32

global start
global exit

extern kmain
extern asm_lock
extern asm_hlt

section .text
align 4
start:
    mov esp, stack_bottom
    
    push ebp
    mov ebp, esp

    call asm_lock
    call kmain

exit:
    call asm_hlt

    mov esp, ebp
    pop ebp

section .bss
align 4
stack_top:
    resb 8192   ; 8KB for stack
stack_bottom:

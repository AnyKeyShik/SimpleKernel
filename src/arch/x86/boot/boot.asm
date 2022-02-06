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

section .text
start:
    cli         ; block interrupts
    mov esp, stack_bottom
    call kmain
    hlt         ; halt the CPU

exit:
    hlt

section .bss
stack_top:
    resb 8192   ; 8KB for stack
stack_bottom:

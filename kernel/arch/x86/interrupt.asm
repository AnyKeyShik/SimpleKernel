; Copyright (c) 2022. AnyKeyShik Rarity
;
; nikitav59@gmail.com
;
; https://t.me/AnyKeyShik

global asm_lock
global asm_unlock
global asm_hlt

bits 32

section .text
asm_lock:
    push ebp
    mov ebp, esp

    cli

    mov esp, ebp
    pop ebp
    ret

asm_unlock:
    push ebp
    mov ebp, esp

    sti

    mov esp, ebp
    pop ebp
    ret

asm_hlt:
    push ebp
    mov ebp, esp

    hlt

    mov esp, ebp
    pop ebp
    ret
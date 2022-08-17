; Copyright (c) 2022. AnyKeyShik Rarity
;
; nikitav59@gmail.com
;
; https://t.me/AnyKeyShik

global asm_read_port
global asm_write_port

bits 32

section .text
asm_read_port:
    push ebp
    mov ebp, esp

    mov edx, [esp + 8]
    in al, dx

    mov esp, ebp
    pop ebp
    ret

asm_write_port:
    push ebp
    mov ebp, esp

    mov edx, [esp + 8]
    mov eax, [esp + 12]
    out dx, al

    mov esp, ebp
    pop ebp
    ret
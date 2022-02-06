; Copyright (c) 2022. AnyKeyShik Rarity
;
; nikitav59@gmail.com
;
; https://t.me/AnyKeyShik

bits 32

global load_idt
global read_port
global write_port
global keyboard_handler

extern keyboard_handler_main

section .text
    
; Load Interrupt Descriptor Table (cdecl)
load_idt:
    mov edx, [esp + 4]

    lidt [edx]
    sti             ; turn on interrupts
    ret

; Read from port (cdecl)
read_port:
    mov edx, [esp + 4]
    in al, dx
    ret

; Write to port (cdecl)
write_port:
    mov edx, [esp + 4]
    mov al, [esp + 8]
    out dx, al
    ret

keyboard_handler:
    call keyboard_handler_main
    iretd

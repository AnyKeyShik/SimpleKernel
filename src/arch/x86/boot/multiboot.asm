; Copyright (c) 2022. AnyKeyShik Rarity
;
; nikitav59@gmail.com
;
; https://t.me/AnyKeyShik

global check_multiboot

section .multiboot_header
header_start:
    magic    dd 0xE85250D6                           
    arch     dd 0x0                         ; protected i386
    length   dd header_end - header_start
    checksum dd 0x100000000 - ( 0xE85250D6 + 0x0 + (header_end - header_start) )

    ; Required End tag
    dw 0    ; type
    dw 0    ; flags
    dd 8    ; size
header_end:

section .text
bits32

check_multiboot:
    cmp eax, 0x36d76289
    je .multiboot_ret
    xor eax, eax
.multiboot_ret
    ret
; Copyright (c) 2022. AnyKeyShik Rarity
;
; nikitav59@gmail.com
;
; https://t.me/AnyKeyShik

global check_multiboot

bits 32
section .multiboot_header
header_start:
    magic    dd 0x1BADB002                           
    flags    dd 0x0
    checksum dd -(0x1BADB002 + 0x0)
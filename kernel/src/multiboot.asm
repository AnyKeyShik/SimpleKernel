; Copyright (c) 2022. AnyKeyShik Rarity
;
; nikitav59@gmail.com
;
; https://t.me/AnyKeyShik

global check_multiboot

bits 32

section .data
    MODULEALIGN equ 1<<0
    MEMINFO equ 1<<1
    
    FLAGS equ MODULEALIGN | MEMINFO
    MAGIC equ 0x1BADB002
    CHECKSUM equ -(MAGIC + FLAGS)

section .multiboot_header
align 4
header_start:
    dd MAGIC
    dd FLAGS
    dd CHECKSUM
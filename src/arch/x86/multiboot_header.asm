; Multiboot header

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

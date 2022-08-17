OUTPUT_FORMAT(elf32-i386)
ENTRY(start)

SECTIONS {
    . = 1M;

    .boot BLOCK(4K) : ALIGN(4K) {
        *(.multiboot_header)
    }

    .text BLOCK(4K) : ALIGN(4K) {
        *(.text)
    }

    .rodata BLOCK(4K) : ALIGN(4K) {
        *(.rodata)
    }

    .data BLOCK(4K) : ALIGN(4K) { 
        *(.data)  
    }

    .bss BLOCK(4K) : ALIGN(4K) {
        sbss = .;
        *(COMMON)
        *(.bss)
        ebss = .;
    }
}

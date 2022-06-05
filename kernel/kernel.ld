OUTPUT_FORMAT(elf32-i386)
ENTRY(start)

SECTIONS {
    . = 1M;

    .boot : {
        *(.multiboot_header)
    }

    .text : {
        *(.text)
    }

    .rodata ALIGN (0x1000) : {
        *(.rodata)
    }

    .data ALIGN (0x1000) : { 
        *(.data)  
    }

    .bss : {
        sbss = .;
        *(COMMON)
        *(.bss)
        ebss = .;
    }
}

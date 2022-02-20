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

    .data : { 
        *(.data)  
    }

    .bss  : { 
        *(.bss)   
    }
}

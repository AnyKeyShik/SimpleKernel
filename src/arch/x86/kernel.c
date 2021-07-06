#include "keyboard_map.h"
#include "idt.h"
#include "keyboard.h"
#include "screen.h"

extern void 
load_gdt(void);

extern void
exit(void);

extern int
check_multiboot(void);

extern int
check_cpuid(void);

extern int
check_long_mode(void);

void 
kmain(void)
{
    const char *str = "Kernel v0.1";
	
    clear_screen();

    print_string(str);
    print_newline();
    print_newline();

    load_gdt();
    print_string("GDT loaded");
    print_newline();

    idt_init();
    print_string("IDT loaded");
    print_newline();
	
    keyboard_init();
    print_string("Keyboard initialized");
    print_newline();
    print_newline();
	
    while(1);
}

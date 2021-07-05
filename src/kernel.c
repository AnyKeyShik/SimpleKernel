#include "keyboard_map.h"
#include "idt.h"
#include "keyboard.h"
#include "screen.h"

extern void load_gdt();
void kmain(void)
{
	const char *str = "Kernel v0.2";
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
	while(1);
}

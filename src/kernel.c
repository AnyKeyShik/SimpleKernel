#include "../include/keyboard_map.h"
#include "../include/idt.h"
#include "../include/keyboard.h"
#include "../include/screen.h"

void kmain(void)
{
	const char *str = "Kernel v0.1";
	clear_screen();
	print_string(str);
	print_newline();
	print_newline();

	idt_init();
	keyboard_init();

	while(1);
}

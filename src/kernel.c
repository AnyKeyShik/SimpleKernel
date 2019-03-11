#include "keyboard_map.h"
#include "idt.h"
#include "keyboard.h"
#include "screen.h"

void kmain(void)
{
	const char *str = "Kernel v0.2";
	clear_screen();
	print_string(str);
	print_newline();
	print_newline();

	idt_init();
	keyboard_init();

	while(1);
}

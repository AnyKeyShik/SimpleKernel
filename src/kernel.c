#include "includes/keyboard_map.h"
#include "includes/idt.h"
#include "includes/keyboard.h"
#include "includes/screen.h"

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

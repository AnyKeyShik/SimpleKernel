// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#include "keyboard/idt.h"
#include "keyboard/keyboard.h"
#include "screen/screen.h"

extern void load_gdt(void);

extern int check_multiboot(void);

extern void exit(void);

void kmain(void) {

    if (!check_multiboot()) {
        exit();
    }

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

    while (1);
}

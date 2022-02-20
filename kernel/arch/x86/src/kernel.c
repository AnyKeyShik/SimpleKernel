// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#include <console.h>

extern int check_multiboot(void);

extern void exit(void);

void kmain(void) {

    if (!check_multiboot()) {
        exit();
    }

    const char *str = "Kernel v0.1";

    clear_screen();

    print_string(str);
    putchar('\n');
    putchar('\n');

    while (1);
}

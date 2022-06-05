// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#include <console.h>

extern void exit(void);

void __attribute__((noreturn)) kmain(void) {
    const char *title = "Kernel v0.1\n\r\n\r";
    const char *author = "AnyKeyShik Rarity\n\r";

    clear_screen();

    print_string(title);
    print_error(author);

    while (1);
}

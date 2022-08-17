// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#include <libk/stdio.h>

extern void exit(void);

void __attribute__((noreturn)) kmain(void) {
    const u8 *title = "Kernel v0.1\n";
    const u8 *author = "AnyKeyShik Rarity\n";

    kprintf("\t\t\t\t%s", title);
    kprintf("\t\t\t%s", author);

    for (;;);
}

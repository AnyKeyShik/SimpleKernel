// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#include <console.h>

void
print_string(const unsigned char *const string) {
    for (unsigned int i = 0; string[i] != '\0'; i++) {
        putchar(string[i], BLACK, GREEN);
    }
}

void
print_error(const unsigned char *const string) {
    for (unsigned int i = 0; string[i] != '\0'; i++) {
        putchar(string[i], BLACK, RED);
    }
}

void
putchar(const unsigned char symbol, const unsigned char bg_color, const unsigned char fg_color) {
    switch (symbol) {
        case '\b':
            if (current_loc > 0) {
                vidptr[--current_loc] = EMPTY_SYMBOL;
                vidptr[--current_loc] = EMPTY_SYMBOL;
            }
            break;
        case '\n':
            current_loc += LINE_SIZE;
            break;
        case '\r':
            current_loc -= (current_loc % LINE_SIZE);
            break;
        case '\t':
            for (unsigned char i = 0; i < 4; i++) {
                vidptr[current_loc++] = EMPTY_SYMBOL;
                vidptr[current_loc++] = EMPTY_SYMBOL;
            }
            break;
        default:
            vidptr[current_loc++] = symbol;
            vidptr[current_loc++] = bg_color << 4 | fg_color;
    }
}

void
clear_screen(void) {
    for (unsigned int i = 0; i < SCREENSIZE; i++) {
        vidptr[i++] = EMPTY_SYMBOL;
        vidptr[i] = EMPTY_SYMBOL;
    }
}

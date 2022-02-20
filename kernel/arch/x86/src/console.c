// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#include <console.h>

void
print_string(const char *const string) {
    for (unsigned int i = 0; string[i] != '\0'; i++) {
        putchar(string[i]);
    }
}

void
print_error(const char *const string) {
    for (unsigned int i = 0; string[i] != '\0'; i++) {
        vidptr[current_loc++] = string[i];
        vidptr[current_loc++] = RED_SYMBOL;
    }
}

void
putchar(const char symbol) {
    switch (symbol) {
        case '\b':
            if (current_loc > 0) {
                vidptr[--current_loc] = EMPTY_SYMBOL;
                vidptr[--current_loc] = ' ';
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
                vidptr[current_loc++] = ' ';
                vidptr[current_loc++] = GREEN_SYMBOL;
            }
            break;
        default:
            vidptr[current_loc++] = symbol;
            vidptr[current_loc++] = GREEN_SYMBOL;
    }
}

void
clear_screen(void) {
    for (unsigned int i = 0; i < SCREENSIZE; i++) {
        vidptr[i++] = ' ';
        vidptr[i] = EMPTY_SYMBOL;
    }
}

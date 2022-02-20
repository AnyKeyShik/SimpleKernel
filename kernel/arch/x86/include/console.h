// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#ifndef SIMPLEKERNEL_CONSOLE_H
#define SIMPLEKERNEL_CONSOLE_H

#define LINES 25
#define COLUMNS_IN_LINE 80
#define BYTES_FOR_EACH_ELEMENT 2
#define LINE_SIZE BYTES_FOR_EACH_ELEMENT * COLUMNS_IN_LINE
#define SCREENSIZE LINE_SIZE * LINES

//TODO: Re-define this shit
#define GREEN_SYMBOL 0x02
#define RED_SYMBOL 0x04
#define EMPTY_SYMBOL 0x07

static unsigned int current_loc = 0;
static char *const vidptr = (char *) 0xb8000;

extern void print_string(const char *const string);

extern void print_error(const char *const string);

extern void putchar(const char symbol);

extern void clear_screen(void);

#endif //SIMPLEKERNEL_CONSOLE_H

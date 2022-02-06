// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#ifndef SCREEN_H
#define SCREEN_H

#include "consts.h"

extern unsigned int current_loc;

extern void print_string(const char *string);

extern void print_error(const char *string);

extern void print_symbol(char symbol);

extern void print_newline(void);

extern void print_delete_symbol(void);

extern void print_tab(void);

extern void clear_screen(void);

#endif

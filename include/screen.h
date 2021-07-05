#ifndef SCREEN_H
#define SCREEN_H

#include "consts.h"

extern unsigned int current_loc;

void print_string(const char *string);
void print_symbol(char symbol);
void print_newline(void);
void print_delete_symbol(void);
void print_tab(void);
void clear_screen(void);

#endif

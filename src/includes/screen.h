#ifndef SCREEN_H
#define SCREEN_H

#include "consts.h"

unsigned int current_loc;

void print_string(const char *string);
void print_symbol(char symbol);
void print_newline(void);
void clear_screen(void);

#endif

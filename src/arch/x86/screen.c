#include "screen.h"

unsigned int current_loc = 0; // current cursor location
	
void print_string(const char *str)
{
    unsigned int i = 0;
    while (str[i] != '\0') {
        vidptr[current_loc++] = str[i++];
        vidptr[current_loc++] = 0x02;
    }
}

void print_error(const char *str)
{
    unsigned int i = 0;
    while (str[i] != '\0') {
        vidptr[current_loc++] = str[i++];
        vidptr[current_loc++] = 0x04;
    }
}

void print_symbol(char str)
{
    vidptr[current_loc++] = str;
    vidptr[current_loc++] = 0x02;
}

void print_newline(void)
{
    unsigned int line_size = BYTES_FOR_EACH_ELEMENT * COLUMNS_IN_LINE;
    current_loc = current_loc + (line_size - current_loc % (line_size));
}

void print_delete_symbol()
{
    vidptr[--current_loc] = 0x07;
    vidptr[--current_loc] = ' ';
}

void print_tab() 
{
    unsigned int i = 0;
    while(i < 4) {
        print_symbol(' ');
        i++;
    }
}

void clear_screen(void)
{
    unsigned int i = 0;
    while (i < SCREENSIZE) {
        vidptr[i++] = ' ';
        vidptr[i++] = 0x07;
    }
}

// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#ifndef SIMPLEKERNEL_CONSOLE_H
#define SIMPLEKERNEL_CONSOLE_H

#include <stdint.h>

enum screen_prop
{
    LINES = 25,
    COLUMNS_IN_LINE = 80,
    BYTES_FOR_EACH_ELEMENT = 2,
    LINE_SIZE = BYTES_FOR_EACH_ELEMENT * COLUMNS_IN_LINE,
    SCREENSIZE = LINE_SIZE * LINES
};

enum text_colors
{
    BLACK = 0x00,
    BLUE = 0x01,
    GREEN = 0x02,
    CYAN = 0x03,
    RED = 0x04,
    MAGENTA = 0x05,
    BROWN = 0x06,
    LIGHT_GRAY = 0x07,
    DARK_GRAY = 0x08,
    LIGHT_BLUE = 0x09,
    LIGHT_GREEN = 0x0a,
    LIGHT_CYAN = 0x0b,
    LIGHT_RED = 0x0c,
    PINK = 0x0d,
    YELLOW = 0x0e,
    WHITE = 0x0f
};

enum consts
{
    EMPTY_SYMBOL = 0x0,
};

static u8 *const video_mem = (void *)0xb8000;
static u8 video_mem_buff[SCREENSIZE];

extern void video_init(void);
extern void video_disable_cursor(void);
extern void *video_scroll(const u8 *pos);
extern u8 *video_clear(void);
extern void video_flush(void);

#endif // SIMPLEKERNEL_CONSOLE_H

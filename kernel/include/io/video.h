// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#ifndef SIMPLEKERNEL_CONSOLE_H
#define SIMPLEKERNEL_CONSOLE_H

#include <libk/stdint.h>

enum
{
    VIDEO_MEM_ADDRESS = 0xb8000
};

enum screen_prop
{
    HEIGHT = 25,
    WIDTH = 80,
    SCREENSIZE = HEIGHT * WIDTH,

    BYTES_FOR_EACH_ELEMENT = 2,
    LINE_SIZE = BYTES_FOR_EACH_ELEMENT * WIDTH,
    SCREENSIZE_BYTES = LINE_SIZE * HEIGHT
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

static u8 *const video_mem = (void *)VIDEO_MEM_ADDRESS;
static u8 video_mem_buff[SCREENSIZE_BYTES];

extern void video_init(void);
extern void video_disable_cursor(void);
extern void *video_scroll(const u8 *video_buffer, u8 *pos);
extern u8 *video_clear(const u8 *video_buffer);
extern void video_flush(const u8 *video_buffer);

#endif // SIMPLEKERNEL_CONSOLE_H

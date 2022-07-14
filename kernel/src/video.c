// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#include <video.h>
#include <string.h>
#include <ports.h>

void video_init()
{
    memset(video_mem_buff, EMPTY_SYMBOL, SCREENSIZE);
    video_disable_cursor();
}

// https://wiki.osdev.org/Text_Mode_Cursor
void video_disable_cursor()
{
    asm_write_port(0x3D4, 0x0A);
    asm_write_port(0x3D5, 0x20);
}

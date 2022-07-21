// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#include <ports.h>
#include <string.h>
#include <video.h>

void video_init(void) {
    memset(video_mem_buff, EMPTY_SYMBOL, SCREENSIZE);
    video_disable_cursor();
}

// https://wiki.osdev.org/Text_Mode_Cursor
void video_disable_cursor(void) {
    asm_write_port(0x3D4, 0x0A);
    asm_write_port(0x3D5, 0x20);
}

void *video_scroll(const u8 *video_buffer, u8 *pos) {
    char *ptr = (void *)video_buffer;

    for (int i = 1; i < LINES; i++) {
        for (int j = 0; j < COLUMNS_IN_LINE; j++) {
            ptr[(i - 1) * COLUMNS_IN_LINE + j] = ptr[i * COLUMNS_IN_LINE + j];
        }
    }

    for (int j = 0; j < COLUMNS_IN_LINE; ++j) {
        ptr[(COLUMNS_IN_LINE - 1) * COLUMNS_IN_LINE + j] = EMPTY_SYMBOL;
    }

    pos -= COLUMNS_IN_LINE;

    return pos;
}
// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#include <io/ports.h>
#include <io/video.h>
#include <libk/string.h>

void video_init(void) {
    memset(video_mem_buff, ' ', SCREENSIZE);
    video_disable_cursor();
}

// https://wiki.osdev.org/Text_Mode_Cursor
void video_disable_cursor(void) {
    asm_write_port(0x3D4, 0x0A);
    asm_write_port(0x3D5, 0x20);
}

void *video_scroll(const u8 *video_buffer, u8 *pos) {
    u8 *ptr = (void *)video_buffer;

    for (int i = 1; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            ptr[(i - 1) * WIDTH + j] = ptr[i * WIDTH + j];
        }
    }

    for (int j = 0; j < WIDTH; ++j) {
        ptr[(WIDTH - 1) * WIDTH + j] = ' ';
    }

    pos -= WIDTH;

    return pos;
}

u8 *video_clear(u8 const *video_buff) {
    u8 *ptr = (void *)video_buff;

    for (int i = 0; i < WIDTH; ++i) {
        *ptr++ = ' ';
    }

    return (void *)video_buff;
}

void video_flush(u8 const *video_buff) {
    memext((void *)video_mem_buff, SCREENSIZE_BYTES, video_buff, LIGHT_GRAY);
    memcpy((void *)video_mem, video_mem_buff, SCREENSIZE_BYTES);
}
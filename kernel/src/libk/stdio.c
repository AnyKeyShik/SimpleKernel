#include <sys/interrupt.h>
#include <io/video.h>
#include <libk/assert.h>
#include <libk/string.h>
#include <libk/stdio.h>

static void kflush();
static void kputc(u8 ch);

static u8 const syslog[SCREENSIZE];
u8 *syslog_pos = (u8 *) syslog;
bool is_early_mode = true;  // whether syslog attached to video memory

void kclear()
{
    syslog_pos = video_clear(syslog);
    kflush();
}

void kprintf(const u8 *format, ...)
{
    va_list list;
    va_start(list, format);

    kvprintf(format, list);
}

void kvprintf(const u8 *format, va_list list)
{
    u8 buff[WIDTH];
    size_t len = vsprintf(buff, format, list);

    for (size_t i = 0; i < len; ++i) {
        if (buff[i] != '\n' && buff[i] != '\t') {
            kputc(buff[i]);
        } else if (buff[i] == '\n') {
            size_t line_pos = (syslog_pos - syslog) % WIDTH;
            for (size_t j = 0; j < WIDTH - line_pos; ++j) {
                kputc(' ');
            }
        } else if (buff[i] == '\t') {
            kputc(' ');
            kputc(' ');
            kputc(' ');
            kputc(' ');
        }
    }

    kflush();
}

void kmode(bool is_early)
{
    is_early_mode = is_early;
}

void klog(u8 *buf, u32 n)
{
    assert(n > 0);
    assert(n < VIDEO_MEM_ADDRESS);
    asm_lock();

    u32 syslog_end_line = (syslog_pos - syslog) / WIDTH;
    u32 syslog_start_line = syslog_end_line - n;
    const void* syslog_begin = syslog + syslog_start_line * WIDTH;
    memcpy(buf, syslog_begin, WIDTH * n);

    asm_unlock();
}

void kflush()
{
    if (is_early_mode) {
        video_flush(syslog);
    }
}

void kputc(u8 ch)
{
    if ((size_t)syslog_pos - (size_t)syslog + 1 < SCREENSIZE) {
        *syslog_pos++ = ch;
    } else {
        syslog_pos = video_scroll(syslog, syslog_pos);
        kputc(ch);
    }
}
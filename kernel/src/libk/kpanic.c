#include <sys/interrupt.h>
#include <libk/assert.h>
#include <libk/stdbool.h>
#include <libk/stdarg.h>
#include <libk/stdio.h>

void kpanic(u8 *message, ...)
{
    va_list list;
    va_start(list, message);

    kmode(true);
    kvprintf(message, list);
    kprintf("kernel panic!\n");
    asm_lock();
    asm_hlt();
}
#include <libk/assert.h>
#include <libk/panic.h>
#include <libk/stdio.h>

void kassert(const u8 *file, u32 line, bool expr)
{
    if (!expr) {
        kpanic("%s line %u\n", file, line);
    }
}

void kunreachable(const u8 *file, u32 line)
{
    kprintf("code unreachable!\n");
    kpanic("%s line %u\n", file, line);
}
#ifndef PANIC_H
#define PANIC_H

#include <libk/stdint.h>

extern void kpanic(u8 *message, ...);

#endif
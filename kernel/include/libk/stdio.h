#ifndef STDIO_H
#define STDIO_H

#include <libk/stdint.h>
#include <libk/stdbool.h>
#include <libk/stdarg.h>

extern void kclear(void);
extern void kprintf(const u8 *format, ...);
extern void kvprintf(const u8 *format, va_list list);
extern void kmode(bool is_early);
extern void klog(u8 *buf, u32 n);

#endif
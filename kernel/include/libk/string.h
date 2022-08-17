// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#ifndef SIMPLEKERNEL_STRING_H
#define SIMPLEKERNEL_STRING_H

#include <libk/stdint.h>
#include <libk/stdarg.h>

extern size_t strlen(const u8 *s);
extern u8 *strcpy(u8 *restrict __dest, const u8 *restrict __src);
extern void *memcpy(void *restrict __dest, const void *restrict __src,
                    size_t __n);
extern void *memset(void *__s, u8 __c, size_t __n);
extern u8 *memext(void *restrict __dest, size_t size, const void *restrict __src,
                  const u8 sym);
extern int strcmp(const u8 *__s1, const u8 *__s2);
extern u8 *strcat(u8 *restrict __dest, const u8 *restrict __src);

extern u8 *strinv(u8 *str);

extern u8 *itoa(int value, u8 *str, int radix);

extern size_t sprintf(u8 *restrict str, const u8 *restrict format, ...);
extern size_t snprintf(u8 *restrict str, size_t size, const u8 *restrict format, ...);
extern size_t vsprintf(u8 *restrict str, const u8 *restrict format, va_list ap);
extern size_t vsnprintf(u8 *restrict str,size_t size, const u8 *restrict format, va_list ap);

#endif  // SIMPLEKERNEL_STRING_H
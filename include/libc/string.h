// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#ifndef SIMPLEKERNEL_STRING_H
#define SIMPLEKERNEL_STRING_H

#include <stdint.h>

extern size_t strlen(const u8 *s);

extern u8 *strcpy(u8 *__restrict __dest, const u8 *__restrict __src);

extern void *memcpy(void *__restrict __dest, const void *__restrict __src,
                    size_t __n);

extern void *memset(void *__s, u8 __c, size_t __n);

extern int strcmp(const u8 *__s1, const u8 *__s2);

extern u8 *strcat(u8 *__restrict __dest, const u8 *__restrict __src);

#endif //SIMPLEKERNEL_STRING_H

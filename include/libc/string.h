// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#ifndef SIMPLEKERNEL_STRING_H
#define SIMPLEKERNEL_STRING_H

#include <stdint.h>

extern size_t strlen(const char *s);

extern char *strcpy(char *__restrict __dest, const char *__restrict __src);

extern void *memcpy(void *__restrict __dest, const void *__restrict __src,
                    size_t __n);

extern void *memset(void *__s, u8 __c, size_t __n);

extern int strcmp(const char *__s1, const char *__s2);

extern char *strcat(char *__restrict __dest, const char *__restrict __src);

#endif //SIMPLEKERNEL_STRING_H
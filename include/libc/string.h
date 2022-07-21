// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#ifndef SIMPLEKERNEL_STRING_H
#define SIMPLEKERNEL_STRING_H

#include <stdint.h>

#ifdef LIBK
extern size_t strlen(const u8 *s);
extern u8 *strcpy(u8 *__restrict __dest, const u8 *__restrict __src);
extern void *memcpy(void *__restrict __dest, const void *__restrict __src,
                    size_t __n);
extern void *memset(void *__s, u8 __c, size_t __n);
extern u8 *memext(void *__restrict __dest, u32 n, const void *__restrict __src,
                  const u8 sym);
extern int strcmp(const u8 *__s1, const u8 *__s2);
extern u8 *strcat(u8 *__restrict __dest, const u8 *__restrict __src);

#else
extern size_t strlen(const u_char *s);
extern u_char *strcpy(u_char *__restrict __dest, const u_char *__restrict __src);
extern void *memcpy(void *__restrict __dest, const void *__restrict __src,
                    size_t __n);
extern void *memset(void *__s, u_char __c, size_t __n);
extern int strcmp(const u_char *__s1, const u_char *__s2);
extern u_char *strcat(u_char *__restrict __dest, const u_char *__restrict __src);
#endif

#endif  // SIMPLEKERNEL_STRING_H
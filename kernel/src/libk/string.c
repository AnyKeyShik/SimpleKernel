// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#include <libk/string.h>

size_t strlen(const u8 *s) {
    const u8 *original = s;

    while (*s != '\0')
        s++;

    return s - original;
}

u8 *strcpy(u8 *__restrict __dest, const u8 *__restrict __src) {
    u8 *original = __dest;

    while (*__src != '\0')
        *__dest++ = *__src++;
    *__dest = '\0';

    return original;
}

void *memcpy(void *__restrict __dest, const void *__restrict __src,
             size_t __n) {
    u8 *buf_dst = __dest;
    const u8 *buf_src = __src;

    for (int i = 0; i < __n; i++) {
        *buf_dst++ = *buf_src++;
    }

    return buf_dst;
}

void *memset(void *__s, u8 __c, size_t __n) {
    u8 *buf_dst = __s;

    for (int i = 0; i < __n; i++) {
        *buf_dst++ = __c;
    }

    return buf_dst;
}

u8 *memext(void *__restrict __dest, u32 n, const void *__restrict __src,
           const u8 sym) {
    u8 *buf_dst = __dest;
    const u8 *buf_src = __src;

    for (int i = 0; i < n; i++) {
        *buf_dst++ = *buf_src++;
        *buf_dst++ = sym;
    }
}

int strcmp(const u8 *__s1, const u8 *__s2) {
    while (1) {
        if (*__s1 != *__s2)
            return (*__s1 - *__s2);
        if (*__s1 == '\0')
            return (0);
        __s1++;
        __s2++;
    }
}

u8 *strcat(u8 *__restrict __dest, const u8 *__restrict __src) {
    u8 *original = __dest;

    while (*__dest != '\0')
        __dest++;
    while (*__src != '\0')
        *__dest++ = *__src++;
    *__dest = '\0';

    return original;
}
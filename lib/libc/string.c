// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#include <string.h>

extern size_t strlen(const char *s) {
    const char *original = s;

    while (*s != '\0')
        s++;

    return s - original;
}

extern char *strcpy(char *__restrict __dest, const char *__restrict __src) {
    char *original = __dest;

    while (*__src != '\0')
        *__dest++ = *__src++;
    *__dest = '\0';

    return original;
}

extern void *memcpy(void *__restrict __dest, const void *__restrict __src,
                    size_t __n) {
    u8 *buf_dst = __dest;
    const u8 *buf_src = __src;

    for (int i = 0; i < __n; ++i) {
        *buf_dst++ = *buf_src++;
    }

    return buf_dst;
}

extern void *memset(void *__s, u8 __c, size_t __n) {
    u8 *buf_dst = __s;

    for (int i = 0; i < __n; ++i) {
        *buf_dst++ = __c;
    }

    return buf_dst;
}

extern int strcmp(const char *__s1, const char *__s2) {
    while (1) {
        if (*__s1 != *__s2)
            return (*__s1 - *__s2);
        if (*__s1 == '\0')
            return (0);
        __s1++;
        __s2++;
    }
}

extern char *strcat(char *__restrict __dest, const char *__restrict __src) {
    char *original = __dest;

    while (*__dest != '\0')
        __dest++;
    while (*__src != '\0')
        *__dest++ = *__src++;
    *__dest = '\0';

    return original;
}
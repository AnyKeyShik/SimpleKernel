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

u8 *memext(void *__restrict __dest, size_t size, const void *__restrict __src,
           const u8 sym) {
    u8 *buf_dst = __dest;
    const u8 *buf_src = __src;

    for (int i = 0; i < size; i++) {
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

u8 *strinv(u8 *str)
{
    size_t size = strlen(str);
    char reverse[size + 2];
    int i = 0;

    for (int j = size - 1; j >= 0; j--) {
        reverse[i] = str[j];
        i++;
    }
    reverse[++i] = '\0';

    strcpy(str, reverse);

    return str; 
}

u8 *itoa(int value, u8 *str, int radix)
{
    char digit;

    do {
        digit = value % radix;
        value /= radix;

        if (digit < 10) {
            *str++ = digit | 0x30;
        } else if (digit < 16) {
            *str++ = ((digit - 10) | 0x40) + 1; /* alpha */
        } else {
            *str++ = '?';
        }
    } while (value > 0);

    if (radix == 16) {
        *str++ = 'x';
        *str++ = '0';
    } else if (radix == 8) {
        *str++ = 'o';
        *str++ = '0';
    } else if (radix == 2) {
        *str++ = 'b';
        *str++ = '0';
    }
    *str++ = '\0';

    strinv(str);

    return str;
}

size_t sprintf(u8 *restrict str, const u8 *restrict format, ...)
{
    va_list list;
    va_start(list, format);

    return vsprintf(str, format, list);
}

size_t snprintf(u8 *restrict str, size_t size, const u8 *restrict format, ...)
{
    va_list list;
    va_start(list, format);

    return vsnprintf(str, size, format, list);
}

size_t vsprintf(u8 *restrict str, const u8 *restrict format, va_list ap)
{
    return vsnprintf(str, 4 * 1024, format, ap);
}

size_t vsnprintf(u8 *restrict str,size_t size, const u8 *restrict format, va_list ap)
{
    size_t count = 0;

    for (size_t j = 0; j < size && format[j] != '\0'; j++) {
        if (format[j] != '%') {
            *str++ = format[j];

            count++;
        } else if (format[j] == '%') {
            u8 number[32];
            u8 *tmp_str;

            switch (format[++j]) {
                case 'c':
                    *str++ = va_arg(ap, char);
                    count++;
                    break;
                case 'd':
                    itoa(va_arg(ap, int), number, 10);
                    strcpy(str, number);
                    str += strlen(number);
                    count += strlen(number);
                    break;
                case 'u':
                    itoa(va_arg(ap, u32), number, 10);
                    strcpy(str, number);
                    str += strlen(number);
                    count += strlen(number);
                    break;
                case 'X':
                    itoa(va_arg(ap, u32), number, 16);
                    strcpy(str, number);
                    str += strlen(number);
                    count += strlen(number);
                    break;
                case 's':
                    tmp_str = va_arg(ap, u8 *);
                    strcpy(str, tmp_str);
                    str += strlen(tmp_str);
                    count += strlen(tmp_str);
                    break;
            }
        }
    }

    *str++ = '\0';

    va_end(ap);

    return count;
}
// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#ifndef SIMPLEKERNEL_LIMITS_H
#define SIMPLEKERNEL_LIMITS_H

/* Number of bits in a `char'.  */
#define CHAR_BIT  8

/* Minimum and maximum values a `signed char' can hold.  */
#define SCHAR_MIN (-128)
#define SCHAR_MAX 127

/* Maximum value an `unsigned char' can hold.  (Minimum is 0.)  */
#define UCHAR_MAX 255

/* Minimum and maximum values a `signed short int' can hold.  */
#define SHRT_MIN  (-32768)
#define SHRT_MAX  32767

/* Maximum value an `unsigned short int' can hold.  (Minimum is 0.)  */
#define USHRT_MAX 65535

/* Minimum and maximum values a `signed int' can hold.  */
#define INT_MIN   (-INT_MAX - 1)
#define INT_MAX   2147483647

/* Maximum value an `unsigned int' can hold.  (Minimum is 0.)  */
#define UINT_MAX  4294967295U

/* Minimum and maximum values a `signed long int'' can hold.  */
#define LONG_MIN  (-LONG_MAX - 1L)
#define LONG_MAX 2147483647L

/* Minimum and maximum values a `unsigned long int' can hold.  */
#define ULONG_MAX    4294967295UL

#define CHAR_WIDTH 8
#define SCHAR_WIDTH 8
#define UCHAR_WIDTH 8
#define SHRT_WIDTH 16
#define USHRT_WIDTH 16
#define INT_WIDTH 32
#define UINT_WIDTH 32
#define LONG_WIDTH 32
#define ULONG_WIDTH 32

#endif //SIMPLEKERNEL_LIMITS_H

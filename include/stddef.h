// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#ifndef SIMPLEKERNEL_STDDEF_H
#define SIMPLEKERNEL_STDDEF_H

typedef unsigned long size_t;

#define HIGH_WORD(addr) ((addr & 0xffff0000) >> 16)
#define LOW_WORD(addr) ((addr & 0xffff))
#define LOW_BYTE(addr) ((addr & 0x00ff))
#define HIGH_BYTE(addr) ((addr & 0xff00) >> 8)

#endif //SIMPLEKERNEL_STDDEF_H

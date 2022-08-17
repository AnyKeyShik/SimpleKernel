// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#ifndef PORTS_H
#define PORTS_H

#include <libk/stdint.h>

/*
 * Port operations
 */
extern u8 asm_read_port(u8 port);
extern void asm_write_port(u32 port, u8 data);

#endif  // PORTS_H
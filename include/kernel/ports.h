// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#ifndef PORTS_H
#define PORTS_H


#include <stdint.h>

/*
 * Port operations
 */
extern u_char asm_read_port(u_char port);
extern void asm_write_port(u_int port, u_char data);

#endif //PORTS_H
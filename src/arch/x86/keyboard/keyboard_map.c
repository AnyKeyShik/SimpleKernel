// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#include "keyboard/keyboard_map.h"

unsigned char keyboard_map[128] = {
        0, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
        '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
        0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',
        0, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0,
        '*', 0, ' ',
        0,      // Caps lock
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // F1..10 Keys
        0,      // 69 - Num lock
        0,      // Scroll Lock
        0,      // Home key
        0,      // Up Arrow
        0,      // Page Up
        '-',
        0,      // Left Arrow
        0,
        0,      // Right Arrow
        '+',
        0,      // 79 - End key
        0,      // Down Arrow
        0,      // Page Down
        0,      // Insert Key
        0,      // Delete Key
        0, 0, 0,
        0,      // F11 Key
        0,      // F12 Key
        0,      // All other keys are undefined
};

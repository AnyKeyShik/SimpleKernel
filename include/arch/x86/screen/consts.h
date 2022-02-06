// Copyright (c) 2022. AnyKeyShik Rarity
//
// nikitav59@gmail.com
//
// https://t.me/AnyKeyShik

#ifndef SCREEN_CONSTS_H
#define SCREEN_CONSTS_H

// there are 25 lines each of 80 columns; each element takes 2 bytes
#define LINES 25
#define COLUMNS_IN_LINE 80
#define BYTES_FOR_EACH_ELEMENT 2
#define SCREENSIZE BYTES_FOR_EACH_ELEMENT * COLUMNS_IN_LINE * LINES

extern char *vidptr;

#endif

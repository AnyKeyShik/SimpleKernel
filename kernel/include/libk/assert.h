#ifndef ASSERT_H
#define ASSERT_H

#include <libk/stdint.h>
#include <libk/stdbool.h>

#define assert(expr) kassert(__FILE__, __LINE__, expr)
#define unreachable() kunreachable(__FILE__, __LINE__)

extern void kassert(const u8 *file, u32 line, bool expr);
extern void kunreachable(const u8 *file, u32 line);

#endif
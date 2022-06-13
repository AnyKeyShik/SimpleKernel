# Copyright (c) 2022. AnyKeyShik Rarity
#
# nikitav59@gmail.com
#
# https://t.me/AnyKeyShik

#
# Makefile fragment for the Simple Kernel.
# This is NOT a complete makefile;
# you must run GNU make in the top-level directory
# where the Makefile is located.
#

# Folders
LIB_SRCDIR := $(LIBDIR)/$(LIBC_DIR)
LIB_INCLUDE := $(INCLUDE)/$(LIBC_DIR)

LIBC_CFLAGS := -fno-stack-protector -fPIC -Wno-builtin-declaration-mismatch -m32 -c -I$(LIB_INCLUDE)
LIBK_CFLAGS := -fno-stack-protector -fPIC -Wno-builtin-declaration-mismatch -m32 -c -I$(LIB_INCLUDE) -DLIBK
ifeq ($(DEBUG),1)
LIBC_CFLAGS += -g
LIBK_CFLAGS += -g
endif

# Flags for libc
LIBC_LFLAGS := -m elf_i386 --nmagic -nostdlib -shared

#Flags for libk
LIBK_LFLAGS := rcs

LIBC_OBJDIR := $(BUILDDIR)/libc
LIBK_OBJDIR := $(BUILDDIR)/libk

# Sources and objects lists
LIB_SRC := $(LIB_SRCDIR)/string.c
LIBC_OBJ := $(patsubst $(LIB_SRCDIR)/%, $(LIBC_OBJDIR)/%, $(LIB_SRC:.c=_c.o))
LIBK_OBJ := $(patsubst $(LIB_SRCDIR)/%, $(LIBK_OBJDIR)/%, $(LIB_SRC:.c=_c.o))

$(LIBC_OBJDIR)/%_c.o: $(LIB_SRCDIR)/%.c
	$(V)mkdir -p $(LIBC_OBJDIR)
	$(V)echo "Compiling parts of $(LIBC_TARGET)..."
	$(V)echo -e "\tCompiling $<..."; $(CC) $(LIBC_CFLAGS) -o $@ $<

$(LIBK_OBJDIR)/%_c.o: $(LIB_SRCDIR)/%.c
	$(V)mkdir -p $(LIBK_OBJDIR)
	$(V)echo "Compiling parts of $(LIBK_TARGET)..."
	$(V)echo -e "\tCompiling $<..."; $(CC) $(LIBK_CFLAGS) -o $@ $<

$(LIBC_TARGET): $(LIBC_OBJ)
	$(V)mkdir -p $(TARGETDIR)
	$(V)echo -e "\tLinking $(LIBC_TARGET)"; $(LD) $(LIBC_LFLAGS) -o $@ $(LIBC_OBJ)

$(LIBK_TARGET): $(LIBK_OBJ)
	$(V)mkdir -p $(BUILDDIR)
	$(V)echo "Making $(LIBK_TARGET)..."; $(AR) $(LIBK_LFLAGS) $@ $(LIBK_OBJ)
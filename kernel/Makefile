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
KER_SRCDIR := $(KERDIR)/src
KER_INCLUDE := $(INCLUDE)/$(KERDIR)

# Flags
ifeq ($(DEBUG),1)
KER_CFLAGS := -fno-stack-protector -fno-pie -Wno-builtin-declaration-mismatch -m32 -g -c -I$(KER_INCLUDE) -I$(LIB_INCLUDE) -o
else
KER_CFLAGS := -fno-stack-protector -fno-pie -Wno-builtin-declaration-mismatch -m32 -c -I$(KER_INCLUDE) -I$(LIB_INCLUDE) -o
endif
KER_NFLAGS := -felf
KER_LFLAGS := -m elf_i386 --nmagic -nostdlib  -T

# Sources and objects lists
KER_SOURCES := $(KER_SRCDIR)/console.c \
		$(KER_SRCDIR)/kernel.c
KER_OBJECTS := $(patsubst $(KER_SRCDIR)/%, $(BUILDDIR)/%, $(KER_SOURCES:.c=_c.o))

KER_ASM_SRC := $(KER_SRCDIR)/multiboot.asm \
		$(KER_SRCDIR)/boot.asm
KER_ASM_OBJ := $(patsubst $(KER_SRCDIR)/%,$(BUILDDIR)/%,$(KER_ASM_SRC:.asm=_asm.o))

$(BUILDDIR)/%_c.o: $(KER_SRCDIR)/%.c
	$(V)mkdir -p $(BUILDDIR)
	$(V)echo "Compiling c parts of $(EXECUTABLE)..."
	$(V)echo -e "\tCompiling $<..."; $(CC) $(KER_CFLAGS) $@ $<

$(BUILDDIR)/%_asm.o: $(KER_SRCDIR)/%.asm
	$(V)mkdir -p $(BUILDDIR)
	$(V)echo "Compiling asm parts of $(EXECUTABLE)..."
	$(V)echo -e "\tCompiling $<..."; $(ASM) $(KER_NFLAGS) $< -o $@

$(TARGET): $(KER_OBJECTS) $(KER_ASM_OBJ) $(LIBK_TARGET)
	$(V)mkdir -p $(TARGETDIR)
	$(V)echo "Linking..."
	$(V)echo -e "\tLinking $(TARGET)"; $(LNK) $(KER_LFLAGS) $(KERDIR)/kernel.ld -o $@ $(KER_OBJECTS) $(KER_ASM_OBJ)
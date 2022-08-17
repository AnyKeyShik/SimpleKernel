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
KER_ARCHDIR := $(KERDIR)/arch/$(arch)
KER_SRCDIR := $(KERDIR)/src
KER_INCLUDE := $(KERDIR)/include

# Flags
ifeq ($(DEBUG),1)
KER_CFLAGS := -fno-stack-protector -fno-pie -nostdlib -Wno-builtin-declaration-mismatch -m32 -std=c99 -g -c -I$(KER_INCLUDE)
else
KER_CFLAGS := -fno-stack-protector -fno-pie -nostdlib -Wno-builtin-declaration-mismatch -m32 -std=c99 -c -I$(KER_INCLUDE)
endif
KER_NFLAGS := -felf
KER_LFLAGS := -m elf_i386 --nmagic -nostdlib -z noexecstack  -T

# Sources and objects lists
KER_SOURCES := $(KER_SRCDIR)/io/video.c \
		$(KER_SRCDIR)/libk/string.c \
		$(KER_SRCDIR)/libk/stdio.c \
		$(KER_SRCDIR)/libk/kpanic.c \
		$(KER_SRCDIR)/libk/kassert.c
KER_OBJECTS := $(patsubst $(KER_SRCDIR)/%, $(BUILDDIR)/%, $(KER_SOURCES:.c=_c.o))
KER_OBJECTS += $(BUILDDIR)/kernel_c.o

KER_ASM_SRC := $(KER_ARCHDIR)/multiboot.asm \
		$(KER_ARCHDIR)/boot.asm \
		$(KER_ARCHDIR)/ports.asm \
		$(KER_ARCHDIR)/interrupt.asm
KER_ASM_OBJ := $(patsubst $(KER_ARCHDIR)/%, $(BUILDDIR)/$(arch)/%, $(KER_ASM_SRC:.asm=_asm.o))

$(BUILDDIR)/%_c.o: $(KER_SRCDIR)/%.c
	$(V)mkdir -p $(BUILDDIR)/{io,libk}
	$(V)echo "Compiling c parts of $(EXECUTABLE)..."
	$(V)echo -e "\tCompiling $<..."; $(CC) $(KER_CFLAGS) $< -o $@

$(BUILDDIR)/kernel_c.o: $(KERDIR)/kernel.c
	$(V)mkdir -p $(BUILDDIR)
	$(V)echo "Compiling c parts of $(EXECUTABLE)..."
	$(V)echo -e "\tCompiling $<..."; $(CC) $(KER_CFLAGS) $< -o $@

$(BUILDDIR)/$(arch)/%_asm.o: $(KER_ARCHDIR)/%.asm
	$(V)mkdir -p $(BUILDDIR)/$(arch)
	$(V)echo "Compiling asm parts of $(EXECUTABLE)..."
	$(V)echo -e "\tCompiling $<..."; $(ASM) $(KER_NFLAGS) $< -o $@

$(TARGET): $(KER_OBJECTS) $(KER_ASM_OBJ)
	$(V)mkdir -p $(TARGETDIR)
	$(V)echo "Linking..."
	$(V)echo -e "\tLinking $(TARGET)"; $(LNK) $(KER_LFLAGS) $(KERDIR)/kernel.ld -o $@ $(KER_OBJECTS) $(KER_ASM_OBJ)
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
ARCHDIR := $(KERDIR)/arch/$(arch)
SRCDIR := $(KERDIR)/arch/$(arch)/src
INCLUDEDIR := $(KERDIR)/arch/$(arch)/include

# Flags
ifeq ($(DEBUG),1)
CFLAGS := -fno-stack-protector -fno-pie -Werror -Wno-builtin-declaration-mismatch -m32 -g -c -I $(INCLUDEDIR) -o
else
CFLAGS := -fno-stack-protector -fno-pie -Werror -Wno-builtin-declaration-mismatch -m32 -c -I $(INCLUDEDIR) -o
endif

NFLAGS := -felf
LFLAGS := -m elf_i386 --nmagic -nostdlib  -T

# Sources and objects lists
SOURCES := $(SRCDIR)/console.c \
		$(SRCDIR)/kernel.c
OBJECTS := $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(SOURCES:.$(SRCTEXT)=_c.o))

ASM_SOURCES := $(SRCDIR)/multiboot.asm \
		$(SRCDIR)/boot.asm
ASM_OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(ASM_SOURCES:.$(ASMTEXT)=_asm.o))

$(BUILDDIR)/%_c.o: $(SRCDIR)/%.$(SRCTEXT)
	$(V)mkdir -p $(BUILDDIR)
	$(V)echo "Compiling c parts of $(EXECUTABLE)..."
	$(V)echo -e "\tCompiling $<..."; $(CC) $(CFLAGS) $@ $<

$(BUILDDIR)/%_asm.o: $(SRCDIR)/%.$(ASMTEXT)
	$(V)mkdir -p $(BUILDDIR)
	$(V)echo "Compiling asm parts of $(EXECUTABLE)..."
	$(V)echo -e "\tCompiling $<..."; $(ASM) $(NFLAGS) $< -o $@

$(TARGET): $(OBJECTS) $(ASM_OBJECTS)
	$(V)mkdir -p $(TARGETDIR)
	$(V)echo "Linking..."
	$(V)echo -e "\tLinking $(TARGET)"; $(LNK) $(LFLAGS) $(ARCHDIR)/kernel.$(LNKTEXT) -o $@ $(OBJECTS) $(ASM_OBJECTS)
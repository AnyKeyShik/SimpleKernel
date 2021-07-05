#
# Makefile
# Simple OS project
#
# Created by AnyKeyShik Rarity 2021-06-07
# Copyright (c) 2021 AnyKeyShik Lab Inc. All rights reserved.
#

arch ?= x86

# CC
CC := gcc
ASM := nasm
LNK := ld

# Folders
SRCDIR := src/arch/x86
INCLUDEDIR := include/arch/x86
LNKDIR := lnk
WORKERSDIR := workers/arch/x86
BUILDDIR := build
TARGETDIR := bin

# Targets
EXECUTABLE := kernel
ISOIM := kernel.iso
TARGET := $(TARGETDIR)/$(EXECUTABLE)
ISO := $(TARGETDIR)/$(ISOIM)

# Code lists
SRCTEXT := c
ASMTEXT := S
LNKTEXT := ld
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCTEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCTEXT)=_c.o))
ASM_SOURCES := $(shell find $(SRCDIR) -type f -name *.$(ASMTEXT))
ASM_OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(ASM_SOURCES:.$(ASMTEXT)=_asm.o))

# Flags
CFLAGS := -fno-stack-protector -m32 -c -I $(INCLUDEDIR) -o
NFLAGS := -felf
LFLAGS := -m elf_i386 --nmagic -T

.PHONY: first distclean clean iso run

first: iso

$(BUILDDIR)/%_c.o: $(SRCDIR)/%.$(SRCTEXT)
	@mkdir -p $(BUILDDIR)
	@echo "Compiling c parts of $(EXECUTABLE)..."
	@echo -e "\tCompiling $<..."; $(CC) $(CFLAGS) $@ $<

$(BUILDDIR)/%_asm.o: $(SRCDIR)/%.$(ASMTEXT)
	@mkdir -p $(BUILDDIR)
	@echo "Compiling asm parts of $(EXECUTABLE)..."
	@echo -e "\tCompiling $<..."; $(ASM) $(NFLAGS) $< -o $@

$(TARGET): $(OBJECTS) $(ASM_OBJECTS)
	@mkdir -p $(TARGETDIR)
	@echo "Linking..."
	@echo -e "\tLinking $(TARGET)"; $(LNK) $(LFLAGS) $(LNKDIR)/link.$(LNKTEXT) -o $@ $(OBJECTS) $(ASM_OBJECTS)

distclean:
	@echo "Cleaning objects..."
	@rm -rf build

clean:
	@echo "Cleaning all..."
	@rm -rf build bin

iso $(ISO): $(TARGET)
	@mkdir -p iso/boot/grub
	@cp bin/kernel iso/boot/
	@cp $(WORKERSDIR)/grub.cfg iso/boot/grub/
	grub-mkrescue -d /usr/lib/grub/i386-pc/ -o bin/kernel.iso iso
	@rm -r iso

run: $(ISO)
	@qemu-system-x86_64 -cdrom $<

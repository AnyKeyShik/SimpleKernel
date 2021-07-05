#
# Makefile
# Simple kernel project
#
# Created by AnyKeyShik Rarity 2018-30-11
# Copyright (c) 2018 AnyKeyShik Lab Inc. All rights reserved.
#

# CC
CC := gcc
NASM := nasm
LNK := ld

# Folders
SRCDIR := src
LNKDIR := lnk
INCLUDEDIR := include
BUILDDIR := build
TARGETDIR := bin

# Targets
EXECUTABLE := kernel
TARGET := $(TARGETDIR)/$(EXECUTABLE)

# Code lists
SRCTEXT := c
ASMTEXT := asm
LNKTEXT := ld
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCTEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCTEXT)=_c.o))
ASM_SOURCES := $(shell find $(SRCDIR) -type f -name *.$(ASMTEXT))
ASM_OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(ASM_SOURCES:.$(ASMTEXT)=_asm.o))

# Flags
CFLAGS := -fno-stack-protector -m32 -c -I $(INCLUDEDIR) -o
NFLAGS := -f elf32
LFLAGS := -m elf_i386 -T

first: $(TARGETDIR)/$(EXECUTABLE)

$(BUILDDIR)/%_c.o: $(SRCDIR)/%.$(SRCTEXT)
	@mkdir -p $(BUILDDIR)
	@echo "Compiling c parts of $(EXECUTABLE)..."
	@echo -e "\tCompiling $<..."; $(CC) $(CFLAGS) $@ $<

$(BUILDDIR)/%_asm.o: $(SRCDIR)/%.$(ASMTEXT)
	@echo "Compiling asm parts of $(EXECUTABLE)..."
	@echo -e "\tCompiling $<..."; $(NASM) $(NFLAGS) $< -o $@

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

run: $(TARGETDIR)/$(EXECUTABLE)
	@qemu-system-x86_64 -kernel $<
iso: $(TARGETDIR)/$(EXECUTABLE)
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp bin/kernel iso/boot/
	echo 'set timeout=0' > iso/boot/grub/grub.cfg
	echo 'set default=0' >> iso/boot/grub/grub.cfg
	echo '' >> iso/boot/grub/grub.cfg
	echo 'menuentry "simplekernel" {' >> iso/boot/grub/grub.cfg
	echo '  multiboot /boot/kernel' >> iso/boot/grub/grub.cfg
	echo '	boot'	>> iso/boot/grub/grub.cfg
	echo '}'	>> iso/boot/grub/grub.cfg
	grub-mkrescue --output=bin/kernel.iso iso
	rm -r iso

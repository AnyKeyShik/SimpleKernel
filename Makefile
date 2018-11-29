#
# Makefile
# Simple kernel project
#
# Created by AnyKeyShik Rarity on 2018-29-11
# Copyright (c) 2018 AnyKeyShik Lab Inc. All rights reserved.
#


# Objects. TODO: rewrite it
OBJECTS := obj/include/keyboard_map_c.o obj/include/consts_c.o obj/include/idt_c.o obj/include/keyboard_c.o obj/include/screen_c.o obj/kernel_c.o obj/kernel_asm.o

# Source dirs
SRCDIR := src
INCDIR := include
LNKDIR := lnk

#TODO: Add docs and it autogenerate
# Build dirs
OBJDIR := obj
BINDIR := bin

# Output binary name
KERNEL_NAME := kernel

first: $(BINDIR)/$(KERNEL_NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)/include

$(BINDIR):
	mkdir -p $(BINDIR)

# Compile asm part
$(OBJDIR)/%_asm.o: $(SRCDIR)/%.asm $(OBJDIR)
	nasm -f elf32 $< -o $@

# Compile *.c part of header
$(OBJDIR)/include/%_c.o: $(INCDIR)/%.c $(OBJDIR)
	gcc -fno-stack-protector -m32 -c $< -o $@

# Compile main file
$(OBJDIR)/%_c.o: $(SRCDIR)/%.c $(OBJDIR)
	gcc -fno-stack-protector -m32 -c $< -o $@

# Link all files and create binary
$(BINDIR)/$(KERNEL_NAME): $(LNKDIR)/link.ld $(OBJECTS) $(BINDIR)
	ld -m elf_i386 -T $< -o $@ $(OBJECTS)

# Build and run kernel
run: $(BINDIR)/$(KERNEL_NAME)
	qemu-system-x86_64 -kernel $<

# Clean all build directories (objects and binaries)
clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: run first clean

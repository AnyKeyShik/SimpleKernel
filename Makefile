# Copyright (c) 2022. AnyKeyShik Rarity
#
# nikitav59@gmail.com
#
# https://t.me/AnyKeyShik

# Run 'make V=1' to turn on verbose commands, or 'make V=0' to turn them off.
ifeq ($(V),1)
override V =
endif
ifeq ($(V),0)
override V = @
endif

# try to infer the correct QEMU
ifndef QEMU
QEMU := $(shell if which qemu > /dev/null 2>&1; \
	then echo qemu; exit; \
	elif which qemu-system-i386 > /dev/null 2>&1; \
	then echo qemu-system-i386; exit; \
	else \
	qemu=/Applications/Q.app/Contents/MacOS/i386-softmmu.app/Contents/MacOS/i386-softmmu; \
	if test -x $$qemu; then echo $$qemu; exit; fi; fi; \
	echo "***" 1>&2; \
	echo "*** Error: Couldn't find a working QEMU executable." 1>&2; \
	echo "*** Is the directory containing the qemu binary in your PATH" 1>&2; \
	echo "*** or have you tried setting the QEMU variable in conf/env.mk?" 1>&2; \
	echo "***" 1>&2; exit 1)
endif

-include conf/env.mk

# Architecture defines
arch ?= x86

# CC
CC := gcc
ASM := nasm
LNK := ld

# Folders
SRCDIR := src/arch/$(arch)
INCLUDEDIR := include/arch/$(arch)
LNKDIR := lnk
BOOTDIR := boot/arch/$(arch)
BUILDDIR := build
TARGETDIR := bin

# Targets
EXECUTABLE := kernel
ISOIM := kernel.iso
TARGET := $(TARGETDIR)/$(EXECUTABLE)
ISO := $(TARGETDIR)/$(ISOIM)

# Code lists
SRCTEXT := c
ASMTEXT := asm
LNKTEXT := ld

# Flags
CFLAGS := -fno-stack-protector -nostdinc -O0 -m32 -c -I $(INCLUDEDIR) -o
NFLAGS := -felf
LFLAGS := -m elf_i386 --nmagic -T
QEMUOPTS := -serial mon:stdio -cdrom

ifdef DEBUG
GDBPORT	:= $(shell expr `id -u` % 5000 + 25000)
override QEMUOPTS = -serial mon:stdio -gdb tcp::$(GDBPORT) -cdrom
endif

.PHONY: first distclean clean iso run all

first: iso

all: run

run: $(ISO)
	$(V)$(QEMU) $(QEMUOPTS) $<

iso $(ISO): $(TARGET)
	$(V)mkdir -p iso/boot/grub
	$(V)cp bin/kernel iso/boot/
	$(V)cp $(BOOTDIR)/grub.cfg iso/boot/grub/
	$(V)grub-mkrescue -d /usr/lib/grub/i386-pc/ -o bin/kernel.iso iso
	$(V)rm -r iso

distclean:
	$(V)echo "Cleaning objects..."
	$(V)rm -rf build

clean:
	$(V)echo "Cleaning all..."
	$(V)rm -rf build bin

include $(SRCDIR)/Makefrag

$(TARGET): $(OBJECTS) $(ASM_OBJECTS)
	$(V)mkdir -p $(TARGETDIR)
	$(V)echo "Linking..."
	$(V)echo -e "\tLinking $(TARGET)"; $(LNK) $(LFLAGS) $(LNKDIR)/link.$(LNKTEXT) -o $@ $(OBJECTS) $(ASM_OBJECTS)
